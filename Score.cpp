#include "Score.h"



Score::Score()
	: text_score("Score "), text_next_figure("Next Figure ")//, x(550), y(300)
{
	font.loadFromFile("Xolonium-Regular.otf");//set font from file

	score.setColor(sf::Color::Red);//set text Color
	score.setString(text_score);//set string
	score.setFont(font);//set font for text
	score.setCharacterSize(20);//set char size in pixels

	score_num.setColor(sf::Color::Red);
	score_num.setString(char_score);
	score_num.setFont(font);
	score_num.setCharacterSize(20);

	next_figure.setColor(sf::Color::Black);
	next_figure.setString(text_next_figure);
	next_figure.setFont(font);
	next_figure.setCharacterSize(20);
}


Score::~Score()
{
}

/*float Score::X()const
{
	return x;
}

void Score::X(float x_)
{
	x = x_;
}

float Score::Y()const
{
	return y;
}

void Score::Y(float y_)
{
	y = y_;
}*/

void Score::DRAW_SCORE(sf::RenderWindow& window_, float x_, float y_)
{
	score.setPosition(x_, y_);//set position of text
	score_num.setPosition(x_ + 70, y_);

	char_score[0] = SCORES % 100000 / 10000 + 48;
	char_score[1] = SCORES % 10000 / 1000 + 48;
	char_score[2] = SCORES % 1000 / 100 + 48;
	char_score[3] = SCORES % 100 / 10 + 48;
	char_score[4] = SCORES % 10 + 48;
	score_num.setString(char_score);

	window_.draw(score);
	window_.draw(score_num);
}

void Score::DRAW_NEXT_FIG_STR(sf::RenderWindow& window_, float x_, float y_)
{
	next_figure.setPosition(x_, y_);

	window_.draw(next_figure);
}

/*void Score::DRAW(sf::RenderWindow& window_)
{
	score.setPosition(x, y);//set position of text
	score_num.setPosition(x + 70, y);
	next_figure.setPosition(x, y - 280);

	char_score[0] = SCORES % 100000 / 10000 + 48;
	char_score[1] = SCORES % 10000 / 1000 + 48;
	char_score[2] = SCORES % 1000 / 100 + 48;
	char_score[3] = SCORES % 100 / 10 + 48;
	char_score[4] = SCORES % 10 + 48;
	score_num.setString(char_score);

	window_.draw(score);
	window_.draw(score_num);
	window_.draw(next_figure);
}*/