#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include "Data.h"

#define H_MENU 2
#define W_MENU 11

class Menu
{
private:
	const char str_menu[H_MENU][W_MENU] = {
		"START GAME",
		"EXIT"
	};

	sf::Font font;

	sf::Text menu[H_MENU];

	int flag_menu;
	
public:
	Menu();

	void FLAG_MENU(int);
	int FLAG_MENU()const;

	void CHK_MENU_CLR();
	void DRAW(sf::RenderWindow &, float, float);

//	int WORK(sf::RenderWindow &);
};

int MENU(sf::RenderWindow &);

