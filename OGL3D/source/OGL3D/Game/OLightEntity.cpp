#include <OGL3D/Game/OLightEntity.h>

OLightEntity::OLightEntity()
{
}

OLightEntity::~OLightEntity()
{
}

void OLightEntity::setColor(const OVec4& color)
{
	m_color = color;
}

OVec4 OLightEntity::getColor()
{
	return m_color;
}
