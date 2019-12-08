#include "StartMenu.h"
StartMenu::StartMenu()
{
	
}
void StartMenu::startApp()
{
	this->game = new View();
	sf::RenderWindow window(sf::VideoMode{ 200, 200 }, "My window");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// check the type of the event...
			switch (event.type)
			{
				// window closed
			case sf::Event::Closed:
				window.close();
				delete this;
				break;

				// key pressed
			case sf::Event::KeyPressed:
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					startGame();
					break;
				}
				break;

				// we don't process other types of events
			default:
				break;
			}
		}
	}
	
}
void StartMenu::startGame()
{
	game->start();
}