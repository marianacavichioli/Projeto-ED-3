#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>


class ganhou : public cScreen{
private:
    sf::Sprite background;
    sf::Texture texture;
    sf::Texture htp;
    sf::Text button1;
    sf::Text button2;
    sf::Text textganhou;
    sf::Font font;
    int posicaox, posicaoy;


public:
	ganhou(void);
	virtual int Run(sf::RenderWindow &window);
};

ganhou::ganhou(void){

}

int ganhou::Run(sf::RenderWindow &window){

    if (!font.loadFromFile("../Fonts/PirataOne-Regular.ttf")){
        std::cout << "Error" << std::endl;
    }

    textganhou.setFont(font);
    textganhou.setColor(sf::Color::Black);
    textganhou.setString("Parabens!!");
    textganhou.setPosition(sf::Vector2f(175,60));  
    textganhou.setCharacterSize(120);  

    button1.setFont(font);
    button1.setColor(sf::Color::Black);
    button1.setString("Proximo nivel");
    button1.setPosition(sf::Vector2f(230,350));  
    button1.setCharacterSize(60);

    button2.setFont(font);
    button2.setColor(sf::Color::Black);
    button2.setString("Sair");
    button2.setPosition(sf::Vector2f(340,450));  
    button2.setCharacterSize(60);    

    if(!texture.loadFromFile("../Images/fundo_inicio.bmp")){
        std::cout << "Error" << std::endl;
    }
    
    background.setTexture(texture);

    while (window.isOpen()){
     	posicaoy = sf::Mouse::getPosition(window).y;
        posicaox = sf::Mouse::getPosition(window).x;

        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); 
            }
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    if (posicaoy>=376 && posicaoy<=411){
                        if (posicaox>= 226 && posicaox<=557){
                            return 1;
                        }
                    }
                    if (posicaoy>=485 && posicaoy<=510){
                        if (posicaox>= 343 && posicaox<=441){
                            return 0;
                        }
                    }
            	case sf::Event::MouseMoved:
            		if (posicaoy>=376 && posicaoy<=411){
                        if (posicaox>= 226 && posicaox<=557){
                            button1.setColor(sf::Color::Red);
                        }
                    }else{
                        button1.setColor(sf::Color::Black);
                    }
                    if (posicaoy>=485 && posicaoy<=510){
                        if (posicaox>= 343 && posicaox<=441){
                            button2.setColor(sf::Color::Red);
                        }
                    }else{
                        button2.setColor(sf::Color::Black);
                    }
                break;         
            }

        }

        window.draw(background);
        window.draw(textganhou);
        window.draw(button1);
        window.draw(button2);
        window.display();
    }
	return (-1);
}