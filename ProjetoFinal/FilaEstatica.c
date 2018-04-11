#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "FilaEstatica.h"

const int TRUE = 1;
const int FALSE = 0;
const int tamanho = 30;

//Esta fun��o vai criar uma estrutura que ir� controlar a fila;
Fila_estatica criaFilaEstatica(){
	Fila_estatica fila;
	fila.inicio=0; //Esta linha afirma que o in�cio da fila ser� no indice 0 do vetor;
	fila.final=-1; //Esta linha � setada com -1 pelo fato de -1 ser um indice imposs�vel do vetor, dizendo assim que a estutura ainda n�o tem nenhum item;
	fila.senha=0;
	fila.ultimo=0;
	return fila;
}

//Esta fun��o serve para organizer os dados de nome, idade e Nivel de atendimento preferencial dentro;
//de uma estrutura do tipo Pessoa, declarada na linha 6;
Pessoa_estatica criaPessoaEstatica(Fila_estatica * minhaFila){
	Pessoa_estatica pessoa;
	fflush(stdin);
	system("cls");
	printf("\nInforme seu nivel preferencial de 0 a 3:\n");
	scanf("%d",&pessoa.nivelPreferencial);
	minhaFila->senha+=1;
	pessoa.senha=minhaFila->senha;
	pessoa.tempoEspera=0;
	return pessoa;
}


//Esta fun��o serve para inserir uma pessoa dentro da fila;
//Ela ainda n�o trada os niveis de atendimento preferencial;
Fila_estatica insereFilaEstatica(Fila_estatica minhaFila){
	if(filaCheiaEstatica(minhaFila)){ //testa se a fila est� cheia;
		printf("ERROR: Fila cheia!\n");
	}
	else{
		Pessoa_estatica pessoa = criaPessoaEstatica(&minhaFila);
		if(minhaFila.final==-1){ //testa se a fila est� totalmente vazia;
			minhaFila.fila[minhaFila.inicio] = pessoa; //e insere no in�cio;
			minhaFila.final = minhaFila.inicio; //como a fila s� tem uma pessoa, o in�cio ser� igual ao final da fila;
		}
		else{
			if((minhaFila.final==tamanho-1)&&(minhaFila.inicio>0)){ //testa se a fila precisa dar uma volta do ultimo �ndice para o �ndice 0;
				minhaFila.final=0; //continua a fila de maneira circular no in�cio do vetor (�ndice 0);
				minhaFila.fila[minhaFila.final] = pessoa;
			}
			else{
				minhaFila.final = minhaFila.final + 1; //Ap�s testar todos os casos ele cai no caso se simplesmente inserir no final da fila;
				minhaFila.fila[minhaFila.final] = pessoa;
			}
		}
		printf("Inserido com sucesso!\n");	
	}
	return minhaFila; 	
}


/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
//NAO FUNCIONA
//Esta fun��o serve para remover algu�m da fila (atender alguma pessoa);
Fila_estatica removeFilaEstatica(Fila_estatica minhaFila){
	if(filaVaziaEstatica(minhaFila)){
		printf("ERROR: Fila vazia!\n");
	}
	else{
		int senhaRemover;
		int ultimoPref=0;
		int inicio = minhaFila.inicio; //seta duas variaveis para facilitar o acesso dos �ndices;
		int final = minhaFila.final;
		if(inicio==final){ //testa se s� existia uma pessoa na fila;
			senhaRemover = minhaFila.fila[inicio].senha;
			ultimoPref = minhaFila.fila[inicio].nivelPreferencial;
			minhaFila.inicio=0;
			minhaFila.final=-1;
		}
		else{
			int n1= contarPreferencial_estatica(minhaFila,1);
			int n2= contarPreferencial_estatica(minhaFila,2);
			int n3= contarPreferencial_estatica(minhaFila,3);
			if((n1==0)&&(n2==0)&&(n3==0)){
				senhaRemover = minhaFila.fila[inicio].senha;
				if(inicio<final){
					minhaFila.inicio=inicio+1;
				}
				else if((inicio>final)&&(inicio=tamanho-1)){
					minhaFila.inicio=0;
				}
					else minhaFila.inicio=inicio+1;
			}
			else if ((minhaFila.ultimo>0)&&(prioridade_de_tempoEstatica(minhaFila))){
				if(minhaFila.fila[inicio].nivelPreferencial>3){
					senhaRemover = minhaFila.fila[inicio].senha;
					if(inicio<final) minhaFila.inicio = inicio +1;
					else if((inicio>final)&&(inicio=tamanho-1)){
						minhaFila.inicio=0;
					}
					else minhaFila.inicio= inicio+1; 
				}
				else{
					while((inicio!=final)&&(minhaFila.fila[inicio].nivelPreferencial<3)){
						if(inicio<final) inicio++;
						else if((inici>final)&&(inicio==tamanho-1)) inicio=0
							else inicio++;
					}
					
				} 
			}
		}
		else if((inicio>final)&&(inicio==tamanho-1)){ //testa se o in�cio da fila est� no ultimo �ndice do vetor;
			minhaFila.inicio=0;
		}
			else if(inicio<tamanho-1){ //ap�s todos os testes ele cai nesse caso, onde ele simplesmente remove do inicio e pulo pro pr�ximo;
				minhaFila.inicio=inicio+1;
			}
	minhaFila.ultimo=ultimoPref;		
	system("cls");
	printf("P%d Foi atendido com sucesso!\n\n",senhaRemover);
	}
	system("pause");
	return minhaFila;
}

//Esta fun��o testa se a fila est� cheia
int filaCheiaEstatica(Fila_estatica minhaFila){
	int inicio = minhaFila.inicio; //seta duas variaveis para facilitar o acesso dos �ndices;
	int final = minhaFila.final;
	if(final==-1){ //testa se a fila est� vazia;
		return FALSE;
	}
	else{
		if((final>inicio)&&(final-inicio==tamanho-1)){ //testa se a fila est� cheia;
			return TRUE;
		}
		else if((inicio>final)&&((tamanho+final-inicio)==tamanho-1)){ //testa se a fila est� cheia;
			return TRUE;
		}
			else return FALSE; //caso contr�rio, ela n�o estar� nem vazia e nem cheia;
	}
}

//Esta fun��o testa se a fila est� vazia;
int filaVaziaEstatica(Fila_estatica minhaFila){
	if(minhaFila.final==-1){ //Se o indice do fim for -1, ent�o a fila est� vazia;
		return TRUE;
	}
	else return FALSE; //Se n�o for, ela n�o est� vazia;
}

//Esta fun��o serve apenas para imprimir a fila de maneira din�mica no CMD;
//Detalhe que esta fun��o � uma porra e tirou v�rias horas da minha vida;
void imprimirEstatica(Fila_estatica minhaFila){ 
	int inicio = minhaFila.inicio; //seta duas variaveis para facilitar o acesso dos �ndices;
	int final = minhaFila.final;
	if(filaVaziaEstatica(minhaFila)){ //testa se a fila est� vazia;
		printf("ERROR: Fila Vazia!\n");
	}
	else{
		//caso a fila n�o esteja vazia, concluimos que existe pelo menos uma pessoa na fila;
		//Ent�o emprimimos a primeira pessoa, depois testamos se existem outras pessoas;
		int k=1,i,max;
		if(minhaFila.fila[inicio].senha<10) max = 6;
		else if(minhaFila.fila[inicio].senha<100) max = 7; 
		// i e K servem como variaveis de controle. o K vai imprimir a posi��o de cada pessoa na fila;
		for(i=0;i<max;i++){
			printf("-");
		}
		printf("\n| P%d |  .%d     Nivel preferencial %d\n",minhaFila.fila[inicio].senha,k,minhaFila.fila[inicio].nivelPreferencial);
		//Imprimindo de maneira din�mica o contorno para cada nome;
		for(i=0;i<max;i++){
			printf("-");
		}
		printf("\n\n");
		//este while vai parar ap�s o in�cio e o final serem iguais, pois s� restara uma pessoa na fila;
		while(inicio!=final){
			if(inicio<tamanho-1){//testa se o �ndice do in�cio n�o chegou ainda ao limite do vetor
				inicio++;
			}
			else inicio=0; //d� a volta no vetor, do final para o �ndice 0;
			if(minhaFila.fila[inicio].senha<10) max = 6;
			else if(minhaFila.fila[inicio].senha<100) max = 7; 
			//como estas atualiza��es da variavel inicio est�o no come�o do while, isso vai garatir
			//que ele imprima o nome at� da ultima pessoa na fila;
			k++;
			//Imprimindo de maneira din�mica o contorno para cada nome;
			for(i=0;i<max;i++){
				printf("-");
			}
			printf("\n| P%d |  .%d     Nivel preferencial %d\n",minhaFila.fila[inicio].senha,k,minhaFila.fila[inicio].nivelPreferencial);
			//Imprimindo de maneira din�mica o contorno para cada nome;
			for(i=0;i<max;i++){
				printf("-");
			}
			printf("\n\n");
		}
		
	}
}

int contarPreferencial_estatica(Fila_estatica minhaFIla,int n){
	int inicio=minhaFila.inicio;
	int final=minhaFila.final;
	if(final==-1) return 0;
	int cont = 0;
	if(minhaFila.fila[inicio].nivelPreferencial==n){
		cont++
	}
	while(inicio!=final){
		if(inicio<final){
			inicio++;
		}
		else if((inicio>final)&&(inicio==tamanho-1)){
			inicio=0;
		}
			else inicio++;
		if(minhaFila.fila[inicio].nivelPreferencial==n){
			cont++
		}	
	}
	return cont;
}

Fila_estatica filaAnda_estatica(Fila_estatica minhaFila){
	int inicio = minhaFila.inicio;
	int final = minhaFila.final;
	if(final!=-1){
		minhaFila.fila[inicio].tempoEspera++;
		while(inicio!=final){
			if(inicio<final){
				inicio++;
			}
			else if((inicio>final)&&(inicio==tamanho-1)){
				inicio=0;
			}
				else inicio++;
			minhaFila.fila[inicio].tempoEspera++;
			
		}
	}
	return minhaFila;
}

int prioridade_de_tempoEstatica(Fila_estatica minhaFIla){
	int inicio=minhaFila.inicio;
	int final=minhaFila.final;
	if(minhaFila.fila[inicio]>3){
		return TRUE;
	}
	while((inicio!=final)&&(minhaFila.fila[inicio]<3)){
		if(inicio<final) inicio++;
		else if((inici>final)&&(inicio==tamanho-1)) inicio=0
			else inicio++;
		if(minhaFila.fila[inicio]>3) return true;
	}
	if(inicio==final) return FALSE;
}




