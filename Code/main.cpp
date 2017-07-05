#include "SFML/Graphics.hpp"
#include <iostream>
#include "Screens.hpp"

int main(){

    std::vector<cScreen*> Screens;
    int screen = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo indefinido");

    mainmenu s0;
    Screens.push_back(&s0);
    play s1;
    Screens.push_back(&s1);
    nivel1 s2;
    Screens.push_back(&s2);
    nivel2 s3;
    Screens.push_back(&s3);
    nivel3 s4;
    Screens.push_back(&s4);
    howto s5;
    Screens.push_back(&s5);
    

    while (screen >= 0){
        switch (screen = Screens[screen]->Run(window)){
            case 1:
                Screens[1] = new play();
            break;
        }
    }

    return -1;
}

