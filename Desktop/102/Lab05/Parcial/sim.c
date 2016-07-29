#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char cod1[5], cod2[5];
	short int i, igual=0, j;
	float sim=0;
	
	scanf (" %[^\n]s", cod1);
	scanf (" %[^\n]s", cod2);
	
	//Como strings com tamanhos diferentes podem ser usadas, calcula-se o tamanho.
	j = strlen(cod1);
	
	//Compara-se as duas strings em cada caractere.
	for(i=0; i<j; i++) {
		if (cod1[i]==cod2[i]) 
			igual++;
	}
	//A similaridade é dada pelo número de caracteres iguais, dividido pelo tamanho (porcentagem).
	sim = igual/j;
	printf("%.2f\n", sim);
	return 0;
}
