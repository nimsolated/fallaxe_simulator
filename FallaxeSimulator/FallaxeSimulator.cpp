#include <SFML/Graphics.hpp>
#include <iostream>

bool isMouseWithin(const sf::RenderWindow& window, const int& leftBorder, const int& topBorder, const int& rightBorder, const int& bottomBorder) {
    return sf::Mouse::getPosition(window).x > leftBorder && sf::Mouse::getPosition(window).y > topBorder && sf::Mouse::getPosition(window).x < rightBorder && sf::Mouse::getPosition(window).y < bottomBorder;
}

int main()
{
    sf::VideoMode vm = sf::VideoMode(sf::Vector2u(600, 600));
    sf::RenderWindow menuWindow = sf::RenderWindow(vm, "Fallaxe Simulator!");
    menuWindow.setFramerateLimit(60);

    sf::Font font_underdog("Fonts/Underdog-Regular.ttf");

    // Title Text Properties
    sf::Text titleText(font_underdog, "Fallaxe Simulator", 32);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition({164, 64});

    // Play Button Properties
    sf::Vector2<int> playButtonPos(264, 264);
    sf::Vector2<int> playButtonSize(60, 40);
    sf::Text playText(font_underdog, "Play", 32);
    playText.setFillColor(sf::Color::Black);
    playText.setPosition(static_cast<sf::Vector2<float>>(playButtonPos));

    // BG Color
    sf::Color backgroundColor(135, 206, 235);

    // run the program as long as the window is open
    while (menuWindow.isOpen()) {
        
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = menuWindow.pollEvent()) {

            // close the window as soon as we received "close requested" event
            if (event->is<sf::Event::Closed>()) {
                menuWindow.close();
            }
        }

        /*
        ////////////////
        ///// UPDATE /////
        ////////////////
        */

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            menuWindow.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (isMouseWithin(
                menuWindow,
                playButtonPos.x,
                playButtonPos.y,
                playButtonPos.x + playButtonSize.x,
                playButtonPos.y + playButtonSize.y
                )){

                std::cout << "Play clicked!\n";
            }
        }

        /*
        //////////////
        ///// DRAW /////
        //////////////
        */

        menuWindow.clear(backgroundColor);
        
        menuWindow.draw(titleText);
        menuWindow.draw(playText);
        
        menuWindow.display();
    }

    return 0;
}