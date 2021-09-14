#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Cube.h"
#include "Figure.h"
#include "FloorArray.h"
#include "Score.h"


int game(sf::RenderWindow&, sf::RectangleShape&, sf::RectangleShape&, Score &);

void DRAW_MAIN_RECT(sf::RenderWindow &, sf::RectangleShape &);