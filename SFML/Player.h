#pragma once
#include "Entity.h"
#include <ctime>
//#define WIDTH 32
//#define HEIGHT 32
class Player :public Entity
{
	
public:	
	
	Player(float x, float y);
	static const int WIDTH = 32;
	static const int HEIGHT = 32;
	int index;
	void endGo(int x, int y) override;
	double oxygenLevel;
	};

