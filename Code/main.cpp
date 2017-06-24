#include "SFML/Graphics.hpp"
#include <iostream>
#include "Screens.hpp"

int main(){

    std::vector<cScreen*> Screens;
    int screen = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo indefinido");

    mainmenu s0;
    Screens.push_back(&s0);
    scene1 s1;
    Screens.push_back(&s1);
    scene2 s2;
    Screens.push_back(&s2);
    scene3 s3;
    Screens.push_back(&s3);
    howto s4;
    Screens.push_back(&s4);
    

    while (screen >= 0){
        switch (screen = Screens[screen]->Run(window)){
            case 1:
                Screens[1] = new scene1();
            break;
        }
    }

    return -1;
}

