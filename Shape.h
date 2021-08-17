#pragma once
#include <SFML/Graphics.hpp>

class Shape//virtual class
{
public:
//	Shape();
//	virtual ~Shape();
	virtual void DRAW(sf::RenderWindow&)const = 0;//virt func for future polymirph class
};

