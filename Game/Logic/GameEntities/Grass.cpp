#include "Grass.h"

Grass::Grass()
{
}

Grass::~Grass()
{
}

void Grass::setEntity(OMeshEntity* entity)
{
	m_entity = entity;
}

void Grass::setPosition(const OVec3 position)
{
	m_entity->setPosition(position);
}

void Grass::setScale(const OVec3 scale)
{
	m_entity->setScale(scale);
}

void Grass::setRotation(const OVec3 rotation)
{
	m_entity->setRotation(rotation);
}

void Grass::setTexture(const OTexturePtr& texture)
{
	m_entity->setTexture(texture);
}

void Grass::setMesh(const OMeshPtr& mesh)
{
	m_entity->setMesh(mesh);
}

void Grass::setShader(const OShaderPtr& shader)
{
	m_entity->setShader(shader);
}

OEntity* Grass::getEntity()
{
	return m_entity;
}

OVec3 Grass::getPosition()
{
	return m_entity->getPosition();
}

OVec3 Grass::getScale()
{
	return m_entity->getScale();
}

OVec3 Grass::getRotation()
{
	return m_entity->getRotation();
}

void Grass::setX(const f32 x)
{
	m_x = x;
}

void Grass::setY(const f32 y)
{
	m_y = y;
}

void Grass::setZ(const f32 z)
{
	m_z = z;
}

f32 Grass::getX()
{
	return m_x;
}


f32 Grass::getY()
{
	return m_y;
}


f32 Grass::getZ()
{
	return m_z;
}