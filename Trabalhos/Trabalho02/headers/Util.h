#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Util {

public:
    Util(sf::RenderWindow &window, sf::View &camera);
    ~Util();

    bool isKeyPressed(sf::Keyboard::Key key);

    sf::RenderWindow &window;
    sf::View &camera;
    sf::Font font;

    std::vector<sf::Text> texts;

    void renderTexts();
    void addTextToList(std::string text);
    void resetTexts();
protected:
    bool holding_key;
};