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

    options = {"Selecione o genero", "Masculino", "Feminino"};
    texts.resize(3);
    coords = {{400, 114}, {480,282},{495,430}};
    sizes = {48, 64, 64};

    for (std::size_t i{}; i < texts.size(); ++i){
        if(i == 0){
            texts[i].setColor(sf::Color::Black);
        }

        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }

    pos = 1;

    texts[pos].setOutlineThickness(4);
    texts[pos].setOutlineColor(sf::Color::Red);
}

void AtributesMenu::loop_events(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !pressed){
            if(pos < 2){
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos].setOutlineColor(sf::Color::Red);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !pressed){
            if(pos > 1){
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos].setOutlineColor(sf::Color::Red);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
            theselect = true;
            close();
        }
    }
}

void AtributesMenu::draw_all(){
    window.clear();
    window.draw(*bg);
    for(auto t : texts) {
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
