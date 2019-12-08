#include "View.h"
View::View() {
	
	
	map = new Map();
	for (int i = 0; i < textureCount; i++)
	{
		textures[i] = new sf::Texture();
		if (!textures[i]->loadFromFile(fileNames[i]))
		{
			printf("Error %s", fileNames[i].c_str());
		}
		textures[i]->setRepeated(true);
		sprites[i] = new sf::Sprite(*textures[i], rectSourceSprite);
		sprites[i]->setScale(sf::Vector2f{ SCALE_X,SCALE_Y });
	}
	oxygenLevelShape = new sf::RectangleShape();
	oxygenLevelShape->setFillColor(sf::Color(0, 0, 255));
	oxygenLevelShape->setScale(sf::Vector2f{ SCALE_X,SCALE_Y });
	if (!backgroundTexture.loadFromFile(backgroundTexturePath))
	{
		printf("Background resoursce is not exist\n");
	}
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(sf::Vector2f{ SCALE_X,SCALE_Y });
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, map->width, map->height));
}
void View::start()
{
	
	window = new sf::RenderWindow(sf::VideoMode{ map->width * SCALE_X, map->height * SCALE_Y }, "Game");
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			}
		}

		

		loop();
		window->display();
		if(map->isGameOver)
		{
			gameOver();
		}
		
	}
	delete this;
}
void View::gameOver()
{
	if (!backgroundTexture.loadFromFile(gameOverImages[map->winnerIndex]))
	{
		printf("Winner image is not exist\n");
	}	
	
	window->draw(backgroundSprite);
	if (!backgroundTexture.loadFromFile(gameOverImage))
	{
		printf("Game over image is not exist\n");
	}

	
	window->draw(backgroundSprite);
	window->display();
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			window->close();
			break;
		}
	}
}
View::~View() {
	delete(window);
	for (int i = 0; i < textureCount; i++)
	{
		delete(sprites[i]);
		delete(textures[i]);
	}
	delete(oxygenLevelShape);
	delete map;
}
void View::drawEntity(Entity* obj)
{
	rectSourceSprite.left = PLAYER_TEXTURE_WIDTH * obj->frameIndex;
	rectSourceSprite.width = PLAYER_TEXTURE_WIDTH;
	rectSourceSprite.top = PLAYER_TEXTURE_HEIGHT * obj->animationIndex;
	rectSourceSprite.height = PLAYER_TEXTURE_HEIGHT;
	int index = obj->TYPE;
	if (index == TYPE_PLAYER)
	{
		index += ((Player*)obj)->index;

		if (((Player*)obj)->alive) {
			oxygenLevelShape->setSize(sf::Vector2f(((Player*)obj)->oxygenLevel * PLAYER_TEXTURE_WIDTH, OXYGEN_LEVEL_WIDTH));
			oxygenLevelShape->setPosition(sf::Vector2f(obj->position->x * SCALE_X, (obj->position->y - OXYGEN_LEVEL_WIDTH) * SCALE_Y));
			window->draw(*oxygenLevelShape);
			sprites[index]->setColor(sf::Color(255, 255, 255));
		}
		else
		{
			sprites[index]->setColor(sf::Color(128, 128, 128));
		}
	}
	sprites[index]->setTextureRect(rectSourceSprite);
	sprites[index]->setPosition(SCALE_X * obj->position->x, SCALE_Y * obj->position->y);
	window->draw(*sprites[index]);

}
void View::drawGameObject(GameObject* obj)
{
	if (obj->isEntity)
	{
		drawEntity((Entity*)obj);
	}
	else
	{

		rectSourceSprite.left = 0;
		rectSourceSprite.width = obj->position->width;
		rectSourceSprite.top = 0;
		rectSourceSprite.height = obj->position->height;
		sprites[obj->TYPE]->setTextureRect(rectSourceSprite);
		sprites[obj->TYPE]->setPosition(SCALE_X * obj->position->x, SCALE_Y * obj->position->y);
		window->draw(*sprites[obj->TYPE]);
	}

}
void View::loop()
{
	char actions[2] = { 0b00000000, 0b00000000 };
	actions[0] |= sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ? GO_FORWARD : 0;
	actions[0] |= sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ? GO_BACKWARD : 0;
	actions[0] |= sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ? GO_LEFT : 0;
	actions[0] |= sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ? GO_RIGHT : 0;
	actions[1] |= sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? GO_FORWARD : 0;
	actions[1] |= sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? GO_BACKWARD : 0;
	actions[1] |= sf::Keyboard::isKeyPressed(sf::Keyboard::A) ? GO_LEFT : 0;
	actions[1] |= sf::Keyboard::isKeyPressed(sf::Keyboard::D) ? GO_RIGHT : 0;
	map->tick(actions);
	window->draw(backgroundSprite);
	for (int i = 0; i < map->objCount; i++)
	{
		drawGameObject(map->positions[i]);
	}

}
