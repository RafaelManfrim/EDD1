#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "./Util.h"

class AttributesMenu {

public:
    AttributesMenu(sf::RenderWindow &window, Util* util, int &life, int &attack, int &defense, int &luck);
    ~AttributesMenu();

    Util* util;

    int pos;
    int remaining_points, &life, &attack, &defense, &luck;
    bool pressed, theselect;

    sf::RenderWindow &window;
    sf::Font * font;
    sf::Texture * image;
    sf::Sprite * bg;

    std::vector<const char *> labels;
    std::vector<sf::Vector2f> labels_coords;
    std::vector<sf::Text> labels_texts;
    std::vector<std::size_t> labels_sizes;

    std::vector<const char *> stats_labels;
    std::vector<sf::Vector2f> stats_labels_coords;
    std::vector<sf::Text> stats_labels_texts;
    std::vector<std::size_t> stats_labels_sizes;

    std::vector<const char *> controls;
    std::vector<sf::Vector2f> controls_coords;
    std::vector<sf::Text> controls_texts;
    std::vector<std::size_t> controls_sizes;

    void run_menu();

protected:
    bool isOpen;
    void close();

    void set_values();
    void loop_events();
    void draw_all();
};