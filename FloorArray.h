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

	void MARK_LINE(int& n, int);
public:
	FloorArray();
	~FloorArray();

//	void COLLISION(Figure *);
	size_t SZ()const;

	int BOTTOM_COLLISION(Figure &);
	void MOVE_LEFT_AND_COLLISION(Figure &, float, float, float);
	void MOVE_RIGHT_AND_COLLISION(Figure &, float, float, float);
	int ROTATE(Figure &);

	void MARK_FOR_DEL_LINES();
	void DEL_LINES();

	void DRAW(sf::RenderWindow &)const;

};

