#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Figure.h"
#include "Cube.h"
#include "Data.h"

class FloorArray
{
//private:
	Cube* shape;//arr of bottom Cubes
	size_t sz;//size of this arr
public:
	FloorArray();
	~FloorArray();

//	void COLLISION(Figure *);
	void BOTTOM_COLLISION(Figure &);
	void MOVE_LEFT_AND_COLLISION(Figure &, float, float, float);
	void MOVE_RIGHT_AND_COLLISION(Figure &, float, float, float);

	void CHK_DEL_LINE();

	void DRAW(sf::RenderWindow &)const;
};

