#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <sstream>

class scene1 : public cScreen{
private:
    int posicaox, posicaoy, posicao;

public:
	scene1(void);
	virtual int Run(sf::RenderWindow &window);
};

scene1::scene1(void){

}

int scene1::Run(sf::RenderWindow &window){

    sf::Font font;

    if (!font.loadFromFile("../Fonts/mmsarica_csi.ttf")){
        std::cout << "Error" << std::endl;
    }

    //Background
    /*if(!texture.loadFromFile("../Images/background.bmp")){
        std::cout << "Error" << std::endl;
    }
    background.setTexture(texture);*/

    while (window.isOpen()){
        
        sf::Event event;

        while (window.pollEvent(event)){

            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    
                    switch(event.key.code){

                        case sf::Mouse::Left:
                            std::cout << "Pressed" << std::endl;                            
                        break;
                    }

                case sf::Event::KeyReleased:
                    switch(event.key.code){
                                                
                        case sf::Keyboard::Escape:
                            return 0;
                        break;
                    }
                    
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                
            }

        }


        window.clear(sf::Color::White);
        //window.draw(background);
        window.display();

    }
    
    return (-1);
}