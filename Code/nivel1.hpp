#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <sstream>
#include "fila.hpp"

using namespace std;

class nivel1 : public cScreen{
private:
    int posicaox, posicaoy, posicao;
    int countdown = 60;
    Fila fila;
    Objeto obj1, obj2, obj3, obj4, obj5;

    sf::Texture texture;
    sf::Texture peixeEscondido;
    sf::Texture ancoraEscondida;
    sf::Texture carangueijoEscondido;
    sf::Texture lunetaEscondida;
    sf::Texture passaroEscondido;
    sf::Texture peixe;
    sf::Texture ancora;
    sf::Texture carangueijo;
    sf::Texture luneta;
    sf::Texture passaro;
    sf::Sprite background;
    sf::Font font;
    sf::Clock clockgeral;
    sf::Text timerText;
    sf::Text timerhead;
    std::string countdownString;
    std::ostringstream converter;

public:
	nivel1(void);
	virtual int Run(sf::RenderWindow &window);
};

nivel1::nivel1(void){

}

int nivel1::Run(sf::RenderWindow &window){

    if (!font.loadFromFile("../Fonts/mmsarica_csi.ttf")){
        std::cout << "Error" << std::endl;
    }

    converter << countdown;
    countdownString = converter.str();
    timerText.setFont(font);
    timerText.setString(countdownString);
    timerText.setColor(sf::Color::Black);
    timerText.setPosition(730, 0);
    timerText.setCharacterSize(40);
    timerhead.setFont(font);
    timerhead.setString("Tempo restante:");
    timerhead.setColor(sf::Color::Black);
    timerhead.setPosition(473, 0);
    timerhead.setCharacterSize(40);

    //Background
    if(!texture.loadFromFile("../Images/fundo.bmp")){
        std::cout << "Error" << std::endl;
    }
    background.setTexture(texture);

    //Texturas Objetos Escondidos
    if(!peixeEscondido.loadFromFile("../Images/peixinho_escondido.png")){
        std::cout << "Error" << std::endl;
    }

    if(!ancoraEscondida.loadFromFile("../Images/ancora_escondida.png")){
        std::cout << "Error" << std::endl;
    }

    if(!carangueijoEscondido.loadFromFile("../Images/carangueijo_escondido.png")){
        std::cout << "Error" << std::endl;
    }

    if(!lunetaEscondida.loadFromFile("../Images/luneta_escondida.png")){
        std::cout << "Error" << std::endl;
    }

    if(!passaroEscondido.loadFromFile("../Images/passaro_escondido.png")){
        std::cout << "Error" << std::endl;
    }

    //Objetos Escondidos
    sf::Sprite Objeto1(peixeEscondido);
    Objeto1.setPosition(sf::Vector2f(750,310));

    sf::Sprite Objeto2(ancoraEscondida);
    Objeto2.setPosition(sf::Vector2f(145,310));

    sf::Sprite Objeto3(carangueijoEscondido);
    Objeto3.setPosition(sf::Vector2f(285,479));

    sf::Sprite Objeto4(lunetaEscondida);
    Objeto4.setPosition(sf::Vector2f(240,450));

    sf::Sprite Objeto5(passaroEscondido);
    Objeto5.setPosition(sf::Vector2f(350,60));

    //Texturas Objetos Menu

    if(!peixe.loadFromFile("../Images/peixinho.png")){
        std::cout << "Error" << std::endl;
    }

    if(!ancora.loadFromFile("../Images/ancora.png")){
        std::cout << "Error" << std::endl;
    }

    if(!carangueijo.loadFromFile("../Images/carangueijo.png")){
        std::cout << "Error" << std::endl;
    }

    if(!luneta.loadFromFile("../Images/luneta.png")){
        std::cout << "Error" << std::endl;
    }

    if(!passaro.loadFromFile("../Images/passaro.png")){
        std::cout << "Error" << std::endl;
    }

    //Objetos Menu
    sf::Sprite Objeto6(peixe);
    Objeto6.setPosition(sf::Vector2f(390,515));

    sf::Sprite Objeto7(ancora);
    Objeto7.setPosition(sf::Vector2f(450,515));

    sf::Sprite Objeto8(carangueijo);
    Objeto8.setPosition(sf::Vector2f(490,515));

    sf::Sprite Objeto9(luneta);
    Objeto9.setPosition(sf::Vector2f(630,500));

    sf::Sprite Objeto10(passaro);
    Objeto10.setPosition(sf::Vector2f(560,510));

    fila.Insere(obj1); //peixe
    fila.Insere(obj2); //ancora
    fila.Insere(obj3); //carangueijo
    fila.Insere(obj4); //passaro
    fila.Insere(obj5); //luneta


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
                            if(Objeto1.getGlobalBounds().contains(posicaox, posicaoy)){
                                fila.Retira();
                                std::cout<<"Retirou 1" <<std::endl;
                                //Objeto1.setTexture(); ---Apagar o objeto da tela
                            }
                            else if(Objeto2.getGlobalBounds().contains(posicaox, posicaoy)){
                                fila.Retira();
                                std::cout<<"Retirou 2" <<std::endl;
                            }                           
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

        int timer = clockgeral.getElapsedTime().asSeconds();
        if (timer > 0 && countdown > 0){
            countdown--;           
            timerText.setString(to_string(countdown));
            clockgeral.restart();
        }


        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(Objeto1);
        window.draw(Objeto2);
        window.draw(Objeto3);
        window.draw(Objeto4);
        window.draw(Objeto5);
        window.draw(Objeto6);
        window.draw(Objeto7);
        window.draw(Objeto8);
        window.draw(Objeto9);
        window.draw(Objeto10);
        window.draw(timerText);
        window.draw(timerhead);
        window.display();

    }
    
    return (-1);
}