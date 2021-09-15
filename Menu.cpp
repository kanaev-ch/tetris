#include <iostream>
#include "Menu.h"



Menu::Menu()
	: flag_menu(1)//default 1-st item menu is active
{
	font.loadFromFile("Xolonium-Regular.otf");//set font from file

	for (int i = 0; i < sizeof(str_menu) / sizeof (str_menu[0]); i++)
	{
		if (flag_menu - 1 != i)	menu[i].setColor(sf::Color::Red);//set text Color
		menu[i].setString(str_menu[i]);//set string
		menu[i].setFont(font);//set font for text
		menu[i].setCharacterSize(30);//set char size in pixels
	}
	menu[flag_menu - 1].setColor(sf::Color::White);
}

void Menu::CHK_MENU_CLR()//chk active menu item and color it in white
{
	if (flag_menu <= 0) flag_menu++;
	else if (flag_menu > sizeof(str_menu) / sizeof(str_menu[0])) flag_menu--;
	for (int i = 0; i < sizeof(str_menu) / sizeof(str_menu[0]); i++)
		if (flag_menu - 1 != i)	menu[i].setColor(sf::Color::Red);//set text Color
	menu[flag_menu - 1].setColor(sf::Color::White);
}

void Menu::FLAG_MENU(int f_)
{
	flag_menu = f_;
}

int Menu::FLAG_MENU()const
{
	return flag_menu;
}

void Menu::DRAW(sf::RenderWindow& window_, float x_, float y_)
{
	for (int i = 0; i < sizeof(str_menu) / sizeof(str_menu[0]); i++)
	{
		menu[i].setPosition(x_, y_ + i * 50);
		window_.draw(menu[i]);
	}
//	std::cout << (sizeof(str_menu) / sizeof(str_menu[0]))+1 << std::endl;
}