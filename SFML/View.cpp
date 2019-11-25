#include "View.h"
View::View() {
	map = new Map();
	window = new sf::RenderWindow(sf::VideoMode{ map->width*SCALE_X, map->height*SCALE_Y }, "My window");

	window->setFramerateLimit(FRAME_RATE);

	


	//View view(100, 100, &window);
	
	for(int i = 0; i<textureCount;i++)
	{
		textures[i] = new sf::Texture();
		if (!textures[i]->loadFromFile(fileNames[i]))
		{
			printf("Error");
		}
		textures[i]->setRepeated(true);
		sprites[i] = new sf::Sprite(*textures[i], rectSourceSprite);
		sprites[i]->setScale(sf::Vector2f{ SCALE_X,SCALE_Y });
	}
	

	
}
void View::start()
{
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
		
		window->display();
		
		loop();
		
	}
}
View::~View() {
	/*free(window);
	free(shape);*/
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

		rectSourceSprite.left = obj->position->x;
		rectSourceSprite.width = obj->position->width;
		rectSourceSprite.top = obj->position->y;
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
	window->clear(sf::Color::Yellow);
	for (int i = 0; i < map->objCount; i++)
	{
		drawGameObject(map->positions[i]);
	}	 
	
}
