#include <stdio.h>
#include <string.h>

#define maxA 72 //max de horas na agenda
#define maxC 20 //max comprimissos

typedef struct {
	char descricao[21]; 
	int duracao;
} comp; //compromisso


//Funções para tratar o vetor de compromissos
void lerComp (int n, comp vet[]);
void imprimeComp(int nComp, comp vet[]);

//funções para tratar agenda
void imprimeAgenda(int n, int agenda[], comp vetComp[]);
void inicializaVetor(int n, int vet[]);

int main (){
	int nComp, nHoras; //variáveis para entrada
	int nHorasDisp, maxDurComp; //variáveis para saida
	comp vetComp[maxC];
	int agenda[maxA];
	int nReg, i;
	char tipo; //tipo do registro: agendamento ou cancelamento de compromissos
	char desc[21];
	int dia, hora;


	scanf("%d", &nHoras);
	inicializaVetor(nHoras, agenda);

	//leitura dos compromissos (descição e duração)
	scanf("%d", &nComp);
	lerComp(nComp, vetComp);

	//leitura dos registros + agendamento e cancelamento dos compromissos
	scanf("%d", &nReg);

	for (i=0; i<nReg; i++){
		scanf("\n%c ", &tipo);

		switch (tipo){
			case 'A':
				scanf("%s", desc);
				scanf("%d %d", &dia, &hora);
				//AQUI FUNÇÃO para agendar compromisso
				break;
			case 'C':
				scanf("%s", desc);
				//AQUI FNÇÃO para cancelar compromisso
				break;
			default:
				printf("ERRO");
				break;
		}
	}



	//CALCULAR HORAS LIVRES AQUI

	//CALCULAR MAXIMA DURAÇÃO QUE UM COMPROMISSO PODE TER PARA ENTRAR NA AGENDA

	printf("%d horas disponiveis para compromissos com duração menor ou igual a %d\n", //VAR_QNT_HORAS_LIVRE, VAR_MAX_DUR_COMP);

	return 0;

}


/**
 * Ler os comprimissos da entrada. 
 * Função ler N compromissos e armazenas num vetor de estrutura do tipo comp. 
 * O vetor é recebido como referência, portanto a função modifica seus valores.
 * Função retorna nada.
 * @param n Número de compromissos a serem lidos na entrada
 * @param vet Vetor de estrutura comp, onde serão armazenados os compromissos lido da entrada.
 */
void lerComp (int n, comp vet[]){
	int i;
	
	for (i=0; i<n; i++)
		scanf("\n%s %d", vet[i].descricao, &vet[i].duracao);		
}

/**
 * Função que imprime o vetor de comprimissos. 
 * Função feita apenas com o propósito de teste.
 * Função imprime a descrição do compromisso e sua duração em horas
 * @param n Número de compromissos, tamanho do vetor
 * @param vet Vetor de estrutura que armazena os compromissos.
 */
void imprimeComp(int n, comp vet[]){
	int i;
	
	for (i=0; i<n; i++)
		printf("%s %d\n", vet[i].descricao, vet[i].duracao);
}

/**
 * Função que imprime a agenda. 
 * Função feita apenas com o propósito de testar.
 * Função imprime * para horas livres e a descrição do compromisso para horas em qua há um compromisso alocado.
 * @param n Número de horas na agenda
 * @param agenda Vetor de inteiros que armazena o índice do compromisso agendado, isto é, a posição do compromisso no vetor vetComp[]. Vetor mostra a configuração da agenda (os compromissos agendados). 
 * @param vetComp Vetor de estrutras comp, onde estão armazenados os todos os possíveis compromissos da agenda. Vetor resultante populado pela função anterior "lerComp"
 */
void imprimeAgenda(int n, int agenda[], comp vetComp[]){
	int i;
	
	for (i=0; i<n; i++)
		if (agenda[i]==-1)
			printf("* "); //uso * para mostrar horário livre (disponível)
		else
			printf("%s ", vetComp[agenda[i]].descricao);
}

/**
 * Função que inicializa um vetor de inteiros com valor -1.
 * Função usada para inicializar o vetor que representa a agenda.
 * @param n Números de horas na agenda
 * @param vet Vetor de inteiros. Vetor que guarda a configuração da agenda.
 */
void inicializaVetor(int n, int vet[]){
	int i;
	for (i=0; i<n; i++)
		vet[i]=-1;
}


