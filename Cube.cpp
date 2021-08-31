#include "Cube.h"

Cube::Cube()
{
	x = 0; y = 0;
	rect_cube.setSize(sf::Vector2f(50, 50));//size of base cube
	rect_cube.setFillColor(sf::Color::Green);//color of base cube
	rect_cube.setPosition(x, y);//position of cube on screen
//	std::cout << "Cube::Cube()" << std::endl;
}

Cube::Cube(float x_, float y_)
{
	x = x_; y = y_;
	rect_cube.setSize(sf::Vector2f(50, 50));//size of base cube
	rect_cube.setFillColor(sf::Color::Green);//color of base cube
	rect_cube.setPosition(x, y);//position of cube on screen
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

void Cube::DRAW(sf::RenderWindow& window_)const//draw cube
{
	window_.draw(rect_cube);
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

	rect_cube.setPosition(x, y);
}

//func for disable bug when last figure drop on floor and need fixate ROUNDED last coords of it for right drawing, using inf floorarray.BOTTOM_COLLISION
//necessarily before draw cube, its rect NEED TO BE rect_cube.setPosition, or last setPosition is in DRAW func and there is a bug
void Cube::SETPOSITION(float x_, float y_)
{
	rect_cube.setPosition(x_, y_);
}