#pragma once

enum textureNames {
	tile = 0,
	selectedTile,
	openedTile0,
	openedTile1,
	openedTile2,
	openedTile3,
	openedTile4,
	openedTile5,
	openedTile6,
	openedTile7,
	openedTile8,
	openedTileBomb,
	flaggedTile,
	stone,
	wood,
	black,
	red,
	green1,
	green2,
	green3,
	green4,
	sky,
	landscape,
	win,
	lose,
	resumeButton,
	resumeButtonSelected,
	quitButton,
	quitButtonSelected,
	easyButton,
	easyButtonSelected,
	mediumButton,
	mediumButtonSelected,
	hardButton,
	hardButtonSelected,
	classicTitle,
	advanceTitle,
	characterT,
	bombT,
	flagT,
	forestT,
	grassT,
	floorT
};


enum meshNames {

	cube = 0,
	sphere,
	deadTree,
	flag,
	bomb,
	grass,
	character,
	forest
};


enum cooldownTimers {

	changeCamCooldown = 0,
	escapeCooldown,
	clickCouldown,
	playerOnBomb,
	leftclickCouldown,
	bombTimer,
	meunSelectorCooldown,
	winTimer,
	loseTimer,

	nItems //On changes: please keep nItems at the end
};

enum escMenuItems {
	resumeEscButton,
	quitEscButton,

	nEscMenuItems //On changes: please keep nEscMenuItems at the end
};


enum mainMenuItems {
	characterMenu,
	CG_title,
	AG_title,
	CG_easyButton,
	CG_mediumButton,
	CG_hardButton,
	AG_easyButton,
	AG_mediumButton,
	AG_hardButton,
	
	nMainMenuItems //On changes: please keep nMainMenuItems at the end
};

enum menuWindows {
	mainMenuWindow,
	escWindow,
	winWindow,
	loseWindow
};

enum gameMode {
	classic = 0,
	advance
};

enum gameDifficulty {

	easy = 0,
	medium,
	hard
};