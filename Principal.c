#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Lista.h"

void inicio(){
	int i, li = 0, po = 0;
	
	Lista * l1 = criar();
	Lista * l2 = criar();
	Lista * l3 = criar();
	Lista * l4 = criar();
	Lista * l5 = criar();
	Lista * l6 = criar();
	Lista * l7 = criar();
	Lista * l8 = criar();
	Lista * pc = criar();
	Lista * pb = criar();

	//Preecher paredes
	for(i = 0; i < 11; i++){
		inserir_pos(pc, i, 1);
		inserir_pos(pb, i, 1);
	}
	
	//Iniciar livre
	for(i = 0; i < 11; i++){
		inserir_pos(l1, i, 0);
		inserir_pos(l2, i, 0);
		inserir_pos(l3, i, 0);
		inserir_pos(l4, i, 0);
		inserir_pos(l5, i, 0);
		inserir_pos(l6, i, 0);
		inserir_pos(l7, i, 0);
		inserir_pos(l8, i, 0);
	}
	
	//paredes laterais
	escrever_pos(l1, 0,1);
	escrever_pos(l1, 10,1);
	escrever_pos(l2, 0,1);
	escrever_pos(l2, 10,1);
	escrever_pos(l3, 0,1);
	escrever_pos(l3, 10,1);
	escrever_pos(l4, 0,1);
	escrever_pos(l4, 10,1);
	escrever_pos(l5, 0,1);
	escrever_pos(l5, 10,1);
	escrever_pos(l6, 0,1);
	escrever_pos(l6, 10,1);
	escrever_pos(l7, 0,1);
	escrever_pos(l7, 10,1);
	escrever_pos(l8, 0,1);
	escrever_pos(l8, 10,1);
	//preencher posições
	//lista 1
	escrever_pos(pc, 8, 88);
	escrever_pos(l1, 9, 1);
	//lista 2
	escrever_pos(l2, 1,1);
	escrever_pos(l2, 3,1);
	escrever_pos(l2, 4,1);
	escrever_pos(l2, 5,1);
	escrever_pos(l2, 6,1);
	escrever_pos(l2, 7,1);
	escrever_pos(l2, 8,1);
	escrever_pos(l2, 9,1);
	//lista 4
	escrever_pos(l4, 1,1);
	escrever_pos(l4, 2,1);
	escrever_pos(l4, 3,1);
	//lista 5
	escrever_pos(l5, 4,1);
	//lista 6
	escrever_pos(l6, 2,1);
	escrever_pos(l6, 9,1);
	//lista 7
	escrever_pos(l7, 2,1);
	escrever_pos(l7, 4,1);
	escrever_pos(l7, 5,1);
	escrever_pos(l7, 6,1);
	escrever_pos(l7, 9,1);
	//lista 8
	escrever_pos(l8, 2,1);
	escrever_pos(l8, 6,1);
	escrever_pos(l8, 9,1);

	//Impressão
	imprimir(pc);
	imprimir(l1);
	imprimir(l2);
	imprimir(l3);
	imprimir(l4);
	imprimir(l5);
	imprimir(l6);
	imprimir(l7);
	imprimir(l8);
	imprimir(pb);
	
	printf("\n-------------------------------------------\n\nO código de movimento é formado pela linha que você quer ir mais a posição nesta linha.\n\n");]
	printf("Escolha a linha: ");
	scanf("%d", &li);
	printf("Escolha a posição: ");
	scanf("%d", &po);
	
	
	//Destruir
	destruir(l1);
	destruir(l2);
	destruir(l3);
	destruir(l4);
	destruir(l5);
	destruir(l6);
	destruir(l7);
	destruir(l8);
	destruir(pc);
	destruir(pb);
}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	inicio();
	
	
	
	system("pause");
	return 0;
}
