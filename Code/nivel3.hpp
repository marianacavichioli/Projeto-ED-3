#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <sstream>


using namespace std;

class nivel3 : public cScreen{
private:
    int posicaox, posicaoy, posicao;
    int countdown = 60;
    Fila fila;
    Objeto opeixe = obj1, oancora = obj2 , ocarangueijo = obj3, opassaro = obj4, oluneta = obj5, lixo, oanzol = obj6, ocavalo = obj7, ocarta = obj8, ocolmeia = obj9, oconcha = obj10, obola =obj11, ocd = obj12, ogarrafa = obj13, ojoaninha = obj14, oossos = obj15;
    bool status1 = true, status2 = true, status3 = true, status4 = true, status5 = true, status6 = true, status7 = true, status8 = true, status9 = true, status10 = true, status11 = true, status12 = true, status13 = true, status14 = true, status15 = true;
    bool ostatus1 = true, ostatus2 = true, ostatus3 = true, ostatus4 = true, ostatus5 = true;
    sf::Texture texture;
    sf::Texture peixeEscondido;
    sf::Texture ancoraEscondida;
    sf::Texture carangueijoEscondido;
    sf::Texture lunetaEscondida;
    sf::Texture passaroEscondido;
    sf::Texture anzolEscondido;
    sf::Texture cavaloEscondido;
    sf::Texture cartaEscondida;
    sf::Texture colmeiaEscondida;
    sf::Texture conchaEscondida;
    sf::Texture bolaEscondida;
    sf::Texture cdEscondido;
    sf::Texture garrafaEscondida;
    sf::Texture joaninhaEscondida;
    sf::Texture ossosEscondido;
    sf::Texture peixe;
    sf::Texture ancora;
    sf::Texture carangueijo;
    sf::Texture luneta;
    sf::Texture passaro;
    sf::Texture anzol;
    sf::Texture cavalo;
    sf::Texture carta;
    sf::Texture colmeia;
    sf::Texture concha;
    sf::Texture bola;
    sf::Texture cd;
    sf::Texture garrafa;
    sf::Texture joaninha;
    sf::Texture ossos;
    sf::Sprite background;
    sf::Font font;
    sf::Clock clockgeral;
    sf::Text timerText;
    sf::Text timerhead;
    std::string countdownString;
    std::ostringstream converter;

public:
    nivel3(void);
    virtual int Run(sf::RenderWindow &window);
};

nivel3::nivel3(void){

}

int nivel3::Run(sf::RenderWindow &window){

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

    if(!anzolEscondido.loadFromFile("../Images/recortadas/anzol_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!cavaloEscondido.loadFromFile("../Images/recortadas/cavalo1_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!cartaEscondida.loadFromFile("../Images/recortadas/carta_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!colmeiaEscondida.loadFromFile("../Images/recortadas/colmeia_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!conchaEscondida.loadFromFile("../Images/recortadas/concha_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!bolaEscondida.loadFromFile("../Images/recortadas/bola_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!cdEscondido.loadFromFile("../Images/recortadas/cd_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!garrafaEscondida.loadFromFile("../Images/recortadas/garrafa_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!joaninhaEscondida.loadFromFile("../Images/recortadas/joaninha_e.png")){
        std::cout << "Error" << std::endl;
    }

    if(!ossosEscondido.loadFromFile("../Images/recortadas/ossos_e.png")){
        std::cout << "Error" << std::endl;
    }


    //Objetos Escondidos
    sf::Sprite Objeto1e(peixeEscondido);
    Objeto1e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto2e(ancoraEscondida);
    Objeto2e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto3e(carangueijoEscondido);
    Objeto3e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto4e(passaroEscondido);
    Objeto4e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto5e(lunetaEscondida);
    Objeto5e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto6e(anzolEscondido);
    Objeto6e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto7e(cavaloEscondido);
    Objeto7e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto8e(cartaEscondida);
    Objeto8e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto9e(colmeiaEscondida);
    Objeto9e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto10e(conchaEscondida);
    Objeto10e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto11e(bolaEscondida);
    Objeto11e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto12e(cdEscondido);
    Objeto12e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto13e(garrafaEscondida);
    Objeto13e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto14e(joaninhaEscondida);
    Objeto14e.setPosition(sf::Vector2f(100,100));

    sf::Sprite Objeto15e(ossosEscondido);
    Objeto15e.setPosition(sf::Vector2f(100,100));

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

    if(!passaro.loadFromFile("../Images/recortadas/passaro_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!anzol.loadFromFile("../Images/recortadas/anzol_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!cavalo.loadFromFile("../Images/recortadas/cavalo_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!carta.loadFromFile("../Images/recortadas/carta_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!colmeia.loadFromFile("../Images/recortadas/colmeia_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!concha.loadFromFile("../Images/recortadas/concha_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!bola.loadFromFile("../Images/recortadas/bola_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!cd.loadFromFile("../Images/recortadas/cd_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!garrafa.loadFromFile("../Images/recortadas/garrafa_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!joaninha.loadFromFile("../Images/recortadas/joaninha_padrao.png")){
        std::cout << "Error" << std::endl;
    }

    if(!ossos.loadFromFile("../Images/recortadas/ossos_padrao.png")){
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
    fila.Insere(oanzol);
    fila.Insere(ocavalo);
    fila.Insere(ocarta);
    fila.Insere(ocolmeia);
    fila.Insere(oconcha);
    fila.Insere(obola);
    fila.Insere(ocd);
    fila.Insere(ogarrafa);
    fila.Insere(ojoaninha);
    fila.Insere(oossos);

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
                            }
                            else if(Objeto2e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj2)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 2" <<std::endl;
                                status2 = false;
                            }
                            else if(Objeto3e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj3)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 3" <<std::endl;
                                status3 = false;
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
                            }
                            else if(Objeto6e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj6)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 6" <<std::endl;
                                status6 = false;
                            }  
                            else if(Objeto7e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj7)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 7" <<std::endl;
                                status7 = false;
                            }  
                            else if(Objeto8e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj8)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 8" <<std::endl;
                                status8 = false;
                            }  
                            else if(Objeto9e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj9)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 9" <<std::endl;
                                status9 = false;
                            }
                            else if(Objeto10e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj10)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 10" <<std::endl;
                                status10 = false;
                            }
                            else if(Objeto11e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj11)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 11" <<std::endl;
                                status11 = false;
                            }
                            else if(Objeto12e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj12)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 12" <<std::endl;
                                status12 = false;
                            }
                            else if(Objeto13e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj13)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 13" <<std::endl;
                                status13 = false;
                            }
                            else if(Objeto14e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj14)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 14" <<std::endl;
                                status14 = false;
                            }
                            else if(Objeto15e.getGlobalBounds().contains(posicaox, posicaoy) && (fila.first() == obj15)){
                                lixo = fila.Retira();
                                std::cout<<"Retirou 15" <<std::endl;
                                status15 = false;
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
            case obj6:
                Objeto1.setTexture(anzol);
            break;
            case obj7:
                Objeto1.setTexture(cavalo);
            break;
            case obj8:
                Objeto1.setTexture(carta);
            break;
            case obj9:
                Objeto1.setTexture(colmeia);
            break;
            case obj10:
                Objeto1.setTexture(concha);
            break;
            case obj11:
                Objeto1.setTexture(bola);
            break;
            case obj12:
                Objeto1.setTexture(cd);
            break;
            case obj13:
                Objeto1.setTexture(garrafa);
            break;
            case obj14:
                Objeto1.setTexture(joaninha);
            break;
            case obj15:
                Objeto1.setTexture(ossos);
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
            case obj6:
                Objeto2.setTexture(anzol);
            break;
            case obj7:
                Objeto2.setTexture(cavalo);
            break;
            case obj8:
                Objeto2.setTexture(carta);
            break;
            case obj9:
                Objeto2.setTexture(colmeia);
            break;
            case obj10:
                Objeto2.setTexture(concha);
            break;
            case obj11:
                Objeto2.setTexture(bola);
            break;
            case obj12:
                Objeto2.setTexture(cd);
            break;
            case obj13:
                Objeto2.setTexture(garrafa);
            break;
            case obj14:
                Objeto2.setTexture(joaninha);
            break;
            case obj15:
                Objeto2.setTexture(ossos);
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
            case obj6:
                Objeto3.setTexture(anzol);
            break;
            case obj7:
                Objeto3.setTexture(cavalo);
            break;
            case obj8:
                Objeto3.setTexture(carta);
            break;
            case obj9:
                Objeto3.setTexture(colmeia);
            break;
            case obj10:
                Objeto3.setTexture(concha);
            break;
            case obj11:
                Objeto3.setTexture(bola);
            break;
            case obj12:
                Objeto3.setTexture(cd);
            break;
            case obj13:
                Objeto3.setTexture(garrafa);
            break;
            case obj14:
                Objeto3.setTexture(joaninha);
            break;
            case obj15:
                Objeto3.setTexture(ossos);
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
            case obj6:
                Objeto4.setTexture(anzol);
            break;
            case obj7:
                Objeto4.setTexture(cavalo);
            break;
            case obj8:
                Objeto4.setTexture(carta);
            break;
            case obj9:
                Objeto4.setTexture(colmeia);
            break;
            case obj10:
                Objeto4.setTexture(concha);
            break;
            case obj11:
                Objeto4.setTexture(bola);
            break;
            case obj12:
                Objeto4.setTexture(cd);
            break;
            case obj13:
                Objeto4.setTexture(garrafa);
            break;
            case obj14:
                Objeto4.setTexture(joaninha);
            break;
            case obj15:
                Objeto4.setTexture(ossos);
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
            case obj6:
                Objeto5.setTexture(anzol);
            break;
            case obj7:
                Objeto5.setTexture(cavalo);
            break;
            case obj8:
                Objeto5.setTexture(carta);
            break;
            case obj9:
                Objeto5.setTexture(colmeia);
            break;
            case obj10:
                Objeto5.setTexture(concha);
            break;
            case obj11:
                Objeto5.setTexture(bola);
            break;
            case obj12:
                Objeto5.setTexture(cd);
            break;
            case obj13:
                Objeto5.setTexture(garrafa);
            break;
            case obj14:
                Objeto5.setTexture(joaninha);
            break;
            case obj15:
                Objeto5.setTexture(ossos);
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
        if (status6)
            window.draw(Objeto6e);
        if (status7)
            window.draw(Objeto7e);
        if (status8)
            window.draw(Objeto8e);
        if (status9)
            window.draw(Objeto9e);
        if (status10)
            window.draw(Objeto10e);
        if (status11)
            window.draw(Objeto11e);
        if (status12)
            window.draw(Objeto12e);
        if (status13)
            window.draw(Objeto13e);
        if (status14)
            window.draw(Objeto14e);
        if (status15)
            window.draw(Objeto15e);
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