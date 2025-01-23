#include "Flag.h"

Flag::Flag()
{
}

Flag::~Flag()
{
}

void Flag::setEntity(OMeshEntity* entity)
{
	m_entity = entity;
}

void Flag::setPosition(const OVec3 position)
{
	m_entity->setPosition(position);
}

void Flag::setScale(const OVec3 scale)
{
	m_entity->setScale(scale);
}

void Flag::setRotation(const OVec3 rotation)
{
	m_entity->setRotation(rotation);
}

void Flag::setTexture(const OTexturePtr& texture)
{
	m_entity->setTexture(texture);
}

void Flag::setMesh(const OMeshPtr& mesh)
{
	m_entity->setMesh(mesh);
}

void Flag::setShader(const OShaderPtr& shader)
{
	m_entity->setShader(shader);
}

OEntity* Flag::getEntity()
{
	return m_entity;
}

OVec3 Flag::getPosition()
{
	return m_entity->getPosition();
}

OVec3 Flag::getScale()
{
	return m_entity->getScale();
}

OVec3 Flag::getRotation()
{
	return m_entity->getRotation();
}

void Flag::setIsOpen(const bool isOpen)
{
	m_isOpen = isOpen;
}

void Flag::setIsSelected(const bool isSelected)
{
	m_isSelected = isSelected;
}

void Flag::setX(const f32 x)
{
	m_x = x;
}

void Flag::setY(const f32 y)
{
	m_y = y;
}

void Flag::setZ(const f32 z)
{
	m_z = z;
}

bool Flag::getIsOpen()
{
	return m_isOpen;
}

bool Flag::getIsSelected()
{
	return m_isSelected;
}

f32 Flag::getX()
{
	return m_x;
}


f32 Flag::getY()
{
	return m_y;
}


f32 Flag::getZ()
{
	return m_z;
}



