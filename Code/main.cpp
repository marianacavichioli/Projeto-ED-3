#include "SFML/Graphics.hpp"
#include <iostream>
#include "Screens.hpp"

int main(){

    std::vector<cScreen*> Screens;
    int screen = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Where are ye?");

    mainmenu s0;
    Screens.push_back(&s0);
    play s1;
    Screens.push_back(&s1);
    howto s2;
    Screens.push_back(&s2);
    nivel1 s3;
    Screens.push_back(&s3);
    nivel2 s4;
    Screens.push_back(&s4);
    nivel3 s5;
    Screens.push_back(&s5);

    

    while (screen >= 0){
        switch (screen = Screens[screen]->Run(window)){
            case 1:
                Screens[1] = new play;
            break;
            case 2:
                Screens[2] = new howto;
            break;
            case 3:
                window.close();
            break;
            case 4:
                Screens[4] = new nivel1;
            break;
            case 5:
                Screens[5] = new nivel2;
            break;
            case 6:
                Screens[6] = new nivel3;
            break;
        }
    }

    return -1;
}

