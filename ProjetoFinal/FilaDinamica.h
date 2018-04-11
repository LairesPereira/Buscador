/************** Declara��o das estruturas utilizadas pela fila Din�mica **************/
//A estrutura pessoa armazena o nome e o nivel de atendimento preferencial, al�m do link de encadeiamento da fila;
//O nome � armazenado para que possa ser feita a impress�o de maneira din�mica, e que facilita o reconhecimento de cada pessoa;
//O nivel prefer�ncial que vai de 0 a 3 trata a ordem com que as pessoas v�o ser atendidas;
struct pessoa{ //Tamb�m tratado como NODO;
	int senha;
	int nivelPreferencial;
	int tempoEspera;
	struct pessoa*proximo;
};
typedef struct pessoa Pessoa; // declara��o da estrutura;

//A estrutura Fila ir� armazenar o in�cio  da fila para uma manipula��o mais simples do c�digo;
struct fila{
	Pessoa*inicio;
	int ultimoAtendido;
	int senha;
};
typedef struct fila Fila; // declara��o da estrutura;

/************** DECLARA��O DE FUN��ES PARA A FILA DIN�MICA **************/

//Fun��o que incialisar� a fila din�mica;
//Fun��o utilizada pelo cliente; 
Fila * criaFila (void);

//Fun��o que se encarrega de Ler o nome e o nivel preferencial de uma pessoa;
//Ela pega os dados e p�e em uma estrutura do tipo Pessoa;
//Fun��o utilizada na parte de inser��o;
Pessoa * criaPessoa (Fila*fila);

//Fun��o que insere uma pessoa no final da fila;
//Fun��o utilizada pelo cliente;
void insere (Fila*fila);

//Fun��o que testa o atual estado da fil;
//retorna 1 caso a fila esteja vazia e 0 caso n�o esteja;
//Fun��o utilizada pelo cliente;
int estaVazia (Fila*fila);

//Fun��o que imprime a fila de maneira din�mica, tratando cada nome das pessoas na fila;
//Esta fun��o tamb�m imprime a posi��o de cada pessoa na fila;
//Fun��o utilizada pelo cliente; 
void imprimir (Fila*fila);

//Fun��o que atende a primeira pessoa da fila;
//Ela remove o NODO ap�s atender;
//Fun��o utilizada pelo cliente;
void removePrimeiro (Fila*fila);

//Fun��o que trata de contabilizar quanto tempo cada pessoa passa na fila por rodadas de atendimento;
//Sempre que se atende algu�m da fila, as outras pessoas contam com 1 ponto a mais de tempo;
void filaAnda(Fila*fila);

//Fun��a que testa se existe algu�m com prioridade de tempo na fila;
//Caso o contador de tempo da pessoas esteja acima de 3 ela � considerada com prioridade;
int prioridade_de_tempo(Fila*fila);

//Fun��a que conta quantes pessoas do nivel N preferencial existem na fila;
int contarPreferencia(Fila*fila,int pref);
