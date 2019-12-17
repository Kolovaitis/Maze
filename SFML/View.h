#pragma once
#include "Map.h"
#include <SFML/Graphics.hpp>

#define FRAME_RATE 60
#define PLAYER_TEXTURE_WIDTH 32
#define PLAYER_TEXTURE_HEIGHT 32
#define SCALE_X 2
#define SCALE_Y 2
#define OXYGEN_LEVEL_WIDTH 4

#define textureCount 5

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
	void gameOver();
	Map* map;
	sf::RenderWindow* window;
	sf::IntRect rectSourceSprite;
	sf::Sprite* sprites[textureCount];
	sf::Texture* textures[textureCount];
	sf::RectangleShape* oxygenLevelShape;
	std::string fileNames[textureCount] = { "images/player1.png", "images/player2.png"  ,"images/Wall.png", "images/oxygen.png" , "images/monster.png"};
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	std::string backgroundTexturePath = "images/ground.png";
	std::string gameOverImage = "images/game_over.png";
	std::string gameOverImages[PLAYER_COUNT] = { "images/winner_right.png", "images/winner_left.png"};
	
};

