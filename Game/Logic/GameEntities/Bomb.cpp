#include "Bomb.h"

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

void Bomb::setEntity(OMeshEntity* entity)
{
	m_entity = entity;
}

void Bomb::setPosition(const OVec3 position)
{
	m_entity->setPosition(position);
}

void Bomb::setScale(const OVec3 scale)
{
	m_entity->setScale(scale);
}

void Bomb::setRotation(const OVec3 rotation)
{
	m_entity->setRotation(rotation);
}

void Bomb::setTexture(const OTexturePtr& texture)
{
	m_entity->setTexture(texture);
}

void Bomb::setMesh(const OMeshPtr& mesh)
{
	m_entity->setMesh(mesh);
}

void Bomb::setShader(const OShaderPtr& shader)
{
	m_entity->setShader(shader);
}

OEntity* Bomb::getEntity()
{
	return m_entity;
}

OVec3 Bomb::getPosition()
{
	return m_entity->getPosition();
}

OVec3 Bomb::getScale()
{
	return m_entity->getScale();
}

OVec3 Bomb::getRotation()
{
	return m_entity->getRotation();
}

void Bomb::setX(const f32 x)
{
	m_x = x;
}

void Bomb::setY(const f32 y)
{
	m_y = y;
}

void Bomb::setZ(const f32 z)
{
	m_z = z;
}

f32 Bomb::getX()
{
	return m_x;
}


f32 Bomb::getY()
{
	return m_y;
}


f32 Bomb::getZ()
{
	return m_z;
}



