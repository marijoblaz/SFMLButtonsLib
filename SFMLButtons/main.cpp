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

    //Quit the game
    if (buttons["EXIT_BTN"]->isPressed()) {
        std::cout << "EXIT" <<std::endl;
    }

    //Opens settings
    if (buttons["SETTINGS_BTN"]->isPressed()) {
        std::cout << "SETTING" << std::endl;
    }

    //Plays the game
    if (buttons["PLAY_BTN"]->isPressed()) {
        std::cout << "PLAY" << std::endl;
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

    buttons["PLAY_BTN"] = new Button(300, 450, 100, 50,
        &font, "1",
        sf::Color(0, 0, 0),
        sf::Color(255, 255, 255),
        sf::Color(40, 40, 40), &window);

    buttons["EXIT_BTN"] = new Button(300, 550, 100, 50,
        &font, "2",
        sf::Color(0, 0, 0),
        sf::Color(255, 255, 255),
        sf::Color(40, 40, 40), &window);

    buttons["SETTINGS_BTN"] = new Button(300, 650, 100, 50,
        &font, "3",
        sf::Color(0, 0, 0),
        sf::Color(255, 255, 255),
        sf::Color(40, 40, 40), &window);

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Close);

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