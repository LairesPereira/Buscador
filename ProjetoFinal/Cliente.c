#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FilaDinamica.h"
#include "FilaEstatica.h"
#include "imprime.h"

/*As linhas 4,5 e 6 fazem o link das Tad's que abstraem todo o cliente*/

int main(int argc, char *argv[]) {
	imprimeLogo();
	int escolheFila=1; //Esta variavel define qual fila o programa dever� utilizar. A est�tica cricular ou a din�mica;
	int escolha=1; //Esta variavel servir� como controle de op��es do usu�rio no men�;
	do{ // Pede para o usu�rio escolher qual fila deseja;
		imprimeEscolha();
		scanf("%d",&escolheFila);
		if(escolheFila<1||escolheFila>2){
			imprimeErro(); //caso o usuario digite algum numero que n�o seja 1 ou 2 ele ir� imprimir um erro;
		}
	}while((escolheFila!=1)&&(escolheFila!=2)); // ir� etrar em loop at� que o usu�rio escolha corretamente uma fila;
	limpaTela();
	if(escolheFila==1){ //Entra na interface de Fila Din�mica; 
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
	}else{ //Entrar na interface de Fila Est�tica;
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
