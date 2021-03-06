#include "Menu.h"
#include "Game.h"
#include "Score.h"

int MENU(sf::RenderWindow & window_)//func of main menu, game calls inside
{
	Menu menu;//create obj of Menu

	sf::RectangleShape main_rect_left(sf::Vector2f(WML, HML));//create obj of left rect big for main window
	sf::RectangleShape main_rect_right(sf::Vector2f(WMR, HMR));//create obj of right small rect for main window

	Score score;

	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				menu.FLAG_MENU( menu.FLAG_MENU() - 1 );
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				menu.FLAG_MENU( menu.FLAG_MENU() + 1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && menu.FLAG_MENU() == 1)
			{
				game(window_, main_rect_left, main_rect_right, score);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && menu.FLAG_MENU() == 2)
			{
				return 0;
			}
		}

		window_.clear();
		score.DRAW_SCORE(window_, 100, 100);

		menu.CHK_MENU_CLR();
		menu.DRAW(window_, 200, 200);
//		if (game(window_, main_rect_left, main_rect_right, score)) return 0;//call game func from menu

		window_.display();
	}
	return 0;
}