#include <iostream>
#include <cstdlib>
using namespace std;

enum Objeto {obj1, obj2, obj3, obj4, obj5, obj6, obj7, obj8, obj9, obj10, obj11, obj12, obj13, obj14, obj15};

struct node{
	
	Objeto info;
	
	struct node *next;
};

class Fila {
		private:
			node *primeiro;
			node *ultimo;
			
		public:
			Fila();
			void Insere(Objeto&);
			Objeto Retira();
			bool Vazia();
			int Contador();	
};

Fila::Fila() {
	primeiro = NULL;
	ultimo = NULL;
}

void Fila::Insere(Objeto& o1){
	
	node *aux = new node;
	
	if (primeiro == NULL && ultimo == NULL){
		aux->info = o1;
		primeiro = aux;
		ultimo = aux;
		primeiro->next = primeiro;
		aux = NULL;
		delete aux;
		
	} else if (primeiro == ultimo) {
			aux->info = o1;
			primeiro->next = aux;
			aux->next = primeiro;
			ultimo = aux;
			aux = NULL;
			delete aux;

		} else if (primeiro->next == ultimo){
				aux->info = o1;
				ultimo->next = aux;
				ultimo = aux;
				ultimo->next = primeiro;
				aux = NULL;
				delete aux;				
			}
}

Objeto Fila::Retira(){
	
	Objeto r;
	node *aux = new node;
	
	if (primeiro == ultimo){
		r = primeiro->info;
		primeiro = NULL;
		ultimo = NULL;
		
	}else if (primeiro->next == ultimo){
			r = primeiro->info;
			ultimo->next = ultimo;
			aux = primeiro;
			primeiro = ultimo;
			delete aux;
			
		} else {
				r = primeiro->info;
				aux = primeiro;
				primeiro = primeiro->next;
				ultimo->next = primeiro;
				delete aux;
			}
	return r;
}

bool Fila::Vazia(){
	if (primeiro == NULL && ultimo == NULL)
		return true;
	else
		return false;
}

int Fila::Contador(){
	Fila aux1;
	Objeto o;
	int i = 0;
	while (this->Vazia() != true){
		o = this->Retira();
		aux1.Insere(o);
		i++;
	}
	while(aux1.Vazia() != true){
		o = aux1.Retira();
		this->Insere(o);
	}
	return i;
}
	
/* Para testar a estrutura basta descomentar essa parte e salvar o arquivo como fila.cpp
int main() {
		
	Fila f1;
	Objeto lixo;
	Objeto teste = obj1;
	
	if(f1.Vazia() == true)
		cout << "deu bom"<< endl;
	else
		cout << "deu ruim" << endl;
	
	f1.Insere(teste);
	f1.Insere(teste);
	f1.Insere(teste);
	cout << "Inseriu os objs" << endl;
	cout << f1.Contador() << endl;
	
	lixo = f1.Retira();
	cout << "Retirou" << endl;
	cout << f1.Contador() << endl;	
		
	return 0;
}
*/