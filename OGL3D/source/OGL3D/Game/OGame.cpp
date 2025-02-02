#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>

#include <OGL3D/Math/OMat4.h>
#include <OGL3D/Math/OVec2.h>
#include <OGL3D/Math/OVec4.h>

#include <OGL3D/Game/OCamera.h>
#include <OGL3D/Game/OGraphicsEntity.h>
#include <OGL3D/Game/OLightEntity.h>

#include <OGL3D/Resource/OMesh.h>
#include <OGL3D/Resource/OTexture.h>

#include <math.h>

struct LightData
{
    OVec4 color;
    OVec4 direction;
};



struct UniformData
{
    OMat4 world;
    OMat4 view;
    OMat4 proj;
    OVec4 cameraPos;
    LightData lights[32];
    int lightsNum = 0;
};



OGame::OGame()
{
    m_inputManager = std::make_unique<OInputManager>();
	m_graphicsEngine = std::make_unique<OGraphicsEngine>();
	m_display = std::make_unique<OWindow>();
    m_resourceManager = std::make_unique<OResourceManager>(this);

    m_soundEngine = irrklang::createIrrKlangDevice();


	m_display->makeCurrentContext();

	m_graphicsEngine->setViewport(m_display->getInnerSize());

    getInputManager()->setScreenArea(m_display->getInnerSize());


    m_uniform = m_graphicsEngine->createUniformBuffer({
        sizeof(UniformData) // size in bytes of the data structure we want to pass to shaders
        });
}



OGame::~OGame()
{
}

void OGame::onCreate()
{
}

void OGame::onUpdate(f32 deltaTime)
{
}

void OGame::onUpdateInternal()
{
    m_inputManager->update();

    //computing delta time-------------------
    auto now = std::chrono::system_clock::now(); // take the current time
    std::chrono::duration<double> elapsedSeconds = now - m_oldTime; // let's take the difference between the current time and the time taken in the previous frame in seconds (the so called delta time)
    if (!m_oldTime.time_since_epoch().count()) //if m_oldTime has not been set yet, simply set elapsedSeconds to 0
        elapsedSeconds = std::chrono::duration<double>();
    m_oldTime = now; // store the current time in order to be used in the next frame

    f32 deltaTime = (f32)elapsedSeconds.count();
    //---------------------------------------------

    //destroy the entities that have been release in the previous iteration
    // we destroy the entities here in order to not create issues during the loop over the main map (m_entities)
    //--------------------------------
    for (auto entity : m_entitiesToDestroy)
    {
        auto id = typeid(OMeshEntity).hash_code(); //Only working for OMeshEntities actually ( FURTHER REVISION IS REQUIRED !!! )
       
        m_entities[id].erase(entity);
    }
    m_entitiesToDestroy.clear();
    //----------------------------------
   

    //update game and entities
    //----------------------------------
    onUpdate(deltaTime);

    for (auto& [key, entities] : m_entities)
    {
        for (auto& [key, entity] : entities)
        {
            entity->onUpdate(deltaTime);
        }
    }
    //----------------------------------

    //update the graphics part
    onGraphicsUpdate(deltaTime);


   
}

void OGame::onQuit()
{
    //m_soundEngine->drop();
}


void OGame::quit()
{
	m_isRunning = false;
}

void OGame::onGraphicsUpdate(f32 deltaTime)
{
    m_graphicsEngine->clear(OVec4(0, 0, 0, 1));
   
    UniformData data = {};


    {
        auto camId = typeid(OCamera).hash_code();
        auto it = m_entities.find(camId);
        //let's set the camera data to the uniformdata structure, in order to pass them to the shaders for the final rendering
        if (it != m_entities.end())
        {
            for (auto& [key, camera] : it->second)
            {
                //the camera data are the view and projection
                //view is simply the world matrix of the camera inverted
                OMat4 w;
                auto cam = dynamic_cast<OCamera*>(camera.get());
                cam->getViewMatrix(data.view);
                cam->setScreenArea(this->m_display->getInnerSize());
                cam->getProjectionMatrix(data.proj);
                cam->getWorldMatrix(w);
                auto pos = w.getTranslation();
                data.cameraPos = OVec4(pos.x, pos.y, pos.z, 1);
            }
        }
    }


    {
        auto lightId = typeid(OLightEntity).hash_code();
        auto it = m_entities.find(lightId);
        //let's pass the data of all the lights in the uniform data structure
        if (it != m_entities.end())
        {
            auto i = 0;
            for (auto& [key, light] : it->second)
            {
                OMat4 w;
                auto l = dynamic_cast<OLightEntity*>(light.get());
                light->getWorldMatrix(w);
                auto dir = w.getForwardDirection();
                data.lights[i].direction = OVec4(dir.x,dir.y,dir.z,1);
                data.lights[i].color = l->getColor();
                i++;
            }
            data.lightsNum = (int)it->second.size(); 
        }
    }

    for (auto& [key, entities] : m_entities)
    {
        //for each graphics entity
        for (auto& [key, entity] : entities)
        {
            if (auto e = dynamic_cast<OGraphicsEntity*>(entity.get()))
            {
                //let's retrive the world matrix and let's pass it to the uniform buffer
                e->getWorldMatrix(data.world);

                m_uniform->setData(&data);
                m_graphicsEngine->setShader(m_shader); //bind shaders to graphics pipeline
                m_graphicsEngine->setUniformBuffer(m_uniform, 0); // bind uniform buffer

                //call internal graphcis update of the entity in order to handle specific graphics data/functions 
                e->onGraphicsUpdate(deltaTime);
            }
            else if (auto e = dynamic_cast<OMeshEntity*>(entity.get()))
            {
                //let's retrive the world matrix and let's pass it to the uniform buffer
                e->getWorldMatrix(data.world);

                m_uniform->setData(&data);
                m_graphicsEngine->setShader(e->getShader()); //bind custom shader created by the user to graphics pipeline
                m_graphicsEngine->setUniformBuffer(m_uniform, 0); // bind uniform buffer

                drawMesh(e);
            }
            else
            {
                break;
            }
        }
    }

    m_display->present(false);
}

void OGame::createEntityConcrete(OEntity* entity, size_t id)
{   
    auto entityPtr = std::unique_ptr<OEntity>(entity);
    auto camId = typeid(OCamera).hash_code();
    entity->m_game = this;
    if (id == camId)
    {
        auto it = m_entities.find(camId);
        if (it != m_entities.end())
        {
            if (it->second.size()) return;
            it->second.emplace(entity, std::move(entityPtr));
        }
        else
        {
            m_entities[camId].emplace(entity, std::move(entityPtr));
        }
    }
    else
    {
        m_entities[id].emplace(entity, std::move(entityPtr));
    }
    entity->onCreate();
}

void OGame::removeEntity(OEntity* entity)
{
    m_entitiesToDestroy.emplace(entity);
}

void OGame::drawMesh(OMeshEntity* entity)
{
    if (!entity) return;
   
    m_graphicsEngine->setFaceCulling(OCullType::None); // draw only the front faces, the back faces are discarded
    m_graphicsEngine->setWindingOrder(OWindingOrder::CounterClockWise); //consider the position of vertices in clock wise way.

    if (entity->getTexture())
        m_graphicsEngine->setTexture2D(entity->getTexture()->getTexture2D(), 0);

    //during the graphcis update, we call the draw function
    m_graphicsEngine->setVertexArrayObject(entity->getMesh()->getVertexArrayObject()); //bind vertex buffer to graphics pipeline
    m_graphicsEngine->drawIndexedTriangles(OTriangleType::TriangleList, entity->getMesh()->getVertexArrayObject()->getNumIndices());//draw triangles through the usage of index buffer
}
