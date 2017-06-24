#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#define Max_Itens 7

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

	if (!font.loadFromFile("../Fonts/mmsarica_csi.ttf")){
		std::cout << "Error" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::White);
	menu[0].setString("WHERE ARE YOU?");
	menu[0].setPosition(sf::Vector2f(150,60));	
	menu[0].setCharacterSize(70);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Choose a Scene: ");
	menu[1].setPosition(sf::Vector2f(240,200));	
	menu[1].setCharacterSize(50);	

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Scene 1");
	menu[2].setPosition(sf::Vector2f(330,260));	
	menu[2].setCharacterSize(40);

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Scene 2");
	menu[3].setPosition(sf::Vector2f(330, 300));	
	menu[3].setCharacterSize(40);

	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString("Scene 3");
	menu[4].setPosition(sf::Vector2f(330, 340));	
	menu[4].setCharacterSize(40);	

	menu[5].setFont(font);
	menu[5].setColor(sf::Color::White);
	menu[5].setString("How to Play");
	menu[5].setPosition(sf::Vector2f(280, 420));	
	menu[5].setCharacterSize(50);	

	menu[6].setFont(font);
	menu[6].setColor(sf::Color::White);
	menu[6].setString("Exit");
	menu[6].setPosition(sf::Vector2f(350, 500));	
	menu[6].setCharacterSize(50);	

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

	if (posicaoy>=271 && posicaoy<=302){
		if (posicaox>= 332 && posicaox<=442){
			posicao = 1;

		}
	}
	else if (posicaoy>=310 && posicaoy<=342){
		if (posicaox>= 332 && posicaox<=442){
			posicao = 2;

		}
	}
	else if (posicaoy>=351 && posicaoy<=383){
		if (posicaox>= 332 && posicaox<=442){
			posicao = 3;

		}	
	}
	else if (posicaoy>=435 && posicaoy<=472){
		if (posicaox>= 281 && posicaox<=496){
			posicao = 4;

		}	
	}

	else if (posicaoy>=515 && posicaoy<=553){
		if (posicaox>= 351 && posicaox<=427){
			posicao = 5;

		}	
	}

	menu[2].setColor(sf::Color::White);
	menu[3].setColor(sf::Color::White);
	menu[4].setColor(sf::Color::White);
	menu[5].setColor(sf::Color::White);
	menu[6].setColor(sf::Color::White);

	if (posicao == 1){
		menu[2].setColor(sf::Color::Red);
	}
	else if(posicao == 2){
		menu[3].setColor(sf::Color::Red);
	}
	else if(posicao == 3){
		menu[4].setColor(sf::Color::Red);
	}
	else if(posicao == 4){
		menu[5].setColor(sf::Color::Red);
	}
	else if(posicao == 5){
		menu[6].setColor(sf::Color::Red);
	}
}


int Menu::GetPressedItem(int posicaox, int posicaoy){


	if (posicaoy>=271 && posicaoy<=302){
		if (posicaox>= 332 && posicaox<=442){
			SelectedItemIndex = 1;

		}
	}
	else if (posicaoy>=310 && posicaoy<=342){
		if (posicaox>= 332 && posicaox<=442){
			SelectedItemIndex = 2;

		}
	}
	else if (posicaoy>=351 && posicaoy<=383){
		if (posicaox>= 332 && posicaox<=442){
			SelectedItemIndex = 3;

		}	
	}
	else if (posicaoy>=435 && posicaoy<=472){
		if (posicaox>= 281 && posicaox<=496){
			SelectedItemIndex = 4;

		}	
	}

	else if (posicaoy>=515 && posicaoy<=553){
		if (posicaox>= 351 && posicaox<=427){
			SelectedItemIndex = 5;

		}	
	}

	cout << SelectedItemIndex << endl;
	return SelectedItemIndex;
}