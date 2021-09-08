#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Data.h"

class Cube //cube - component of future figures
//	:public Shape//inherit from virtual Class shape, in future will create Polymorph claster from Shape
{
private:
	float x, y;//coords of cube on screen
	sf::RectangleShape rect_cube;//rectangle of cube
	bool same;//flag if elements is same with other 10 elements in line
public:
	Cube();
	Cube(float, float);
	~Cube();

	float X()const;
	void X(float);
	float Y()const;
	void Y(float);

	void SAME(bool);
	bool SAME()const;

	void DRAW(sf::RenderWindow&)const;//draw cube

	void MOVE(float, float, float);

	void SETPOSITION(float, float);
};

