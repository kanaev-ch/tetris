#pragma once
#include <SFML/Graphics.hpp>

class Shape//virtual class
{
private:
	size_t sz;
public:
	virtual ~Shape() {}	//For not to be an error if virtual destructor, syntax must be that virtual ~Shape() {}

	virtual void DRAW(sf::RenderWindow&)const = 0;//virt func for future polymirph class
	virtual void MOVE(float, float, float) = 0;

	int SZ();
};

