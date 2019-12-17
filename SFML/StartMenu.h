#pragma once
#include "View.h"
#define START_MENU_WIDTH 1024
#define START_MENU_HEIGHT 512
#define BUTTON_X 320
#define BUTTON_Y1 128
#define BUTTON_Y2 256
#define START_GAME 0
#define EXIT 1
class StartMenu
{
public:
	StartMenu();
	void startApp();
private:
	void startGame();
	View* game;
	bool canRun;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture startGameTexture;
	sf::Texture exitTexture;
	sf::Texture selectTexture;
	sf::Sprite buttonSprite;
	int selectedOption;
};

