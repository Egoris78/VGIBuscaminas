#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>
#include <Windows.h>


OGraphicsEngine* OGame::getGraphicsEngine()
{
	return m_graphicsEngine.get();
}

OInputManager* OGame::getInputManager()
{
	return m_inputManager.get();
}

OResourceManager* OGame::getResourceManager()
{
	return m_resourceManager.get();
}

void OGame::run()
{

	onCreate();
	while (m_isRunning)
	{
		MSG msg = {};
		if (PeekMessage(&msg, HWND(), NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				m_isRunning = false;
				continue;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		onUpdateInternal();
	}

	onQuit();
}
