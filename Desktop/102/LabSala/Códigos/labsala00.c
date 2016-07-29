/* Victor Ferreira Ferrari, Lab 00c, 14/03/2016. 
Calculadora de médias + identificadora de aprovações */

#include <stdio.h>

int main(void)
{
	int nota1, nota2, nota3;
	float media;

	scanf("%d %d %d", &nota1, &nota2, &nota3);

	media = (nota1+nota2+nota3) / 3.0;
	
	if (media >= 5.0)
	{
	  printf("Aprovado com media %.1f\n", media);
	}
	else
	{
	  printf ("Reprovado com media %.1f\n", media);
	}

	return 0;
}
