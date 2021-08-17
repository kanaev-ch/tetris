#include "Menu.h"



Menu::Menu()
{
}

int Menu::WORK(sf::RenderWindow & window_)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
		}

		window_.clear();
		window_.draw(shape);
		window_.display();
	}

	return 0;
}