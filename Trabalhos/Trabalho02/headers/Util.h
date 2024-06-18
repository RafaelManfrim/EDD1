#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Util {

public:
    Util();
    ~Util();

    bool isKeyPressed(sf::Keyboard::Key key);
protected:
    bool holding_key;
};