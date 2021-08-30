#include "FloorArray.h"



FloorArray::FloorArray()
	:sz(10)//Create default bottom arr of 10 elements
{
	shape = new Cube[sz];//from heap
	for (size_t i = 0; i < sz; i++)
	{
		shape[i] = Cube(float(i) * 1 * 50+10, H-WB-50);
	}
}


FloorArray::~FloorArray()
{
	delete[]shape;//free heap
}

//void FloorArray::COLLISION(Figure * f_)
void FloorArray::BOTTOM_COLLISION(Figure & f_)//func collision of Figures cubes and bottom Cubes
{
	size_t old_sz = sz;//save temp old size arr
	for (size_t i = 0; i < old_sz; i++)
	{
		if (sz >= 160) exit(0);//Temporary PLUG for exit if array of CUBEs overload, means this cycle (of move down figure) is infinity
		if ( f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().X() == shape[i].X() ||
			 f_.CUBE2().Y() + 50 >= shape[i].Y() && f_.CUBE2().X() == shape[i].X() ||
			 f_.CUBE3().Y() + 50 >= shape[i].Y() && f_.CUBE3().X() == shape[i].X() ||
			 f_.CUBE4().Y() + 50 >= shape[i].Y() && f_.CUBE4().X() == shape[i].X() )
		{
			FL = false;//Figure not live
			sz += 4;//increase arr size
			Cube* p = new Cube[sz];//create new arr from heap
			for (size_t j = 0; j < old_sz; j++)//copy from old to new arr
			{
				p[j] = shape[j];
			}

			//add last figure to bottom arr
			p[sz - 4] = f_.CUBE1();
			p[sz - 3] = f_.CUBE2();
			p[sz - 2] = f_.CUBE3();
			p[sz - 1] = f_.CUBE4();

			//round Y in bottom arr, rounding by X is inside cube.MOVE, DIV and MULT int count by 10 needs for round by 10
			p[sz - 4].X(f_.CUBE1().X()); p[sz - 4].Y(float(int(f_.CUBE1().Y()) / 10 * 10));
			p[sz - 3].X(f_.CUBE2().X()); p[sz - 3].Y(float(int(f_.CUBE2().Y()) / 10 * 10));
			p[sz - 2].X(f_.CUBE3().X()); p[sz - 2].Y(float(int(f_.CUBE3().Y()) / 10 * 10));
			p[sz - 1].X(f_.CUBE4().X()); p[sz - 1].Y(float(int(f_.CUBE4().Y()) / 10 * 10));

			delete[]shape;//free heap from old arr
			shape = p;//init new increased arr

/*			std::cout << shape[sz - 4].Y() << " ";
			std::cout << shape[sz - 3].Y() << " ";
			std::cout << shape[sz - 2].Y() << " ";
			std::cout << shape[sz - 1].Y() << std::endl;*/

			break;
		}
	}
}

void FloorArray::MOVE_LEFT_AND_COLLISION(Figure& f_, float x_, float y_, float time_)//func move figure to the left and collision with edges and cross bottom figures
{
	float x = x_;
	if (f_.CUBE1().X() <= WB || f_.CUBE2().X() <= WB || f_.CUBE3().X() <= WB || f_.CUBE4().X() <= WB)//if cross left edge
	{
		x = 0;//STOP move if cross, x isn't coord it is OFFSET
		std::cout << "!!!xxx!!!" << sz << std::endl;
	}
	for (size_t i = 0; i < sz; i++)
	{
		//block of check of crossing figure with every bottom array member, and don't cross if
		if (f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().X() == shape[i].X() + 50 ||
			f_.CUBE2().Y() + 50 >= shape[i].Y() && f_.CUBE2().X() == shape[i].X() + 50 ||
			f_.CUBE3().Y() + 50 >= shape[i].Y() && f_.CUBE3().X() == shape[i].X() + 50 ||
			f_.CUBE4().Y() + 50 >= shape[i].Y() && f_.CUBE4().X() == shape[i].X() + 50)
		{
			std::cout << "!!!xxx!!!" << sz << std::endl;
			x = 0;//STOP move if cross, x isn't coord it is OFFSET
		}
	}
	f_.CUBE1().MOVE(x, y_, time_);
	f_.CUBE2().MOVE(x, y_, time_);
	f_.CUBE3().MOVE(x, y_, time_);
	f_.CUBE4().MOVE(x, y_, time_);
}

void FloorArray::MOVE_RIGHT_AND_COLLISION(Figure& f_, float x_, float y_, float time_)//func move figure to the right and collision with edges and cross bottom figures
{
	float x = x_;
	if (f_.CUBE1().X() + 50 >= WML + WB || f_.CUBE2().X() + 50 >= WML + WB || f_.CUBE3().X() + 50 >= WML + WB || f_.CUBE4().X() + 50 >= WML + WB)//if cross right edge
	{
		x = 0;//STOP move if cross, x isn't coord it is OFFSET
		std::cout << "!!!xxx!!!" << sz << std::endl;
	}
	for (size_t i = 0; i < sz; i++)
	{
		//block of check of crossing figure with every bottom array member, and don't cross if
		if (f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().X() + 50 == shape[i].X() ||
			f_.CUBE2().Y() + 50 >= shape[i].Y() && f_.CUBE2().X() + 50 == shape[i].X() ||
			f_.CUBE3().Y() + 50 >= shape[i].Y() && f_.CUBE3().X() + 50 == shape[i].X() ||
			f_.CUBE4().Y() + 50 >= shape[i].Y() && f_.CUBE4().X() + 50 == shape[i].X())
		{
			std::cout << "!!!xxx!!!" << sz << std::endl;
			x = 0;//STOP move if cross, x isn't coord it is OFFSET
		}
	}
	f_.CUBE1().MOVE(x, y_, time_);
	f_.CUBE2().MOVE(x, y_, time_);
	f_.CUBE3().MOVE(x, y_, time_);
	f_.CUBE4().MOVE(x, y_, time_);
}

void FloorArray::DRAW(sf::RenderWindow & window_)const//draw arr of bottom Cubes
{
//	if (sz)
//	{
		for (size_t i = 0; i < sz; i++)
			shape[i].DRAW(window_);
		std::cout << shape[sz - 4].Y() << " ";
		std::cout << shape[sz - 3].Y() << " ";
		std::cout << shape[sz - 2].Y() << " ";
		std::cout << shape[sz - 1].Y() << std::endl;
//	}
}
