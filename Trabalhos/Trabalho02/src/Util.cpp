#include "../headers/Util.h"

Util::Util(sf::RenderWindow &window, sf::View &camera): window(window), camera(camera) {
    holding_key = false;
    texts = {};

    if (!font.loadFromFile("../assets/fonts/TT-Octosquares-Trial-Medium.otf")) {
        std::cout << "Erro ao carregar a fonte" << std::endl;
    }
}

Util::~Util(){

}

bool Util::isKeyPressed(sf::Keyboard::Key key) {
    if(sf::Keyboard::isKeyPressed(key) && !this->holding_key) {
        this->holding_key = true;
        return true;
    }

    if (this->holding_key) {
        if(!sf::Keyboard::isKeyPressed(key)) {
            this->holding_key = false;
        }

        return false;
    }

    return false;
}

void Util::addTextToList(std::string text) {
    sf::Text sfText;
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(16);
    sfText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = sfText.getLocalBounds();
    sfText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    size_t i;

    for (i = 0; i < texts.size(); ++i) {
        texts[i].setPosition(texts[i].getPosition().x, camera.getCenter().y - 100 - 18 / 2 * (texts.size() - 1) + i * 20);
    }

    float x = this->camera.getCenter().x;
    float y = camera.getCenter().y - 100 - 18 / 2 * (texts.size() - 1) + i * 22;
    sfText.setPosition(x, y);
    texts.push_back(sfText);
}

void Util::renderTexts() {
    for (auto &text : texts) {
        window.draw(text);
    }
}

void Util::resetTexts() {
    texts = {};
}