#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Figure.h"
#include "Cube.h"
#include "Data.h"

class FloorArray
{
private:
	Cube* shape;//arr of bottom Cubes
	size_t sz;//size of this arr
public:
	FloorArray();
	~FloorArray();

//	void COLLISION(Figure *);
	void COLLISION(Figure &);

	void DRAW(sf::RenderWindow &)const;
};

