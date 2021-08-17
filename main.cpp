#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Data.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(W, H), "Tetris");//main window

	MENU(window);//func of main menu, game inside

/*	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/
}