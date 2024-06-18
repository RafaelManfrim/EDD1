#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class AtributesMenu {

public:
    AtributesMenu(sf::RenderWindow &window, int &life, int &attack, int &defense, int &luck);
    ~AtributesMenu();

    int pos, remaining_points, &life, &attack, &defense, &luck;
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