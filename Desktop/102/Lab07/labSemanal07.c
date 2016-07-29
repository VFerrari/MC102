/* Victor Ferreira Ferrari, RA 187890, Turma S 
	O programa consiste de um método de gerenciamento de consultas
médicas, por meio do armazenamento de uma lista de doenças, uma de
médicos, e outra de consultas. Ao final das adições e alterações, um
relatório é retornado, em ordem alfabética, iniciando com uma letra
indicada pelo usuário. No processo, foi usado um método de criptografia
para decifrar o nome dado e codificar o nome ao ser colocado na lista.*/

#include "inicio.h"
#include "criptografia.h"
#include "operacoes.h"
#include "hub.h"

int main(int argc, char *argv[]){
	doenca *vetD; //Vetor de doenças a ser alocado.
	medico *vetM; //Vetor de médicos a ser alocado
	TPconsulta lista; //Apontador para o início da lista de consultas.
	int nDoenca, nMedico, chave[2][2];
	char letra; //Letra de início do relatório.
	
	scanf("%d", &nDoenca);
	vetD = leDoenca(nDoenca); //Criação do vetor de doenças.
	
	scanf("%d", &nMedico);
	vetM = leMedico(nMedico); //Criação do vetor de médicos.

	//Leitura da chave para criptografia.
	scanf("%d %d", &chave[0][0], &chave[0][1]);
	scanf("%d %d", &chave[1][0], &chave[1][1]);
	scanf(" %c", &letra);	
	
	//Operações de adição e alteração de consultas.
	lista = operacoes(vetD, vetM, chave, nDoenca, nMedico);
		
	//Impressão do relatório final.
	imprimeRelat(lista, letra, chave);	
	free(vetD);
	free(vetM);	
	
	return 0;
}
