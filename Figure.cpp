#include "Figure.h"



/*Figure::Figure()
{
}*/

Figure::Figure(const Type & t_, float x_, float y_)
	:type(t_), x(x_), y(y_), position(up)
//Figure::Figure(int t_, float x_, float y_)
//	:type(t_), x(x_), y(y_)
{
	if (t_ == gstick)
	{
		cube2 = Cube(x, y - 50);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x + 50, y + 50);
	}
	if (t_ == stick)
	{
		cube2 = Cube(x, y - 50);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x, y + 100);
	}
	if (t_ == cube)
	{
		cube2 = Cube(x, y - 50);
		cube1 = Cube(x, y);
		cube3 = Cube(x + 50, y - 50);
		cube4 = Cube(x + 50, y);
	}
	if (t_ == zz)
	{
		cube2 = Cube(x - 50, y);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x + 50, y + 50);
	}
	if (t_ == t)
	{
		cube2 = Cube(x - 50, y);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y - 50);
		cube4 = Cube(x + 50, y);
	}
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

void Figure::ROTATE()//func of simple rotate figures without check collision with edges and bottom array, this functional in FloorArray::ROTATE and it calls this func after check
{
	//Block of rotate gstick
	if (type == gstick && position == up)
	{
		cube2.MOVE(-50, 50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(0, -100, 1);
		position = left;
	}
	else if (type == gstick && position == left)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(-50, -50, 1);
		cube4.MOVE(-100, 0, 1);
		position = down;
	}
	else if (type == gstick && position == down)
	{
		cube2.MOVE(50, -50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(0, 100, 1);
		position = right;
	}
	else if (type == gstick && position == right)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(50, 50, 1);
		cube4.MOVE(100, 0, 1);
		position = up;
	}
	//Block of rotate stick
	if (type == stick && position == up)
	{
		cube2.MOVE(-50, 50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(100, -100, 1);
		position = left;
	}
	else if (type == stick && position == left)
	{
		cube2.MOVE(50, -50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(-100, 100, 1);
		position = up;
	}
	//Block of rotate zz
	if (type == zz && position == up)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(0, -100, 1);
		position = left;
	}
	else if (type == zz && position == left)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(0, 100, 1);
		position = up;
	}
	//Block of rotate T
	if (type == t && position == up)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(-50, -50, 1);
		position = left;
	}
	else if (type == t && position == left)
	{
		cube2.MOVE(50, -50, 1);
		cube3.MOVE(50, 50, 1);
		cube4.MOVE(-50, 50, 1);
		position = down;
	}
	else if (type == t && position == down)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(50, 50, 1);
		position = right;
	}
	else if (type == t && position == right)
	{
		cube2.MOVE(-50, 50, 1);
		cube3.MOVE(-50, -50, 1);
		cube4.MOVE(50, -50, 1);
		position = up;
	}

//	std::cout << cube1.X() << " " << cube2.X() << " " << cube3.X() << " " << cube4.X() << std::endl;
}

void Figure::MOVE_DOWN(float x_, float y_, float time_)//figures falls down 
{
	cube1.MOVE(x_, y_, time_);
	cube2.MOVE(x_, y_, time_);
	cube3.MOVE(x_, y_, time_);
	cube4.MOVE(x_, y_, time_);
}