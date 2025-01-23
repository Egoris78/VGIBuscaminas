#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::setEntity(OMeshEntity* entity)
{
	m_entity = entity;
}

void Tile::setPosition(const OVec3 position)
{
	m_entity->setPosition(position);
}

void Tile::setScale(const OVec3 scale)
{
	m_entity->setScale(scale);
}

void Tile::setRotation(const OVec3 rotation)
{
	m_entity->setRotation(rotation);
}

void Tile::setTexture(const OTexturePtr& texture)
{
	m_entity->setTexture(texture);
}

void Tile::setMesh(const OMeshPtr& mesh)
{
	m_entity->setMesh(mesh);
}

void Tile::setShader(const OShaderPtr& shader)
{
	m_entity->setShader(shader);
}

OEntity* Tile::getEntity()
{
	return m_entity;
}

OVec3 Tile::getPosition()
{
	return m_entity->getPosition();
}

OVec3 Tile::getScale()
{
	return m_entity->getScale();
}

OVec3 Tile::getRotation()
{
	return m_entity->getRotation();
}

void Tile::setValue(const int value)
{
	m_value = value;
}

void Tile::setIsOpen(const bool isOpen)
{
	m_isOpen = isOpen;
}

void Tile::setIsSelected(const bool isSelected)
{
	m_isSelected = isSelected;
}

void Tile::setIsMarked(bool isMarked)
{
	m_isMarked = isMarked;
}

void Tile::setX(const f32 x)
{
	m_x = x;
}

void Tile::setY(const f32 y)
{
	m_y = y;
}

void Tile::setZ(const f32 z)
{
	m_z = z;
}

int Tile::getValue()
{
	return m_value;
}

bool Tile::getIsOpen()
{
	return m_isOpen;
}

bool Tile::getIsSelected()
{
	return m_isSelected;
}

bool Tile::getIsMarked()
{
	return m_isMarked;
}

f32 Tile::getX()
{
	return m_x;
}


f32 Tile::getY()
{
	return m_y;
}


f32 Tile::getZ()
{
	return m_z;
}



