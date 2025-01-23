#pragma once
#include "UIObject.h"

UIObject::UIObject()
{
}

UIObject::~UIObject()
{
}

void UIObject::setEntity(OMeshEntity* entity)
{
	m_entity = entity;
}

void UIObject::setPosition(const OVec3 position)
{
	m_entity->setPosition(position);
}

void UIObject::setScale(const OVec3 scale)
{
	m_entity->setScale(scale);
}

void UIObject::setRotation(const OVec3 rotation)
{
	m_entity->setRotation(rotation);
}

void UIObject::setTexture(const OTexturePtr& texture)
{
	m_entity->setTexture(texture);
}

void UIObject::setMesh(const OMeshPtr& mesh)
{
	m_entity->setMesh(mesh);
}

void UIObject::setShader(const OShaderPtr& shader)
{
	m_entity->setShader(shader);
}

void UIObject::setDefaultTexture(const OTexturePtr& defaultTexture)
{
	m_defaultTexture = defaultTexture;
}

void UIObject::setSelectedTexture(const OTexturePtr& selectedTexture)
{
	m_selectedTexture = selectedTexture;
}

OEntity* UIObject::getEntity()
{
	return m_entity;
}

OTexturePtr UIObject::getDefaultTexture()
{
	return m_defaultTexture;
}

OTexturePtr UIObject::getSelectedTexture()
{
	return m_selectedTexture;
}

OVec3 UIObject::getPosition()
{
	return m_entity->getPosition();
}

OVec3 UIObject::getScale()
{
	return m_entity->getScale();
}

OVec3 UIObject::getRotation()
{
	return m_entity->getRotation();
}

void UIObject::setX(const f32 x)
{
	m_x = x;
}

void UIObject::setY(const f32 y)
{
	m_y = y;
}

void UIObject::setZ(const f32 z)
{
	m_z = z;
}

f32 UIObject::getX()
{
	return m_x;
}


f32 UIObject::getY()
{
	return m_y;
}


f32 UIObject::getZ()
{
	return m_z;
}