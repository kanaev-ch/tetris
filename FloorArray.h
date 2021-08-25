#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Figure.h"
#include "Cube.h"
#include "Data.h"

class FloorArray
{
private:
//	Figure* shape;
//	Figure shape[100];
	Cube shape[100];
	int sz;
public:
	FloorArray();
	~FloorArray();

//	void COLLISION(Figure *);
	void COLLISION(Figure &);

	void DRAW(sf::RenderWindow &)const;
//	void MOVE(float, float, float);
};

