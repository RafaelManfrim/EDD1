#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "./Util.h"

class GenderMenu {

public:
    GenderMenu(sf::RenderWindow &window, Util* util, int &gender);
    ~GenderMenu();

    Util* util;

    int pos, &gender;
    bool pressed, theselect;

    sf::RenderWindow &window;
    sf::Font * font;
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