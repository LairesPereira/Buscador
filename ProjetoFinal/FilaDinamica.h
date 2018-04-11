/************** Declaração das estruturas utilizadas pela fila Dinâmica **************/
//A estrutura pessoa armazena o nome e o nivel de atendimento preferencial, além do link de encadeiamento da fila;
//O nome é armazenado para que possa ser feita a impressão de maneira dinâmica, e que facilita o reconhecimento de cada pessoa;
//O nivel preferêncial que vai de 0 a 3 trata a ordem com que as pessoas vão ser atendidas;
struct pessoa{ //Também tratado como NODO;
	int senha;
	int nivelPreferencial;
	int tempoEspera;
	struct pessoa*proximo;
};
typedef struct pessoa Pessoa; // declaração da estrutura;

//A estrutura Fila irá armazenar o início  da fila para uma manipulação mais simples do código;
struct fila{
	Pessoa*inicio;
	int ultimoAtendido;
	int senha;
};
typedef struct fila Fila; // declaração da estrutura;

/************** DECLARAÇÃO DE FUNÇÕES PARA A FILA DINÂMICA **************/

//Função que incialisará a fila dinâmica;
//Função utilizada pelo cliente; 
Fila * criaFila (void);

//Função que se encarrega de Ler o nome e o nivel preferencial de uma pessoa;
//Ela pega os dados e põe em uma estrutura do tipo Pessoa;
//Função utilizada na parte de inserção;
Pessoa * criaPessoa (Fila*fila);

//Função que insere uma pessoa no final da fila;
//Função utilizada pelo cliente;
void insere (Fila*fila);

//Função que testa o atual estado da fil;
//retorna 1 caso a fila esteja vazia e 0 caso não esteja;
//Função utilizada pelo cliente;
int estaVazia (Fila*fila);

//Função que imprime a fila de maneira dinâmica, tratando cada nome das pessoas na fila;
//Esta função também imprime a posição de cada pessoa na fila;
//Função utilizada pelo cliente; 
void imprimir (Fila*fila);

//Função que atende a primeira pessoa da fila;
//Ela remove o NODO após atender;
//Função utilizada pelo cliente;
void removePrimeiro (Fila*fila);

//Função que trata de contabilizar quanto tempo cada pessoa passa na fila por rodadas de atendimento;
//Sempre que se atende alguém da fila, as outras pessoas contam com 1 ponto a mais de tempo;
void filaAnda(Fila*fila);

//Funçõa que testa se existe alguém com prioridade de tempo na fila;
//Caso o contador de tempo da pessoas esteja acima de 3 ela é considerada com prioridade;
int prioridade_de_tempo(Fila*fila);

//Funçõa que conta quantes pessoas do nivel N preferencial existem na fila;
int contarPreferencia(Fila*fila,int pref);
