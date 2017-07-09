#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#define Max_Itens 4

using namespace std;

class Menu{
public:
	Menu (float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void Position(int posicaox, int posicaoy);
	int GetPressedItem(int posicaox, int posicaoy);

private:
	int SelectedItemIndex;
	int posicaox, posicaoy, posicao;
	sf::Font font;
	sf::Text menu[Max_Itens];
};

Menu::Menu(float width, float height){

	if (!font.loadFromFile("../Fonts/PirataOne-Regular.ttf")){
		std::cout << "Error" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Black);
	menu[0].setString("Where are ye?");
	menu[0].setPosition(sf::Vector2f(195,60));	
	menu[0].setCharacterSize(70);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Black);
	menu[1].setString("Jogar");
	menu[1].setPosition(sf::Vector2f(350,220));	
	menu[1].setCharacterSize(50);		

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Black);
	menu[2].setString("Como Jogar");
	menu[2].setPosition(sf::Vector2f(300, 300));	
	menu[2].setCharacterSize(50);	

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::Black);
	menu[3].setString("Sair");
	menu[3].setPosition(sf::Vector2f(355, 380));	
	menu[3].setCharacterSize(50);	

	SelectedItemIndex = 0;
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window){
	for(int i=0; i < Max_Itens; i++){
		window.draw(menu[i]);
	}
}


void Menu::Position(int posicaox, int posicaoy){

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

	menu[1].setColor(sf::Color::Black);
	menu[2].setColor(sf::Color::Black);
	menu[3].setColor(sf::Color::Black);

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


int Menu::GetPressedItem(int posicaox, int posicaoy){


	if (posicaoy>=230 && posicaoy<=281){
		if (posicaox>= 345 && posicaox<=447){
			SelectedItemIndex = 1;

		}
	}
	else if (posicaoy>=308 && posicaoy<=360){
		if (posicaox>= 299 && posicaox<=505){
			SelectedItemIndex = 2;

		}	
	}

	else if (posicaoy>=389 && posicaoy<=433){
		if (posicaox>= 356 && posicaox<=429){
			SelectedItemIndex = 3;

		}	
	}

	cout << SelectedItemIndex << endl;
	return SelectedItemIndex;
}