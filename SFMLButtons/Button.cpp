#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color pressColor, sf::Color hoverColor, sf::RenderWindow* window)
{

	//Setting up the buttons
	this->window = window;

	this->buttonState = BTN_IDLE;

	this->bShape.setSize(sf::Vector2f(width, height));
	this->bShape.setPosition(sf::Vector2f(x, y));
	this->bShape.setOutlineColor(sf::Color::White);
	this->bShape.setOutlineThickness(1.5);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setLetterSpacing(1.4f);
	this->text.setCharacterSize(25);



	this->text.setPosition(
		sf::Vector2f(
			(this->bShape.getPosition().x + (this->bShape.getGlobalBounds().width / 2.f)) - this->text.getGlobalBounds().width / 2.f - 2.5 ,
			(this->bShape.getPosition().y + (this->bShape.getGlobalBounds().height / 2.f)) - this->text.getGlobalBounds().height / 2.f - 7.5));


	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->pressColor = pressColor;


	this->bShape.setFillColor(this->idleColor);


}
Button::~Button()
{
}

//Update functions

void Button::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Button::updatePress()
{
	/* Update the bools for hover and press*/
	this->updateMousePos();
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->bShape.getGlobalBounds().contains(mousePosView)) {
		this->buttonState = BTN_HOVERED;

		//Presed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_PRESSED;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->bShape.setFillColor(this->idleColor);
		this->text.setFillColor(sf::Color::White);
		break;
	case BTN_HOVERED:
		this->bShape.setFillColor(this->hoverColor);
		this->text.setFillColor(sf::Color::White);
		break;
	case BTN_PRESSED:
		this->bShape.setFillColor(this->pressColor);
		this->text.setFillColor(sf::Color::Black);
		break;
	default:
		//This should not happend!
		this->bShape.setFillColor(sf::Color::Blue);
		break;
	}


}
const bool Button::isPressed() const
{
	//returns if buttin is pressed
	if (this->buttonState == BTN_PRESSED)
		return true;
	else
	{
		return false;
	}
}

//Render function
void Button::render(sf::RenderTarget* target)
{
	target->draw(this->bShape);
	target->draw(this->text);
}
