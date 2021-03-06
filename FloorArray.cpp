#include "FloorArray.h"



FloorArray::FloorArray()
	:sz(10)//Create default bottom arr of 10 elements
{
	cube_texture.loadFromFile("Tetris.png");

	shape = new Cube[sz];//from heap

	for (size_t i = 0; i < sz; i++)
	{
		shape[i] = Cube(float(i) * 1 * 50+10, float(H));
	}
}


FloorArray::~FloorArray()
{
	delete[]shape;//free heap
}

size_t FloorArray::SZ()const
{
	return sz;
}

//func collision of Figures cubes and bottom Cubes, if return 1 exit, it meand overload bottom array, delete shape array from heap in destructor
int FloorArray::BOTTOM_COLLISION(Figure & f_)
{
	size_t old_sz = sz;//save temp old size arr
	for (size_t i = 0; i < old_sz; i++)
	{

		//Block End Game
//		if (shape[i].Y() <= 160)//Simple End Game and exit if some of bottom cubes upper then 160 by Y, it's third Cube by Y
		//IF Block of End Game NEED TO DEBUG!!!
		if (f_.CUBE1().Y() + 50 > shape[i].Y() && f_.CUBE1().X() == shape[i].X() && shape[i].Y() <= 160 ||
			f_.CUBE2().Y() + 50 > shape[i].Y() && f_.CUBE2().X() == shape[i].X() && shape[i].Y() <= 160 ||
			f_.CUBE3().Y() + 50 > shape[i].Y() && f_.CUBE3().X() == shape[i].X() && shape[i].Y() <= 160 ||
			f_.CUBE4().Y() + 50 > shape[i].Y() && f_.CUBE4().X() == shape[i].X() && shape[i].Y() <= 160 
			)
		{
			return 1;
		}
/*		if (sz >= 160)//Temporary PLUG for exit if array of CUBEs overload, means this cycle (of move down figure) is infinity
		{
			return 1;
		}*/

		if ( f_.CUBE1().Y() + 50 > shape[i].Y() && f_.CUBE1().Y() < shape[i].Y() + 50 && f_.CUBE1().X() == shape[i].X() ||
			 f_.CUBE2().Y() + 50 > shape[i].Y() && f_.CUBE2().Y() < shape[i].Y() + 50 && f_.CUBE2().X() == shape[i].X() ||
			 f_.CUBE3().Y() + 50 > shape[i].Y() && f_.CUBE3().Y() < shape[i].Y() + 50 && f_.CUBE3().X() == shape[i].X() ||
			 f_.CUBE4().Y() + 50 > shape[i].Y() && f_.CUBE4().Y() < shape[i].Y() + 50 && f_.CUBE4().X() == shape[i].X() )
		{

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
	return 0;
}

void FloorArray::MOVE_LEFT_AND_COLLISION(Figure& f_, float x_, float y_, float time_)//func move figure to the left and collision with edges and cross bottom figures
{
	float x = x_;
	if (f_.CUBE1().X() <= WB || f_.CUBE2().X() <= WB || f_.CUBE3().X() <= WB || f_.CUBE4().X() <= WB)//if cross left edge
	{
		x = 0;//STOP move if cross, x isn't coord it is OFFSET
//		std::cout << "!!!xxx!!!" << sz << std::endl;
	}
	for (size_t i = 0; i < sz; i++)
	{
		//block of check of crossing figure with every bottom array member from the left side, and don't cross it
		if (f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() < shape[i].Y() + 50 && f_.CUBE1().X() == shape[i].X() + 50 ||
			f_.CUBE2().Y() + 50 >= shape[i].Y() && f_.CUBE2().Y() < shape[i].Y() + 50 && f_.CUBE2().X() == shape[i].X() + 50 ||
			f_.CUBE3().Y() + 50 >= shape[i].Y() && f_.CUBE3().Y() < shape[i].Y() + 50 && f_.CUBE3().X() == shape[i].X() + 50 ||
			f_.CUBE4().Y() + 50 >= shape[i].Y() && f_.CUBE4().Y() < shape[i].Y() + 50 && f_.CUBE4().X() == shape[i].X() + 50)
		{
//			std::cout << "!!!xxx!!!" << sz << std::endl;
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
//		std::cout << "!!!xxx!!!" << sz << std::endl;
	}
	for (size_t i = 0; i < sz; i++)
	{
		//block of check of crossing figure with every bottom array member from the right side, and don't cross it
		if (f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() < shape[i].Y() + 50 && f_.CUBE1().X() + 50 == shape[i].X() ||
			f_.CUBE2().Y() + 50 >= shape[i].Y() && f_.CUBE2().Y() < shape[i].Y() + 50 && f_.CUBE2().X() + 50 == shape[i].X() ||
			f_.CUBE3().Y() + 50 >= shape[i].Y() && f_.CUBE3().Y() < shape[i].Y() + 50 && f_.CUBE3().X() + 50 == shape[i].X() ||
			f_.CUBE4().Y() + 50 >= shape[i].Y() && f_.CUBE4().Y() < shape[i].Y() + 50 && f_.CUBE4().X() + 50 == shape[i].X())
		{
//			std::cout << "!!!xxx!!!" << sz << std::endl;
			x = 0;//STOP move if cross, x isn't coord it is OFFSET
		}
	}
	f_.CUBE1().MOVE(x, y_, time_);
	f_.CUBE2().MOVE(x, y_, time_);
	f_.CUBE3().MOVE(x, y_, time_);
	f_.CUBE4().MOVE(x, y_, time_);
}

int FloorArray::ROTATE(Figure& f_)//Func of rotate Figures and collision with edges and bottom array
{
	bool r = true;//flag do rotate figure or not

	if (f_.type == Figure::O)//deny for rotate if CUBE, it doesn't rotate
	{
		r = false;
		return 0;//exit if Cube, don't exec down code
	}

	//block of collision with bottom array
	for (size_t i = 10; i < sz; i++)
	{
		//Collision L with bottom array in rotate
		if (f_.type == Figure::L && (f_.position == Figure::up || f_.position == Figure::down))
		{
			if (f_.CUBE1().X() == shape[i].X() + 50 && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
			if (f_.CUBE1().X() + 50 == shape[i].X() && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
		}

		//Collision l with bottom array in rotate
		if (f_.type == Figure::l && f_.position == Figure::up)
		{
			if (f_.CUBE1().X() == shape[i].X() + 50 && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
			if (f_.CUBE1().X() + 50 == shape[i].X() && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
			if (f_.CUBE1().X() + 100 == shape[i].X() && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
		}

		//Collision z with bottom array in rotate
		if (f_.type == Figure::z && f_.position == Figure::left)
		{
			if (f_.CUBE1().X() == shape[i].X() + 50 && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
		}

		//Collision T with bottom array in rotate
		if (f_.type == Figure::T && (f_.position == Figure::left || f_.position == Figure::right))
		{
			if (f_.CUBE1().X() == shape[i].X() + 50 && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
			if (f_.CUBE1().X() + 50 == shape[i].X() && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
		}

		//Collision s with bottom array in rotate
		if (f_.type == Figure::s && f_.position == Figure::left)
		{
			if (f_.CUBE1().X() == shape[i].X() + 50 && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
		}

		//Collision J with bottom array in rotate
		if (f_.type == Figure::J && (f_.position == Figure::up || f_.position == Figure::down))
		{
			if (f_.CUBE1().X() == shape[i].X() + 50 && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
			if (f_.CUBE1().X() + 50 == shape[i].X() && f_.CUBE1().Y() + 50 >= shape[i].Y() && f_.CUBE1().Y() <= shape[i].Y() + 50)
				r = false;
		}
	}

	//block of collision with edges
	if (f_.type == Figure::L)//deny for rotate if L and at the both edges
	{
		if (f_.CUBE1().X() == WB) r = false;
		if (f_.CUBE1().X() + 50 == WML + WB) r = false;
	}
	if (f_.type == Figure::l)//deny for rotate if l and at the both edges
	{
		if (f_.CUBE1().X() == WB) r = false;
		if (f_.CUBE1().X() + 100 >= WML + WB) r = false;
	}
	if (f_.type == Figure::z)//deny for rotate if z and at the both edges
	{
		if (f_.CUBE1().X() == WB) r = false;
	}
	if (f_.type == Figure::T)//deny for rotate if T and at the both edges
	{
		if (f_.CUBE1().X() == WB) r = false;
		if (f_.CUBE1().X() + 50 >= WML + WB) r = false;
	}
	if (f_.type == Figure::s)//deny for rotate if z and at the both edges
	{
		if (f_.CUBE1().X() == WB) r = false;
	}
	if (f_.type == Figure::J)//deny for rotate if L and at the both edges
	{
		if (f_.CUBE1().X() == WB) r = false;
		if (f_.CUBE1().X() + 50 == WML + WB) r = false;
	}

	if (r) f_.ROTATE();//if flag true -> rotate figure, ROTATE fun inside Figure Class
	return 0;
}

void FloorArray::MARK_LINE(int & n, int line_num)//func for mark 10 same elements when it founded
{
	if (n == 10)
	{
		n = 0;//n is link, it reset to 0 for non overload LINES_FOR_DEL
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

	int k = 0;//var for index DEL_Y_ARR[k]

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
		//DEL_Y_ARR[] the array is replenished in this block
		if (n760 == 10)
		{
			MARK_LINE(n760, 760); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n710 == 10)
		{
			MARK_LINE(n710, 710); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n660 == 10)
		{
			MARK_LINE(n660, 660); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n610 == 10)
		{
			MARK_LINE(n610, 610); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n560 == 10)
		{
			MARK_LINE(n560, 560); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n510 == 10)
		{
			MARK_LINE(n510, 510); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n460 == 10)
		{
			MARK_LINE(n460, 460); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n410 == 10)
		{
			MARK_LINE(n410, 410); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n360 == 10)
		{
			MARK_LINE(n360, 360); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n310 == 10)
		{
			MARK_LINE(n310, 310); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n260 == 10)
		{
			MARK_LINE(n260, 260); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n210 == 10)
		{
			MARK_LINE(n210, 210); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n160 == 10)
		{
			MARK_LINE(n160, 160); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}
		if (n60 == 10)
		{
			MARK_LINE(n60, 60); DEL_Y_ARR[k] = shape[i].Y(); k++;
		}

/*		//Block of mark if elements inline are 10
		if (n760 == 10)	MARK_LINE(n760, 760);
		if (n710 == 10)	MARK_LINE(n710, 710);
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
		if (n60 == 10)	MARK_LINE(n60, 60);*/
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

static void sort_arr(float a[], int m)//func do Sort Ascending of arr, array members must not be zeros!!!
{
	int i, j; 
	float ex;
	for (i = m - 1; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
			a[j] > a[i] && (ex = a[j]) && (a[j] = a[i]) && (a[i] = ex);//if need sort descending change a[j] < a[i]
	}
}

void FloorArray::DEL_LINES()//func remove marked elements
{
	size_t new_sz = sz - LINES_FOR_DEL * 10;//new lower size of arr
	Cube* p = new Cube[new_sz];//new lower arr
	int j = 0;//var for increment new arr
//	float s = 0;//var for memory first same Y, in future all upper elements move down

	for (size_t i = 0; i < sz; i++)//cycle of old arr
	{
//		if (shape[i].SAME()) { if (!s) s = shape[i].Y(); }//remember first same Y

		if (!shape[i].SAME())//if not marked -> copy to new arr
		{
			p[j] = shape[i]; //copy to new arr
			j++;//increment old arr
		}

//		if (shape[i].SAME()) { if (!s) s = shape[i].Y(); }//remember first same Y
	}
	delete[]shape;//remove old arr
	shape = p;//init old to new
	sz = new_sz;//new lower size of arr
//	int l = LINES_FOR_DEL;//temp var number of lines for delete
	LINES_FOR_DEL = 0;//discharge to default num of global lines for delete

	//THIS BLOCK MUST BE REPROGRAMMING, BUG IS HERE
/*	for (size_t i = 10; i < sz; i++)//chk all new arr for move all elements down
	{
		if (shape[i].Y() < s)
		{
			shape[i].MOVE(0, float(l) * 50, 1);//how many lines move down
			shape[i].SETPOSITION(shape[i].X(), shape[i].Y());//set new position of Cubes for draw
		}
	}*/

	sort_arr(DEL_Y_ARR, 4);//sort arr of Y corrds by ascending

	//this block move members of new arr to 50px down
	for (int j = 0; j < 4; j++)//chk all heights (DEL_Y_ARR) from lower
	{
		if (DEL_Y_ARR[j] > 10)//move if only DEL_Y_ARR is not empty, 10 is empty
		{
			SCORES += 10;//increase speed of falling Figures
			if (!(SCORES % 100)) SPEED_FDOWN += .02f;//increase Figures Speed Down if Scores == 100, 200 and more by 100 div%

			for (size_t i = 10; i < sz; i++)//compare heights (DEL_Y_ARR) with new arr members
			{
				if (shape[i].Y() < DEL_Y_ARR[j])
				{
					shape[i].MOVE(0, 50, 1);
					shape[i].SETPOSITION(shape[i].X(), shape[i].Y());
				}
			}
			DEL_Y_ARR[j] = 10;////discharge to default, 10 is default means arr is empty
		}
	}

/*	for (int i = 0; i < 4; i++)
	{
		std::cout << DEL_Y_ARR[i] << " "; DEL_Y_ARR[i] = 10;
	}
	std::cout << std::endl;*/
}

void FloorArray::DRAW(sf::RenderWindow & window_)const//draw arr of bottom Cubes
{
	if (sz)
	{
		//Block of simple drawing bottom array if it's without sprites and textures
//		for (size_t i = 0; i < sz; i++)
//			shape[i].DRAW(window_);

		//Block of drawing bottom array if it have sprites-textures
		for (size_t i = 10; i < sz; i++)
		{
			sf::Sprite sprite;
			sprite.setTexture(cube_texture);

			sprite.setTextureRect(sf::IntRect(213, 8, 50, 50));//if only ONE sprite-color of bottom cubes

			//block of different sprites-colors bottom Cubes
/*			int x_spr = 0; int y_spr = 0;
			switch (shape[i].TYPE_FIGURE())
			{
			case 1:	x_spr = 578; y_spr = 331; break;
			case 2:	x_spr = 7; y_spr = 160; break;
			case 3:	x_spr = 65; y_spr = 8; break;
			case 4:	x_spr = 634; y_spr = 130; break;
			case 5:	x_spr = 292; y_spr = 182; break;
			case 6:	x_spr = 406; y_spr = 331; break;
			case 7:	x_spr = 178; y_spr = 274; break;
			}
			sprite.setTextureRect(sf::IntRect(x_spr, y_spr, 50, 50));*/

			shape[i].SPRITE(sprite);
			shape[i].SETPOSITION(shape[i].X(), shape[i].Y());
			shape[i].DRAW(window_);
		}
	}
}
