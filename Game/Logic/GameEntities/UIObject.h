#pragma once
#include <OGL3D/All.h>

class UIObject
{
public:
	UIObject();
	~UIObject();

	void setEntity(OMeshEntity* entity);
	void setPosition(const OVec3 position);
	void setScale(const OVec3 scale);
	void setRotation(const OVec3 rotation);
	void setTexture(const OTexturePtr& texture);
	void setMesh(const OMeshPtr& mesh);
	void setShader(const OShaderPtr& shader);
	
	void setDefaultTexture(const OTexturePtr& defaultTexture);
	void setSelectedTexture(const OTexturePtr& selectedTexture);

	OEntity* getEntity();
	OTexturePtr getDefaultTexture();
	OTexturePtr getSelectedTexture();
	OVec3 getPosition();
	OVec3 getScale();
	OVec3 getRotation();

public:

	void setX(const f32 x);
	void setY(const f32 y);
	void setZ(const f32 z);

	f32 getX();
	f32 getY();
	f32 getZ();

private:
	OMeshEntity* m_entity = nullptr;
	OTexturePtr m_defaultTexture;
	OTexturePtr m_selectedTexture;

	f32 m_x;
	f32 m_y;
	f32 m_z;
};





