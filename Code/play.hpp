#include "cScreen.hpp"
#include "menuplay.hpp"
#include <SFML/Graphics.hpp>

class play : public cScreen{
private:
    int posicaoy, posicaox;
    int SelectedItemIndex;
    sf::Sprite background;
    sf::Texture texture;
    sf::Texture lvl1;
    sf::Texture lvl2;
    sf::Texture lvl3;

public:
    play(void);
    virtual int Run(sf::RenderWindow &Tela);
};

play::play(void){

}

int play::Run(sf::RenderWindow &window){ 

    if(!texture.loadFromFile("../Images//recortadas/inicio.bmp")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);

    if(!lvl1.loadFromFile("../Images//recortadas/epic.png")){
        std::cout << "Error" << std::endl;
    }

    if(!lvl2.loadFromFile("../Images//recortadas/uthere.png")){
        std::cout << "Error" << std::endl;
    }

    if(!lvl3.loadFromFile("../Images//recortadas/hello.png")){
        std::cout << "Error" << std::endl;
    }

    sf::Sprite nivel1(lvl1);
    nivel1.setPosition(sf::Vector2f(550,310));

    sf::Sprite nivel2(lvl2);
    nivel2.setPosition(sf::Vector2f(100,220));

    sf::Sprite nivel3(lvl3);
    nivel3.setPosition(sf::Vector2f(300,30));   


    menuplay menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()){
        
        sf::Event event;

        while (window.pollEvent(event)){
            posicaoy = sf::Mouse::getPosition(window).y;
            posicaox = sf::Mouse::getPosition(window).x;

            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    switch(event.key.code){

                        case sf::Mouse::Left:

                            if(nivel1.getGlobalBounds().contains(posicaox, posicaoy)){
                                return 4;
                            }
                            else if(nivel2.getGlobalBounds().contains(posicaox, posicaoy)){
                                return 5;
                            }
                            else if(nivel3.getGlobalBounds().contains(posicaox, posicaoy)){
                                return 6;
                            }
                        break;
                    }
                    
                break;

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape){
                        return 0;
                    }
                break;
                
                case sf::Event::MouseMoved:
                    menu.Position(posicaox, posicaoy);
                    break;
            }

        }
        
        window.clear();
        window.draw(background);
        window.draw(nivel1);
        window.draw(nivel2);
        window.draw(nivel3);
        menu.draw(window);
        window.display();

    }
    
    return (-1);
}