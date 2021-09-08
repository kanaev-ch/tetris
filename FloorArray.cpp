#include "FloorArray.h"



FloorArray::FloorArray()
	:sz(10)//Create default bottom arr of 10 elements
{
	shape = new Cube[sz];//from heap
	for (size_t i = 0; i < sz; i++)
	{
//		shape[i] = Cube(float(i) * 1 * 50+10, H-WB-50);
		shape[i] = Cube(float(i) * 1 * 50+10, float(H));
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
		if ( f_.CUBE1().Y() + 50 > shape[i].Y() && f_.CUBE1().Y() < shape[i].Y() + 50 && f_.CUBE1().X() == shape[i].X() ||
			 f_.CUBE2().Y() + 50 > shape[i].Y() && f_.CUBE2().Y() < shape[i].Y() + 50 && f_.CUBE2().X() == shape[i].X() ||
			 f_.CUBE3().Y() + 50 > shape[i].Y() && f_.CUBE3().Y() < shape[i].Y() + 50 && f_.CUBE3().X() == shape[i].X() ||
			 f_.CUBE4().Y() + 50 > shape[i].Y() && f_.CUBE4().Y() < shape[i].Y() + 50 && f_.CUBE4().X() == shape[i].X() )
		{
//			FL = false;//Figure not live
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
			p[sz - 4].X(f_.CUBE1().X()); p[sz - 4].Y(float(int(f_.CUBE1().Y()) / 50 * 50 + 10));
			p[sz - 3].X(f_.CUBE2().X()); p[sz - 3].Y(float(int(f_.CUBE2().Y()) / 50 * 50 + 10));
			p[sz - 2].X(f_.CUBE3().X()); p[sz - 2].Y(float(int(f_.CUBE3().Y()) / 50 * 50 + 10));
			p[sz - 1].X(f_.CUBE4().X()); p[sz - 1].Y(float(int(f_.CUBE4().Y()) / 50 * 50 + 10));

			delete[]shape;//free heap from old arr
			shape = p;//init new increased arr

			//block of func for disable bug when last figure drop on floor and need fixate ROUNDED last coords of it for right drawing
			//necessarily before draw cube, its rect NEED TO BE rect_cube.setPosition, or last setPosition is in DRAW func and there is a bug
			shape[sz - 4].SETPOSITION(p[sz - 4].X(), p[sz - 4].Y());
			shape[sz - 3].SETPOSITION(p[sz - 3].X(), p[sz - 3].Y());
			shape[sz - 2].SETPOSITION(p[sz - 2].X(), p[sz - 2].Y());
			shape[sz - 1].SETPOSITION(p[sz - 1].X(), p[sz - 1].Y());

			FL = false;//Figure not live

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
		if (f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() < shape[i].Y() + 50 && f_.CUBE1().X() == shape[i].X() + 50 ||
			f_.CUBE2().Y() + 50 >= shape[i].Y() && f_.CUBE2().Y() < shape[i].Y() + 50 && f_.CUBE2().X() == shape[i].X() + 50 ||
			f_.CUBE3().Y() + 50 >= shape[i].Y() && f_.CUBE3().Y() < shape[i].Y() + 50 && f_.CUBE3().X() == shape[i].X() + 50 ||
			f_.CUBE4().Y() + 50 >= shape[i].Y() && f_.CUBE4().Y() < shape[i].Y() + 50 && f_.CUBE4().X() == shape[i].X() + 50)
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
		if (f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() < shape[i].Y() + 50 && f_.CUBE1().X() + 50 == shape[i].X() ||
			f_.CUBE2().Y() + 50 >= shape[i].Y() && f_.CUBE2().Y() < shape[i].Y() + 50 && f_.CUBE2().X() + 50 == shape[i].X() ||
			f_.CUBE3().Y() + 50 >= shape[i].Y() && f_.CUBE3().Y() < shape[i].Y() + 50 && f_.CUBE3().X() + 50 == shape[i].X() ||
			f_.CUBE4().Y() + 50 >= shape[i].Y() && f_.CUBE4().Y() < shape[i].Y() + 50 && f_.CUBE4().X() + 50 == shape[i].X())
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

void FloorArray::MARK_LINE(int & n, int line_num)//func for mark 10 same elements when it founded
{
	if (n == 10)
	{
		n = 0;
		LINES_FOR_DEL++;//increment count of same lines
		for (size_t i = 10; i < sz; i++)//chk arr from begin to last founded element and mark elements of line_num
		{
			if (shape[i].Y() == line_num)
				shape[i].SAME(true);
		}
	}
}

void FloorArray::MARK_FOR_DEL_LINES()//func chk all lines and mark them for remove if in line are 10 same Cubes
{
	int n760 = 0; int n710 = 0; int n660 = 0; int n610 = 0;	int n560 = 0; int n510 = 0;	int n460 = 0; int n410 = 0;
	int n360 = 0; int n310 = 0;	int n260 = 0; int n210 = 0;	int n160 = 0; int n110 = 0;	int n60 = 0;//counters for chk if inline Cubes are 10
	for (size_t i = 10; i < sz; i++)//chk floor arr if inline are 10 same elements
	{
		//Block of increment this vars
		if (shape[i].Y() == 760) n760++;
		if (shape[i].Y() == 710) n710++;
		if (shape[i].Y() == 660) n660++;
		if (shape[i].Y() == 610) n610++;
		if (shape[i].Y() == 560) n560++;
		if (shape[i].Y() == 510) n510++;
		if (shape[i].Y() == 460) n460++;
		if (shape[i].Y() == 410) n410++;
		if (shape[i].Y() == 360) n360++;
		if (shape[i].Y() == 310) n310++;
		if (shape[i].Y() == 260) n260++;
		if (shape[i].Y() == 210) n210++;
		if (shape[i].Y() == 160) n160++;
		if (shape[i].Y() == 110) n110++;
		if (shape[i].Y() == 60) n60++;
		//Block of mark if elements inline are 10
		if (n760 == 10)	MARK_LINE(n760, 760);
		if (n710 == 10)	MARK_LINE(n710, 660);
		if (n660 == 10)	MARK_LINE(n660, 660);
		if (n610 == 10)	MARK_LINE(n610, 610);
		if (n560 == 10)	MARK_LINE(n560, 560);
		if (n510 == 10)	MARK_LINE(n510, 510);
		if (n460 == 10)	MARK_LINE(n460, 460);
		if (n410 == 10)	MARK_LINE(n410, 410);
		if (n360 == 10)	MARK_LINE(n360, 360);
		if (n310 == 10)	MARK_LINE(n310, 310);
		if (n260 == 10)	MARK_LINE(n260, 260);
		if (n210 == 10)	MARK_LINE(n210, 210);
		if (n160 == 10)	MARK_LINE(n160, 160);
		if (n60 == 10)	MARK_LINE(n60, 60);
/*		{
			n760 = 0;
			LINES_FOR_DEL++;
			for (size_t i = 10; i < sz; i++)
			{
				if (shape[i].Y() == 760)
					shape[i].SAME(true);
			}
		}
		if (shape[i].Y() == 710)
			n710++;
		if (n710 == 10)
		{
			n710 = 0;
			LINES_FOR_DEL++;
			for (size_t i = 10; i < sz; i++)
			{
				if (shape[i].Y() == 710)
					shape[i].SAME(true);
			}
		}
		if (shape[i].Y() == 660)
			n660++;
		if (n660 == 10)
		{
			n660 = 0;
			LINES_FOR_DEL++;
			for (size_t i = 10; i < sz; i++)
			{
				if (shape[i].Y() == 660)
					shape[i].SAME(true);
			}
		}
		if (shape[i].Y() == 610)
			n610++;
		if (n610 == 10)
		{
			n610 = 0;
			LINES_FOR_DEL++;
			for (size_t i = 10; i < sz; i++)
			{
				if (shape[i].Y() == 610)
					shape[i].SAME(true);
			}
		}*/
//		if (shape[i].SAME())
//			std::cout << shape[i].Y() << " ";
	}
//	std::cout << LINES_FOR_DEL << "\n";
}

void FloorArray::DEL_LINES()//func remove marked elements
{
	size_t new_sz = sz - LINES_FOR_DEL * 10;//new lower size of arr
	Cube* p = new Cube[new_sz];//new lower arr
	int j = 0;//var for increment new arr
	float s = 0;//var for memory first same Y, in future all upper elements move down
	for (size_t i = 0; i < sz; i++)//cycle of ald arr
	{
		if (!shape[i].SAME())//if not marked -> copy to new arr
		{
			p[j] = shape[i]; //copy to new arr
			j++;//increment old arr
		}

		if (shape[i].SAME()) { if (!s) s = shape[i].Y(); }//remember first same Y
	}
	delete[]shape;//remove old arr
	shape = p;//init old to new
	sz = new_sz;//new lower size of arr
	int l = LINES_FOR_DEL;//temp var number of lines for delete
	LINES_FOR_DEL = 0;//discharge to default num of global lines for delete

	for (size_t i = 10; i < sz; i++)//chk all new arr for move all elements down
	{
		if (shape[i].Y() < s)
		{
			shape[i].MOVE(0, float(l) * 50, 1);//how many lines move down
			shape[i].SETPOSITION(shape[i].X(), shape[i].Y());//set new posotion of Cubes for draw
		}
	}
}

void FloorArray::DRAW(sf::RenderWindow & window_)const//draw arr of bottom Cubes
{
//	if (sz)
//	{
		for (size_t i = 0; i < sz; i++)
			shape[i].DRAW(window_);
//	}
}
