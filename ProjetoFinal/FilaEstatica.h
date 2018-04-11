/************** Declaração das estruturas utilizadas pela fila Dinâmica **************/

//A estrutura pessoa_estatica vai guardar o nome e o nivel preferencial de cada pessoa na fila;
//O nome é armazenado para que se possa ser feita a impressão de maneira diâmica, e que facilida o reconhecimento de cada pessoa;
//O nivel preferêncial que vai de 0 a 3 trata a ordem com que as pessoas vão ser atendidas;

struct pessoa_estatica{
	int senha;
	int nivelPreferencial;
	int tempoEspera;
};
typedef struct pessoa_estatica Pessoa_estatica; //declaração da estrutura;

//A estrutura fila_estatica possui 3 campos para que se possa ter total controle sobre a fila;
//Os campois "inicio" e "final" delimitam a área da fila dentro do vetor;
//O campo "fila" nada mais é do que um vetor que servirá como uma fila de pessoas;
//A fila estática é trada de maneira circular, para o melhor desemepenho e uso de memória;
struct fila_estatica{
	int inicio;
	int final;
	Pessoa_estatica fila[30];	
	int ultimo;
	int senha;
};
typedef struct fila_estatica Fila_estatica; //declaração da estrutura;

/************** DECLARAÇÃO DE FUNÇÕES PARA A FILA ESTÁTICA **************/

//Esta função irá criar uma estrutura do fila Fila_estatica;
//inicializará os valores para os campos "inicio" e "final";
//Função utilizada pelo cliente; 
Fila_estatica criaFilaEstatica(void);

//Esta função irá criar um estrutura do tipo Pessoa_estatica;
//Ela tratará dados informados pelo usuário, abstraindo os dados do cliente; 
//Função utilizada na parte de inserção; 
Pessoa_estatica criaPessoaEstatica(Fila_estatica * minhaFila);

//Esta função irá inserir uma pessoa na fila;
//Ela trata o conceito de fila circular;
//Utiliza do método criaPessoaEstatica para abistrair o cliente;
Fila_estatica insereFilaEstatica(Fila_estatica minhaFila);

//Esta função irá remover a primeira pessoa da fila;
//Ela trata o conceito de fila circular;
//"Atende" uma pessoa;
Fila_estatica removeFilaEstatica(Fila_estatica minhaFila);

//Testa se a fila atingiu o seu limite;
int filaCheiaEstatica(Fila_estatica minhaFila);

//Testa se a fila está ou não vazia;
int filaVaziaEstatica(Fila_estatica minhaFila);

//Função que imprime a fila de maneira dinâmica, tratando cada nome das pessoas na fila;
//Esta função também imprime a posição de cada pessoa na fila;
//Função utilizada pelo cliente; 
void imprimirEstatica(Fila_estatica minhaFila);

int contarPreferencial_estatica(Fila_estatica minhaFIla,int n);

Fila_estatica filaAnda_estatica(Fila_estatica minhaFila);

int prioridade_de_tempoEstatica(Fila_estatica minhaFIla);


