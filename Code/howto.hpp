#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>


class howto : public cScreen{
private:
    sf::Texture texture;
    sf::Texture htp;
    sf::Text text;
    sf::Text button;
    sf::Font font;
    int posicaox, posicaoy, posicao;
    int index;


public:
    howto(void);
    virtual int Run(sf::RenderWindow &window);
};

howto::howto(void){

}

int howto::Run(sf::RenderWindow &window){

    index = 0;
    posicao = 0;

    sf::Sprite background;

    if(!texture.loadFromFile("../Images/howtome0.png")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);

    if (!font.loadFromFile("../Fonts/PirataOne-Regular.ttf")){
        std::cout << "Error" << std::endl;
    }

    button.setFont(font);
    button.setColor(sf::Color::Black);
    button.setString("Next ->");
    button.setPosition(sf::Vector2f(100,500));  
    button.setCharacterSize(50);   


    while (window.isOpen()){
        posicaoy = sf::Mouse::getPosition(window).y;
        posicaox = sf::Mouse::getPosition(window).x;

        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); 
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    return 0;
                }
            }
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    std::cout << posicaox << "," << posicaoy << endl;
                    switch(event.key.code){
                        case sf::Mouse::Left:
                           if(posicaox >= 103 && posicaox <= 222){
                                if (posicaoy >= 510 && posicaoy <= 556){
                                    posicao = 1;
                                    index++;
                                }
                            }
                        break;
                    }
                
                case sf::Event::MouseMoved:
                    button.setColor(sf::Color::Black);
                    if(posicaox >= 103 && posicaox <= 222){
                        if (posicaoy >= 510 && posicaoy <= 556){
                            button.setColor(sf::Color::Red);
                        }
                    }                           
                break;         
            }

        }

        if (index == 1){
            if(!texture.loadFromFile("../Images/howtome1.png")){
            }
        }
        else if (index == 2){
            if(!texture.loadFromFile("../Images/howtome2.png")){
            }
        }
        else if (index == 3){
            if(!texture.loadFromFile("../Images/howtome3.png")){
            }
        }
        else if(index == 4){
            return 0;
        }

        window.draw(background);
        window.draw(text);
        window.draw(button);
        window.display();
    }
    return (-1);
}