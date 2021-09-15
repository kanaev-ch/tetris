#include "Figure.h"



/*Figure::Figure()
{
}*/

Figure::Figure(const Type & t_, float x_, float y_)
	:type(t_), x(x_), y(y_), position(up)
//Figure::Figure(int t_, float x_, float y_)
//	:type(t_), x(x_), y(y_)
{
	cube_texture.loadFromFile("Tetris.png");
	int x_spr = 0; int y_spr = 0;
	switch (t_)
	{
	case L:	x_spr = 578; y_spr = 331; break;
	case l:	x_spr = 7; y_spr = 160; break;
	case O:	x_spr = 65; y_spr = 8; break;
	case z:	x_spr = 634; y_spr = 130; break;
	case T:	x_spr = 292; y_spr = 182; break;
	case s:	x_spr = 406; y_spr = 331; break;
	case J:	x_spr = 178; y_spr = 274; break;
	}

	//block needs if Cubes have sprites and textures
	if (t_ == L)
	{
		cube2 = Cube(x, y - 50, cube_texture, x_spr, y_spr, t_+1);//t_+1 its mark of sprite color-coords of this cube, because different figures, need if bottom cubes colors-sprites are different
		cube1 = Cube(x, y, cube_texture, x_spr, y_spr, t_+1);
		cube3 = Cube(x, y + 50, cube_texture, x_spr, y_spr, t_+1);
		cube4 = Cube(x + 50, y + 50, cube_texture, x_spr, y_spr, t_+1);
	}
	if (t_ == l)
	{
		cube2 = Cube(x, y - 50, cube_texture, x_spr, y_spr, t_+1);
		cube1 = Cube(x, y, cube_texture, x_spr, y_spr, t_+1);
		cube3 = Cube(x, y + 50, cube_texture, x_spr, y_spr, t_+1);
		cube4 = Cube(x, y + 100, cube_texture, x_spr, y_spr, t_+1);
	}
	if (t_ == O)
	{
		cube2 = Cube(x, y - 50, cube_texture, x_spr, y_spr, t_+1);
		cube1 = Cube(x, y, cube_texture, x_spr, y_spr, t_+1);
		cube3 = Cube(x + 50, y - 50, cube_texture, x_spr, y_spr, t_+1);
		cube4 = Cube(x + 50, y, cube_texture, x_spr, y_spr, t_+1);
	}
	if (t_ == z)
	{
		cube2 = Cube(x - 50, y, cube_texture, x_spr, y_spr, t_+1);
		cube1 = Cube(x, y, cube_texture, x_spr, y_spr, t_+1);
		cube3 = Cube(x, y + 50, cube_texture, x_spr, y_spr, t_+1);
		cube4 = Cube(x + 50, y + 50, cube_texture, x_spr, y_spr, t_+1);
	}
	if (t_ == T)
	{
		cube2 = Cube(x - 50, y, cube_texture, x_spr, y_spr, t_+1);
		cube1 = Cube(x, y, cube_texture, x_spr, y_spr, t_+1);
		cube3 = Cube(x, y - 50, cube_texture, x_spr, y_spr, t_+1);
		cube4 = Cube(x + 50, y, cube_texture, x_spr, y_spr, t_+1);
	}
	if (t_ == s)
	{
		cube2 = Cube(x + 50, y, cube_texture, x_spr, y_spr, t_+1);
		cube1 = Cube(x, y, cube_texture, x_spr, y_spr, t_+1);
		cube3 = Cube(x, y + 50, cube_texture, x_spr, y_spr, t_+1);
		cube4 = Cube(x - 50, y + 50, cube_texture, x_spr, y_spr, t_+1);
	}
	if (t_ == J)
	{
		cube2 = Cube(x, y - 50, cube_texture, x_spr, y_spr, t_+1);
		cube1 = Cube(x, y, cube_texture, x_spr, y_spr, t_+1);
		cube3 = Cube(x, y + 50, cube_texture, x_spr, y_spr, t_+1);
		cube4 = Cube(x - 50, y + 50, cube_texture, x_spr, y_spr, t_+1);
	}

	//block needs if Cubes NO sprites and figures
/*	if (t_ == L)
	{
		cube2 = Cube(x, y - 50);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x + 50, y + 50);
	}
	if (t_ == l)
	{
		cube2 = Cube(x, y - 50);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x, y + 100);
	}
	if (t_ == O)
	{
		cube2 = Cube(x, y - 50);
		cube1 = Cube(x, y);
		cube3 = Cube(x + 50, y - 50);
		cube4 = Cube(x + 50, y);
	}
	if (t_ == z)
	{
		cube2 = Cube(x - 50, y);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x + 50, y + 50);
	}
	if (t_ == T)
	{
		cube2 = Cube(x - 50, y);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y - 50);
		cube4 = Cube(x + 50, y);
	}
	if (t_ == s)
	{
		cube2 = Cube(x + 50, y);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x - 50, y + 50);
	}
	if (t_ == J)
	{
		cube2 = Cube(x, y - 50);
		cube1 = Cube(x, y);
		cube3 = Cube(x, y + 50);
		cube4 = Cube(x - 50, y + 50);
	}*/
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

void Figure::MOVE(float x_, float y_, float time_)
{
	cube1.MOVE(x_, y_, time_);
	cube2.MOVE(x_, y_, time_);
	cube3.MOVE(x_, y_, time_);
	cube4.MOVE(x_, y_, time_);
}

void Figure::ROTATE()//func of simple rotate figures without check collision with edges and bottom array, this functional in FloorArray::ROTATE and it calls this func after check
{
	//Block of rotate L
	if (type == L && position == up)
	{
		cube2.MOVE(-50, 50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(0, -100, 1);
		position = left;
	}
	else if (type == L && position == left)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(-50, -50, 1);
		cube4.MOVE(-100, 0, 1);
		position = down;
	}
	else if (type == L && position == down)
	{
		cube2.MOVE(50, -50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(0, 100, 1);
		position = right;
	}
	else if (type == L && position == right)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(50, 50, 1);
		cube4.MOVE(100, 0, 1);
		position = up;
	}
	//Block of rotate l
	if (type == l && position == up)
	{
		cube2.MOVE(-50, 50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(100, -100, 1);
		position = left;
	}
	else if (type == l && position == left)
	{
		cube2.MOVE(50, -50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(-100, 100, 1);
		position = up;
	}
	//Block of rotate z
	if (type == z && position == up)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(0, -100, 1);
		position = left;
	}
	else if (type == z && position == left)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(0, 100, 1);
		position = up;
	}
	//Block of rotate T
	if (type == T && position == up)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(-50, -50, 1);
		position = left;
	}
	else if (type == T && position == left)
	{
		cube2.MOVE(50, -50, 1);
		cube3.MOVE(50, 50, 1);
		cube4.MOVE(-50, 50, 1);
		position = down;
	}
	else if (type == T && position == down)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(50, 50, 1);
		position = right;
	}
	else if (type == T && position == right)
	{
		cube2.MOVE(-50, 50, 1);
		cube3.MOVE(-50, -50, 1);
		cube4.MOVE(50, -50, 1);
		position = up;
	}
	//Block of rotate s
	if (type == s && position == up)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(100, 0, 1);
		position = left;
	}
	else if (type == s && position == left)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(-100, 0, 1);
		position = up;
	}
	//Block of rotate J
	if (type == J && position == up)
	{
		cube2.MOVE(-50, 50, 1);
		cube3.MOVE(50, -50, 1);
		cube4.MOVE(100, 0, 1);
		position = left;
	}
	else if (type == J && position == left)
	{
		cube2.MOVE(50, 50, 1);
		cube3.MOVE(-50, -50, 1);
		cube4.MOVE(0, -100, 1);
		position = down;
	}
	else if (type == J && position == down)
	{
		cube2.MOVE(50, -50, 1);
		cube3.MOVE(-50, 50, 1);
		cube4.MOVE(-100, 0, 1);
		position = right;
	}
	else if (type == J && position == right)
	{
		cube2.MOVE(-50, -50, 1);
		cube3.MOVE(50, 50, 1);
		cube4.MOVE(0, 100, 1);
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