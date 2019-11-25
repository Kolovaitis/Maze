#pragma once
#include "Map.h"
#include <SFML/Graphics.hpp>

#define FRAME_RATE 60
#define PLAYER_TEXTURE_WIDTH 32
#define PLAYER_TEXTURE_HEIGHT 32
#define SCALE_X 2
#define SCALE_Y 2

#define textureCount 4

class View
{
public:
	View();
	~View();
	void start();
private:
	void drawEntity(Entity* obj);
	void drawGameObject(GameObject* obj);
	void loop();
	Map* map;
	sf::RenderWindow* window;
	sf::IntRect rectSourceSprite;
	sf::Sprite* sprites[textureCount];
	sf::Texture* textures[textureCount];
	std::string fileNames[textureCount] = { "images/player1.png", "images/player2.png" ,"" ,"images/Wall.png" };
};

