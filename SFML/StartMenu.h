#pragma once
#include "View.h"
class StartMenu
{
public:
	StartMenu();
	void startApp();
private:
	void startGame();
	View* game;
};

