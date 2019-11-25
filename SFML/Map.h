#pragma once
#define GO_LEFT 0b00000001
#define GO_RIGHT 0b00000010
#define GO_FORWARD 0b00000100
#define GO_BACKWARD 0b00001000
#define STANDART_WALL_WIDTH 16
#define STANDART_WALL_HEIGHT 48
#define PLAYER_COUNT 2
#define OXYGEN_WIDTH 24
#define OXYGEN_GENERATE_TIME 5000
#define WALL_COUNT 27
#define MONSTER_COUNT 1
#include "Player.h"
#include "Monster.h"
#include <ctime>
typedef struct Coordinates{
float x,y; }Coordinates;
class Map
{
	
public:
	
	Player* players[PLAYER_COUNT];
	Monster* monsters[MONSTER_COUNT];
	GameObject* positions[128];
	int objCount;
	
	void tick(char actions[]);	
	Map();
	const unsigned int width = 512;
	const unsigned int height = 256;
	
	
private:
	const float speed = 0.5;
	void addWalls();
	void addPlayers();
	void addMonsters();
	void generateOxygen();
	void generateWall(float x, float y);
	bool checkAllCollisions(Position* pos);
	time_t lastTime;
	time_t lastGenerationOxigen;
    unsigned int startPos[PLAYER_COUNT][2] = {{width- STANDART_WALL_WIDTH- Player::WIDTH, height-STANDART_WALL_WIDTH-Player::HEIGHT},{STANDART_WALL_WIDTH,STANDART_WALL_WIDTH} };
	

};

