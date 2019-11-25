#include "Map.h"
Map::Map() {
	
	this->lastTime = clock();
	
	objCount = PLAYER_COUNT;
	addPlayers();
	addWalls();
	
	
}
void Map::addPlayers()
{
	for (int i = 0; i < PLAYER_COUNT; i++) {
		players[i] = new Player(startPos[i][0], startPos[i][1]);
		positions[i] = players[i];
		players[i]->characterView.objCount = &objCount;
		players[i]->characterView.positions = &positions[0];
		players[i]->index = i;
	}
}
void Map::addWalls()
{
	positions[objCount] = new GameObject(0, 0, STANDART_WALL_WIDTH, this->height);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
	positions[objCount] = new GameObject(0, 0, this->width, STANDART_WALL_WIDTH);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
	positions[objCount] = new GameObject(0, this->height-STANDART_WALL_WIDTH, this->width, STANDART_WALL_WIDTH);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
	positions[objCount] = new GameObject(this->width-STANDART_WALL_WIDTH, 0, STANDART_WALL_WIDTH, this->height);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
}
void Map::tick(char actions[]) {
	time_t deltaTime = clock() - lastTime;
	for (int i = 0; i < PLAYER_COUNT; i++) {
		if (actions[i] & GO_BACKWARD) {
			players[i]->goBackward(deltaTime);
		}
		if (actions[i] & GO_FORWARD) {
			players[i]->goForward(deltaTime);
		}
		if (actions[i] & GO_LEFT) {
			players[i]->goLeft(deltaTime);
		}
		if (actions[i] & GO_RIGHT) {
			players[i]->goRight(deltaTime);
		}
		if (!actions[i]) {
			players[i]->stay();
		}
	}
	lastTime = clock();
}
