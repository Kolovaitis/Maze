#include "StartMenu.h"
StartMenu::StartMenu()
{
	canRun = true;
	selectedOption = 0;
}
void StartMenu::startApp()
{
	if (!backgroundTexture.loadFromFile("images/ground.png"))
	{
		printf("Background resoursce is not exist\n");
	}
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(sf::Vector2f{ SCALE_X,SCALE_Y });
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, START_MENU_WIDTH,START_MENU_HEIGHT));
	if(!startGameTexture.loadFromFile("images/start_game.png"))
	{
		printf("Button 'start' not found\n");
	}
	if (!exitTexture.loadFromFile("images/exit.png"))
	{
		printf("Button 'start' not found\n");
	}
	if (!selectTexture.loadFromFile("images/select.png"))
	{
		printf("Button 'start' not found\n");
	}
	
	sf::RenderWindow window(sf::VideoMode{ START_MENU_WIDTH,START_MENU_HEIGHT }, "Maze", sf::Style::None);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();
				
				break;


			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Enter)
				{
					switch(selectedOption)
					{
					case START_GAME:
						if (canRun) {
							startGame();
						}
						break;
					case EXIT:
						window.close();
						
						break;
					}
					
				}
				if (event.key.code == sf::Keyboard::Down|| event.key.code == sf::Keyboard::Up)
				{
					selectedOption = abs(selectedOption-1);
				}

				break;
			
			case sf::Event::LostFocus:
				window.requestFocus();
				break;
			default:
				break;
			}
		}
		window.draw(backgroundSprite);
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			canRun = true;
		}
		if(selectedOption)
		{
			//exit option selected
			buttonSprite.setPosition(BUTTON_X, BUTTON_Y2);
		}else
		{
			//startGame option selected
			buttonSprite.setPosition(BUTTON_X, BUTTON_Y1);
		}
		buttonSprite.setTexture(selectTexture);
		window.draw(buttonSprite);
		buttonSprite.setPosition(BUTTON_X, BUTTON_Y1);
		buttonSprite.setTexture(startGameTexture);
		window.draw(buttonSprite);
		buttonSprite.setPosition(BUTTON_X, BUTTON_Y2);
		buttonSprite.setTexture(exitTexture);
		window.draw(buttonSprite);
		
		window.display();
	}

}
void StartMenu::startGame()
{
	canRun = false;
	this->game = new View();
	game->start();
	delete game;
}