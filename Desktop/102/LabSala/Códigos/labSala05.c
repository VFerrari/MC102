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

//funções para tratar agenda, versão de implementação como vetor de inteiros (índices)
void imprimeAgendaInt(int n, int agenda[], comp vetComp[]);
void inicializaVetorIntNeg(int n, int vet[]);

//-------Protótipos adicionados na implementação da tarefa--------------//
void agCompI(comp vet[], int agenda[], char desc[], int dia, int hora);
void cancCompI(comp vet[], int agenda[], char desc[]);
int	horasDispI(int nHoras, int agenda[]);
int	durMaxSlotI(int nHoras, int agenda[]);

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
	inicializaVetorIntNeg(nHoras, agenda);

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
				agCompI(vetComp, agenda, desc, dia, hora);
				break;
			case 'C':
				scanf("%s", desc);
				cancCompI(vetComp, agenda, desc);
				break;
			default:
				printf("ERRO %c", tipo);
				break;
		}
	}

	nHorasDisp=horasDispI(nHoras, agenda);
	maxDurComp=durMaxSlotI(nHoras, agenda);

	printf("%d horas disponiveis para compromissos com duração menor ou igual a %d\n", nHorasDisp, maxDurComp);

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
 * @param vetComp[] Vetor de estrutras comp, onde estão armazenados os todos os possíveis compromissos da agenda. Vetor resultante populado pela função anterior "lerComp"
 */
void imprimeAgendaInt(int n, int agenda[], comp vetComp[]){
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
void inicializaVetorIntNeg(int n, int vet[]){
	int i;
	for (i=0; i<n; i++)
		vet[i]=-1;
}


//------------Funções Implementadas----------------------------------------//

/**Função para agendar compromissos na agenda. Agenda a partir da hora inicial recebida, aloca as horas seguintes de acordo com a duração.
Função recebe o vetor de compromissos, o vetor da agenda, a descrição do compromisso e dia e hora a ser agendado.. Função retorna nada. **/
void agCompI(comp vet[], int agenda[], char desc[], int dia, int hora){
	int i=0, j;

	//calcular hora total => transforma dia, hora em apenas hora.
	hora=hora+(dia-1)*24;

	//busca pelo compromisso correspondende aquela descrição, para saber sua duração. O compromisso em i é o compromisso buscado
	i=0;	
	while (strcmp(vet[i].descricao,desc))
		i++;
	 
	//agenda o compromisso na posição da hora calculada (correspondente a hora inicial transformada no formato 0 a 72 horas)
	for (j=hora; j<hora+vet[i].duracao; j++)
		agenda[j]=i;
		
}


/**Função para cancelar compromissos na agenda. Procura pela primeira ocorrência do compromisso e desaloca as ocorrencias
em seguida (inclusive a primeira) enquanto fizer parte da duração do compromisso.
Função recebe o vetor de compromissos, o vetor da agenda e a descrição do compromisso a ser cancelado. Função retorna nada. **/
void cancCompI(comp vet[], int agenda[], char desc[]){
	int i, j, dur;

	//busca por hora alocada para a descricao recebida no registro de saída
	for (i=0; ; i++) 
		if (agenda[i]!=-1)
			if (!strcmp(vet[agenda[i]].descricao, desc)){ //se encontra a primeira ocorrencia do compromisso
				dur=vet[agenda[i]].duracao;
				for (j=i; j<i+dur; j++) //percorro ate o sua duracao
					agenda[j]=-1;
				break; //sai do for
			}
}


/*Função que recebe a configuração da agenda e retorna a quantidade de horas livres*/
int horasDispI(int n, int vet[]){
	int i, cont=0;
	for (i=0; i<n; i++)
		if (vet[i]==-1)
			cont++;
	return cont;
}

/*Função que recebe a configuração da agenda e retorna o tamanho do maior slot de horas consecutivas, que indica a duração maxima de comprimisso suportado pela agenda*/
int durMaxSlotI(int n, int vet[]){
	int i, cont=0, max=0;
	for (i=0; i<n; i++)
		if (vet[i]==-1){
			cont++;
			if (cont>max)
				max=cont;
		}
		else 
			cont=0;
	return max;
}

