/* Victor Ferreira Ferrari, RA 187890, Turma S, 27/06/2016
	Trata-se de um programa que, ao receber 2 arquivos como parâmetro, e o nome de um terceiro,
compara os dois primeiros para encontrar os que aparecem em ambos. A resposta é então colocada
em um terceiro arquivo cujo nome está no terceiro parâmetro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[102]; //Definição do tipo "string", para ler o nome;

//Protótipos das funções
void lerArq(FILE *arq, int qte, string dest[]);
int comparaArq(string atuais[], int qte1, FILE *antiga, int qte2, FILE *lista);

int main(int argc, char *argv[]){
	FILE *antiga; //Arquivo com os clientes antigos.
	FILE *nova; //Arquivo com os clientes atuais.
	FILE *lista; //Arquivo para saída.
	string *atuais;	//Vetor de nomes dos clientes atuais, para comparação.
	int qte1, qte2, qteFinal=0; //Quantidade de clientes em cada lista.
	
	//Abertura dos arquivos.
	antiga = fopen(argv[1], "r");
	nova = fopen(argv[2], "r");
	lista = fopen(argv[3], "w");

	//Leitura das quantidades, que aparecem no começo dos arquivos.
	fscanf(nova, "%d\n", &qte1);
	fscanf(antiga, "%d\n", &qte2);	

	//Criação do vetor dinâmico com o nome dos clientes atuais.
	atuais = (string *)malloc(sizeof(string)*qte1);

	//Função para leitura dos nomes atuais.
	lerArq(nova, qte1, atuais);
	
	//Espaços, pois a última coisa a ser impressa é a quantidade de clientes em comum.
	fprintf(lista, "\n\n\n\n");

	//Cálculo da quantidade de clientes em comum, e impressão dos nomes.
	qteFinal = comparaArq(atuais, qte1, antiga, qte2, lista);

	rewind(lista); //Retorno ao início do arquivo.
	fprintf(lista, "%d\n", qteFinal); //Impressão da quantidade final.

	//Fechamento dos arquivos e liberação da memória dinâmica;
	fclose(antiga);
	fclose(nova);
	fclose(lista);
	free(atuais);
	return 0;
}

/*
	* Função para leitura dos nomes da lista atual.
	* Lê o nome e descarta as próximas 3 linhas, com informações irrelevantes.
*/
void lerArq(FILE *arq, int qte, string dest[]){
	int i, j;
	string descarte;	

	for(i=0;i<qte;i++){
		fgets(dest[i], 100, arq);

		for(j=0;j<3;j++)
			fgets(descarte, 100, arq);	
	}		

}

/*
	* Função para cálculo da quantidade final e impressão dos nomes em comum.
	* Lê cada nome, e descarta as proximas 3 linhas.
	* Compara com todos os do vetor criado anteriormente.
*/
int comparaArq(string atuais[], int qte1, FILE *antiga, int qte2, FILE *lista){
	string nome, descarte;
	int i, j, aux=0;
	int qteFinal=0; //Quantidade de clientes em comum.
	
	for(i=0;i<qte2;i++){
		fgets(nome, 100, antiga); 	

		for (j=0;j<3;j++)
			fgets(descarte, 100, antiga);			

		for (aux=0;aux<qte1;aux++){
			if (strcmp(nome,atuais[aux]) == 0){
				fputs(nome, lista);
				qteFinal++;
				break;
			}
		}
	}
	return qteFinal;
}

