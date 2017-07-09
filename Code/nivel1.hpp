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
    Objeto opeixe = obj1, oancora = obj2 , ocarangueijo = obj3, opassaro = obj4, oluneta = obj5, lixo;
    bool status1 = true, status2 = true, status3 = true, status4 = true, status5 = true;
    bool ostatus1 = true, ostatus2 = true, ostatus3 = true, ostatus4 = true, ostatus5 = true;
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
    sf::Texture peixe_c;
    sf::Texture ancora_c;
    sf::Texture carangueijo_c;
    sf::Texture luneta_c;
    sf::Texture passaro_c;
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

    if (!font.loadFromFile("../Fonts/PirataOne-Regular.ttf")){
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
    sf::Sprite Objeto1e(peixeEscondido);
    Objeto1e.setPosition(sf::Vector2f(750,310));

    sf::Sprite Objeto2e(ancoraEscondida);
    Objeto2e.setPosition(sf::Vector2f(145,310));

    sf::Sprite Objeto3e(carangueijoEscondido);
    Objeto3e.setPosition(sf::Vector2f(285,479));

    sf::Sprite Objeto4e(passaroEscondido);
    Objeto4e.setPosition(sf::Vector2f(350,60));

    sf::Sprite Objeto5e(lunetaEscondida);
    Objeto5e.setPosition(sf::Vector2f(240,450));

    //Texturas Objetos Menu

    if(!peixe.loadFromFile("../Images/recortadas/peixe_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!ancora.loadFromFile("../Images/recortadas/ancora_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!carangueijo.loadFromFile("../Images/recortadas/carangueijo_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!luneta.loadFromFile("../Images/recortadas/luneta_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!passaro.loadFromFile("../Images//recortadas/passaro_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!peixe_c.loadFromFile("../Images/recortadas/peixe_padrao_c.png")){
        std::cout << "Error" << std::endl;
    }

    if(!ancora_c.loadFromFile("../Images/recortadas/ancora_padrao_c.png")){
        std::cout << "Error" << std::endl;
    }

    if(!carangueijo_c.loadFromFile("../Images/recortadas/carangueijo_padrao_c.png")){
        std::cout << "Error" << std::endl;
    }

    if(!luneta_c.loadFromFile("../Images/recortadas/luneta_padrao_c.png")){
        std::cout << "Error" << std::endl;
    }

    //Objetos Menu
    sf::Sprite Objeto1(peixe);
    Objeto1.setPosition(sf::Vector2f(370,490));

    sf::Sprite Objeto2(ancora);
    Objeto2.setPosition(sf::Vector2f(430,490));

    sf::Sprite Objeto3(carangueijo);
    Objeto3.setPosition(sf::Vector2f(490,490));

    sf::Sprite Objeto4(passaro);
    Objeto4.setPosition(sf::Vector2f(560,490));

    sf::Sprite Objeto5(luneta);
    Objeto5.setPosition(sf::Vector2f(630,490));

    fila.Insere(opeixe); //peixe
    fila.Insere(oancora); //ancora
    fila.Insere(ocarangueijo); //carangueijo
    fila.Insere(opassaro); //passaro
    fila.Insere(oluneta); //luneta

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
                            if(Objeto1e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj1)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 1" <<std::endl;
                                status1 = false;
                                Objeto1.setTexture(peixe_c);
                            }
                            else if(Objeto2e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj2)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 2" <<std::endl;
                                status2 = false;
                                Objeto2.setTexture(ancora_c);
                            }
                            else if(Objeto3e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj3)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 3" <<std::endl;
                                status3 = false;
                                Objeto3.setTexture(carangueijo_c);
                            }
                            else if(Objeto4e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj4)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 4" <<std::endl;
                                status4 = false;
                            }
                            else if(Objeto5e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj5)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 5" <<std::endl;
                                status5 = false;
                                Objeto5.setTexture(luneta_c);
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

        switch(fila.firstfive(1)){
            case obj0:
                ostatus1 = false;
            break;
            case obj1:
                Objeto1.setTexture(peixe);
            break;
            case obj2:
                Objeto1.setTexture(ancora);
            break;
            case obj3:
                Objeto1.setTexture(carangueijo);
            break;
            case obj4:
                Objeto1.setTexture(passaro);
            break;
            case obj5:
                Objeto1.setTexture(luneta);
            break;
        }

        switch(fila.firstfive(2)){
            case obj0:
                ostatus2 = false;
            break;
            case obj1:
                Objeto2.setTexture(peixe);
            break;
            case obj2:
                Objeto2.setTexture(ancora);
            break;
            case obj3:
                Objeto2.setTexture(carangueijo);
            break;
            case obj4:
                Objeto2.setTexture(passaro);
            break;
            case obj5:
                Objeto2.setTexture(luneta);
            break;
        }

        switch(fila.firstfive(3)){
            case obj0:
                ostatus3 = false;
            break;
            case obj1:
                Objeto3.setTexture(peixe);
            break;
            case obj2:
                Objeto3.setTexture(ancora);
            break;
            case obj3:
                Objeto3.setTexture(carangueijo);
            break;
            case obj4:
                Objeto3.setTexture(passaro);
            break;
            case obj5:
                Objeto3.setTexture(luneta);
            break;
        }

        switch(fila.firstfive(4)){
            case obj0:
                ostatus4 = false;
            break;
            case obj1:
                Objeto4.setTexture(peixe);
            break;
            case obj2:
                Objeto4.setTexture(ancora);
            break;
            case obj3:
                Objeto4.setTexture(carangueijo);
            break;
            case obj4:
                Objeto4.setTexture(passaro);
            break;
            case obj5:
                Objeto4.setTexture(luneta);
            break;
        }

        switch(fila.firstfive(5)){
            case obj0:
                ostatus5 = false;
            break;
            case obj1:
                Objeto5.setTexture(peixe);
            break;
            case obj2:
                Objeto5.setTexture(ancora);
            break;
            case obj3:
                Objeto5.setTexture(carangueijo);
            break;
            case obj4:
                Objeto5.setTexture(passaro);
            break;
            case obj5:
                Objeto5.setTexture(luneta);
            break;
        }
        window.clear(sf::Color::White);
        window.draw(background);
        if (status1)
            window.draw(Objeto1e);
        if (status2)
            window.draw(Objeto2e);
        if (status3)
            window.draw(Objeto3e);
        if (status4)
            window.draw(Objeto4e);
        if (status5)
            window.draw(Objeto5e);
        if (ostatus1)
            window.draw(Objeto1);
        if (ostatus2)
            window.draw(Objeto2);
        if (ostatus3)
            window.draw(Objeto3);
        if (ostatus4)
            window.draw(Objeto4);
        if (ostatus5)
            window.draw(Objeto5);
        window.draw(timerText);
        window.draw(timerhead);
        window.display();

        if (fila.Contador() == 0){
            return 0; //tela de ganhou do lvl1
        }

        if (countdown == 0){
            return 0; //tela perdeu
        }
    }
    return (-1);
}