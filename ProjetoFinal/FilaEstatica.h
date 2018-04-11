/************** Declara��o das estruturas utilizadas pela fila Din�mica **************/

//A estrutura pessoa_estatica vai guardar o nome e o nivel preferencial de cada pessoa na fila;
//O nome � armazenado para que se possa ser feita a impress�o de maneira di�mica, e que facilida o reconhecimento de cada pessoa;
//O nivel prefer�ncial que vai de 0 a 3 trata a ordem com que as pessoas v�o ser atendidas;

struct pessoa_estatica{
	int senha;
	int nivelPreferencial;
	int tempoEspera;
};
typedef struct pessoa_estatica Pessoa_estatica; //declara��o da estrutura;

//A estrutura fila_estatica possui 3 campos para que se possa ter total controle sobre a fila;
//Os campois "inicio" e "final" delimitam a �rea da fila dentro do vetor;
//O campo "fila" nada mais � do que um vetor que servir� como uma fila de pessoas;
//A fila est�tica � trada de maneira circular, para o melhor desemepenho e uso de mem�ria;
struct fila_estatica{
	int inicio;
	int final;
	Pessoa_estatica fila[30];	
	int ultimo;
	int senha;
};
typedef struct fila_estatica Fila_estatica; //declara��o da estrutura;

/************** DECLARA��O DE FUN��ES PARA A FILA EST�TICA **************/

//Esta fun��o ir� criar uma estrutura do fila Fila_estatica;
//inicializar� os valores para os campos "inicio" e "final";
//Fun��o utilizada pelo cliente; 
Fila_estatica criaFilaEstatica(void);

//Esta fun��o ir� criar um estrutura do tipo Pessoa_estatica;
//Ela tratar� dados informados pelo usu�rio, abstraindo os dados do cliente; 
//Fun��o utilizada na parte de inser��o; 
Pessoa_estatica criaPessoaEstatica(Fila_estatica * minhaFila);

//Esta fun��o ir� inserir uma pessoa na fila;
//Ela trata o conceito de fila circular;
//Utiliza do m�todo criaPessoaEstatica para abistrair o cliente;
Fila_estatica insereFilaEstatica(Fila_estatica minhaFila);

//Esta fun��o ir� remover a primeira pessoa da fila;
//Ela trata o conceito de fila circular;
//"Atende" uma pessoa;
Fila_estatica removeFilaEstatica(Fila_estatica minhaFila);

//Testa se a fila atingiu o seu limite;
int filaCheiaEstatica(Fila_estatica minhaFila);

//Testa se a fila est� ou n�o vazia;
int filaVaziaEstatica(Fila_estatica minhaFila);

//Fun��o que imprime a fila de maneira din�mica, tratando cada nome das pessoas na fila;
//Esta fun��o tamb�m imprime a posi��o de cada pessoa na fila;
//Fun��o utilizada pelo cliente; 
void imprimirEstatica(Fila_estatica minhaFila);

int contarPreferencial_estatica(Fila_estatica minhaFIla,int n);

Fila_estatica filaAnda_estatica(Fila_estatica minhaFila);

int prioridade_de_tempoEstatica(Fila_estatica minhaFIla);


