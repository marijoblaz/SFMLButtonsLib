#include <SFML/Graphics.hpp>
#include "Button.h"

//Buttons
std::map<std::string, Button*> buttons;
sf::Font font;

void updateButtons() {

    //Updates all button and handlles funcs
    for (auto& it : buttons)
    {
        //Update pressing and pass the mouse Positions 
        it.second->updatePress();
    }

    //Opens settings
    if (buttons["BTN1"]->isPressed()) {
        std::cout << "ON1" << std::endl;
    }

    //Plays the game
    if (buttons["BTN2"]->isPressed()) {
        std::cout << "ON2" << std::endl;
    }
    //Plays the game
    if (buttons["BTN3"]->isPressed()) {
        std::cout << "ON3" << std::endl;
    }

}

void renderButtons(sf::RenderWindow *target) {

    //Rendering the buttons
    for (auto& it : buttons)
    {
        it.second->render(target);
    }
}
void initButtons(sf::RenderWindow &window) {
    //Creating buttons

    buttons["BTN1"] = new Button(150, 50, 100, 50,
        &font, "BTN1",
        sf::Color(0, 0, 0),
        sf::Color(0, 255, 0),
        sf::Color(40, 40, 40), &window, BTN_TOGGLE);

    buttons["BTN2"] = new Button(150, 175, 100, 50,
        &font, "BTN2",
        sf::Color(0, 0, 0),
        sf::Color(0, 255, 0),
        sf::Color(40, 40, 40), &window, BTN_TOGGLE);

    buttons["BTN3"] = new Button(150, 300, 100, 50,
        &font, "BTN3",
        sf::Color(0, 0, 0),
        sf::Color(255, 255, 255),
        sf::Color(40, 40, 40), &window, BTN_STANDARD);

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!", sf::Style::Close);

    font.loadFromFile("Fonts/arial.ttf");
    initButtons(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                //Deleting all the buttons
                for (auto i = buttons.begin(); i != buttons.end(); ++i) {
                    delete i->second;
                }
                window.close();
            }
                
        }
        updateButtons();
        window.clear();
        renderButtons(&window);
        window.display();
    }

    return 0;
}