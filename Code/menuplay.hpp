#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
//#define Itens 3

class menuplay{
public:
	menuplay (float width, float height);
	~menuplay();

	void draw(sf::RenderWindow &window);
	void Position(int posicaox, int posicaoy);
	int GetPressedItem(int posicaox, int posicaoy);

private:
	int SelectedItemIndex;
	int posicaox, posicaoy, posicao;
	sf::Font font;
	sf::Text menu[4];
};

menuplay::menuplay(float width, float height){

	if (!font.loadFromFile("../Fonts/PirataOne-Regular.ttf")){
		std::cout << "Error" << std::endl;
	}

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Nivel 1");
	menu[1].setPosition(sf::Vector2f(350,220));	
	menu[1].setCharacterSize(50);		

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Nivel 2");
	menu[2].setPosition(sf::Vector2f(350, 300));	
	menu[2].setCharacterSize(50);	

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Nivel 3");
	menu[3].setPosition(sf::Vector2f(350, 380));	
	menu[3].setCharacterSize(50);	
}

menuplay::~menuplay(){

}

void menuplay::draw(sf::RenderWindow &window){
	/*for(int i=1; i < 4; i++){
		window.draw(menu[i]);
	}*/
}


void menuplay::Position(int posicaox, int posicaoy){

	posicao = 0;

	if (posicaoy>=230 && posicaoy<=281){
		if (posicaox>= 345 && posicaox<=447){
			posicao = 1;

		}
	}
	else if (posicaoy>=308 && posicaoy<=360){
		if (posicaox>= 299 && posicaox<=505){
			posicao = 2;

		}	
	}

	else if (posicaoy>=389 && posicaoy<=433){
		if (posicaox>= 356 && posicaox<=429){
			posicao = 3;

		}	
	}

	menu[1].setColor(sf::Color::White);
	menu[2].setColor(sf::Color::White);
	menu[3].setColor(sf::Color::White);

	if (posicao == 1){
		menu[1].setColor(sf::Color::Red);
	}
	else if(posicao == 2){
		menu[2].setColor(sf::Color::Red);
	}
	else if(posicao == 3){
		menu[3].setColor(sf::Color::Red);
	}
}


int menuplay::GetPressedItem(int posicaox, int posicaoy){


	if (posicaoy>=230 && posicaoy<=281){
		if (posicaox>= 345 && posicaox<=447){
			SelectedItemIndex = 4;

		}
	}
	else if (posicaoy>=308 && posicaoy<=360){
		if (posicaox>= 299 && posicaox<=505){
			SelectedItemIndex = 5;

		}	
	}

	else if (posicaoy>=389 && posicaoy<=433){
		if (posicaox>= 356 && posicaox<=429){
			SelectedItemIndex = 6;

		}	
	}

	cout << SelectedItemIndex << endl;
	return SelectedItemIndex;
}