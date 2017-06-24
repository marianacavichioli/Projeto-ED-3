#include <iostream>
#include <cstdlib>
using namespace std;

//lista menor = lista de objetos a serem procurados
//lista maior = lista de objetos disponiveis






//CLASSES

class Objeto {
	private:
		int indice;
		
	public:
		int getIndice();
		Objeto(int);
		Objeto();
};

struct node{
	
	Objeto info;
	
	struct node *next;
};

//cada objeto possui seu indice que será usado para ser procurado na lista, esse indice
//sera inserido manualmente no construtor, então na primeira vez que os itens tiverem que ser
//dispostos na tela, vai ser necessário declarar TODOS os objetos e colocar indices neles


class Lista { 			
	private: 
		node *primeiro;
		
	public:
		Lista();
		Objeto Retira(Objeto&);
		void Insere();
		bool Compara(Objeto&);
		bool Vazia();
};


//METODOS

Objeto::Objeto(){
	
}
	
Objeto::Objeto(int i) {
	indice = i;
}

int Objeto::getIndice() {
	return indice;
}


Lista::Lista() {
	primeiro = NULL;
}

void Lista::Insere(){
	//estou confusa em como fazer esse método ainda
}

Objeto Lista::Retira(Objeto &o1){				//esse metodo tem q ser chamado na lista maior
	node *aux1, *aux2;
	Objeto x;
	aux1 = primeiro;
	aux2 = NULL;
	
	while (aux1->info.getIndice() != o1.getIndice() || aux1 == NULL ){
		aux1 = aux1->next;
		aux2->next = aux1;
	}
	
	if (aux1->info.getIndice() == o1.getIndice()){
		if (aux1->next == NULL){
			x = aux1->info;
			delete aux1;
		} else if (aux1 == primeiro){
				x = aux1->info;
				aux1->next = primeiro;
				aux1->next = NULL;
				delete aux1;
			} else {
					x = aux1->info;
					aux2->next = aux1->next;
					aux1->next = NULL;
					delete aux1;
				}
		return x;
	}
}

bool Lista::Compara(Objeto& o1){			//esse metodo tem que ser chamado na lista menor, quando se retirar um elemento da lista maior
	node *aux1, *aux2;
	Objeto x;
	aux1 = primeiro;
	aux2 = NULL;
	
	while (aux1->info.getIndice() != o1.getIndice() || aux1 == NULL ){
		aux1 = aux1->next;
		aux2->next = aux1;
	}
	
	if (aux1->info.getIndice() == o1.getIndice()){
		this->Retira(o1);
		return true;
	} else
		return false;
	
}

bool Lista::Vazia(){
	if (primeiro == NULL)
		return true;
	else
		return false;
}


int main(){
	
	
	
	return 0;
}


