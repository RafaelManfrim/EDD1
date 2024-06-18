#pragma once

#include "./Util.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu {

public:
    Menu(sf::RenderWindow &window, Util* util);
    ~Menu();

    Util* util;

    int pos;
    bool pressed, theselect;

    sf::RenderWindow &window;
    sf::Font * font;
    sf::Font * buttonFont;
    sf::Texture * image;
    sf::Sprite * bg;

    std::vector<const char *> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

    void run_menu();

protected:
    bool isOpen;
    void close();

    void set_values();
    void loop_events();
    void draw_all();
};