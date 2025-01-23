#pragma once
#include <OGL3D/All.h>

class Tile
{
public:
	Tile();
	~Tile();

	void setEntity(OMeshEntity* entity);
	void setPosition(const OVec3 position);
	void setScale(const OVec3 scale);
	void setRotation(const OVec3 rotation);
	void setTexture(const OTexturePtr& texture);
	void setMesh(const OMeshPtr& mesh );
	void setShader(const OShaderPtr& shader);

	OEntity* getEntity();
	OVec3 getPosition();
	OVec3 getScale();
	OVec3 getRotation();

public:
	void setValue(const int value);
	void setIsOpen(const bool isOpen);
	void setIsSelected(const bool isSelected);
	void setIsMarked(bool isMarked);

	void setX(const f32 x);
	void setY(const f32 y);
	void setZ(const f32 z);

	int getValue();
	bool getIsOpen();
	bool getIsSelected();
	bool getIsMarked();

	f32 getX();
	f32 getY();
	f32 getZ();

private:
	OMeshEntity* m_entity = nullptr;

	f32 m_x;
	f32 m_y;
	f32 m_z;

private:
	int m_value;
	bool m_isOpen;
	bool m_isSelected;
	bool m_isMarked = false;
};

