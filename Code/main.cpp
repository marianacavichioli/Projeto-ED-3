#include "SFML/Graphics.hpp"
#include <iostream>
#include "Screens.hpp"

int main(){

    std::vector<cScreen*> Screens;
    int screen = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo indefinido");

    mainmenu s0;
    Screens.push_back(&s0);
    jogo s1;
    Screens.push_back(&s1);
    howto s2;
    Screens.push_back(&s2);

    while (screen >= 0){
        switch (screen = Screens[screen]->Run(window)){
            case 1:
                Screens[1] = new jogo();
            break;
        }
    }

    return -1;
}

