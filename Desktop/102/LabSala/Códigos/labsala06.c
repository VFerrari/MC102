/**************************************************
*	Universidade Estadual de Campinas             *
*	Instituto de Computação                       *
*	MC102 - TURMA: S                             *
*	labSala06 - 06/06/2016                        *
* 	Victor Ferreira Ferrari, RA 187890.		      *
***************************************************/

#include <stdio.h>

unsigned long long int potencia(int base, int exp);
int contagem(int base, int digito, unsigned long long int result);

int main(int argc, char *argv[])
{
    int base,expoente,contador, digito;
    unsigned long long int resultado;

	scanf("%d %d", &base, &expoente);

	resultado = potencia(base, expoente);

	digito=base%10; //Último dígito da base.
	contador = contagem(base, digito, resultado);

	printf("%llu\n%d\n", resultado, contador);

    return 0;
}

//Função que calcula a potência de base elevada a exp.
unsigned long long int potencia(int base, int exp){
	
	//Caso base:
	if (exp==1)
		return base;
	if (exp==0)
		return 1;
	//Passo recursivo:
	else{
		exp--;
		return base*potencia(base, exp);
	}
}

/*
 * Função de contagem
 * Calcula o número de ocorrências do último algarismo da base no resultado.
*/
int contagem(int base, int digito, unsigned long long int result){
	static int contador=0;	

	if (result%10==digito)
		contador++;

	//Caso base:
	if(result == 0){
		//Se o último digito da base for 0, ele iria aumentar mais.
		if (base != 0 && digito == 0)
			contador--; 
		return contador;
	}
	//Passo recursivo:
	else
		return contagem(base, digito, result/10);
}
