#pragma once
#include <SFML/Graphics.hpp>
#include "Cube.h"

class Figure//:
//	public Shape
{
public:
//	enum Type { cube, stick, gstick, zz };//if enum is Class member it need to be defined in Public block before announcement like field in Private
private:
	float x, y;
	Cube cube1, cube2, cube3, cube4;
//	const Type type;
	int type;
public:
	Figure();
//	Figure(const Type &, float, float);
	Figure(int, float, float);
	~Figure();

	Cube & CUBE1();
	Cube & CUBE2();
	Cube & CUBE3();
	Cube & CUBE4();

	void DRAW(sf::RenderWindow&)const;
	void MOVE(float, float, float);

};

