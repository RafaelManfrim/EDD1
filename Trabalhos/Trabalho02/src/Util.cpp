#include "../headers/Util.h"

Util::Util() {
    holding_key = false;
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
