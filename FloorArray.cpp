#include "FloorArray.h"



FloorArray::FloorArray()
	:sz(0)
{
//	size_t s = 100;
	
//	p[0] = new Figure(Figure::gstick, 10, 60);
//	p[1] = new Figure(Figure::gstick, 110, 60);
//	p[2] = new Figure(Figure::gstick, 210, 60);
/*	Figure* p = new Figure[10];
	p[0] = Figure(1, 10, 60);
	p[1] = Figure(1, 110, 60);
	p[2] = Figure(1, 210, 60);
	shape = p;*/
}


FloorArray::~FloorArray()
{
//	delete[]shape;
}

//void FloorArray::COLLISION(Figure * f_)
void FloorArray::COLLISION(Figure & f_)
{
//	if (f_->CUBE1().Y() > 760 || f_->CUBE2().Y() > 760 || f_->CUBE3().Y() > 760 || f_->CUBE4().Y() > 760)
//	if (f_.CUBE1().Y() > 760 || f_.CUBE2().Y() > 760 || f_.CUBE3().Y() > 760 || f_.CUBE4().Y() > 760)
/*	if (f_.CUBE1().Y() > 760 || f_.CUBE2().Y() > 760 || f_.CUBE3().Y() > 760 || f_.CUBE4().Y() > 760)
	{
		FL = false;
//		++sz;
//		shape[sz - 1] = f_;
		sz += 4;
		shape[sz - 4] = f_.CUBE1();
		shape[sz - 3] = f_.CUBE2();
		shape[sz - 2] = f_.CUBE3();
		shape[sz - 1] = f_.CUBE4();

		std::cout << sz << std::endl;*/

/*		if (!sz)
		{
			++sz;
			shape = new Figure[sz];
			shape[sz - 1] = f_;
		}
		else {
			++sz;
			Figure * p = new Figure[sz];
			for (int i = 0; i < sz - 1; i++)
			{
				p[i] = shape[i];
//				delete []shape;
			}
			delete[]shape;
			shape = new Figure[sz];
			shape = p;
			shape[sz] = f_;
			delete[]p;
		}*/
//	for (int i = 0; i < sz; i++)
	for (int i = 0; i < sz; i++)
	{
		if (sz >= 100) exit(0);//Temporary PLUG for exit if array of CUBEs overload, means next IF cycle (of move down figure) is infinity
		if (f_.CUBE1().Y() + 50 > shape[i].Y() || f_.CUBE2().Y() + 50 > shape[i].Y() || f_.CUBE3().Y() + 50 > shape[i].Y() || f_.CUBE4().Y() + 50 > shape[i].Y())
		{
			FL = false;
			sz += 4;
			shape[sz - 4] = f_.CUBE1();
			shape[sz - 3] = f_.CUBE2();
			shape[sz - 2] = f_.CUBE3();
			shape[sz - 1] = f_.CUBE4();

			std::cout << sz << std::endl;
			break;
		}
//		std::cout << i << std::endl;
//		std::cout << shape[i].Y() << std::endl;
//		std::cout << shape[sz-1].Y() << std::endl;
	}
	if (f_.CUBE1().Y() > 760 || f_.CUBE2().Y() > 760 || f_.CUBE3().Y() > 760 || f_.CUBE4().Y() > 760)
	{
		FL = false;
		sz += 4;
		shape[sz - 4] = f_.CUBE1();
		shape[sz - 3] = f_.CUBE2();
		shape[sz - 2] = f_.CUBE3();
		shape[sz - 1] = f_.CUBE4();

		std::cout << sz << std::endl;
	}
}

void FloorArray::DRAW(sf::RenderWindow & window_)const
{
	if (sz)
	{
//		shape[0].DRAW(window_);
		for (int i = 0; i < sz; i++)
			shape[i].DRAW(window_);
	}
}

/*void FloorArray::MOVE(float x_, float y_, float time_)
{
	for (int i = 0; i < 3; i++)
		shape[i].MOVE(x_, y_, time_);
}*/