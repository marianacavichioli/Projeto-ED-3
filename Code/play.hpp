#include "cScreen.hpp"
#include "menuplay.hpp"
#include <SFML/Graphics.hpp>

class play : public cScreen{
private:
    int posicaoy, posicaox;
    int SelectedItemIndex;

public:
    play(void);
    virtual int Run(sf::RenderWindow &Tela);
};

play::play(void){

}

int play::Run(sf::RenderWindow &window){

    /*sf::Sprite background;
    sf::Texture texture;

    if(!texture.loadFromFile("../Images/menu_sem_texto.bmp")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);*/

    menuplay Menuplay(window.getSize().x, window.getSize().y);

    while (window.isOpen()){
        
        sf::Event event;

        while (window.pollEvent(event)){
            posicaoy = sf::Mouse::getPosition(window).y;
            posicaox = sf::Mouse::getPosition(window).x;

            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    switch(event.key.code){

                        case sf::Mouse::Left:
                            std::cout << "Pressed" << std::endl;
                            std::cout << posicaox << " , "<< posicaoy << std::endl;
                            return Menuplay.GetPressedItem(posicaox, posicaoy);
                        break;
                    }
                    
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::MouseMoved:
                    Menuplay.Position(posicaox, posicaoy);
                    break;
            }

        }
        
        window.clear();
        //window.draw(background);
        Menuplay.draw(window);
        window.display();

    }
    
    return (-1);
}