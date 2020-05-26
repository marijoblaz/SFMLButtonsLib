#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum button_states
{
	BTN_IDLE = 0,
	BTN_PRESSED,
	BTN_HOVERED
};


class Button
{
private:

	short unsigned buttonState;
	sf::RenderWindow* window;

	//init shape
	sf::RectangleShape bShape;

	//init text/font
	sf::Font* font;
	sf::Text text;


	//Button colors
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressColor;

	//Mouse pos
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;


public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color pressColor, sf::Color hoverColor, sf::RenderWindow* window);
	virtual ~Button();

	//funs
	void render(sf::RenderTarget* target);
	void updateMousePos();
	void updatePress();

	//getter
	const bool isPressed() const;

};

