#pragma once

#include <OGL3D/Math/ORect.h>



class OWindow
{
public:
	OWindow();
	~OWindow();

	ORect getInnerSize();

	void makeCurrentContext();
	void present(bool vsync);
private:
	void* m_handle = nullptr;
	void* m_context = nullptr;
    ORect m_size = ORect(1600, 900);
};

