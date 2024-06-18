#include "../headers/Menu.h"

Menu::Menu(sf::RenderWindow &window, Util* util): window(window), util(util), isOpen(true){
    font = new sf::Font();
    buttonFont = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    pos = 0;
    pressed = theselect = false;

    set_values();
}

Menu::~Menu(){
    delete font;
    delete buttonFont;
    delete image;
    delete bg;
}

void Menu::close() {
    isOpen = false;
}

void Menu::set_values(){
    if (!font->loadFromFile("../assets/fonts/Platinum-Sign-Over.otf")) {
        std::cout << "ERRO::MENU::Não foi possível carregar a fonte!" << "\n";
    }

    if (!buttonFont->loadFromFile("../assets/fonts/TT-Octosquares-Trial-Medium.otf")) {
        std::cout << "ERRO::MENU::Não foi possível carregar a fonte!" << "\n";
    }

    if (!image->loadFromFile("../assets/sprites/menu/menu.png")) {
        std::cout << "ERRO::MENU::Não foi possível carregar o background do menu!" << "\n";
    }

    bg->setTexture(*image);

    options = {"ZORBA GAME", "Jogar", "Sair"};
    texts.resize(3);
    coords = {{380, 114}, {550,282},{570,430}};
    sizes = {64, 64, 64};

    for (std::size_t i{}; i < texts.size(); ++i){
        if(i == 0){
            texts[i].setFont(*font);
            texts[i].setColor(sf::Color::Black);

        } else {
            texts[i].setFont(*buttonFont);
        }

        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }

    pos = 1;

    texts[pos].setOutlineThickness(4);
    texts[pos].setOutlineColor(sf::Color::Red);
}

void Menu::loop_events(){
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

        if(util->isKeyPressed(sf::Keyboard::Enter) && !theselect){
            theselect = true;
            if(pos == 1) {
                close();
            }
            if(pos == 2){
                window.close();
            }
        }
    }
}

void Menu::draw_all(){
    window.clear();
    window.draw(*bg);
    for(auto t : texts) {
        window.draw(t);
    }
    window.display();
}

void Menu::run_menu(){
    while(window.isOpen() && isOpen){
        loop_events();
        draw_all();
    }
}
