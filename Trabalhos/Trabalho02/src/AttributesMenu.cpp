#include "../headers/AttributesMenu.h"

AttributesMenu::AttributesMenu(sf::RenderWindow &window, Util* util, int &life, int &attack, int &defense, int &luck):
window(window), util(util), life(life), attack(attack), defense(defense), luck(luck), isOpen(true) {
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();
    remaining_points = 10;

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
    int pos = 0;

    pressed = theselect = false;

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
        controls_texts[i].setColor(sf::Color::Black);
        controls_texts[i].setFont(*font);
        controls_texts[i].setString(controls[i]);
        controls_texts[i].setCharacterSize(controls_sizes[i]);
        controls_texts[i].setOutlineColor(sf::Color::Black);
        controls_texts[i].setPosition(controls_coords[i]);
    }

    pos = 1;
}

void AttributesMenu::loop_events(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !pressed){
            if(pos < 2){
                pos += 2;
                pressed = true;
                controls_texts[pos].setOutlineThickness(4);
                controls_texts[pos].setOutlineColor(sf::Color::Red);
                controls_texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !pressed){
            if(pos > 2){
                pos -= 2;
                pressed = true;
                controls_texts[pos].setOutlineThickness(4);
                controls_texts[pos].setOutlineColor(sf::Color::Red);
                controls_texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !pressed){
            if(pos > 1){
                --pos;
                pressed = true;
                controls_texts[pos].setOutlineThickness(4);
                controls_texts[pos].setOutlineColor(sf::Color::Red);
                controls_texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !pressed){
            if(pos < 1){
                ++pos;
                pressed = true;
                controls_texts[pos].setOutlineThickness(4);
                controls_texts[pos].setOutlineColor(sf::Color::Red);
                controls_texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 1 && !theselect && remaining_points > 0){
            theselect = true;
            life++;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 2 && !theselect && remaining_points < 10){
            theselect = true;
            life--;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 3 && !theselect && remaining_points > 0){
            theselect = true;
            attack++;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 4 && !theselect && remaining_points < 10){
            theselect = true;
            attack--;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 5 && !theselect && remaining_points > 0){
            theselect = true;
            defense++;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 6 && !theselect && remaining_points < 10){
            theselect = true;
            defense--;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 7 && !theselect && remaining_points > 0){
            theselect = true;
            luck++;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 8  && !theselect && remaining_points < 10){
            theselect = true;
            luck--;
        }

        if(util->isKeyPressed(sf::Keyboard::Enter) && pos == 9 && !theselect){
            theselect = true;
            close();
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
    window.display();
}

void AttributesMenu::run_menu(){
    while(window.isOpen() && isOpen){
        loop_events();
        draw_all();
    }
}
