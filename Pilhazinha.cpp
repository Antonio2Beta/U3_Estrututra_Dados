/* Disciplina: Estrutura de Dados
   Professor: Lima Júnior
   Alunos: Antonio Vicente
           Erick Eduardo
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <thread>        
#include <chrono> 

using namespace std;
using namespace chrono;
using namespace this_thread;

typedef struct Reg{
	int info;
	Reg *prox;
} No;

typedef struct pilha{
	No *Topo;
	int tamanho;
}Pilha;

Pilha *iniciaPilha(Pilha *PL){
	PL->Topo = NULL;
	PL->tamanho = 0;
	return PL;
}

int P_Vazia(Pilha *PL){
	return(PL->Topo == NULL);
}

Pilha *adicionar(Pilha *PL, int k){
	No *novo;
	novo = new No;
	novo->info = k;
	novo->prox = PL->Topo;
	PL->Topo = novo;
	PL->tamanho++;
	return PL;
}

Pilha *remover(Pilha *PL){
	No *aux;
	int sai;
	if (P_Vazia(PL))
		cout << "\nA pilha está vazia!" << endl;
	else{
		aux = PL->Topo;
		PL->Topo = aux->prox;
		sai = aux->info;
		cout << "\n" << sai << " Removido da pilha! " << endl;
		PL->tamanho--;
		delete aux;
	}
	return PL;
}

void imprimirPilha(Pilha *PL){
	No *copia;
	copia = PL->Topo;
	int cont = 1;
	if (P_Vazia(PL))
		cout << "A pilha está vazia!" << endl;
	else
		while (copia != NULL){
			cout << "Pilha[" << cont << "] = " << copia->info << endl;
			copia = copia->prox;
			cont++;
		}
}


int GeraValorAleatorio(int val[], int QuantNum, int lim){
	int N;
	srand(time(NULL));
	for (int i = 0; i < QuantNum; i++){
		val[i] = rand() % lim;
		N = val[i];
	}
	return N;
}

int main(){
	int x;
	int num[100];
	Pilha *PL;
	PL = new Pilha;
	int v = 10;
	iniciaPilha(PL);

	while (v != 0){	
		while(PL->tamanho<=19){
		for (int i = 0; i < 1; i++) {   

			sleep_for(seconds(3));
			x = GeraValorAleatorio(num, 1, 100);
			adicionar(PL, x);
			cout << "Inserido na Pilha" << endl;
			imprimirPilha(PL);
			cout << endl;
		}
		}
		sleep_for(seconds(2));
		remover(PL);
		imprimirPilha(PL);
		cout << endl;

		v--;
	}

	return 0;
}
