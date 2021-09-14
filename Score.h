#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <string>
#include <SFML/Graphics.hpp>
#include "Data.h"

class Score
{
private:
//	float x, y;

	const std::string text_score;//string for word Scores
	const std::string text_next_figure;//string for word Next Figure

	char char_score[6] = { 0 };//string for scores

	sf::Font font;

	sf::Text score;
	sf::Text score_num;

	sf::Text next_figure;

public:
	Score();
	~Score();

	float X()const;
	void X(float);
	float Y()const;
	void Y(float);

	void DRAW_SCORE(sf::RenderWindow &, float, float);
	void DRAW_NEXT_FIG_STR(sf::RenderWindow &, float, float);
};

