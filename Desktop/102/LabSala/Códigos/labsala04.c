/* Victor Ferreira Ferrari, RA 187890, Turma S, 09/05/2016
	O programa consiste no cálculo da integral de uma função polinomial fornecida
como entrada pelo usuário. A entrada consiste do número de termos do polinômio,
e cada termo, fornecendo o coeficiente, o expoente e o sinal. 
	Para o cálculo, o expoente teve seu valor aumentado em 1, e o coeficiente foi
dividido pelo novo valor. Nos casos nos quais o coeficiente resultante foi zero, 
foi omitido o resultado. Toda integral possui uma constante C anterior ao polinômio. */

#include <stdio.h>

//Declaração das funções
int leitura(char sinal[], float coef[], int exp[]);
int calculo(int termos, float coef[], int exp[], float coefnovo[], int expnovo[]);
void impressao(char sinal[], float coef[], int exp[], int aux);


int main (int argc, char *argv[]) 
{
	char sinal[51]; //O sinal é utilizado, então é lido como caractere (+,-).

	int termos, controle, expintegral[50], exp[50];

	float coefintegral[50], coef[50]; //O coeficiente é declarado como ponto flutuante pois ele pode assumir valores fracionários.
	
	//O número de termos é essencial, então é retornado à função principal.
	termos = leitura(sinal, coef, exp);

	//O valor da variável de controle é retornado pois será utilizado na impressão da integral.
	controle = calculo(termos, coef, exp, coefintegral, expintegral);

	//A função imprime o valor da integral, utilizando como índice dos vetores com os resultados a variável de controle.
	impressao(sinal, coefintegral, expintegral, controle);
	
	return 0; 
}

int leitura(char sinal[], float coef[], int exp[])
{
	int termos, i;
	scanf("%d", &termos);

	//Para cada um dos termos, foram lidos os valores, e o número de termos foi retornado.
	for (i=0; i<termos; i++)
		scanf(" %c %f x^%d", &sinal[i], &coef[i], &exp[i]);	

	return termos;  
}

int calculo(int termos, float coef[], int exp[], float coefnovo[], int expnovo[])
{
	int i, aux=0;

	//Adição de um ao expoente, e divisão do coeficiente pelo novo valor.
	for (i=0; i<termos; i++){
		exp[i]++;
		coef[i]/=exp[i];

		/*Apenas os valores nos quais o coeficiente é diferente de zero são
copiados aos vetores que serão impressos, e a variável de controle indica a
quantidade nova de termos.*/
		if (coef[i] !=0){
			coefnovo[aux]=coef[i];
			expnovo[aux]=exp[i];
			aux++;	
		}
	}
	//A variável de controle é retornada.
	return aux;
}


void impressao(char sinal[], float coef[], int exp[], int aux) 
{
	int i;
	printf ("C"); //Toda integral possui uma constante C que é somada no começo.

	//Os valores finais diferentes de zero são impressos, com 3 casas decimais.
	for (i=0; i<aux; i++)
		printf(" %c %.3f x^%d", sinal[i], coef[i], exp[i]);
	printf ("\n");
}


