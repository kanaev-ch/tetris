#include <iostream>
#include "Game.h"

static float TIME(sf::Clock& c_)//func for binding to time
{
	float time = static_cast<float>(c_.getElapsedTime().asMicroseconds());
	c_.restart();
	time /= 800;
	return time;
}

static Figure * RAND_CHOOSE_FIGURE()//func randomly choose type of figure
{
	srand((unsigned)time(NULL)); rand(); rand();
	Figure* p = NULL;
	int r = rand() % 7 + 1;
	switch (r)
	{
	case 1: p = new Figure(Figure::L, 260, 60); break;
	case 2: p = new Figure(Figure::l, 260, 60); break;
	case 3: p = new Figure(Figure::O, 260, 60); break;
	case 4: p = new Figure(Figure::z, 260, 10); break;
	case 5: p = new Figure(Figure::T, 260, 60); break;
	case 6: p = new Figure(Figure::s, 260, 60); break;
	case 7: p = new Figure(Figure::J, 260, 60); break;
	}
	return p;
}

//func for draw main rects in menu and game, it calls from game func and menu func
void DRAW_MAIN_RECT(sf::RenderWindow& window_, sf::RectangleShape& main_rect_, float x_, float y_)
{
	main_rect_.setFillColor(sf::Color::White);
	main_rect_.setPosition(x_, y_);
	window_.draw(main_rect_);
}

//main game func
int game(sf::RenderWindow& window_, sf::RectangleShape& main_rect_left_, sf::RectangleShape& main_rect_right_, Score & score_)
{
	FL = false;//be sure to reset the flag!!! Figure must not be alive in beginning of GAME!!!
	SCORES = 0;//reset the Scores in beginning of the Game
	sf::Clock clock;

/*	Shape* shape[2];
	shape[0] = new Cube(200, 10);
	shape[1] = new Cube(300, 10);*/

//	Figure figure(Figure::gstick);
//	Figure* f = new Figure(Figure::gstick);
	Figure* f = NULL;//pointer because each cycle create new obj of Figure from heap, FL is live or delete this pointer
	Figure* fn = RAND_CHOOSE_FIGURE();//pointer for next figure, it will be random
	fn->MOVE(350, 50, 1);//move next figure to right window
	FloorArray floor_array;
	float temp_speed = 0;//var for temp speed, it init by global SPEED_FDOWN

	while (window_.isOpen())
	{
		float time = TIME(clock);//var for binding to time, func TIME must execute ONLY in cycle which is drawing
	
		if (!FL)
		{
//			f = new Figure(Figure::L, 260, 60);
//			f = new Figure(Figure::l, 260, 60);
//			f = new Figure(Figure::O, 260, 60);
//			f = new Figure(Figure::z, 260, 10);
//			f = new Figure(Figure::T, 260, 60);
//			f = new Figure(Figure::s, 260, 60);
//			f = new Figure(Figure::J, 260, 60);
//			f = new Figure(1, 260, 60);
//			f = RAND_CHOOSE_FIGURE();
			
//			SPEED_FDOWN = .05f;
			temp_speed = SPEED_FDOWN;
			FL = true;

			f = fn;//create new figure from next figure by copy
			f->MOVE(-350, -50, 1);//move it to start position
			fn = RAND_CHOOSE_FIGURE();//create new next position
			fn->MOVE(350, 50, 1);//move it to right window
		}

		sf::Event event;
		while (window_.pollEvent(event))
		{
			window_.setKeyRepeatEnabled(false);
			if (event.type == sf::Event::Closed)
				window_.close();

			//Block of moving to the left-right only at 50 px by releasing key
			//It must be in while Event cycle for one-time exec, round in Cube::MOVE
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (FL) floor_array.MOVE_LEFT_AND_COLLISION(*f, -50.f, 0, time);//func move figure to the left and collision with edges and cross bottom figures
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (FL) floor_array.MOVE_RIGHT_AND_COLLISION(*f, 50.f, 0, time);//func move figure to the right and collision with edges and cross bottom figures
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
//				SPEED_FDOWN = 1.f;
				temp_speed = 1.f;
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Down)
				{
//					SPEED_FDOWN = .05f;
					temp_speed = SPEED_FDOWN;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (FL) floor_array.ROTATE(*f);
			}
		}

		if (FL)
		{
//			f->MOVE_DOWN(0, SPEED_FDOWN, time);//figure move down
			f->MOVE_DOWN(0, temp_speed, time);//figure move down
			
			//collision of figures whith bottom array, exit game if return 1, it means overload bottom array, delete shape array from heap in destructor of FloorArray
			if (floor_array.BOTTOM_COLLISION(*f) == 1)
			{
				delete f; delete fn;//clear HEAP of Figures
				return 1;
			}
		}

		if (!FL) floor_array.MARK_FOR_DEL_LINES();
		if (LINES_FOR_DEL) floor_array.DEL_LINES();//Inside is LINES_FOR_DEL = 0;//discharge to default num of global lines for delete

/*		for (int i = 0; i < sizeof(shape) / sizeof(shape[0]); i++)
			shape[i]->MOVE(0, 0.1f, time);*/

		window_.clear();
		
		DRAW_MAIN_RECT(window_, main_rect_left_, WB, WB);//func for draw main left rect in game
		DRAW_MAIN_RECT(window_, main_rect_right_, WML + WB*2, WB);//func for draw main right rect in game

/*		for (int i = 0; i < sizeof(shape) / sizeof(shape[0]); i++)
			shape[i]->DRAW(window_);*/

		if (FL)
		{
			f->DRAW(window_);
			fn->DRAW(window_);
		}

		if (!FL) delete f;

		floor_array.DRAW(window_);

//		score_.DRAW(window_);
		score_.DRAW_NEXT_FIG_STR(window_, 550, 20);
		score_.DRAW_SCORE(window_, 550, 260);

		window_.display();

//		std::cout << fn->type << std::endl;
//		std::cout << floor_array.SZ() << std::endl;
//		std::cout << SCORES << std::endl;
//		std::cout << SPEED_FDOWN << " " << SCORES << std::endl;
	}

/*	for (int i = 0; i < sizeof(shape) / sizeof(shape[0]); i++)
		delete shape[i];*/
	if (FL) delete f;
	if (FL) delete fn;

	return 0;
}
