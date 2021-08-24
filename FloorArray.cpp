#include "FloorArray.h"



FloorArray::FloorArray()
	:sz(100)
{
//	size_t s = 100;
	Figure* p = new Figure[10];
//	p[0] = new Figure(Figure::gstick, 10, 60);
//	p[1] = new Figure(Figure::gstick, 110, 60);
//	p[2] = new Figure(Figure::gstick, 210, 60);
	p[0] = Figure(1, 10, 60);
	p[1] = Figure(1, 110, 60);
	p[2] = Figure(1, 210, 60);

	shape = p;
}


FloorArray::~FloorArray()
{
	delete[]shape;
}

void FloorArray::COLLISION(Figure * f_)
{
	if (f_->CUBE1().Y() > 760 || f_->CUBE2().Y() > 760 || f_->CUBE3().Y() > 760 || f_->CUBE4().Y() > 760)
	{
		FL = false;
	}
	
}

void FloorArray::DRAW(sf::RenderWindow & window_)const
{
	shape[0].DRAW(window_);
	shape[1].DRAW(window_);
	shape[2].DRAW(window_);
}

void FloorArray::MOVE(float x_, float y_, float time_)
{
	for (int i = 0; i < 3; i++)
		shape[i].MOVE(x_, y_, time_);
}