#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Lista.h"
#include "lab.h"

struct lab{
	Lista * l1;
	Lista * l2;
	Lista * l3;
	Lista * l4;
	Lista * l5;
	Lista * l6;
	Lista * l7;
	Lista * l8;
	Lista * pc;
	Lista * pb;
	Lista * pl;
    Lista * la;
    Lista * aux;
    Lista * listaAtual;
    int pp, pa, con, laI, plI;
};

Lab * criarLab(){
	Lab * l = malloc(sizeof(Lab));
	l->pb = criar();
	l->pc = criar();
	l->l1 = criar();
	l->l2 = criar();
	l->l3 = criar();
	l->l4 = criar();
	l->l5 = criar();
	l->l6 = criar();
	l->l7 = criar();
	l->l8 = criar();
	
	return l;
}

void destruirLab(Lab * l){
	if(l != NULL){
		destruir(l->l1);
		destruir(l->l2);
		destruir(l->l3);
		destruir(l->l4);
		destruir(l->l5);
		destruir(l->l6);
		destruir(l->l7);
		destruir(l->l8);
		destruir(l->pc);
		destruir(l->pb);
		free(l);
	}
}

void inicio(){
	Lab * l = criarLab();
	inicializar(l);
	
	
	movimento(l);
}

void inicializar(Lab * l){
	int i;
	//Lista e posições iniciais
	l->la = l->l4;
	l->pl = l->l3;
	l->laI = 4;
	l->plI = 3;
	l->pa = 4;
	l->pp = 0;
	
	//Preecher paredes
	for(i = 0; i < 11; i++){
		inserir_pos(l->pc, i, 1);
		inserir_pos(l->pb, i, 1);
	}
	
	//Preencher parades com fechamentos
	for(i = 0; i < 11; i++){
		inserir_pos(l->l1, i, 1);
		inserir_pos(l->l2, i, 1);
		inserir_pos(l->l3, i, 1);
		inserir_pos(l->l4, i, 1);
		inserir_pos(l->l5, i, 1);
		inserir_pos(l->l6, i, 1);
		inserir_pos(l->l7, i, 1);
		inserir_pos(l->l8, i, 1);
	}
	
	for(i = 2; i < 8; i++){
		escrever_pos(l->l2, i, 0);
		escrever_pos(l->l7, i, 0);
	}
	//Paredes laterais
	/*escrever_pos(l->l1, 0,1);
	escrever_pos(l->l1, 10,1);
	escrever_pos(l->l2, 0,1);
	escrever_pos(l->l2, 10,1);
	escrever_pos(l->l3, 0,1);
	escrever_pos(l->l3, 10,1);
	escrever_pos(l->l4, 0,1);
	escrever_pos(l->l4, 10,1);
	escrever_pos(l->l5, 0,1);
	escrever_pos(l->l5, 10,1);
	escrever_pos(l->l6, 0,1);
	escrever_pos(l->l6, 10,1);
	escrever_pos(l->l7, 0,1);
	escrever_pos(l->l7, 10,1);
	escrever_pos(l->l8, 0,1);
	escrever_pos(l->l8, 10,1);*/
	//Preencher posições
	//lista 1
	escrever_pos(l->l1, 6, 9);
	//lista 3
	escrever_pos(l->l3, 2,0);
	escrever_pos(l->l3, 7,0);
	//lista 4
	escrever_pos(l->l4, 2,0);
	escrever_pos(l->l4, 4,5);
	escrever_pos(l->l4, 6,0);
	escrever_pos(l->l4, 7,0);
	//lista 5
	escrever_pos(l->l5, 2,0);
	escrever_pos(l->l5, 4,0);
	escrever_pos(l->l5, 7,0);
	//lista 6
	escrever_pos(l->l6, 2,0);
	escrever_pos(l->l6, 4,0);
	escrever_pos(l->l6, 6,1);
	escrever_pos(l->l6, 7,0);
	 	
	escrever_pos(l->l7, 5,1);
	
}

void movimento(Lab * l){
	
	system("cls");
	
	printf("PA: %d\n", l->pa);
	printf("PP: %d\n", l->pp);
	//Impressão
	imprimir(l->pc);
	imprimir(l->l1);
	imprimir(l->l2);
	imprimir(l->l3);
	imprimir(l->l4);
	imprimir(l->l5);
	imprimir(l->l6);
	imprimir(l->l7);
	imprimir(l->l8);
	imprimir(l->pb);
	
	printf("\n\n");
	system("pause");
	
	if(l->pl != l->l1 && l->pp != 88){
		cima(l);
		baixo(l);
		direita(l);
		esquerda(l);
	
	}else{
		printf("\n\n\nT E R M I N O U!\n");
		//destruirLab(l);
	}
}

void cima(Lab * l){
	l->pp = l->pa;
	defPL(l, 0);
	if(ler_pos(l->pl, l->pp) == 0 || ler_pos(l->pl, l->pp) == 9)
		if(l->aux != l->pl){
			escrever_pos(l->pl, l->pp, 5);
			escrever_pos(l->la, l->pa, 0);
			l->aux = l->la;
			l->la = l->pl;
			l->laI = l->plI;
			movimento(l);
		}
}
void baixo(Lab * l){
	l->pp = l->pa;
	defPL(l, 1);
	if(ler_pos(l->pl, l->pp) == 0 || ler_pos(l->pl, l->pp) == 9)
		if(l->aux != l->pl){
			escrever_pos(l->pl, l->pp, 5);
			escrever_pos(l->la, l->pa, 0);
			l->aux = l->la;
			l->la = l->pl;
			l->laI = l->plI;
			movimento(l);
		}
}
void direita(Lab * l){
	l->pp = l->pa + 1;
	if(ler_pos(l->listaAtual, (l->pp)) == 0){
		//l->pp = l->pp + 1;
		int t = 0;
		//l->pp = l->pa + 1;
		escrever_pos(l->listaAtual, l->pp, 5);
		escrever_pos(l->listaAtual, l->pa, 0);
		//(l->pa)++;
		t = l->pa;
		l->pa = l->pp;
		l->pp = t;
		
		l->aux = l->la;
		movimento(l);
	}
	(l->pp)--;
}

void esquerda(Lab * l){
	l->pp = l->pa - 1;
	if(ler_pos(l->listaAtual, (l->pp)) == 0){
		//l->pp = l->pp - 1;
		int t = 0;
		//l->pp = l->pa - 1;		
		escrever_pos(l->listaAtual, l->pp, 5);
		escrever_pos(l->listaAtual, l->pa, 0);
		//(l->pa)--;
		t = l->pa;
		l->pa = l->pp;
		l->pp = t-1;
		
		l->aux = l->la;
		movimento(l);
	}
	(l->pp)++;
}

void defPL(Lab * l, int cod){
	
	if(cod == 0)
		switch(l->laI){
	        case 1:
	        	l->laI = 1;
	        	l->plI = 0;
	        	l->listaAtual = l->l1;
	            l->pl = l->pc;
	            break;
	        case 2:
	        	l->laI = 2;
	        	l->plI = 1;
	        	l->listaAtual = l->l2;
	            l->pl = l->l1;
	            break;
	        case 3:
	        	l->laI = 3;
	        	l->plI = 2;
	        	l->listaAtual = l->l3;
	            l->pl = l->l2;
	            break;
	        case 4:
	        	l->laI = 4;
	        	l->plI = 3;
	        	l->listaAtual = l->l4;
	            l->pl = l->l3;
	            break;
	        case 5:
	        	l->laI = 5;
	        	l->plI = 4;
	        	l->listaAtual = l->l5;
	            l->pl = l->l4;
	            break;
	        case 6:
	        	l->laI = 6;
	        	l->plI = 5;
	        	l->listaAtual = l->l6;
	            l->pl = l->l5;
	            break;
	        case 7:
	        	l->laI = 7;
	        	l->plI = 6;
	        	l->listaAtual = l->l7;
	            l->pl = l->l6;
	            break;
	        case 8:
	        	l->laI = 8;
	        	l->plI = 7;
	        	l->listaAtual = l->l8;
	            l->pl = l->l7;
	            break;
	        default:
	            break;
	    }  
	if(cod == 1)
		switch(l->laI){
	        case 0:
	        	l->laI = 0;
	        	l->plI = 1;
	        	l->listaAtual = l->pc;
	            l->pl = l->l1;
	            break;
	        case 1:
	        	l->laI = 1;
	        	l->plI = 2;
	        	l->listaAtual = l->l1;
	            l->pl = l->l2;
	            break;
	        case 2:
	        	l->laI = 2;
	        	l->plI = 3;
	        	l->listaAtual = l->l2;
	            l->pl = l->l3;
	            break;
	        case 3:
	        	l->laI = 3;
	        	l->plI = 4;
	        	l->listaAtual = l->l3;
	            l->pl = l->l4;
	            break;
	        case 4:
	        	l->laI = 4;
	        	l->plI = 5;
	        	l->listaAtual = l->l4;
	            l->pl = l->l5;
	            break;
	        case 5:
	        	l->laI = 5;
	        	l->plI = 6;
	        	l->listaAtual = l->l5;
	            l->pl = l->l6;
	            break;
	        case 6:
	        	l->laI = 6;
	        	l->plI = 7;
	        	l->listaAtual = l->l6;
	            l->pl = l->l7;
	            break;
	        case 7:
	        	l->laI = 7;
	        	l->plI = 8;
	        	l->listaAtual = l->l7;
	            l->pl = l->l8;
	            break;
	        default:
	            break;
	    } 
	
	/*
	if(cod == 0)
		switch(l->la){
	        case l->l1:
	            l->pl = l->pc;
	            break;
	        case l->l2:
	            l->pl = l->l1;
	            break;
	        case l->l3;
	            l->pl = l->l2;
	            break;
	        case l->l4:
	            l->pl = l->l3;
	            break;
	        case l->l5:
	            l->pl = l->l4;
	            break;
	        case l->l6:
	            l->pl = l->l5;
	            break;
	        case l->l7:
	            l->pl = l->l6;
	            break;
	        case l->l8:
	            l->pl = l->l7;
	            break;
	        default:
	            break;
	    }  
	if(cod == 1)
		switch(l->la){
	        case l->pc:
	            l->pl = l->l1;
	            break;
	        case l->l1:
	            l->pl = l->l2;
	            break;
	        case l->l2:
	            l->pl = l->l3;
	            break;
	        case l->l3:
	            l->pl = l->l4;
	            break;
	        case l->l4:
	            l->pl = l->l5;
	            break;
	        case l->l5:
	            l->pl = l->l6;
	            break;
	        case l->l6:
	            l->pl = l->l7;
	            break;
	        case l->l7:
	            l->pl = l->l8;
	            break;
	        default:
	            break;
	    } */
}

