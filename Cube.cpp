#include "Cube.h"

//rect_cube needs if no sprites
Cube::Cube()
	:x(0), y(0), same(false)
{
//	x = 0; y = 0;
/*	rect_cube.setSize(sf::Vector2f(50, 50));//size of base cube
	rect_cube.setFillColor(sf::Color::Green);//color of base cube
	rect_cube.setPosition(x, y);//position of cube on screen*/
//	std::cout << "Cube::Cube()" << std::endl;
}

//This constructor need only for init lower 10 Cubes of FloorArray
Cube::Cube(float x_, float y_)
	:x(x_), y(y_), same(false)
{
//	x = x_; y = y_;
/*	rect_cube.setSize(sf::Vector2f(50, 50));//size of base cube
	rect_cube.setFillColor(sf::Color::Green);//color of base cube
	rect_cube.setPosition(x, y);//position of cube on screen*/
//	std::cout << "Cube::Cube(float x_, float y_)" << std::endl;
}

//int type_figure_ -> var needs for memory what kind of figure owns this Cube, in future will load sprite in FloorArray.DRAW, without it will bug of draw bottom array
//it init constructor of Figure
Cube::Cube(float x_, float y_, sf::Texture & texture_, int x_spr_, int y_spr_, int type_figure_)
	:x(x_), y(y_), same(false), type_figure(type_figure_)
{
	sprite.setTexture(texture_);
	sprite.setTextureRect(sf::IntRect(x_spr_, y_spr_, 50, 50));
	sprite.setPosition(x, y);

/*	rect_cube.setSize(sf::Vector2f(50, 50));//size of base cube
	rect_cube.setFillColor(sf::Color::Green);//color of base cube
	rect_cube.setPosition(x, y);//position of cube on screen*/
//	std::cout << "Cube::Cube(float x_, float y_)" << std::endl;
}

Cube::~Cube()
{}

float Cube::X()const
{
	return x;
}

void Cube::X(float x_)
{
	x = x_;
}

float Cube::Y()const
{
	return y;
}

void Cube::Y(float y_)
{
	y = y_;
}

void Cube::SAME(bool s_)
{
	same = s_;
}
bool Cube::SAME()const
{
	return same;
}

void Cube::SPRITE(sf::Sprite& sprite_)
{
	sprite = sprite_;
}

void Cube::DRAW(sf::RenderWindow& window_)const//draw cube
{
//	window_.draw(rect_cube);
	window_.draw(sprite);
}

void Cube::TYPE_FIGURE(int type_)
{
	type_figure = type_;
}
int Cube::TYPE_FIGURE()const
{
	return type_figure;
}

void Cube::MOVE(float dx_, float dy_, float time_)//move cube
{
/*	if (y < 760) y += dy_ * time_;
	else {
		y = 760;
		FL = false;
	}*/
	y += dy_ * time_;
//	y += dy_;
//	x += dx_ * time_;
	x += dx_;//time not need multiply at dx, because every time different values offset by X

//	std::cout << x << std::endl;
	x = float(int(x) / 50 * 50) + 10;//round for moving cubes to the left-right only by 50 px

//	rect_cube.setPosition(x, y);
	sprite.setPosition(x, y);
}

//func for disable bug when last figure drop on floor and need fixate ROUNDED last coords of it for right drawing, using inf floorarray.BOTTOM_COLLISION
//necessarily before draw cube, its rect NEED TO BE rect_cube.setPosition, or last setPosition is in DRAW func and there is a bug
void Cube::SETPOSITION(float x_, float y_)
{
//	rect_cube.setPosition(x_, y_);
	sprite.setPosition(x_, y_);
}