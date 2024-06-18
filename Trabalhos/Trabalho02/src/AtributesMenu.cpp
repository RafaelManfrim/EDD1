#include "../headers/AtributesMenu.h"

AtributesMenu::AtributesMenu(sf::RenderWindow &window, int &life, int &attack, int &defense, int &luck):
window(window), life(life), attack(attack), defense(defense), luck(luck), isOpen(true) {
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();
    remaining_points = 10;

    set_values();
}

AtributesMenu::~AtributesMenu(){
    delete font;
    delete image;
    delete bg;
}

void AtributesMenu::close() {
    isOpen = false;
}

void AtributesMenu::set_values(){
    pos = 0;
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
    labels_coords = {{400, 48}, {460,175},{445,262},{445,358},{455,448}};
    labels_sizes = {36, 56, 56, 56, 56};

    for (std::size_t i{}; i < labels_texts.size(); ++i){
        labels_texts[i].setColor(sf::Color::Black);
        labels_texts[i].setFont(*font);
        labels_texts[i].setString(labels[i]);
        labels_texts[i].setCharacterSize(labels_sizes[i]);
        labels_texts[i].setOutlineColor(sf::Color::Black);
        labels_texts[i].setPosition(labels_coords[i]);
    }

    pos = 1;
}

void AtributesMenu::loop_events(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }

//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !pressed){
//            if(pos < 2){
//                ++pos;
//                pressed = true;
//                texts[pos].setOutlineThickness(4);
//                texts[pos].setOutlineColor(sf::Color::Red);
//                texts[pos - 1].setOutlineThickness(0);
//                pressed = false;
//                theselect = false;
//            }
//        }
//
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !pressed){
//            if(pos > 1){
//                --pos;
//                pressed = true;
//                texts[pos].setOutlineThickness(4);
//                texts[pos].setOutlineColor(sf::Color::Red);
//                texts[pos + 1].setOutlineThickness(0);
//                pressed = false;
//                theselect = false;
//            }
//        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
            theselect = true;
            close();
        }
    }
}

void AtributesMenu::draw_all(){
    window.clear();
    window.draw(*bg);
    for(auto t : labels_texts) {
        window.draw(t);
    }
    window.display();
}

void AtributesMenu::run_menu(){
    while(window.isOpen() && isOpen){
        loop_events();
        draw_all();
    }
}
