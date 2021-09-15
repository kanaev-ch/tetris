#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include "Data.h"

#define H_MENU 2
#define W_MENU 11

class Menu
{
private:
	//arr of char menu items
	const char str_menu[H_MENU][W_MENU] = {
		"START GAME",
		"EXIT"
	};

	sf::Font font;//font

	sf::Text menu[H_MENU];//arr for menu items

	int flag_menu;//var of what item menu is active now
	
public:
	Menu();

	void FLAG_MENU(int);
	int FLAG_MENU()const;

	void CHK_MENU_CLR();//chk active menu item and color it in white
	void DRAW(sf::RenderWindow &, float, float);//draw menu items

};

int MENU(sf::RenderWindow &);//main menu func

