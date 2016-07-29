#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char string[50];

//Algoritmo Soundex para codificação do primeiro nome
int main (int argc, char *argv[]) {
	int aux=0, j;
	char cod[5], vogal=0, consoante=0;
	string nome;
	
	//Inicializando o vetor
	for(j=0; j<5; j++) cod[j] = 0;
	
	scanf(" %[^\n]s", nome);
	
	nome[0] = tolower (nome[0]);
	
	j=0;
	
	//Codificando as três primeiras consoantes do nome, de acordo com uma tabela.
	do {	
		switch (nome[j]) {
			case 'g': case 'j': strcpy (cod+aux, "1"); consoante=1; break;
			case 's': case 'z': case 'x': strcpy (cod+aux, "2"); consoante=1; break;
			case 'c': case 'k': case 'q': strcpy (cod+aux, "3"); consoante=1; break;
			case 'b': case 'p': strcpy (cod+aux, "4"); consoante=1; break;
			case 'm': case 'n': strcpy (cod+aux, "5"); consoante=1; break;
			case 'd': case 't': strcpy (cod+aux, "6"); consoante=1; break;
			case 'f': case 'v': strcpy (cod+aux, "7"); consoante=1; break;
			case 'l': strcpy (cod+aux, "8"); consoante=1; break;
			case 'r': strcpy (cod+aux, "9"); consoante=1; break;				
			default: if (aux!=0) aux--; vogal=1, consoante=0; break;
		}
		printf("%s %d %d\n", cod, aux, vogal);
		
		//Verificação de repetições no código
		if(vogal==0 && cod[aux-1]==cod[aux] && aux!=0) aux--;
		if (vogal==1 && consoante==1) vogal=0;
		
		j++; aux++;
		printf("Apos melhora: %s %d %d\n", cod, aux, vogal);

		if (aux==4) break; //Quando três consoantes forem codificadas, o processo acaba.
	} while (nome[j] != ' ');
	

	printf("%s %d %d\n", cod, aux, vogal);
	//Verificação da primeira letra do código com o primeiro número.
	//if (codletra1==cod[1] && codletra2 != 1) {
	//	cod[1]=cod[2];
	//	aux--;
	//}

	//Adição de zeros ao código, na falta de consoantes ou repetições
	if (aux == 1)
		strcpy (cod+1, "000");
	else if (aux == 2)
		strcpy (cod+2, "00");
	else if (aux == 3)
		strcpy (cod+3, "0");
	
	cod[0] = toupper (nome[0]);
	printf ("O codigo é %s\n", cod);

	return 0;
}		
