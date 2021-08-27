#include <iostream>
#include "Game.h"

static float TIME(sf::Clock& c_)//func for binding to time
{
	float time = static_cast<float>(c_.getElapsedTime().asMicroseconds());
	c_.restart();
	time /= 800;
	return time;
}

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
	sf::Clock clock;

/*	Shape* shape[2];
	shape[0] = new Cube(200, 10);
	shape[1] = new Cube(300, 10);*/

//	Figure figure(Figure::gstick);
//	Figure* f = new Figure(Figure::gstick);
	Figure* f = NULL;//pointer because each cycle create new obj of Figure from heap, FL is live or delete this pointer
	FloorArray floor_array;

	while (window_.isOpen())
	{
		float time = TIME(clock);//var for binding to time, func TIME must execute ONLY in cycle which is drawing
	
		if (!FL)
		{
			f = new Figure(Figure::gstick, 310, 60);
//			f = new Figure(1, 310, 60);
			FL = true;
		}

		sf::Event event;
		while (window_.pollEvent(event))
		{
			window_.setKeyRepeatEnabled(false);
			if (event.type == sf::Event::Closed)
				window_.close();

			//Block of moving to the left-right only at 50 px by releasing key
			//It must be in while Event cycle for one-time exec, round in Cube::MOVE
/*			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					if (FL) f->MOVE(-20.f, 0, time);//different values, I DON'T KNOW WHY
					std::cout << f->CUBE1().X() << std::endl;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Right)
				{
					if (FL) f->MOVE(40.f, 0, time);//different values, I DON'T KNOW WHY
					std::cout << f->CUBE1().X() << std::endl;
				}
			}*/

			//Block of moving to the left-right only at 50 px by releasing key
			//It must be in while Event cycle for one-time exec, round in Cube::MOVE
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (FL) f->MOVE(-50.f, 0, time);//time not need multiply at dx, because every time different values offset by X
//				std::cout << f->CUBE1().X() << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (FL) f->MOVE(50.f, 0, time);//time not need multiply at dx, because every time different values offset by X
//				std::cout << f->CUBE1().X() << std::endl;
			}
		}

		if (FL) floor_array.COLLISION(*f);

/*		for (int i = 0; i < sizeof(shape) / sizeof(shape[0]); i++)
			shape[i]->MOVE(0, 0.1f, time);*/

		if (FL) f->MOVE(0, 0.3f, time);

//		floor_array.MOVE(0, 0.2f, time);

		window_.clear();
		
		DRAW_MAIN_RECT(window_, main_rect_left_, WB, WB);//func for draw main left rect in game
		DRAW_MAIN_RECT(window_, main_rect_right_, WML + WB*2, WB);//func for draw main right rect in game

/*		for (int i = 0; i < sizeof(shape) / sizeof(shape[0]); i++)
			shape[i]->DRAW(window_);*/

//		if (FL) f->LR_MOVE();

		if (FL) f->DRAW(window_);
		if (!FL) delete f;

		floor_array.DRAW(window_);

		window_.display();

		window_.setKeyRepeatEnabled(false);
	}

/*	for (int i = 0; i < sizeof(shape) / sizeof(shape[0]); i++)
		delete shape[i];*/
	if (FL) delete f;

	return 0;
}
