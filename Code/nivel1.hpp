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

    if(!peixe.loadFromFile("../Images/recortadas/peixe_padrao.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!ancora.loadFromFile("../Images/recortadas/ancora_padrao.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!carangueijo.loadFromFile("../Images/recortadas/carangueijo_padrao.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!luneta.loadFromFile("../Images/recortadas/luneta_padrao.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!passaro.loadFromFile("../Images//recortadas/passara_padrao.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!peixe_c.loadFromFile("../Images/recortadas/peixe_padrao_c.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!ancora_c.loadFromFile("../Images/recortadas/ancora_padrao_c.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!carangueijo_c.loadFromFile("../Images/recortadas/carangueijo_padrao_c.bmp")){
        std::cout << "Error" << std::endl;
    }

    if(!luneta_c.loadFromFile("../Images/recortadas/luneta_padrao_c.bmp")){
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
    std::cout << fila.Contador() << endl;
    if (fila.first() == obj1)
        std::cout << "Acho que deu bom" << endl;
    if (fila.first() == obj3)
        std::cout << "Ai deu ruim" << endl;

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
        window.draw(Objeto1);
        window.draw(Objeto2);
        window.draw(Objeto3);
        window.draw(Objeto4);
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