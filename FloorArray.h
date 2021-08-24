#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Figure.h"
#include "Data.h"

class FloorArray
{
private:
	Figure* shape;
	int sz;
public:
	FloorArray();
	~FloorArray();

	void COLLISION(Figure *);

	void DRAW(sf::RenderWindow &)const;
	void MOVE(float, float, float);
};

