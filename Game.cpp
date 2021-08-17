#include <iostream>
#include "Game.h"

//func for draw main rects in menu and game, it calls from game func and menu func
void DRAW_MAIN_RECT(sf::RenderWindow& window_, sf::RectangleShape& main_rect_, float x_, float y_)
{
	main_rect_.setFillColor(sf::Color::White);
	main_rect_.setPosition(x_, y_);
	window_.draw(main_rect_);
}

//main game func
int game(sf::RenderWindow& window_, sf::RectangleShape& main_rect_left_, sf::RectangleShape& main_rect_right_)
{
	Cube cube(200, 10);

	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
		}

		cube.MOVE(0, 0.1f);

		window_.clear();
		
		DRAW_MAIN_RECT(window_, main_rect_left_, 10, 10);//func for draw main left rect in game
		DRAW_MAIN_RECT(window_, main_rect_right_, 520, 10);//func for draw main right rect in game

		cube.DRAW(window_);

		window_.display();
	}

	return 0;
}
