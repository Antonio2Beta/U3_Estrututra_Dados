/* 
  Disciplina: Estrutura de Dados
  Professor: Lima Júnior
  Alunos: Erick Eduardo
          Antonio Vicente
*/
#include "pch.h"
#include <iostream>
#include <stdio.h>     
#include <stdlib.h>    
#include <thread>      
#include <chrono>      

using namespace std;
using namespace chrono;
using namespace this_thread;

typedef struct Reg{
	int info;
	Reg *prox;
}No;

typedef struct fila{
	No *inicio;
	No *final;
	int tam;
}Fila;


void inicializaFila(Fila *f){
	f->inicio = NULL;
	f->final = NULL;
}

Fila *inserirFila(Fila *f, int k){
	No *novo;
	novo = new No;
	novo->info = k;

	if (f->inicio == NULL) {
		f->inicio = novo;
		f->final = novo;
		novo->prox = NULL;
		f->tam++;
	}
	else{
		novo->prox = f->final->prox;
		f->final->prox = novo;
		f->final = novo;
	}
	return f;
}

int F_Vazia(Fila *f){
	return f->inicio == NULL; 
}

Fila *removerFila(Fila *f){
	No *aux;
	aux = f->inicio;

	if (aux == NULL)
		cout << "\n A fila está vazia!" << endl;
	else{
		f->inicio = aux->prox;
		free(aux);
		f->tam--;
	}
	return f;
}

void mostrarFila(Fila *f){
	No *copia;
	copia = f->inicio;
	int cont = 1;
	if (copia == NULL){
		cout << "\n A fila está vazia!" << endl;
	}
	else{
		while (copia != NULL){
			cout << "Fila[" << cont << "]= " << copia->info << endl;
			copia = copia->prox;
			cont++;
		}
	}

}

int GeraValAleatorio(int val[], int QuantNum, int lim){
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
	Fila *F1;
	F1 = new Fila;
	int v = 3;
	inicializaFila(F1);

	while (v != 0) {
		for (int i = 0; i < 3; i++) {
			sleep_for(seconds(3));
			x = GeraValAleatorio(num, 1, 100);
			inserirFila(F1, x);
			cout << "Inserido na Fila" << endl;
			mostrarFila(F1);
			cout << endl;
		}
		sleep_for(seconds(2));
		removerFila(F1);
		cout << "Removido da Fila" << endl;
		mostrarFila(F1);
		cout << endl;

		v--;
	}
	return 0;
}
