#include "Menu.h"
#include "Game.h"


int MENU(sf::RenderWindow & window_)//func of main menu, game calls inside
{
	Menu menu;//create obj of Menu

	sf::RectangleShape main_rect_left(sf::Vector2f(WML, HML));//create obj of left rect big for main window
	sf::RectangleShape main_rect_right(sf::Vector2f(WMR, HMR));//create obj of right small rect for main window

	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
		}

		window_.clear();

		game(window_, main_rect_left, main_rect_right);//call game func from menu

		window_.display();
	}
	return 0;
}