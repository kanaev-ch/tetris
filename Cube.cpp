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
	x += dx_ * time_;
	this->rect_cube.setPosition(x, y);
}