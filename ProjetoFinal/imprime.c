#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "imprime.h"
#include "FilaEstatica.h"
#include "FilaDinamica.h"

void imprimeLogo(){
	printf("==================================================\n");
	printf("==                                              ==\n")/
	printf("==  =======     =====    ===   ==     = =   ==  ==\n")/
	printf("==  =     =     =    =   ===   = =    = =  ==   ==\n")/
	printf("==  =     =  == =    =  =   =  =  =   = = ==    ==\n");
	printf("==  =     =     ======  = = =  =   =  = ==      ==\n");
	printf("==  =   = =  	=    = =     = =    = = = ==    ==\n");
	printf("==  =======     =====  =     = =     == =  ==   ==\n");
	printf("==         =                                    ==\n");
	printf("==                                              ==\n");
	printf("==================================================\n");	
	printf("\n\n");
}

void imprimeEscolha(){
	printf("Escolha a fila que deseja utilizar:\n\n");
	printf("Digite 1 para fila dinâmica:\n");
	printf("Digite 2 para fila estática:\n");
}

void imprimeMenu(){
	printf("0. Encerrar Fila\n");
	printf("1. Inserir uma pessoa;\n");
	printf("2. Atender uma pessoa;\n");
//	printf("3. verificar se a fila esta vazia:\n");
//	printf("4. imprimir a fila:\n\n");
	printf("Selecione alguma das opcoes acima:");
}

void imprimeCaixa(){
	printf("\n\n");
	printf("==========\n");
	printf("= GUICHE =\n");
	printf("==========\n\n");
}

void imprimeErro(){
	printf("ERROR: Valor invalido!\n\n"); 
	printf("Aperte ENTER para continuar\n");
	system("pause");
}

void limpaTela(){
	printf("\n");
	system("pause");
	system("cls");
}

void imprimeFilaVazia(Fila * fila){
	if(fila->inicio==NULL){
		printf("\nFila Vazia!\n");
	}
	else printf("\nA Fila Não Está Vazia!");
}

void imprimeFilaCheia_estatica(Fila_estatica minhaFila){
	if(filaCheiaEstatica(minhaFila)) //testa se a fila está cheia;
		printf("A fila esta cheia!\n");
	else printf("A fila nao esta cheia!\n");
}

void imprimeFilaVazia_estatica(Fila_estatica minhaFila){
	if(filaVaziaEstatica(minhaFila)) //testa se a fila está vazia;
		printf("A fila esta vazia!\n");
	else printf("A fila nao esta vazia!\n");
}

void encerraFila(){
	limpaTela();
	printf("\tENCERRANDO A FILA DO BANCO\n\n\n");
	printf("Aperte ENTER para encerrar:\n");
	system("pause");
}
