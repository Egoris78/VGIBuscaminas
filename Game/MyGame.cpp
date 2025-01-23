#include "MyGame.h"
#include <iostream>
#include <time.h>
using namespace std;

//For randomizing stuff
std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> rand_engine;
std::uniform_real_distribution<> uniform_zero_to_one(0.0, 1.0);
//


MyGame::MyGame()
{
}

MyGame::~MyGame()
{
}

//Loads textures, meshes and shaders
void MyGame::loadAssets() //On changes: please update "Logic/Utilities.h" enums
{
	//Textures
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/tile.png"))); // 0 -> Tile
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/selectedTile.png"))); // 1 -> Selected tile
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile0.png"))); // 2 -> Opened tile 0
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile1.png"))); // 3 -> Opened tile 1
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile2.png"))); // 4 -> Opened tile 2
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile3.png"))); // 5 -> Opened tile 3
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile4.png"))); // 6 -> Opened tile 4
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile5.png"))); // 7 -> Opened tile 5
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile6.png"))); // 8 -> Opened tile 6
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile7.png"))); // 9 -> Opened tile 7
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTile8.png"))); // 10 -> Opened tile 8
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/openedTileBomb.png"))); // 11 -> Opened tile bomb
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/tiles/flaggedTile.png"))); // 12 -> Flagged tile
	
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/stone.png"))); // 13 -> Stone
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/wood.png"))); // 14 -> Wood
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/black.jpg")));// 15 -> Black
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/red.png")));// 16 -> Red
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/green1.png")));// 17 -> Green1
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/green2.png")));// 18 -> Green2
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/green3.png")));// 19 -> Green3
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/others/green4.png")));// 20 -> Green4

	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/skybox/sky.jpg"))); // 21 -> Sky

	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/wallpaper/landscape.png"))); // 22 -> Landscape
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/wallpaper/win.png"))); // 23 -> Win
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/wallpaper/lose.png"))); // 24 -> Lose

	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/resume.png"))); // 25 -> Resume button
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/resumeSelected.png"))); // 26 -> Resume button selected
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/quit.png"))); // 27 -> Quit button
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/quitSelected.png"))); // 28 -> Quit button selected
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/easy.png"))); // 29 -> Easy button
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/easySelected.png"))); // 30 -> Easy button selected
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/medium.png"))); // 31 -> Medium button
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/mediumSelected.png"))); // 32 -> Medium button selected
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/hard.png"))); // 33 -> Hard button
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/hardSelected.png"))); // 34 -> Hard button selected
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/classic.png"))); // 35 -> Classic title
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/UIElements/advance.png"))); // 36 -> Advance title
	

	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/entities/character.png"))); // 37 -> Character
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/entities/bomb.png"))); // 38 -> Bomb
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/entities/flag.png"))); // 39 -> Flag
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/entities/forest.png"))); // 40 -> Forest
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/entities/grass.png"))); // 41 -> Grass
	m_textures.push_back(std::dynamic_pointer_cast<OTexture>(getResourceManager()->createResourceFromFile(L"Assets/Textures/entities/floor.png"))); // 42 -> Floor

	//MeshObj
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/cube.obj"))); // 0 -> Cube
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/sphere.obj"))); // 1 -> Sphere
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/deadTree.obj"))); // 2 -> DeadTree
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/flag.obj"))); // 3 -> Flag
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/bomb.obj"))); // 4 -> Bomb
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/grass.obj"))); // 5 -> Grass
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/character.obj"))); // 6 -> Character
	m_meshObj.push_back(std::dynamic_pointer_cast<OMesh>(getResourceManager()->createResourceFromFile(L"Assets/Meshes/forest.obj"))); // 6 -> Forest

	//shaders
	m_meshShader = getGraphicsEngine()->createShader(
		{
			L"Assets/Shaders/MeshShader.vert",
			L"Assets/Shaders/MeshShader.frag"
		});

	m_skyboxShader = getGraphicsEngine()->createShader(
		{
			L"Assets/Shaders/SkyBoxShader.vert",
			L"Assets/Shaders/SkyBoxShader.frag"
		});

	//Cooldown timers
	for (size_t i = 0; i < cooldownTimers::nItems; i++)
	{
		m_cooldowns.push_back(0);
	}
}

// Returns true or false based on a probability between 0.0 and 1.0
bool MyGame::randomBoolWithProb(f32 prob)
{
	return uniform_zero_to_one(rand_engine) <= prob;
}

f32 MyGame::randomNumberInRange(f32 low, f32 high)
{
	std::uniform_real_distribution<f32> distr(low, high);
	return distr(rand_engine);
}

void MyGame::onCreate()
{
	rand_engine.seed(std::chrono::system_clock::now().time_since_epoch().count()); // We prerandomize the rand_engine seed
	
	//Loading textures, meshes, shaders and cooldowns
	loadAssets();
	
	// background music
	if (m_soundEngine)
		m_soundEngine->play2D("Assets/Audios/music/bestFriend8bits.mp3", true);

	//Creating the camera
	{
		m_cam = createEntity<OCamera>();

		m_cam->setCameraType(OCameraType::Perspective);
		m_cam->setFarPlane(1500.0f);
		m_cam->setNearPlane(3.1f);
		m_cam->setFieldOfView(1.2f);
		m_cam->setPosition(OVec3(10.0f, 2.0f, 10.0f));

		m_sensitivity = 0.0005f;
	}

	//Creating the player model
	{
		m_player = createEntity<OMeshEntity>();

		m_player->setScale(OVec3(0.75f, 0.75f, 0.75f));
		m_player->setPosition(OVec3(10.0f, 2.0f, 10.0f));
		m_player->setRotation(OVec3(1.5f, 0.0f, 0.0f));
		m_player->setTexture(m_textures[textureNames::characterT]);
		m_player->setMesh(m_meshObj[meshNames::character]);
		m_player->setShader(m_meshShader);
	}

	//Creating skybox
	{
		auto entity = createEntity<OMeshEntity>();
		entity->setScale(OVec3(1000, 1000, 1000));
		entity->setPosition(OVec3(0, 0, 0));
		entity->setTexture(m_textures[textureNames::sky]);
		entity->setMesh(m_meshObj[meshNames::sphere]);
		entity->setShader(m_skyboxShader);
		m_skybox = entity;
	}

	//Adding a white light
	{
		auto entity = createEntity<OLightEntity>();
		entity->setRotation(OVec3(0.0f, 0.0f, 0.0f));
		entity->setPosition(OVec3(0.0f, 0.0f, 0.0f));
		entity->setColor(OVec4(1, 1, 1, 1));

		m_light = entity;
	}

	m_gamemode = gameMode::classic;
	m_difficulty = gameDifficulty::easy;
	
	getInputManager()->enablePlayMode(false);

	menuWindows m_menuWindow = menuWindows::mainMenuWindow;
	m_onMenu = true;

	MENU_onOpen();
}

void MyGame::onUpdate(f32 deltaTime)
{
	if (m_onMenu == true)
	{
		MENU_onUpdate(deltaTime);
	}
	else if (m_onMenu == false)
	{
		if (m_gamemode == gameMode::classic) //Classic Gamemode
		{
			CG_onUpdate(deltaTime);
		}
		else if (m_gamemode == gameMode::advance) //Advance Gamemode
		{
			AG_onUpdate(deltaTime);
		}
		
		//Using escape to open Menu
		if (m_cooldowns[cooldownTimers::escapeCooldown] < 0.75)
			m_cooldowns[cooldownTimers::escapeCooldown]+=deltaTime;

		if (m_inputManager->isKeyDown(OKey::KeyEscape) && m_cooldowns[cooldownTimers::escapeCooldown] > 0.5)
		{
			m_cooldowns[cooldownTimers::escapeCooldown] = 0;
			getInputManager()->enablePlayMode(false);
			m_onMenu = true;
			MENU_onOpen();
		}
	}
	
	//Rotating skybox and light
	m_roty += 0.05f * deltaTime;

	m_skybox->setRotation(OVec3(0, m_roty, 0));
	m_light->setRotation(OVec3(-0.707f, m_roty, 0));
}

///////////////////////////////////////////////////////////////////////////
//                          MENU METHODS                                 //
///////////////////////////////////////////////////////////////////////////

//Loads menu elements and moves camera
void MyGame::MENU_onOpen()
{
	m_cam->setCameraType(OCameraType::Perspective);
	m_cam->setFarPlane(1080.0f);
	m_cam->setNearPlane(0.5f);
	m_cam->setFieldOfView(1.0f);
	m_cam->setRotation(OVec3(1.56f, 0.0f, 0.0f));

	f32 y = 0.0f;
	if (m_difficulty == gameDifficulty::easy)
		y = 20.0f;
	else if (m_difficulty == gameDifficulty::medium)
		y = 35.0f;
	else if (m_difficulty == gameDifficulty::hard)
		y = 50.0f;
	
	if (m_menuWindow == menuWindows::mainMenuWindow)
	{
		m_cam->setPosition(OVec3(0.0f, 10.0f, 0.0f));
		m_selectedUIButtonPos = 3;
	}
	else
	{
		m_cam->setPosition(OVec3(m_mapSize, y, m_mapSize));
		m_selectedUIButtonPos = 0;
	}
	
	//Please update Enums.h menuItems on adding / removing UI elements !!!!!
	
	if (m_menuWindow == menuWindows::mainMenuWindow)
	{
		UIObject* character = new UIObject;

		character->setEntity(createEntity<OMeshEntity>());
		character->setScale(OVec3(1.0f, 1.0f, 1.0f));
		character->setPosition(OVec3((m_mapSize + 0.0f), (10.0f - 5.75f), (m_mapSize + 0.0f)));
		character->setRotation(OVec3(0.0f,3.15f,0.0f));
		character->setTexture(m_textures[textureNames::characterT]);
		character->setMesh(m_meshObj[meshNames::character]);
		character->setShader(m_meshShader);
		
		m_menuEntities.push_back(character); //1 -> Character


		UIObject* classicTitle = new UIObject;

		classicTitle->setEntity(createEntity<OMeshEntity>());
		classicTitle->setScale(OVec3(1.35f, 0.1f, 0.8f));
		classicTitle->setPosition(OVec3((m_mapSize - 1.3f), (10.0f - 3.75f), (m_mapSize + 1.2f)));
		classicTitle->setTexture(m_textures[textureNames::classicTitle]);
		classicTitle->setMesh(m_meshObj[meshNames::cube]);
		classicTitle->setShader(m_meshShader);
		
		m_menuEntities.push_back(classicTitle); //2 -> Classic Title


		UIObject* advanceTitle = new UIObject;

		advanceTitle->setEntity(createEntity<OMeshEntity>());
		advanceTitle->setScale(OVec3(1.35f, 0.1f, 0.8f));
		advanceTitle->setPosition(OVec3((m_mapSize + 1.3f), (10.0f - 3.75f), (m_mapSize + 1.2f)));
		advanceTitle->setTexture(m_textures[textureNames::advanceTitle]);
		advanceTitle->setMesh(m_meshObj[meshNames::cube]);
		advanceTitle->setShader(m_meshShader);

		m_menuEntities.push_back(advanceTitle); //3 -> Advance Title


		UIObject* CG_easyButton = new UIObject;
		
		CG_easyButton->setEntity(createEntity<OMeshEntity>());
		CG_easyButton->setScale(OVec3(1.15f, 0.1f, 0.65f));
		CG_easyButton->setPosition(OVec3((m_mapSize - 1.3f), (10.0f - 3.75f), (m_mapSize + 0.25f)));
		CG_easyButton->setDefaultTexture(m_textures[textureNames::easyButton]);
		CG_easyButton->setSelectedTexture(m_textures[textureNames::easyButtonSelected]);
		CG_easyButton->setTexture(CG_easyButton->getSelectedTexture());
		CG_easyButton->setMesh(m_meshObj[meshNames::cube]);
		CG_easyButton->setShader(m_meshShader);
		
		m_selectedUIButton = CG_easyButton;

		m_menuEntities.push_back(CG_easyButton); //4 -> Classic Easy Button 


		UIObject* CG_mediumButton = new UIObject;

		CG_mediumButton->setEntity(createEntity<OMeshEntity>());
		CG_mediumButton->setScale(OVec3(1.15f, 0.1f, 0.65f));
		CG_mediumButton->setPosition(OVec3((m_mapSize - 1.3f), (10.0f - 3.75f), (m_mapSize - 0.60f)));
		CG_mediumButton->setDefaultTexture(m_textures[textureNames::mediumButton]);
		CG_mediumButton->setSelectedTexture(m_textures[textureNames::mediumButtonSelected]);
		CG_mediumButton->setTexture(CG_mediumButton->getDefaultTexture());
		CG_mediumButton->setMesh(m_meshObj[meshNames::cube]);
		CG_mediumButton->setShader(m_meshShader);
		
		m_menuEntities.push_back(CG_mediumButton); //5 -> Classic Medium Button

		
		UIObject* CG_hardButton = new UIObject;

		CG_hardButton->setEntity(createEntity<OMeshEntity>());
		CG_hardButton->setScale(OVec3(1.15f, 0.1f, 0.65f));
		CG_hardButton->setPosition(OVec3((m_mapSize - 1.3f), (10.0f - 3.75f), (m_mapSize - 1.45f)));
		CG_hardButton->setDefaultTexture(m_textures[textureNames::hardButton]);
		CG_hardButton->setSelectedTexture(m_textures[textureNames::hardButtonSelected]);
		CG_hardButton->setTexture(CG_hardButton->getDefaultTexture());
		CG_hardButton->setMesh(m_meshObj[meshNames::cube]);
		CG_hardButton->setShader(m_meshShader);

		m_menuEntities.push_back(CG_hardButton); //6 -> Classic Hard Button


		UIObject* AG_easyButton = new UIObject;

		AG_easyButton->setEntity(createEntity<OMeshEntity>());
		AG_easyButton->setScale(OVec3(1.15f, 0.1f, 0.65f));
		AG_easyButton->setPosition(OVec3((m_mapSize + 1.3f), (10.0f - 3.75f), (m_mapSize + 0.25f)));
		AG_easyButton->setDefaultTexture(m_textures[textureNames::easyButton]);
		AG_easyButton->setSelectedTexture(m_textures[textureNames::easyButtonSelected]);
		AG_easyButton->setTexture(AG_easyButton->getDefaultTexture());
		AG_easyButton->setMesh(m_meshObj[meshNames::cube]);
		AG_easyButton->setShader(m_meshShader);

		m_menuEntities.push_back(AG_easyButton); //7 -> Advance Easy Button 


		UIObject* AG_mediumButton = new UIObject;

		AG_mediumButton->setEntity(createEntity<OMeshEntity>());
		AG_mediumButton->setScale(OVec3(1.15f, 0.1f, 0.65f));
		AG_mediumButton->setPosition(OVec3((m_mapSize + 1.3f), (10.0f - 3.75f), (m_mapSize - 0.60f)));
		AG_mediumButton->setDefaultTexture(m_textures[textureNames::mediumButton]);
		AG_mediumButton->setSelectedTexture(m_textures[textureNames::mediumButtonSelected]);
		AG_mediumButton->setTexture(AG_mediumButton->getDefaultTexture());
		AG_mediumButton->setMesh(m_meshObj[meshNames::cube]);
		AG_mediumButton->setShader(m_meshShader);

		m_menuEntities.push_back(AG_mediumButton); //8 -> Advance Medium Button


		UIObject* AG_hardButton = new UIObject;

		AG_hardButton->setEntity(createEntity<OMeshEntity>());
		AG_hardButton->setScale(OVec3(1.15f, 0.1f, 0.65f));
		AG_hardButton->setPosition(OVec3((m_mapSize + 1.3f), (10.0f - 3.75f), (m_mapSize - 1.45f)));
		AG_hardButton->setDefaultTexture(m_textures[textureNames::hardButton]);
		AG_hardButton->setSelectedTexture(m_textures[textureNames::hardButtonSelected]);
		AG_hardButton->setTexture(AG_hardButton->getDefaultTexture());
		AG_hardButton->setMesh(m_meshObj[meshNames::cube]);
		AG_hardButton->setShader(m_meshShader);

		m_menuEntities.push_back(AG_hardButton); //9 -> Advance Hard Button
	}
	else if (m_menuWindow == menuWindows::escWindow)
	{
		UIObject* resumeButton = new UIObject;

		resumeButton->setEntity(createEntity<OMeshEntity>());
		resumeButton->setScale(OVec3(1.35f, 0.1f, 0.8f));
		resumeButton->setPosition(OVec3((m_mapSize + 0.0f), (y - 3.75f), (m_mapSize + 1.2f)));
		resumeButton->setDefaultTexture(m_textures[textureNames::resumeButton]);
		resumeButton->setSelectedTexture(m_textures[textureNames::resumeButtonSelected]);
		resumeButton->setTexture(resumeButton->getSelectedTexture());
		resumeButton->setMesh(m_meshObj[meshNames::cube]);
		resumeButton->setShader(m_meshShader);

		m_selectedUIButton = resumeButton;

		m_menuEntities.push_back(resumeButton); //1 -> Resume Button


		UIObject* quitButton = new UIObject;

		quitButton->setEntity(createEntity<OMeshEntity>());
		quitButton->setScale(OVec3(1.35f, 0.1f, 0.8f));
		quitButton->setPosition(OVec3((m_mapSize + 0.0f), (y - 3.75f), (m_mapSize - 0.6f)));
		quitButton->setDefaultTexture(m_textures[textureNames::quitButton]);
		quitButton->setSelectedTexture(m_textures[textureNames::quitButtonSelected]);
		quitButton->setTexture(quitButton->getDefaultTexture());
		quitButton->setMesh(m_meshObj[meshNames::cube]);
		quitButton->setShader(m_meshShader);

		m_menuEntities.push_back(quitButton); //2 -> Quit Button
	}
	else if (m_menuWindow == menuWindows::winWindow)
	{
		UIObject* winWindow = new UIObject;
		
		winWindow->setEntity(createEntity<OMeshEntity>());
		winWindow->setScale(OVec3(1.27f, 0.1f, 1.0f));
		winWindow->setPosition(OVec3((m_mapSize + 0.0f), (y - 0.7f), (m_mapSize + 0.0f)));
		winWindow->setTexture(m_textures[textureNames::win]);
		winWindow->setMesh(m_meshObj[meshNames::cube]);
		winWindow->setShader(m_meshShader);

		m_menuEntities.push_back(winWindow); //1 -> Win Popup
	}
	else if (m_menuWindow == menuWindows::loseWindow)
	{
		UIObject* loseWindow = new UIObject;

		loseWindow->setEntity(createEntity<OMeshEntity>());
		loseWindow->setScale(OVec3(1.27f, 0.1f, 1.0f));
		loseWindow->setPosition(OVec3((m_mapSize + 0.0f), (y - 0.7f), (m_mapSize + 0.0f)));
		loseWindow->setTexture(m_textures[textureNames::lose]);
		loseWindow->setMesh(m_meshObj[meshNames::cube]);
		loseWindow->setShader(m_meshShader);
		
		m_menuEntities.push_back(loseWindow); //1 -> Lose Popup
	}
}

//Managing menu inputs and animations
void MyGame::MENU_onUpdate(f32 deltaTime)
{
	if (m_menuWindow == menuWindows::escWindow)
	{
		if (m_cooldowns[cooldownTimers::escapeCooldown] < 0.75)
			m_cooldowns[cooldownTimers::escapeCooldown]+=deltaTime;

		if (m_inputManager->isKeyDown(OKey::KeyEscape) && m_cooldowns[cooldownTimers::escapeCooldown] > 0.5)
		{
			m_cooldowns[cooldownTimers::escapeCooldown] = 0;
			getInputManager()->enablePlayMode(true);
			m_onMenu = false;
			MENU_onClose();
		}

		if (m_cooldowns[cooldownTimers::meunSelectorCooldown] < 0.50f)
			m_cooldowns[cooldownTimers::meunSelectorCooldown] += deltaTime;

		if (m_inputManager->isKeyDown(OKey::KeyW) && (m_selectedUIButtonPos - 1) >= 0
			&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
		{
			m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;

			m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
			m_selectedUIButtonPos--;
			m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
			m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
		}

		if (m_inputManager->isKeyDown(OKey::KeyS) && (m_selectedUIButtonPos + 1) < escMenuItems::nEscMenuItems
			&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
		{
			m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;

			m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
			m_selectedUIButtonPos++;
			m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
			m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
		}


		if (m_inputManager->isMouseDown(OMouseButton::MouseButtonLeft))
		{
			if (m_selectedUIButtonPos == escMenuItems::resumeEscButton && m_cooldowns[cooldownTimers::escapeCooldown] > 0.5)
			{
				m_cooldowns[cooldownTimers::escapeCooldown] = 0;
				
				m_cooldowns[cooldownTimers::clickCouldown] = 0;
				getInputManager()->enablePlayMode(true);
				m_onMenu = false;
				MENU_onClose();
			}
			else if (m_selectedUIButtonPos == escMenuItems::quitEscButton)
				quit();
		}
	}
	else if (m_menuWindow == menuWindows::winWindow)
	{
		if (m_cooldowns[cooldownTimers::winTimer] < 1.5f)
			m_cooldowns[cooldownTimers::winTimer]+=deltaTime;

		if (m_cooldowns[cooldownTimers::winTimer] > 1.25f)
			quit();
	}
	else if (m_menuWindow == menuWindows::loseWindow)
	{
		if (m_cooldowns[cooldownTimers::loseTimer] < 1.5f)
			m_cooldowns[cooldownTimers::loseTimer] += deltaTime;

		if (m_cooldowns[cooldownTimers::loseTimer] > 1.25f)
			quit();
	}
	else if (m_menuWindow == menuWindows::mainMenuWindow) //Please keep this menu at the bottom because of m_menuWindow reassignation
	{
		if (m_cooldowns[cooldownTimers::meunSelectorCooldown] < 0.50f)
			m_cooldowns[cooldownTimers::meunSelectorCooldown] += deltaTime;

		if (m_inputManager->isKeyDown(OKey::KeyD) && m_gamemode == gameMode::classic
			&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
		{
			m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;
			m_gamemode = gameMode::advance;

			m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
			m_selectedUIButtonPos += 3;
			m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
			m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
		}

		if (m_inputManager->isKeyDown(OKey::KeyA) && m_gamemode == gameMode::advance
			&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
		{
			m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;
			m_gamemode = gameMode::classic;
			
			m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
			m_selectedUIButtonPos -= 3;
			m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
			m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
		}
		
		if (m_gamemode == gameMode::classic)
		{
			if (m_inputManager->isKeyDown(OKey::KeyW) && (m_selectedUIButtonPos - 1) >= 3
				&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
			{
				m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;

				m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
				m_selectedUIButtonPos--;
				m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
				m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
			}

			if (m_inputManager->isKeyDown(OKey::KeyS) && (m_selectedUIButtonPos + 1) < 6
				&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
			{
				m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;

				m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
				m_selectedUIButtonPos++;
				m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
				m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
			}
		}
		else if (m_gamemode == gameMode::advance)
		{
			if (m_inputManager->isKeyDown(OKey::KeyW) && (m_selectedUIButtonPos - 1) >= 6
				&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
			{
				m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;

				m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
				m_selectedUIButtonPos--;
				m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
				m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
			}

			if (m_inputManager->isKeyDown(OKey::KeyS) && (m_selectedUIButtonPos + 1) < mainMenuItems::nMainMenuItems
				&& m_cooldowns[cooldownTimers::meunSelectorCooldown] > 0.25f)
			{
				m_cooldowns[cooldownTimers::meunSelectorCooldown] = 0;

				m_selectedUIButton->setTexture(m_selectedUIButton->getDefaultTexture());
				m_selectedUIButtonPos++;
				m_selectedUIButton = m_menuEntities[m_selectedUIButtonPos];
				m_selectedUIButton->setTexture(m_selectedUIButton->getSelectedTexture());
			}
		}
		

		if (m_inputManager->isMouseDown(OMouseButton::MouseButtonLeft))
		{
			if (m_selectedUIButtonPos == mainMenuItems::CG_easyButton || m_selectedUIButtonPos == mainMenuItems::AG_easyButton)
				m_difficulty = gameDifficulty::easy;
			else if (m_selectedUIButtonPos == mainMenuItems::CG_mediumButton || m_selectedUIButtonPos == mainMenuItems::AG_mediumButton)
				m_difficulty = gameDifficulty::medium;
			else if (m_selectedUIButtonPos == mainMenuItems::CG_hardButton || m_selectedUIButtonPos == mainMenuItems::AG_hardButton)
				m_difficulty = gameDifficulty::hard;

			if (m_gamemode == gameMode::classic)
				CG_onCreate();
			else if (m_gamemode == gameMode::advance)
				AG_onCreate();

			getInputManager()->enablePlayMode(true);
			m_onMenu = false;
			MENU_onClose();
			
			m_menuWindow = menuWindows::escWindow;
		}
	}
}

//Removes menu elements and restores camera
void MyGame::MENU_onClose()
{
	m_cam->setCameraType(OCameraType::Perspective);
	m_cam->setFarPlane(1500.0f);
	m_cam->setNearPlane(3.1f);
	m_cam->setFieldOfView(1.2f);
	m_cam->setPosition(OVec3(m_player->getPosition().x, 2.0f, m_player->getPosition().z));

	for (size_t i = 0; i < m_menuEntities.size(); i++)
	{
		removeEntity(m_menuEntities[i]->getEntity());
	}
	m_menuEntities.clear();
	
	m_selectedUIButton = nullptr;
	m_selectedUIButtonPos = 0;
}

///////////////////////////////////////////////////////////////////////////
//                          CLASSIC GAMEMODE                             //
///////////////////////////////////////////////////////////////////////////
void MyGame::CG_onCreate()
{
	//Generating the map grid
	CG_generateMap();

	//Locking mouse on screen
	getInputManager()->enablePlayMode(true);
}

void MyGame::CG_onUpdate(f32 deltaTime)
{
	//Managing player inputs (except tile opening/flagging and esc)
	CG_manageInputs(deltaTime);

	//Moving and rotathing the cam and player thogheter
	CG_playerAndCamMovement(deltaTime);

	//Selecting tile on pointer and managing tile opening
	CG_selectAndOpenTiles(deltaTime);

	//Checking lose and win conditions
	CG_checkLoseAndWinConditions(deltaTime);
}

//Manages player inputs (except tile opening/flagging and esc)
void MyGame::CG_manageInputs(f32 deltaTime)
{
	//Alternating camera type (3rd and 1st person)
	if (m_cooldowns[cooldownTimers::changeCamCooldown] < 0.75f)
		m_cooldowns[cooldownTimers::changeCamCooldown]+=deltaTime;
	if (m_inputManager->isKeyDown(OKey::KeyC) && m_cooldowns[cooldownTimers::changeCamCooldown] > 0.5)
	{
		m_cooldowns[cooldownTimers::changeCamCooldown] = 0;
		
		if (m_cam->getCamType() == OCameraType::Orthogonal) {
			m_cam->setFieldOfView(1.2f);
			m_cam->setFarPlane(1500.0f);
			m_cam->setNearPlane(3.1f);
			m_cam->setCameraType(OCameraType::Perspective);
		}
		else {
			m_cam->setFieldOfView(0.008f);
			m_cam->setFarPlane(1080.0f);
			m_cam->setNearPlane(535.0f);
			m_cam->setCameraType(OCameraType::Orthogonal);
		}
	}
	//Camera zoom in and zoom out

	if (m_cam->getCamType() == OCameraType::Orthogonal)
	{
		f32 fov = m_cam->getFieldOfView();
		f32 nearPlane = m_cam->getNearPlane();

		if (m_inputManager->isKeyDown(OKey::KeyQ))
		{
			fov -= 0.000015f;
			nearPlane += 0.55f;
		}

		if (m_inputManager->isKeyDown(OKey::KeyE))
		{
			fov += 0.000015f;
			nearPlane -= 0.55f;
		}

		if (fov > 0.008f && fov < 0.02f)
		{
			m_cam->setFieldOfView(fov);
			m_cam->setNearPlane(nearPlane);
		}
	}
	
	//Checking if player is running or walking
	if (m_inputManager->isKeyDown(OKey::KeyShift))
		m_speed = 7.5f;
	else
		m_speed = 5.0f;
}

//Computes player and cam movement / rotation
void MyGame::CG_playerAndCamMovement(f32 deltaTime)
{
	//Rotating the camera and player thorugh mouse movements
	m_camRotY += m_inputManager->getMouseXAxis() * m_sensitivity;
	m_camRotX += m_inputManager->getMouseYAxis() * m_sensitivity;

	if (m_camRotX > 0.75f) //Limit is at 1.57f / -1.57
		m_camRotX = 0.75f;
	else if (m_camRotX < 0.05f)
		m_camRotX = 0.05f;

	m_cam->setRotation(OVec3(m_camRotX, m_camRotY, 0));
	m_player->setRotation(OVec3(1.5f, m_camRotY, 0));

	//Moving the camera and player over the map
	auto pos = m_player->getPosition();

	OMat4 playerMat;
	m_player->getWorldMatrix(playerMat);

	auto forwardDir = playerMat.getForwardDirection();
	auto rightwardDir = playerMat.getRightwardDirection();
	auto upwardDir = playerMat.getUpDirection();
	forwardDir.y = 0;
	rightwardDir.y = 0;
	upwardDir.y = 0;
	
	m_playerPointer = pos + upwardDir * 2.5f; //upwardDir instead of forwardDir because character model is imported vertically rotated!!! 

	f32 moveForward = 0, moveRightward = 0;

	if (m_inputManager->isKeyDown(OKey::KeyW))
	{
		moveForward = 1;
	}
	if (m_inputManager->isKeyDown(OKey::KeyS))
	{
		moveForward = -1;
	}
	if (m_inputManager->isKeyDown(OKey::KeyA))
	{
		moveRightward = -1;
	}
	if (m_inputManager->isKeyDown(OKey::KeyD))
	{
		moveRightward = 1;
	}

	//Computing position by moving along the forward axis and rightward axis (forward axis and rightward axis are provided by the world matrix of the player)
	if (moveForward != 0 || moveRightward != 0)
	{
		pos = pos + (upwardDir * moveForward) * m_speed * deltaTime; //upwardDir instead of forwardDir because character model is imported vertically rotated!!! 
		pos = pos + (rightwardDir * moveRightward) * m_speed * deltaTime;
	}


	//Updating player and cam pos inside map limits
	if ((pos.x >= 0.5f && pos.x < ((m_mapSize * m_tileSize) - 0.5f)) && (pos.z >= 0.5f && pos.z < ((m_mapSize * m_tileSize) - 0.5f)))
	{
		if (m_cam->getCamType() == OCameraType::Orthogonal)
		{
			m_player->setPosition(pos);
			m_cam->setPosition(pos);
		}
		else if (m_cam->getCamType() == OCameraType::Perspective)
		{
			m_player->setPosition(pos);
			m_cam->setPosition(OVec3(pos.x, pos.y + 1.5f, pos.z));
		}
	}
}

//Calculates selected tiles and manages opening and marking
void MyGame::CG_selectAndOpenTiles(f32 deltaTime)
{
	//Selecting tile on pointer
	int auxX = int(m_playerPointer.x / m_tileSize);
	int auxZ = int(m_playerPointer.z / m_tileSize);


	if (auxX >= 0 && auxZ >= 0 && auxX < m_mapSize && auxZ < m_mapSize)
	{
		if (m_map[auxX][auxZ]->getIsSelected() == false)
		{
			m_map[auxX][auxZ]->setIsSelected(true);
			if (m_map[auxX][auxZ]->getIsOpen() == false && !m_map[auxX][auxZ]->getIsMarked())
				m_map[auxX][auxZ]->setTexture(m_textures[textureNames::selectedTile]);

			m_selectedTile->setIsSelected(false);
			if (m_selectedTile->getIsOpen() == false)
				m_selectedTile->setTexture(m_textures[textureNames::tile]);
			if (m_selectedTile->getIsMarked())
				m_selectedTile->setTexture(m_textures[textureNames::flaggedTile]);

			m_selectedTile = m_map[auxX][auxZ];
		}
	}
	
	//Opening selected tile
	if (m_cooldowns[cooldownTimers::clickCouldown] < 0.5f)
		m_cooldowns[cooldownTimers::clickCouldown]+=deltaTime;

	if (m_inputManager->isMouseDown(OMouseButton::MouseButtonLeft) && m_cooldowns[cooldownTimers::clickCouldown] > 0.25f
		&& !m_selectedTile->getIsOpen() && !m_selectedTile->getIsMarked() && auxX < m_mapSize && auxZ < m_mapSize) {
			m_cooldowns[cooldownTimers::clickCouldown] = 0;
			CG_openTileRec(auxX, auxZ);
	}

	if (m_cooldowns[cooldownTimers::leftclickCouldown] < 0.5f)
		m_cooldowns[cooldownTimers::leftclickCouldown]+=deltaTime;
	
	//Flagging selected tile
	if (m_inputManager->isMouseDown(OMouseButton::MouseButtonRight) && m_cooldowns[cooldownTimers::leftclickCouldown] > 0.25f
		&& !m_selectedTile->getIsOpen() && auxX < m_mapSize && auxZ < m_mapSize) {
		m_cooldowns[cooldownTimers::leftclickCouldown] = 0;

		if (m_selectedTile->getIsMarked()) {
			m_selectedTile->setTexture(m_textures[textureNames::tile]);
			removeEntity(m_flagMap[auxX][auxZ]->getEntity());

			m_selectedTile->setIsMarked(false);
		}
		else if (!m_selectedTile->getIsMarked()) {
			Flag* newFlag = new Flag;
			newFlag->setEntity(createEntity<OMeshEntity>());
			
			newFlag->setMesh(m_meshObj[meshNames::flag]);
			newFlag->setShader(m_meshShader);
			newFlag->setPosition((m_selectedTile->getPosition() + OVec3(0, m_tileSize/2, 0)));
			newFlag->setRotation((OVec3(1.5f, 0, 0)));
			newFlag->setScale(OVec3(0.8, 0.8, 0.8));
			newFlag->setTexture(m_textures[textureNames::flagT]);
			
			m_flagMap[auxX][auxZ] = newFlag;

			m_selectedTile->setTexture(m_textures[textureNames::flaggedTile]);

			m_selectedTile->setIsMarked(true);
		}
	}	
}

//Checks and manages lose/win conditions
void MyGame::CG_checkLoseAndWinConditions(f32 deltaTime)
{
	if (m_lives <= 0) {
		if (m_cooldowns[cooldownTimers::bombTimer] < 1.75f) {
			m_cooldowns[bombTimer] +=deltaTime;
			
			m_openedBomb->setPosition(m_openedBomb->getPosition() + OVec3(0, 1.2, 0) * deltaTime);
			m_openedBomb->setRotation(m_openedBomb->getRotation() + OVec3(0, 4, 0) * deltaTime);
		}
		else if (m_cooldowns[cooldownTimers::bombTimer] > 1.5f) {
			m_cooldowns[cooldownTimers::bombTimer] = 0;

			m_cooldowns[cooldownTimers::escapeCooldown] = 0;
			m_menuWindow = menuWindows::loseWindow;
			m_onMenu = true;
			MENU_onOpen();
		}
	}
	else if (m_openedTilesCount >= m_emptyTilesCount) {
		m_cooldowns[cooldownTimers::escapeCooldown] = 0;
		m_menuWindow = menuWindows::winWindow;
		m_onMenu = true;
		MENU_onOpen();
	}
}

//Opens selected tile
void MyGame::CG_openTileRec(ui32 x, ui32 z) {
	
Tile* actualTile = m_selectedTile;
m_selectedTile = m_map[x][z];

Bomb* auxBomb = nullptr;
OMeshEntity* entity = nullptr;

	if (!m_selectedTile->getIsMarked()) {
		m_selectedTile->setIsOpen(true);
		if (m_grassMap[x][z]!= nullptr)
			removeEntity(m_grassMap[x][z]->getEntity());
		m_openedTilesCount++;
		switch (m_selectedTile->getValue())
		{
			case -1:
				m_selectedTile->setTexture(m_textures[textureNames::openedTileBomb]);
				m_lives--;

				if (m_lives <= 0 && m_openedBomb == nullptr) {
					auxBomb = new Bomb;
					entity = createEntity<OMeshEntity>();
					auxBomb->setEntity(entity);
					auxBomb->setMesh(m_meshObj[meshNames::bomb]);
					auxBomb->setShader(m_meshShader);
					auxBomb->setPosition(m_selectedTile->getPosition());
					auxBomb->setScale(OVec3(0.8, 0.8, 0.8));
					auxBomb->setTexture(m_textures[textureNames::bombT]);
					m_openedBomb = auxBomb;
				}
				
				break;

			case 0:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile0]);
				// Left
				if (CG_isValid(x - 1, z)) {
					if (!m_map[x - 1][z]->getIsOpen() && !m_map[x - 1][z]->getIsMarked()) {
						CG_openTileRec(x - 1, z);
					}
				}
				//Top  Left
				if (CG_isValid(x - 1, z - 1)) {
					if (!m_map[x - 1][z - 1]->getIsOpen() && !m_map[x - 1][z - 1]->getIsMarked()) {
						CG_openTileRec(x - 1, z - 1);
					}
				}
				//Top
				if (CG_isValid(x, z - 1)) {
					if (!m_map[x][z - 1]->getIsOpen() && !m_map[x][z - 1]->getIsMarked()) {
						CG_openTileRec(x, z - 1);
					}
				}
				//Top Right
				if (CG_isValid(x + 1, z - 1)) {
					if (!m_map[x + 1][z - 1]->getIsOpen() && !m_map[x + 1][z - 1]->getIsMarked()) {
						CG_openTileRec(x + 1, z - 1);
					}
				}
				//Right
				if (CG_isValid(x + 1, z)) {
					if (!m_map[x + 1][z]->getIsOpen()&& !m_map[x + 1][z]->getIsMarked()) {
						CG_openTileRec(x + 1, z);
					}
				}
				//Bottom Right
				if (CG_isValid(x + 1, z + 1)) {
					if (!m_map[x + 1][z + 1]->getIsOpen() && !m_map[x + 1][z + 1]->getIsMarked()) {
						CG_openTileRec(x + 1, z + 1);
					}
				}
				//Bottom
				if (CG_isValid(x, z + 1)) {
					if (!m_map[x][z + 1]->getIsOpen() && !m_map[x][z + 1]->getIsMarked()) {
						CG_openTileRec(x, z + 1);
					}
				}
				//Bottom Left
				if (CG_isValid(x - 1, z + 1)) {
					if (!m_map[x - 1][z + 1]->getIsOpen() && !m_map[x - 1][z + 1]->getIsMarked()) {
						CG_openTileRec(x - 1, z + 1);
					}
				}
				m_selectedTile = actualTile;
				break;

			case 1:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile1]);
				break;

			case 2:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile2]);
				break;

			case 3:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile3]);
				break;

			case 4:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile4]);
				break;

			case 5:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile5]);
				break;

			case 6:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile6]);
				break;

			case 7:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile7]);
				break;

			case 8:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile8]);
				break;

			default:
				m_selectedTile->setTexture(m_textures[textureNames::openedTile0]);
				break;
		}
	}
}

//Generates map grid with all bombs set
void MyGame::CG_generateMap()
{
	switch (m_difficulty)
	{
	case easy:
		m_mapSize = 9;
		m_bombCount = 10;
		break;
	case medium:
		m_mapSize = 16;
		m_bombCount = 40;
		break;
	case hard:
		m_mapSize = 24;
		m_bombCount = 99;
		break;
	default:
		m_mapSize = 0;
		m_bombCount = 0;
		break;
	}
	
	m_emptyTilesCount = (m_mapSize * m_mapSize) - m_bombCount;

	m_lives = 1;
	m_tileSize = 2.0f;

	for (ui32 x = 0; x < m_mapSize; x++)
	{
		std::vector<Tile*> newRow;
		std::vector<Grass*> newRowGrass;
		for (ui32 y = 0; y < m_mapSize; y++)
		{
			Tile* newTile = new Tile;
			newTile->setEntity(createEntity<OMeshEntity>());
			
			newTile->setMesh(m_meshObj[meshNames::cube]);
			newTile->setShader(m_meshShader);

			f32 auxX = 1 + m_tileSize * x;
			f32 auxY = 0.0f;
			f32 auxZ = 1 + m_tileSize * y;

			f32 auxScaleX = m_tileSize;
			f32 auxScaleY = m_tileSize;
			f32 auxScaleZ = m_tileSize;

			newTile->setX(auxX);
			newTile->setY(auxY);
			newTile->setZ(auxZ);
			
			newTile->setIsOpen(false);
			newTile->setIsSelected(false);
			newTile->setValue(0);

			newTile->setPosition(OVec3(auxX, auxY, auxZ));
			newTile->setScale(OVec3(auxScaleX, auxScaleY, auxScaleZ));
			newTile->setTexture(m_textures[textureNames::tile]);

			newRow.push_back(newTile);
			
			if (randomBoolWithProb(0.65))
			{
				Grass* newGrass = new Grass;
				newGrass->setEntity(createEntity<OMeshEntity>());
				
				newGrass->setMesh(m_meshObj[meshNames::grass]);
				newGrass->setShader(m_meshShader);
				newGrass->setScale(OVec3(0.1, randomNumberInRange(0.1f, 0.35f), 0.1));
				newGrass->setPosition(OVec3(auxX, auxY + 1 + randomNumberInRange(0.1f, 0.35f), auxZ));
				newGrass->setRotation(OVec3(0.0f, randomNumberInRange(0.0f, 1.0f), 0.0f));


				newGrass->setTexture(m_textures[textureNames::grassT]);
				newRowGrass.push_back(newGrass);
				if (randomBoolWithProb(0.05))
					newGrass->setTexture(m_textures[textureNames::green2]);
				else
					if (randomBoolWithProb(0.05))
						newGrass->setTexture(m_textures[textureNames::green3]);
					else if (randomBoolWithProb(0.05))
							newGrass->setTexture(m_textures[textureNames::green4]);
			}
			else
				newRowGrass.push_back(nullptr);
		}

		m_map.push_back(newRow);
		m_grassMap.push_back(newRowGrass);
	}
	
	CG_placeMines();

	for (ui32 x = 0; x < m_mapSize; x++)
	{
		std::vector<Flag*> newRow;
		newRow.resize(m_mapSize, new Flag);
		m_flagMap.push_back(newRow);

		for (ui32 y = 0; y < m_mapSize; y++)
		{
			if (m_map[x][y]->getValue() != -1)
				m_map[x][y]->setValue(CG_countAdjacentMines(x, y));
		}
	}

	m_selectedTile = m_map[0][0];

	
	//Creating visual forest around map
	f32 auxX = 1 + m_tileSize * (m_mapSize / 2) - m_difficulty - 2 * m_tileSize * m_mapSize;
	f32 auxY = 0.0f;
	f32 auxZ = 1 + m_tileSize * (m_mapSize / 2) - m_difficulty - 2 * m_tileSize * m_mapSize;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			auto forest = createEntity<OMeshEntity>();
			forest->setScale(OVec3(1.3 + m_difficulty, 1.3 + m_difficulty, 1.3 + m_difficulty));
			forest->setPosition(OVec3(auxX + m_tileSize * m_mapSize * i, auxY + 0.9, auxZ + m_tileSize * m_mapSize * j));
			forest->setTexture(m_textures[textureNames::forestT]);
			forest->setMesh(m_meshObj[meshNames::forest]);
			forest->setShader(m_meshShader);
			if (i == 2 && j == 1)
				j++;
		}
	}
	
	if (m_difficulty == gameDifficulty::hard)
	{
		auto floor = createEntity<OMeshEntity>();
		floor->setScale(OVec3(1000.0f, 0.1f, 1000.0f));
		floor->setPosition(OVec3(0.0f, 0.86f, 0.0f));
		floor->setTexture(m_textures[textureNames::floorT]);
		floor->setMesh(m_meshObj[meshNames::cube]);
		floor->setShader(m_meshShader);
	}
}

//A Function to place the mines randomly on the board
void MyGame::CG_placeMines()
{
	srand(time(NULL));
	
	// Continue until all random mines have been created.
	for (int i = 0; i < m_bombCount; )
	{
		int random = rand() % (m_mapSize * m_mapSize);
		int x = random / m_mapSize;
		int y = random % m_mapSize;

		// Add the mine if no mine is placed at this
		// position on the board
		if (m_map[x][y]->getValue() != -1)
		{
			// Place the mine
			m_map[x][y]->setValue(-1);
			i++;
		}
	}

	return;
}

//A Utility Function to check whether given cell (row, col) is a valid cell or not
bool MyGame::CG_isValid(const unsigned int row, const unsigned int col)
{
	// Returns true if row number and column number
	// is in range
	return (row >= 0) && (row < m_mapSize) &&
		(col >= 0) && (col < m_mapSize);
}

//A Function to count the number of mines in the adjacent cells
int MyGame::CG_countAdjacentMines(const unsigned int row, const unsigned int col)
{

	int i;
	int count = 0;

	/*
		Count all the mines in the 8 adjacent
		cells

			N.W   N   N.E
			  \   |   /
			   \  |  /
			W----Cell----E
				 / | \
			   /   |  \
			S.W    S   S.E

		Cell-->Current Cell (row, col)
		N -->  North        (row-1, col)
		S -->  South        (row+1, col)
		E -->  East         (row, col+1)
		W -->  West            (row, col-1)
		N.E--> North-East   (row-1, col+1)
		N.W--> North-West   (row-1, col-1)
		S.E--> South-East   (row+1, col+1)
		S.W--> South-West   (row+1, col-1)
	*/

	//----------- 1st Neighbour (North) ------------

		// Only process this cell if this is a valid one
	if (CG_isValid(row - 1, col) == true)
	{
		if (m_map[row - 1][col]->getValue() == -1)
			count++;
	}

	//----------- 2nd Neighbour (South) ------------

		// Only process this cell if this is a valid one
	if (CG_isValid(row + 1, col) == true)
	{
		if (m_map[row + 1][col]->getValue() == -1)
			count++;
	}

	//----------- 3rd Neighbour (East) ------------

		// Only process this cell if this is a valid one
	if (CG_isValid(row, col + 1) == true)
	{
		if (m_map[row][col + 1]->getValue() == -1)
			count++;
	}

	//----------- 4th Neighbour (West) ------------

		// Only process this cell if this is a valid one
	if (CG_isValid(row, col - 1) == true)
	{
		if (m_map[row][col - 1]->getValue() == -1)
			count++;
	}

	//----------- 5th Neighbour (North-East) ------------

		// Only process this cell if this is a valid one
	if (CG_isValid(row - 1, col + 1) == true)
	{
		if (m_map[row - 1][col + 1]->getValue() == -1)
			count++;
	}

	//----------- 6th Neighbour (North-West) ------------

	   // Only process this cell if this is a valid one
	if (CG_isValid(row - 1, col - 1) == true)
	{
		if (m_map[row - 1][col - 1]->getValue() == -1)
			count++;
	}

	//----------- 7th Neighbour (South-East) ------------

	   // Only process this cell if this is a valid one
	if (CG_isValid(row + 1, col + 1) == true)
	{
		if (m_map[row + 1][col + 1]->getValue() == -1)
			count++;
	}

	//----------- 8th Neighbour (South-West) ------------

		// Only process this cell if this is a valid one
	if (CG_isValid(row + 1, col - 1) == true)
	{
		if (m_map[row + 1][col - 1]->getValue() == -1)
			count++;
	}

	return count;
}

///////////////////////////////////////////////////////////////////////////
//                          ADVANCE GAMEMODE                             //
///////////////////////////////////////////////////////////////////////////

void MyGame::AG_onCreate()
{
	//Generating the map grid
	AG_generateMap();

	//Setting up the start point
	int startX = int(m_mapSize / 2);
	int startZ = 0;
	
	m_player->setPosition(OVec3(((startX * m_tileSize) + (m_tileSize / 2)), 2.0f, startZ + (m_tileSize / 2)));
	m_cam->setPosition(OVec3(((startX * m_tileSize) + (m_tileSize / 2)), 2.0f, startZ + (m_tileSize / 2)));

	AG_openTileRec(startX, startZ);
	
	//Locking mouse on screen
	getInputManager()->enablePlayMode(true);
}

void MyGame::AG_onUpdate(f32 deltaTime)
{
	//Managing player inputs (except tile opening/flagging and esc)
	AG_manageInputs(deltaTime);

	//Moving and rotathing the cam and player thogheter
	AG_playerAndCamMovement(deltaTime);

	//Selecting tile on pointer and managing tile opening
	AG_selectAndOpenTiles(deltaTime);

	//Checking lose and win conditions
	AG_checkLoseAndWinConditions(deltaTime);
}

//Manages player inputs (except opening and marking tiles)
void MyGame::AG_manageInputs(f32 deltaTime)
{
	//Alternating camera type (3rd and 1st person)
	if (m_cooldowns[cooldownTimers::changeCamCooldown] < 0.75f)
		m_cooldowns[cooldownTimers::changeCamCooldown] += deltaTime;
	if (m_inputManager->isKeyDown(OKey::KeyC) && m_cooldowns[cooldownTimers::changeCamCooldown] > 0.5)
	{
		m_cooldowns[cooldownTimers::changeCamCooldown] = 0;

		if (m_cam->getCamType() == OCameraType::Orthogonal) {
			m_cam->setFieldOfView(1.2f);
			m_cam->setFarPlane(1500.0f);
			m_cam->setNearPlane(3.1f);
			m_cam->setCameraType(OCameraType::Perspective);
		}
		else {
			m_cam->setFieldOfView(0.008f);
			m_cam->setFarPlane(1080.0f);
			m_cam->setNearPlane(535.0f);
			m_cam->setCameraType(OCameraType::Orthogonal);
		}
	}
	//Camera zoom in and zoom out

	if (m_cam->getCamType() == OCameraType::Orthogonal)
	{
		f32 fov = m_cam->getFieldOfView();
		f32 nearPlane = m_cam->getNearPlane();

		if (m_inputManager->isKeyDown(OKey::KeyQ))
		{
			fov -= 0.000015f;
			nearPlane += 0.55f;
		}

		if (m_inputManager->isKeyDown(OKey::KeyE))
		{
			fov += 0.000015f;
			nearPlane -= 0.55f;
		}

		if (fov > 0.008f && fov < 0.02f)
		{
			m_cam->setFieldOfView(fov);
			m_cam->setNearPlane(nearPlane);
		}
	}

	//Checking if player is running or walking
	if (m_inputManager->isKeyDown(OKey::KeyShift))
		m_speed = 7.5f;
	else
		m_speed = 5.0f;
}

//Computes player and cam movement / rotation
void MyGame::AG_playerAndCamMovement(f32 deltaTime)
{
	//Rotating the camera and player thorugh mouse movements
	m_camRotY += m_inputManager->getMouseXAxis() * m_sensitivity;
	m_camRotX += m_inputManager->getMouseYAxis() * m_sensitivity;

	if (m_camRotX > 0.75f) //Limit is at 1.57f / -1.57
		m_camRotX = 0.75f;
	else if (m_camRotX < 0.05f)
		m_camRotX = 0.05f;

	m_cam->setRotation(OVec3(m_camRotX, m_camRotY, 0));
	m_player->setRotation(OVec3(1.5f, m_camRotY, 0));

	//Moving the camera and player over the map
	auto pos = m_player->getPosition();

	OMat4 playerMat;
	m_player->getWorldMatrix(playerMat);

	auto forwardDir = playerMat.getForwardDirection();
	auto rightwardDir = playerMat.getRightwardDirection();
	auto upwardDir = playerMat.getUpDirection();
	forwardDir.y = 0;
	rightwardDir.y = 0;
	upwardDir.y = 0;
	
	m_playerPointer = pos + upwardDir * 2.5f; //upwardDir instead of forwardDir because character model is imported vertically rotated!!! 

	f32 moveForward = 0, moveRightward = 0;

	if (m_inputManager->isKeyDown(OKey::KeyW))
	{
		moveForward = 1;
	}
	if (m_inputManager->isKeyDown(OKey::KeyS))
	{
		moveForward = -1;
	}
	if (m_inputManager->isKeyDown(OKey::KeyA))
	{
		moveRightward = -1;
	}
	if (m_inputManager->isKeyDown(OKey::KeyD))
	{
		moveRightward = 1;
	}

	//Computing position by moving along the forward axis and rightward axis (forward axis and rightward axis are provided by the world matrix of the player)
	if (moveForward != 0 || moveRightward != 0)
	{
		pos = pos + (upwardDir * moveForward) * m_speed * deltaTime; //upwardDir instead of forwardDir because character model is imported vertically rotated!!! 
		pos = pos + (rightwardDir * moveRightward) * m_speed * deltaTime;
	}


	//Updating player and cam pos inside map limits
	if ((pos.x >= 0.5f && pos.x < ((m_mapSize * m_tileSize) - 0.5f)) && (pos.z >= 0.5f && pos.z < ((m_mapSize * m_tileSize) - 0.5f)))
	{
		if (m_cam->getCamType() == OCameraType::Orthogonal)
		{
			m_player->setPosition(pos);
			m_cam->setPosition(pos);
		}
		else if (m_cam->getCamType() == OCameraType::Perspective)
		{
			m_player->setPosition(pos);
			m_cam->setPosition(OVec3(pos.x, pos.y + 1.5f, pos.z));
		}
	}
}

//Calculates selected tiles, manages opening and marking of tiles, and checks for defeat conditions
void MyGame::AG_selectAndOpenTiles(f32 deltaTime)
{
	//Selecting tile on pointer
	int auxX = int(m_playerPointer.x / m_tileSize);
	int auxZ = int(m_playerPointer.z / m_tileSize);


	if (auxX >= 0 && auxZ >= 0 && auxX < m_mapSize && auxZ < m_mapSize)
	{
		if (m_map[auxX][auxZ]->getIsSelected() == false)
		{
			m_map[auxX][auxZ]->setIsSelected(true);
			if (m_map[auxX][auxZ]->getIsOpen() == false && !m_map[auxX][auxZ]->getIsMarked())
				m_map[auxX][auxZ]->setTexture(m_textures[textureNames::selectedTile]);

			m_selectedTile->setIsSelected(false);
			if (m_selectedTile->getIsOpen() == false)
				m_selectedTile->setTexture(m_textures[textureNames::tile]);
			if (m_selectedTile->getIsMarked())
				m_selectedTile->setTexture(m_textures[textureNames::flaggedTile]);

			m_selectedTile = m_map[auxX][auxZ];
		}
	}

	//Opening selected tile
	if (m_cooldowns[cooldownTimers::clickCouldown] < 0.5f)
		m_cooldowns[cooldownTimers::clickCouldown] += deltaTime;

	if (m_inputManager->isMouseDown(OMouseButton::MouseButtonLeft) && m_cooldowns[cooldownTimers::clickCouldown] > 0.25f
		&& !m_selectedTile->getIsOpen() && !m_selectedTile->getIsMarked() && auxX < m_mapSize && auxZ < m_mapSize) {
		m_cooldowns[cooldownTimers::clickCouldown] = 0;
		AG_openTileRec(auxX, auxZ);
	}

	if (m_cooldowns[cooldownTimers::leftclickCouldown] < 0.5f)
		m_cooldowns[cooldownTimers::leftclickCouldown] += deltaTime;
	

	//Flagging selected tile
	if (m_inputManager->isMouseDown(OMouseButton::MouseButtonRight) && m_cooldowns[cooldownTimers::leftclickCouldown] > 0.25f
		&& !m_selectedTile->getIsOpen() && auxX < m_mapSize && auxZ < m_mapSize) {
		m_cooldowns[cooldownTimers::leftclickCouldown] = 0;

		if (m_selectedTile->getIsMarked()) {
			m_selectedTile->setTexture(m_textures[textureNames::tile]);
			removeEntity(m_flagMap[auxX][auxZ]->getEntity());

			m_selectedTile->setIsMarked(false);
		}
		else if (!m_selectedTile->getIsMarked()) {
			Flag* newFlag = new Flag;
			newFlag->setEntity(createEntity<OMeshEntity>());

			newFlag->setMesh(m_meshObj[meshNames::flag]);
			newFlag->setShader(m_meshShader);
			newFlag->setPosition((m_selectedTile->getPosition() + OVec3(0, m_tileSize / 2, 0)));
			newFlag->setRotation((OVec3(1.5f, 0, 0)));
			newFlag->setScale(OVec3(0.8, 0.8, 0.8));
			newFlag->setTexture(m_textures[textureNames::flagT]);

			m_flagMap[auxX][auxZ] = newFlag;

			m_selectedTile->setTexture(m_textures[textureNames::flaggedTile]);

			m_selectedTile->setIsMarked(true);
		}
	}
}

//Checks and manages lose/win conditions
void MyGame::AG_checkLoseAndWinConditions(f32 deltaTime)
{
	if (m_lives <= 0) {
		if (m_cooldowns[cooldownTimers::bombTimer] < 1.75f) {
			m_cooldowns[bombTimer] += deltaTime;

			m_openedBomb->setPosition(m_openedBomb->getPosition() + OVec3(0, 1.2, 0) * deltaTime);
			m_openedBomb->setRotation(m_openedBomb->getRotation() + OVec3(0, 4, 0) * deltaTime);
		}
		else if (m_cooldowns[cooldownTimers::bombTimer] > 1.5f) {
			m_cooldowns[cooldownTimers::bombTimer] = 0;

			m_cooldowns[cooldownTimers::escapeCooldown] = 0;
			m_menuWindow = menuWindows::loseWindow;
			m_onMenu = true;
			MENU_onOpen();
		}
	}
	
	if (m_map[int(m_player->getPosition().x / m_tileSize)][int(m_player->getPosition().z / m_tileSize)]->getValue() == -1)
	{
		if (m_cooldowns[cooldownTimers::playerOnBomb] < 0.50f)
			m_cooldowns[cooldownTimers::playerOnBomb] += deltaTime;
	}
	else
	{
		if (m_cooldowns[cooldownTimers::playerOnBomb]>0)
			m_cooldowns[cooldownTimers::playerOnBomb] -= deltaTime;
	}

	if (m_cooldowns[cooldownTimers::playerOnBomb] > 0.25f)
	{
		m_cooldowns[cooldownTimers::escapeCooldown] = 0;
		m_menuWindow = menuWindows::loseWindow;
		m_onMenu = true;
		MENU_onOpen();
	}
	
	if (int(m_player->getPosition().z / m_tileSize)==m_mapSize-1)
	{
		m_cooldowns[cooldownTimers::escapeCooldown] = 0;
		m_menuWindow = menuWindows::winWindow;
		m_onMenu = true;
		MENU_onOpen();
	}
}

//Opens selected tile
void MyGame::AG_openTileRec(ui32 x, ui32 z) {

	Tile* actualTile = m_selectedTile;
	m_selectedTile = m_map[x][z];

	Bomb* auxBomb = nullptr;
	OMeshEntity* entity = nullptr;

	if (!m_selectedTile->getIsMarked()) {
		m_selectedTile->setIsOpen(true);
		if (m_grassMap[x][z] != nullptr)
			removeEntity(m_grassMap[x][z]->getEntity());
		m_openedTilesCount++;
		switch (m_selectedTile->getValue())
		{
		case -1:
			m_selectedTile->setTexture(m_textures[textureNames::openedTileBomb]);
			m_lives--;

			if (m_lives <= 0 && m_openedBomb == nullptr) {
				auxBomb = new Bomb;
				entity = createEntity<OMeshEntity>();
				auxBomb->setEntity(entity);
				auxBomb->setMesh(m_meshObj[meshNames::bomb]);
				auxBomb->setShader(m_meshShader);
				auxBomb->setPosition(m_selectedTile->getPosition());
				auxBomb->setScale(OVec3(0.8, 0.8, 0.8));
				auxBomb->setTexture(m_textures[textureNames::bombT]);
				m_openedBomb = auxBomb;
			}

			break;

		case 0:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile0]);
			// Left
			if (CG_isValid(x - 1, z)) {
				if (!m_map[x - 1][z]->getIsOpen() && !m_map[x - 1][z]->getIsMarked()) {
					CG_openTileRec(x - 1, z);
				}
			}
			//Top  Left
			if (CG_isValid(x - 1, z - 1)) {
				if (!m_map[x - 1][z - 1]->getIsOpen() && !m_map[x - 1][z - 1]->getIsMarked()) {
					CG_openTileRec(x - 1, z - 1);
				}
			}
			//Top
			if (CG_isValid(x, z - 1)) {
				if (!m_map[x][z - 1]->getIsOpen() && !m_map[x][z - 1]->getIsMarked()) {
					CG_openTileRec(x, z - 1);
				}
			}
			//Top Right
			if (CG_isValid(x + 1, z - 1)) {
				if (!m_map[x + 1][z - 1]->getIsOpen() && !m_map[x + 1][z - 1]->getIsMarked()) {
					CG_openTileRec(x + 1, z - 1);
				}
			}
			//Right
			if (CG_isValid(x + 1, z)) {
				if (!m_map[x + 1][z]->getIsOpen() && !m_map[x + 1][z]->getIsMarked()) {
					CG_openTileRec(x + 1, z);
				}
			}
			//Bottom Right
			if (CG_isValid(x + 1, z + 1)) {
				if (!m_map[x + 1][z + 1]->getIsOpen() && !m_map[x + 1][z + 1]->getIsMarked()) {
					CG_openTileRec(x + 1, z + 1);
				}
			}
			//Bottom
			if (CG_isValid(x, z + 1)) {
				if (!m_map[x][z + 1]->getIsOpen() && !m_map[x][z + 1]->getIsMarked()) {
					CG_openTileRec(x, z + 1);
				}
			}
			//Bottom Left
			if (CG_isValid(x - 1, z + 1)) {
				if (!m_map[x - 1][z + 1]->getIsOpen() && !m_map[x - 1][z + 1]->getIsMarked()) {
					CG_openTileRec(x - 1, z + 1);
				}
			}
			m_selectedTile = actualTile;
			break;

		case 1:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile1]);
			break;

		case 2:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile2]);
			break;

		case 3:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile3]);
			break;

		case 4:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile4]);
			break;

		case 5:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile5]);
			break;

		case 6:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile6]);
			break;

		case 7:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile7]);
			break;

		case 8:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile8]);
			break;

		default:
			m_selectedTile->setTexture(m_textures[textureNames::openedTile0]);
			break;
		}
	}
}

// Generates a random path without bombs on the map 
void MyGame::AG_createRandomPath()
{
	ui32 actualRow = m_mapSize / 2;
	ui32 actualCol = 0;

	m_map[actualRow][actualCol]->setValue(0);

	f32 prob = 0.4;

	while (actualCol < m_mapSize - 1)
	{
		if (randomBoolWithProb(prob)) //Go forward
		{
			if (actualCol + 1 < m_mapSize)
			{
				actualCol++;

				if (prob - 0.15 > 0.0)
				{
					prob -= 0.15;
				}
				else
				{
					prob = 0.4;
				}
			}
		}
		else
		{
			if (randomBoolWithProb(0.5))
			{
				if (actualRow + 1 < m_mapSize)
				{
					actualRow++;

					if (prob + 0.05 < 1.0)
					{
						prob += 0.05;
					}
					else
					{
						prob = 0.4;
					}
				}
			}
			else
			{
				if (actualRow - 1 > -1)
				{
					actualRow--;

					if (prob + 0.05 < 1.0)
					{
						prob += 0.05;
					}
					else
					{
						prob = 0.4;
					}
				}
			}
		}

		m_map[actualRow][actualCol]->setValue(0);
	}
}

// Adds random empty cells to the map
void MyGame::AG_addRandomEmptyCells()
{
	for (size_t row = 0; row < m_mapSize; row++)
	{
		for (size_t col = 0; col < m_mapSize; col++)
		{
			if (randomBoolWithProb(0.35))
			{
				m_map[row][col]->setValue(0);
			}
		}
	}
}

//Generates map grid with all bombs set
void MyGame::AG_generateMap()
{
	switch (m_difficulty)
	{
	case easy:
		m_mapSize = 9;
		m_lives = 5;
		break;
	case medium:
		m_mapSize = 16;
		m_lives = 10;
		break;
	case hard:
		m_mapSize = 24;
		m_lives = 15;
		break;
	default:
		m_mapSize = 0;
		break;
	}

	m_tileSize = 2.0f;

	for (ui32 x = 0; x < m_mapSize; x++)
	{
		std::vector<Tile*> newRow;
		std::vector<Grass*> newRowGrass;
		for (ui32 y = 0; y < m_mapSize; y++)
		{
			Tile* newTile = new Tile;
			auto entity = createEntity<OMeshEntity>();
			newTile->setEntity(entity);

			newTile->setMesh(m_meshObj[meshNames::cube]);
			newTile->setShader(m_meshShader);

			f32 auxX = 1 + m_tileSize * x;
			f32 auxY = 0.0f;
			f32 auxZ = 1 + m_tileSize * y;

			f32 auxScaleX = m_tileSize;
			f32 auxScaleY = m_tileSize;
			f32 auxScaleZ = m_tileSize;

			newTile->setX(auxX);
			newTile->setY(auxY);
			newTile->setZ(auxZ);

			newTile->setIsOpen(false);
			newTile->setIsSelected(false);
			newTile->setValue(-1);

			newTile->setPosition(OVec3(auxX, auxY, auxZ));
			newTile->setScale(OVec3(auxScaleX, auxScaleY, auxScaleZ));
			newTile->setTexture(m_textures[textureNames::tile]);

			newRow.push_back(newTile);

			if (randomBoolWithProb(0.65))
			{
				Grass* newGrass = new Grass;
				newGrass->setEntity(createEntity<OMeshEntity>());

				newGrass->setMesh(m_meshObj[meshNames::grass]);
				newGrass->setShader(m_meshShader);
				newGrass->setScale(OVec3(0.1, randomNumberInRange(0.1f, 0.35f), 0.1));
				newGrass->setPosition(OVec3(auxX, auxY + 1 + randomNumberInRange(0.1f, 0.35f), auxZ));
				newGrass->setRotation(OVec3(0.0f, randomNumberInRange(0.0f, 1.0f), 0.0f));

				newGrass->setTexture(m_textures[textureNames::green1]);
				if (randomBoolWithProb(0.05))
					newGrass->setTexture(m_textures[textureNames::green2]);
				else
					if (randomBoolWithProb(0.05))
						newGrass->setTexture(m_textures[textureNames::green3]);
					else if (randomBoolWithProb(0.05))
						newGrass->setTexture(m_textures[textureNames::green4]);

				newRowGrass.push_back(newGrass);
			}
			else
				newRowGrass.push_back(nullptr);
		}

		m_map.push_back(newRow);
		m_grassMap.push_back(newRowGrass);
	}

	AG_createRandomPath();

	AG_addRandomEmptyCells();

	for (ui32 x = 0; x < m_mapSize; x++)
	{
		std::vector<Flag*> newRow;
		newRow.resize(m_mapSize, new Flag);
		m_flagMap.push_back(newRow);

		for (ui32 y = 0; y < m_mapSize; y++)
		{
			if (m_map[x][y]->getValue() != -1)
				m_map[x][y]->setValue(AG_countAdjacentMines(x, y));
		}
	}
	
	m_selectedTile = m_map[0][0];

	
	//Creating visual forest around map
	f32 auxX = 1 + m_tileSize * (m_mapSize / 2) - m_difficulty - 2 * m_tileSize * m_mapSize;
	f32 auxY = 0.0f;
	f32 auxZ = 1 + m_tileSize * (m_mapSize / 2) - m_difficulty - 2 * m_tileSize * m_mapSize;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			auto forest = createEntity<OMeshEntity>();
			forest->setScale(OVec3(1.3 + m_difficulty, 1.3 + m_difficulty, 1.3 + m_difficulty));
			forest->setPosition(OVec3(auxX + m_tileSize * m_mapSize * i, auxY + 0.9, auxZ + m_tileSize * m_mapSize * j));
			forest->setTexture(m_textures[textureNames::forestT]);
			forest->setMesh(m_meshObj[meshNames::forest]);
			forest->setShader(m_meshShader);
			if (i == 2 && j == 1)
				j++;
		}
	}

	if (m_difficulty == gameDifficulty::hard)
	{
		auto floor = createEntity<OMeshEntity>();
		floor->setScale(OVec3(1000.0f, 0.1f, 1000.0f));
		floor->setPosition(OVec3(0.0f, 0.86f, 0.0f));
		floor->setTexture(m_textures[textureNames::floorT]);
		floor->setMesh(m_meshObj[meshNames::cube]);
		floor->setShader(m_meshShader);
	}
}

//A Utility Function to check whether given cell (row, col) is a valid cell or not
bool MyGame::AG_isValid(const unsigned int row, const unsigned int col)
{
	// Returns true if row number and column number
	// is in range
	return (row >= 0) && (row < m_mapSize) &&
		(col >= 0) && (col < m_mapSize);
}

//A Function to count the number of mines in the adjacent cells
int MyGame::AG_countAdjacentMines(const unsigned int row, const unsigned int col)
{
	int count = 0;

	/*
		Count all the mines in the 8 adjacent
		cells

			N.W   N   N.E
			  \   |   /
			   \  |  /
			W----Cell----E
				 / | \
			   /   |  \
			S.W    S   S.E

		Cell-->Current Cell (row, col)
		N -->  North        (row-1, col)
		S -->  South        (row+1, col)
		E -->  East         (row, col+1)
		W -->  West            (row, col-1)
		N.E--> North-East   (row-1, col+1)
		N.W--> North-West   (row-1, col-1)
		S.E--> South-East   (row+1, col+1)
		S.W--> South-West   (row+1, col-1)
	*/

	//----------- 1st Neighbour (North) ------------

		// Only process this cell if this is a valid one
	if (AG_isValid(row - 1, col) == true)
	{
		if (m_map[row - 1][col]->getValue() == -1)
			count++;
	}

	//----------- 2nd Neighbour (South) ------------

		// Only process this cell if this is a valid one
	if (AG_isValid(row + 1, col) == true)
	{
		if (m_map[row + 1][col]->getValue() == -1)
			count++;
	}

	//----------- 3rd Neighbour (East) ------------

		// Only process this cell if this is a valid one
	if (AG_isValid(row, col + 1) == true)
	{
		if (m_map[row][col + 1]->getValue() == -1)
			count++;
	}

	//----------- 4th Neighbour (West) ------------

		// Only process this cell if this is a valid one
	if (AG_isValid(row, col - 1) == true)
	{
		if (m_map[row][col - 1]->getValue() == -1)
			count++;
	}

	//----------- 5th Neighbour (North-East) ------------

		// Only process this cell if this is a valid one
	if (AG_isValid(row - 1, col + 1) == true)
	{
		if (m_map[row - 1][col + 1]->getValue() == -1)
			count++;
	}

	//----------- 6th Neighbour (North-West) ------------

	   // Only process this cell if this is a valid one
	if (AG_isValid(row - 1, col - 1) == true)
	{
		if (m_map[row - 1][col - 1]->getValue() == -1)
			count++;
	}

	//----------- 7th Neighbour (South-East) ------------

	   // Only process this cell if this is a valid one
	if (AG_isValid(row + 1, col + 1) == true)
	{
		if (m_map[row + 1][col + 1]->getValue() == -1)
			count++;
	}

	//----------- 8th Neighbour (South-West) ------------

		// Only process this cell if this is a valid one
	if (AG_isValid(row + 1, col - 1) == true)
	{
		if (m_map[row + 1][col - 1]->getValue() == -1)
			count++;
	}

	return count;
}


