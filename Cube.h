#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"

class Cube ://cube - component of future figures
	public Shape//inherit from virtual Class shape, in future will create Polymorph claster from Shape
{
private:
	float x, y;//coords of cube on screen
	sf::RectangleShape rect_cube;//rectangle of cube
public:
	Cube(float, float);
	~Cube();

	float X()const;
	void X(float);
	float Y()const;
	void Y(float);

	void DRAW(sf::RenderWindow&)const;//draw cube

	void MOVE(float, float);
};

