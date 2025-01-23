#pragma once
#include <OGL3D/All.h>

class Flag
{
public:
	Flag();
	~Flag();

	void setEntity(OMeshEntity* entity);
	void setPosition(const OVec3 position);
	void setScale(const OVec3 scale);
	void setRotation(const OVec3 rotation);
	void setTexture(const OTexturePtr& texture);
	void setMesh(const OMeshPtr& mesh);
	void setShader(const OShaderPtr& shader);
	void setId(const int id) { m_id = id; }
	OEntity* getEntity();
	OVec3 getPosition();
	OVec3 getScale();
	OVec3 getRotation();

public:
	void setIsOpen(const bool isOpen);
	void setIsSelected(const bool isSelected);

	void setX(const f32 x);
	void setY(const f32 y);
	void setZ(const f32 z);

	bool getIsOpen();
	bool getIsSelected();

	f32 getX();
	f32 getY();
	f32 getZ();

private:
	OMeshEntity* m_entity = nullptr;

	f32 m_x;
	f32 m_y;
	f32 m_z;

private:
	bool m_isOpen;
	bool m_isSelected;
	int m_id;
};

