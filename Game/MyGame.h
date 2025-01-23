#pragma once
#include <OGL3D/All.h>

#include "Logic/Enums.h"
#include "Logic/GameEntities/Tile.h"
#include "Logic/GameEntities/Flag.h"
#include "Logic/GameEntities/Bomb.h"
#include "Logic/GameEntities/Grass.h"
#include "Logic/GameEntities/UIObject.h"

#include <time.h>
#include <vector>
#include <random>
#include <chrono>

class MyGame: public OGame
{

public:
	MyGame();
	~MyGame();

	
	virtual void onCreate();
	virtual void onUpdate(f32 deltaTime);

	void loadAssets();

	bool randomBoolWithProb(f32 prob);
	f32 randomNumberInRange(f32 low, f32 high);

private: //Menu methods
	void MENU_onOpen();
	void MENU_onUpdate(f32 deltaTime);
	void MENU_onClose();
	
private: //Classic gamemode methods
	void CG_onCreate();
	void CG_onUpdate(f32 deltaTime);

	void CG_manageInputs(f32 deltaTime);
	void CG_playerAndCamMovement(f32 deltaTime);
	void CG_selectAndOpenTiles(f32 deltaTime);
	void CG_checkLoseAndWinConditions(f32 deltaTime);
	void CG_openTileRec(ui32 x, ui32 z);

	void CG_generateMap();
	void CG_placeMines();
	int CG_countAdjacentMines(const unsigned int row, const unsigned int col);
	bool CG_isValid(const unsigned int row, const unsigned int col);

private: //Advance gamemode methods
	void AG_onCreate();
	void AG_onUpdate(f32 deltaTime);

	void AG_manageInputs(f32 deltaTime);
	void AG_playerAndCamMovement(f32 deltaTime);
	void AG_selectAndOpenTiles(f32 deltaTime);
	void AG_checkLoseAndWinConditions(f32 deltaTime);
	void AG_openTileRec(ui32 x, ui32 z);
	
	void AG_createRandomPath();
	void AG_addRandomEmptyCells();
	void AG_generateMap();
	int AG_countAdjacentMines(const unsigned int row, const unsigned int col);
	bool AG_isValid(const unsigned int row, const unsigned int col);
	
private: //Menu
	std::vector<UIObject*> m_menuEntities;
	menuWindows m_menuWindow = menuWindows::mainMenuWindow;
	UIObject* m_selectedUIButton = nullptr;
	i32 m_selectedUIButtonPos = 0;

	
private: //Primary game entities
	OMeshEntity* m_player;
	OVec3 m_playerPointer;

	OEntity* m_light = nullptr;
	OEntity* m_skybox = nullptr;

	OCamera* m_cam;

private: //Parameters
	bool m_onMenu = false;
	gameMode m_gamemode = gameMode::classic;
	gameDifficulty m_difficulty = gameDifficulty::easy;
	i32 m_lives = 1;
	
	f32 m_sensitivity;
	f32 m_camRotX = 0;
	f32 m_camRotY = 0;

	f32 m_speed = 5.0f;
	f32 m_roty = 0;

private: //Map
	std::vector<std::vector<Tile*>> m_map;
	std::vector<std::vector<Flag*>> m_flagMap;
	std::vector<std::vector<Grass*>> m_grassMap;
	
	ui32 m_mapSize;
	f32 m_tileSize;
	ui32 m_bombCount;

	Tile* m_selectedTile = nullptr;
	Bomb* m_openedBomb = nullptr;

private: //Assets
	std::vector<std::shared_ptr<OTexture>> m_textures;
	std::vector<std::shared_ptr<OMesh>> m_meshObj;
	std::vector<f32> m_cooldowns;

	OShaderPtr m_meshShader;
	OShaderPtr m_skyboxShader;

private: //Wining conditions
	int m_openedTilesCount = 0;
	int m_emptyTilesCount;
};

