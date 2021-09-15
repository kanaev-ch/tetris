#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cube.h"
#include "Data.h"

class Figure//:
//	public Shape
{
public:
	enum Type { L, l, O, z, T, s, J };//if enum is Class member it need to be defined in Public block before announcement like field in Private
	enum Position { up, down, left, right };//if enum is Class member it need to be defined in Public block before announcement like field in Private
	const Type type;
	Position position;
private:
	float x, y;
	Cube cube1, cube2, cube3, cube4;
	sf::Texture cube_texture;
//	const Type type;
//	Position position;
//	int type;//instead Enum (type of Figure), 1 - gstick and other...
public:
//	Figure();
	Figure(const Type &, float, float);
//	Figure(int, float, float);
	~Figure();

	Cube & CUBE1();
	Cube & CUBE2();
	Cube & CUBE3();
	Cube & CUBE4();

	void DRAW(sf::RenderWindow&)const;
	void MOVE(float, float, float);
	void ROTATE();
	void MOVE_DOWN(float, float, float);
};

