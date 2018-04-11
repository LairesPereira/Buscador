#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "FilaDinamica.h"

//Método que Aloca memória dinâmicamente para a criação de uma fila;
//A fila é inicializada com um ponteiro cujo valor é NULL;
Fila *criaFila(){
	Fila*fila=(Fila*)malloc(sizeof(Fila));
	fila->inicio=NULL;
	fila->ultimoAtendido=0;
	fila->senha=0;
	return fila;
}

//Método que Aloca memória dinâmicamente para a criação de uma nova pessoa;
//Ele também trata as informações de nome e nivel preferencial para a abstração do cliente;
Pessoa * criaPessoa(Fila*fila){
	Pessoa*pessoa=(Pessoa*)malloc(sizeof(Pessoa));
	fflush(stdin);
	system("cls");
	printf("\nInforme seu nivel preferencial de 0 a 3:\n");
	scanf("%d",&pessoa->nivelPreferencial);
	fila->senha++;
	pessoa->senha=fila->senha;
	pessoa->tempoEspera=0;
	pessoa->proximo = NULL; //A ligação que forma o encadeiamento da fila inicialmente aponta para NULL;
	return pessoa;
}

//Método que insere uma pessoa no final da fila;
//Ele utiliza do metodo criaPessoa para a Abstração do cliente;
void insere(Fila*fila){
	Pessoa *novo = criaPessoa(fila);
	if(fila->inicio==NULL){
		fila->inicio=novo;
	}
	else{
		Pessoa*aux=fila->inicio;
		while(aux->proximo!=NULL){
			aux=aux->proximo;
		}
		aux->proximo=novo;
	}
}

//Método que testa se a fila está vazia;
//caso esteja vazia ela retorna o valor 1, caso contrario retorna o valor 0;
int estaVazia(Fila*fila){
	if(fila->inicio==NULL){
		return 1;
	}else return 0;
}


//Método que trata a impressão de maneira dinâmica na fila;
void imprimir(Fila*fila){
	if(estaVazia(fila)){
		printf("Fila Vazia!\n");
	}
	else{
		Pessoa * aux = fila->inicio;
		int k=1,i,max;
		do{
			if(aux->senha<10) max=6;
			else if(aux->senha<100) max = 7;
			for(i=0;i<max;i++){
				printf("-");
			}
			printf("\n| P%d |  .%d     Nivel preferencial %d\n",aux->senha,k,aux->nivelPreferencial);
			for(i=0;i<max;i++){
				printf("-");
			}
			printf("\n\n");
			aux=aux->proximo;
			k++;
		}while(aux!=NULL);
		printf("\n\n");	
	}
}

//Método que remove a primeira pessoa da fila;
//"Atende" a primeira pessoa da fila;
void removePrimeiro(Fila*fila){
	system("cls");	
	if(fila->inicio==NULL){
		printf("Fila Vazia!\n");
	}
	else{
		int senhaRemover;
		Pessoa *aux=fila->inicio;
		if(aux->proximo==NULL){
			fila->inicio=NULL;
			fila->ultimoAtendido=aux->nivelPreferencial;
		}
		else{
			int normal = contarPreferencia(fila,0);
			int n1 = contarPreferencia(fila,1);
			int n2 = contarPreferencia(fila,2);
			int n3 = contarPreferencia(fila,3);
			if((n1==0)&&(n2==0)&&(n3==0)){
				printf("teste 0 preferencial\n");
				fila->ultimoAtendido=aux->nivelPreferencial;
				fila->inicio=aux->proximo;
			}
			else if((fila->ultimoAtendido>0)&&(prioridade_de_tempo(fila))){
				printf("teste prioridade de tempo\n");
				Pessoa*anterior = NULL;
				while(aux->tempoEspera<3){
					anterior=aux;
					aux=aux->proximo;
				}
				if(!(anterior==NULL)){
					fila->ultimoAtendido=aux->nivelPreferencial;
					anterior->proximo=aux->proximo;
				}
				else fila->inicio=aux->proximo;	
			}
				else{
					Pessoa*anterior = NULL;
					if(n3){
						printf("teste nivel 3\n");
						while(aux->nivelPreferencial!=3){
							anterior=aux;
							aux=aux->proximo;
						}
						if(!(anterior==NULL)){
							fila->ultimoAtendido=aux->nivelPreferencial;
							anterior->proximo=aux->proximo;
						}
					}
					else if(n2){
						printf("teste nivel 2\n");
						while(aux->nivelPreferencial!=2){
							anterior=aux;
							aux=aux->proximo;
						}
						if(!(anterior==NULL)){
							fila->ultimoAtendido=aux->nivelPreferencial;
							anterior->proximo=aux->proximo;
						}
					}
						else{
							printf("teste nivel 1\n");
							while(aux->nivelPreferencial!=1){
								anterior=aux;
								aux=aux->proximo;
							}
							if(!(anterior==NULL)){
								fila->ultimoAtendido=aux->nivelPreferencial;
								anterior->proximo=aux->proximo;
							}
						}
				}
		}
	senhaRemover=aux->senha;	
	free(aux);	
	printf("\nP%d atendido(a) com sucesso!\n",senhaRemover);
	}
}

int prioridade_de_tempo(Fila*fila){
	Pessoa*aux=fila->inicio;
	while((aux->proximo!=NULL)&&(aux->tempoEspera<3)){
		aux=aux->proximo;
	}
	if(aux->tempoEspera>3) return 1;
	else return 0;
}

void filaAnda(Fila*fila){
	if(!estaVazia(fila)){
		Pessoa*aux=fila->inicio;
		do{
			aux->tempoEspera+=1;
			aux=aux->proximo;
		}while(aux!=NULL);
	}
}

int contarPreferencia(Fila*fila,int pref){
	Pessoa*aux=fila->inicio;
	int cont = 0;
	do{
		if(aux->nivelPreferencial==pref) cont++;
		aux=aux->proximo;
	}while(aux!=NULL);
	return cont;
}
