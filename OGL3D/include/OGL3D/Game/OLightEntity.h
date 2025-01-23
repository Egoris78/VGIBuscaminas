#pragma once
#include <OGL3D/OPrerequisites.h>
#include <OGL3D/Game/OEntity.h>
#include <OGL3D/Math/OVec4.h>

class OGame;
class OLightEntity : public OEntity
{
public:
	OLightEntity();
	virtual ~OLightEntity();
public:
	void setColor(const OVec4& color);
	OVec4 getColor();
private:
	OVec4 m_color = OVec4(1, 1, 1, 1);

	friend class  OGame;
};

