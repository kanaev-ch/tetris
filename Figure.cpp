#include "Figure.h"



/*Figure::Figure()
{
}*/

Figure::Figure(const Type & t_, float x_, float y_)
	:type(t_), x(x_), y(y_)
//Figure::Figure(int t_, float x_, float y_)
//	:type(t_), x(x_), y(y_)
{
	cube2 = Cube(x, y - 50);
	cube1 = Cube(x, y);
	cube3 = Cube(x, y + 50);
	cube4 = Cube(x + 50, y + 50);
}

Figure::~Figure()
{
}

Cube & Figure::CUBE1()
{
	return cube1;
}

Cube & Figure::CUBE2()
{
	return cube2;
}

Cube & Figure::CUBE3()
{
	return cube3;
}

Cube & Figure::CUBE4()
{
	return cube4;
}

void Figure::DRAW(sf::RenderWindow & window_)const
{
	cube1.DRAW(window_);
	cube2.DRAW(window_);
	cube3.DRAW(window_);
	cube4.DRAW(window_);
}

/*void Figure::MOVE(float x_, float y_, float time_)
{
	cube1.MOVE(x, y, time_);
	cube2.MOVE(x, y, time_);
	cube3.MOVE(x, y, time_);
	cube4.MOVE(x, y, time_);
}*/

void Figure::MOVE_DOWN(float x_, float y_, float time_)//figures falls down 
{
	cube1.MOVE(x_, y_, time_);
	cube2.MOVE(x_, y_, time_);
	cube3.MOVE(x_, y_, time_);
	cube4.MOVE(x_, y_, time_);
}