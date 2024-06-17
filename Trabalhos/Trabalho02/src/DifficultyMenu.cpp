#include "../headers/DifficultyMenu.h"

DifficultyMenu::DifficultyMenu(sf::RenderWindow &window, int &difficulty): window(window), difficulty(difficulty), isOpen(true) {
    font = new sf::Font();
    buttonFont = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

DifficultyMenu::~DifficultyMenu(){
    delete font;
    delete buttonFont;
    delete image;
    delete bg;
}

void DifficultyMenu::close() {
    isOpen = false;
}

void DifficultyMenu::set_values(){
    pos = 0;
    pressed = theselect = false;

    if (!image->loadFromFile("../assets/sprites/menu/menu-difficulty.png")) {
        std::cout << "ERRO::MENU::Não foi possível carregar o background do menu!" << "\n";
    }

    bg->setTexture(*image);

    if (!buttonFont->loadFromFile("../assets/fonts/TT-Octosquares-Trial-Medium.otf")) {
        std::cout << "ERRO::MENU::Não foi possível carregar a fonte!" << "\n";
    }

    options = {"Selecione a dificuldade", "Facil", "Medio", "Dificil"};
    texts.resize(4);
    coords = {{350, 92}, {560,242}, {545,355}, {555,467}};
    sizes = {48, 64, 64, 64};

    for (std::size_t i{}; i < texts.size(); ++i){
        if(i == 0){
            texts[i].setColor(sf::Color::Black);
        }

        texts[i].setFont(*buttonFont);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }

    pos = 1;

    texts[pos].setOutlineThickness(4);
    texts[pos].setOutlineColor(sf::Color::Red);

    pressed = true;
}

void DifficultyMenu::loop_events(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type != sf::Event::KeyPressed && (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S)){
            pressed = true;
        }

        if(event.type == sf::Event::Closed){
            window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pressed){
            if(pos < 3){
                ++pos;
                texts[pos].setOutlineThickness(4);
                texts[pos].setOutlineColor(sf::Color::Red);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pressed){
            if(pos > 1){
                --pos;
                texts[pos].setOutlineThickness(4);
                texts[pos].setOutlineColor(sf::Color::Red);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
            theselect = true;
            difficulty = pos;
            close();
        }
    }
}

void DifficultyMenu::draw_all(){
    window.clear();
    window.draw(*bg);
    for(auto t : texts) {
        window.draw(t);
    }
    window.display();
}

void DifficultyMenu::run_menu(){
    while(window.isOpen() && isOpen){
        loop_events();
        draw_all();
    }
}
