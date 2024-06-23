#include "../headers/AttributesMenu.h"

AttributesMenu::AttributesMenu(sf::RenderWindow &window, Util* util, int &life, int &attack, int &defense, int &luck):
window(window), util(util), life(life), attack(attack), defense(defense), luck(luck), isOpen(true) {
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    remaining_points = 15;

    set_values();
}

AttributesMenu::~AttributesMenu(){
    delete font;
    delete image;
    delete bg;
}

void AttributesMenu::close() {
    isOpen = false;
}

void AttributesMenu::set_values(){
    if (!font->loadFromFile("../assets/fonts/TT-Octosquares-Trial-Medium.otf")) {
        std::cout << "ERRO::MENU::Não foi possível carregar a fonte!" << "\n";
    }

    if (!image->loadFromFile("../assets/sprites/menu/menu-atributes.png")) {
        std::cout << "ERRO::MENU::Não foi possível carregar o background do menu!" << "\n";
    }

    bg->setTexture(*image);

    labels = {"Distribua seus atributos", "Vida", "Ataque", "Defesa", "Sorte"};
    labels_texts.resize(5);
    labels_coords = {{400, 45}, {460,173},{430,262},{430,359},{455,455}};
    labels_sizes = {36, 56, 56, 56, 56};

    for (std::size_t i{}; i < labels_texts.size(); ++i){
        labels_texts[i].setColor(sf::Color::Black);
        labels_texts[i].setFont(*font);
        labels_texts[i].setString(labels[i]);
        labels_texts[i].setCharacterSize(labels_sizes[i]);
        labels_texts[i].setOutlineColor(sf::Color::Black);
        labels_texts[i].setPosition(labels_coords[i]);
    }

    controls = {"+", "-", "+", "-", "+", "-", "+", "-", "Confirmar"};
    controls_texts.resize(9);
    controls_coords = {
        {797, 173},
        {883,168},
        {797,265},
        {883,262},
        {797,359},
        {883,355},
        {797,455},
        {883,451},
        {510,560}
    };
    controls_sizes = {56, 56, 56, 56, 56, 56, 56, 56, 56};

    for (std::size_t i{}; i < controls_texts.size(); ++i){
        controls_texts[i].setFont(*font);
        controls_texts[i].setString(controls[i]);
        controls_texts[i].setCharacterSize(controls_sizes[i]);
        controls_texts[i].setOutlineColor(sf::Color::Black);
        controls_texts[i].setPosition(controls_coords[i]);
    }

    this->pos = 0;

    controls_texts[pos].setOutlineThickness(4);
    controls_texts[pos].setOutlineColor(sf::Color::Red);
}

void AttributesMenu::loop_events(){
    sf::Event event;
    while(window.pollEvent(event)){
        this->stats_labels = {
                std::to_string(remaining_points) + " restantes",
                std::to_string(life),
                std::to_string(attack),
                std::to_string(defense),
                std::to_string(luck)};

        this->stats_labels_texts.resize(5);
        this->stats_labels_coords = {{400, 85}, {710,185},{710,275},{710,372},{710,469}};
        this->stats_labels_sizes = {36, 36, 36, 36, 36};

        for (std::size_t i{}; i < stats_labels_texts.size(); ++i){
            stats_labels_texts[i].setColor(sf::Color::Black);
            stats_labels_texts[i].setFont(*font);
            stats_labels_texts[i].setString(stats_labels[i]);
            stats_labels_texts[i].setCharacterSize(stats_labels_sizes[i]);
            stats_labels_texts[i].setOutlineColor(sf::Color::Black);
            stats_labels_texts[i].setPosition(stats_labels_coords[i]);
        }

        if(event.type == sf::Event::KeyPressed
            && (event.key.code == sf::Keyboard::W
            || event.key.code == sf::Keyboard::S
            || event.key.code == sf::Keyboard::A
            || event.key.code == sf::Keyboard::D
            || event.key.code == sf::Keyboard::Enter
        )){
            this->pressed = true;
        }

        if(event.type == sf::Event::Closed){
            window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->pressed){
            if(this->pos <= 6){
                this->pos += 2;
                controls_texts[pos].setOutlineThickness(4);
                controls_texts[pos].setOutlineColor(sf::Color::Red);
                controls_texts[pos - 2].setOutlineThickness(0);
            } else if (pos == 7) {
                this->pos++;
                controls_texts[pos].setOutlineThickness(4);
                controls_texts[pos].setOutlineColor(sf::Color::Red);
                controls_texts[pos - 1].setOutlineThickness(0);
            }

            this->pressed = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->pressed){
            if(this->pos >= 2){
                this->pos -= 2;
                controls_texts[pos].setOutlineThickness(4);
                controls_texts[pos].setOutlineColor(sf::Color::Red);
                controls_texts[pos + 2].setOutlineThickness(0);
            }

            this->pressed = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            if(this->pos == 1 || this->pos == 3 || this->pos == 5 || this->pos == 7){
                --this->pos;
                controls_texts[this->pos].setOutlineThickness(4);
                controls_texts[this->pos].setOutlineColor(sf::Color::Red);
                controls_texts[this->pos + 1].setOutlineThickness(0);
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            if(this->pos == 0 || this->pos == 2 || this->pos == 4 || this->pos == 6){
                ++this->pos;
                controls_texts[this->pos].setOutlineThickness(4);
                controls_texts[this->pos].setOutlineColor(sf::Color::Red);
                controls_texts[this->pos - 1].setOutlineThickness(0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && this->pressed) {
            this->pressed = false;

            if(this->pos == 0 && remaining_points > 0){
                life++;
                remaining_points--;
            } else  if(this->pos == 1 && remaining_points < 15 && life >= 1){
                life--;
                remaining_points++;
            } else if(this->pos == 2 && remaining_points > 0){
                attack++;
                remaining_points--;
            } else if(this->pos == 3 && remaining_points < 15 && attack >= 1){
                attack--;
                remaining_points++;
            } else if(this->pos == 4 && remaining_points > 0){
                defense++;
                remaining_points--;
            } else if(this->pos == 5 && remaining_points < 15 && defense >= 1){
                defense--;
                remaining_points++;
            } else if(this->pos == 6 && remaining_points > 0){
                luck++;
                remaining_points--;
            } else if(this->pos == 7  && remaining_points < 15 && luck >= 1){
                luck--;
                remaining_points++;
            } else if(this->pos == 8 && remaining_points == 0){
                close();
            }
        }
    }
}

void AttributesMenu::draw_all(){
    window.clear();
    window.draw(*bg);
    for(auto t : labels_texts) {
        window.draw(t);
    }
    for(auto t : controls_texts) {
        window.draw(t);
    }
    for(auto t : stats_labels_texts) {
        window.draw(t);
    }
    window.display();
}

void AttributesMenu::run_menu(){
    while(window.isOpen() && isOpen){
        loop_events();
        draw_all();
    }
}
