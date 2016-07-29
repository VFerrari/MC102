#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definição das estruturas usadas para médicos, doenças, consultas, e nomes.
typedef char string[101]; 
typedef struct  {
				 char codigo[4];
				 string nome;
				} doenca;

typedef struct {
				int crm;
				string nome;
			   } medico;
			   

typedef struct consulta {
				string paciente;
				string data;
				char codigo[4];
				int crm;
				struct consulta *prox;
			   } Tconsulta;

typedef Tconsulta * TPconsulta;


/**
 * Função para leitura e armazenamento das doenças e seus códigos.
 * @param numero Quantidade de doenças a serem armazenadas.
 */
doenca * leDoenca(int numero){	
	doenca *p;
	
	//Alocação de memória para o vetor de estruturas.
	p=(doenca *)malloc(sizeof(doenca)*numero);
	
	for (int i=0;i<numero;i++)
		scanf("%s %[^\n]s", (p+i)->codigo, (p+i)->nome);
		
	return p;
}

/**
 * Função para leitura e armazenamento dos médicos e seus CRMs.
 * @param numero Quantidade de doenças a serem armazenadas.
 */
medico * leMedico(int numero){
	medico *p;
	
	//Alocação de memória para o vetor de estruturas.
	p=(medico *)malloc(sizeof(medico)*numero);
	
	for(int i=0;i<numero;i++)
		scanf("%d %[^\n]s", &(p+i)->crm, (p+i)->nome);

	return p;
}
