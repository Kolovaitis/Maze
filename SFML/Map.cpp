#include "Map.h"


Map::Map() {
	srand(time(NULL));
	this->lastTime = clock();
	objCount = 0;
	addWalls();
	addPlayers();
	generateOxygen();
	addMonsters();
}

Map::~Map()
{
	for (int i = 0; i < objCount; i++) {
		delete(positions[i]);
	}
}

void Map::generateOxygen()
{
	Position* pos = new Position;
	pos->height = OXYGEN_WIDTH;
	pos->width = OXYGEN_WIDTH;
	do
	{
		pos->x = STANDART_WALL_WIDTH + rand() % (this->width - STANDART_WALL_WIDTH * 2);
		pos->y = STANDART_WALL_WIDTH + rand() % (this->height - STANDART_WALL_WIDTH * 2);
	} while (checkAllCollisions(pos));
	positions[objCount] = new GameObject(pos);
	positions[objCount]->TYPE = TYPE_OXYGEN;
	objCount++;
	lastGenerationOxigen = clock();
}
void Map::generateWall(float x, float y)//Придумать
{
	positions[objCount] = new GameObject(x * STANDART_WALL_WIDTH, y * STANDART_WALL_HEIGHT, STANDART_WALL_WIDTH, STANDART_WALL_HEIGHT);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;

}
bool Map::checkAllCollisions(Position* pos)
{
	for (int i = 0; i < objCount; i++)
	{
		if (positions[i]->checkCollision(pos))
		{
			return true;
		}
	}
	return false;
}

void Map::addRandomWalls()
{
	float y = 0;
	for (int i = 3; i < WALL_COUNT; i++)
	{
		if (rand() % 2) {
			y += rand() % 3 - 1;
			if (y < 0)
			{
				y = 0;
			}
			if (y > this->height / STANDART_WALL_HEIGHT)
			{
				y = height / STANDART_WALL_HEIGHT;
			}
			generateWall(i, y);
		}
	}
}

void Map::addPlayers()
{
	for (int i = 0; i < PLAYER_COUNT; i++) {
		players[i] = new Player(startPos[i][0], startPos[i][1]);
		positions[objCount] = players[i];
		objCount++;
		players[i]->characterView.objCount = &objCount;
		players[i]->characterView.positions = &positions[0];
		players[i]->index = i;
	}
}
void Map::addMonsters()
{
	for (int i = 0; i < MONSTER_COUNT; i++) {
		monsters[i] = new Monster(150, 150);
		positions[objCount] = monsters[i];
		objCount++;
		monsters[i]->characterView.objCount = &objCount;
		monsters[i]->characterView.positions = &positions[0];

	}
}
void Map::addWalls(){
	addBorts();
	addRandomWalls();	
}

void Map::addBorts(){
	positions[objCount] = new GameObject(0, 0, STANDART_WALL_WIDTH, this->height);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
	positions[objCount] = new GameObject(0, 0, this->width, STANDART_WALL_WIDTH);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
	positions[objCount] = new GameObject(0, this->height - STANDART_WALL_WIDTH, this->width, STANDART_WALL_WIDTH);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
	positions[objCount] = new GameObject(this->width - STANDART_WALL_WIDTH, 0, STANDART_WALL_WIDTH, this->height);
	positions[objCount]->TYPE = TYPE_WALL;
	objCount++;
}

void Map::tick(char actions[]) {
	time_t deltaTime = clock() - lastTime;
	for (int i = 0; i < PLAYER_COUNT; i++) {
		if (players[i]->alive) {
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
			players[i]->tick(deltaTime);
		}else
		{
			isGameOver = true;
			winnerIndex = i == 0 ? 1 : 0;
		}
	}
	for (int i = 0; i < MONSTER_COUNT; i++) {
		monsters[i]->tick(deltaTime);
	}
	if (clock() - lastGenerationOxigen > OXYGEN_GENERATE_TIME)
	{
		generateOxygen();
	}
	lastTime = clock();
}
