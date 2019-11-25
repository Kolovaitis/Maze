#pragma once
#define GO_LEFT 0b00000001
#define GO_RIGHT 0b00000010
#define GO_FORWARD 0b00000100
#define GO_BACKWARD 0b00001000
#define STANDART_WALL_WIDTH 16
#define PLAYER_COUNT 2
#include "Player.h"
#include <ctime>
typedef struct Coordinates{
float x,y; }Coordinates;
class Map
{
	
public:
	
	Player* players[PLAYER_COUNT];
	GameObject* positions[128];
	int objCount;
	
	void tick(char actions[]);	
	Map();
	const unsigned int width = 400;
	const unsigned int height = 300;
	
private:
	const float speed = 0.5;
	void addWalls();
	void addPlayers();
	time_t lastTime;
    unsigned int startPos[PLAYER_COUNT][2] = {{width- STANDART_WALL_WIDTH- Player::WIDTH, height-STANDART_WALL_WIDTH-Player::HEIGHT},{STANDART_WALL_WIDTH,STANDART_WALL_WIDTH} };
	

};

