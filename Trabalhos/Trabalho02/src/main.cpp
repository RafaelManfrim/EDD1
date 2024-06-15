//#headers<cstdlib>
//#headers<ctime>
//#headers<iostream>
//#headers<ctime>
//
//#headers<SFML/System.hpp>
//#headers<SFML/Graphics.hpp>
//#headers<SFML/Audio.hpp>
//#headers<SFML/Window.hpp>
//#headers<SFML/Network.hpp>

#include "../headers/Game.h"

using namespace std;

int main() {
//    srand(static_cast<unsigned>(time(0)));

    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();
        game.render();
    }

    return 0;
}
