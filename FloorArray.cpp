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
void FloorArray::COLLISION(Figure & f_)//func collision of Figures cubes and bottom Cubes
{
	size_t old_sz = sz;//save temp old size arr
	for (size_t i = 0; i < old_sz; i++)
	{
		if (sz >= 160) exit(0);//Temporary PLUG for exit if array of CUBEs overload, means this cycle (of move down figure) is infinity
		if ( f_.CUBE1().Y() + 50 > shape[i].Y() && f_.CUBE1().X() == shape[i].X() ||
			 f_.CUBE2().Y() + 50 > shape[i].Y() && f_.CUBE2().X() == shape[i].X() ||
			 f_.CUBE3().Y() + 50 > shape[i].Y() && f_.CUBE3().X() == shape[i].X() ||
			 f_.CUBE4().Y() + 50 > shape[i].Y() && f_.CUBE4().X() == shape[i].X() )
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

			//round X Y in bottom arr
			p[sz - 4].X(float(int(f_.CUBE1().X()))); p[sz - 4].Y(float(int(f_.CUBE1().Y())));
			p[sz - 3].X(float(int(f_.CUBE2().X()))); p[sz - 3].Y(float(int(f_.CUBE2().Y())));
			p[sz - 2].X(float(int(f_.CUBE3().X()))); p[sz - 2].Y(float(int(f_.CUBE3().Y())));
			p[sz - 1].X(float(int(f_.CUBE4().X()))); p[sz - 1].Y(float(int(f_.CUBE4().Y())));

			delete[]shape;//free heap from old arr
			shape = p;//init new increased arr


//			std::cout << sz << std::endl;
			std::cout << i << " " << shape[i].X() << " " << shape[i].Y() << std::endl;
			break;
		}
//		std::cout << f_.CUBE1().X() << " " << shape[i].X() << std::endl;
	}
}

void FloorArray::DRAW(sf::RenderWindow & window_)const//draw arr of bottom Cubes
{
	if (sz)
	{
		for (size_t i = 0; i < sz; i++)
			shape[i].DRAW(window_);
	}
}
