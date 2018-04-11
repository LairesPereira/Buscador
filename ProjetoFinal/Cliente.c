#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FilaDinamica.h"
#include "FilaEstatica.h"
#include "imprime.h"

/*As linhas 4,5 e 6 fazem o link das Tad's que abstraem todo o cliente*/

int main(int argc, char *argv[]) {
	imprimeLogo();
	int escolheFila=1; //Esta variavel define qual fila o programa deverá utilizar. A estática cricular ou a dinâmica;
	int escolha=1; //Esta variavel servirá como controle de opções do usuário no menú;
	do{ // Pede para o usuário escolher qual fila deseja;
		imprimeEscolha();
		scanf("%d",&escolheFila);
		if(escolheFila<1||escolheFila>2){
			imprimeErro(); //caso o usuario digite algum numero que não seja 1 ou 2 ele irá imprimir um erro;
		}
	}while((escolheFila!=1)&&(escolheFila!=2)); // irá etrar em loop até que o usuário escolha corretamente uma fila;
	limpaTela();
	if(escolheFila==1){ //Entra na interface de Fila Dinâmica; 
		Fila * fila = criaFila();
		while(1){
			imprimeMenu();
			imprimeCaixa();
			if(estaVazia(fila)){
				imprimeFilaVazia(fila);
			}else imprimir(fila);
			scanf("%d",&escolha);
			switch(escolha){
				case 1: insere(fila);
						break;
				case 2: removePrimeiro(fila);
						filaAnda(fila);	
						break;
				case 0: encerraFila();
						return 0;		
				default: imprimeErro();							
			}
			limpaTela();
		}	
	}else{ //Entrar na interface de Fila Estática;
		Fila_estatica fila = criaFilaEstatica();
		while(1){
			imprimeMenu();
			imprimeCaixa();
			if(filaVaziaEstatica(fila)){
				imprimeFilaVazia_estatica(fila);
			}else imprimirEstatica(fila);
			scanf("%d",&escolha);
			switch(escolha){
				case 1: fila = insereFilaEstatica(fila);
						break;
				case 2: fila = removeFilaEstatica(fila);
						fila = filaAnda_estatica(fila);	
						break;
				case 3: imprimeFilaVazia_estatica(fila);
						break;
				case 4: imprimirEstatica(fila);
						break;
				case 0: encerraFila();
						return 0;
				default: imprimeErro();							
			}
			limpaTela();
		}
	}
	return 0;
}
