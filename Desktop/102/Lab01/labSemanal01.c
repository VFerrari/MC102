/* Victor Ferreira Ferrari, RA 187890, Turma S.
Este programa tem a intenção de, dados uma data, a duração de um mês e de um ano, e os dias restantes na base 6 para uma data específica,
retornar como resultado tal data. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
   int dia, mes, ano, duracao_mes, duracao_ano, dias_restantes, dia_real, mes_real, ano_real, a1, a2, a3, a4, a5, a6, a7, a8; 
   scanf("%d/%d/%d %d %d %8d", &dia, &mes, &ano, &duracao_mes, &duracao_ano, &dias_restantes);

    a1 = dias_restantes / 10000000;
	a2 = (dias_restantes % 10000000) / 1000000;
	a3 = (dias_restantes % 1000000) / 100000;
	a4 = (dias_restantes % 100000) / 10000;
	a5 = (dias_restantes % 10000) / 1000;
	a6 = (dias_restantes % 1000) / 100;
	a7 = (dias_restantes % 100) / 10;
	a8 = dias_restantes % 10;
	
	dias_restantes = a1*6*6*6*6*6*6*6 + a2*6*6*6*6*6*6 + a3*6*6*6*6*6 + a4*6*6*6*6 + a5*6*6*6 + a6*6*6 + a7*6 + a8;
	
	mes = (mes - 1) +(ano * duracao_ano);
	dia = (dia - 1) + (mes * duracao_mes);
   
	dia = dia + dias_restantes;
	mes = dia / duracao_mes;
	
	dia_real = dia % duracao_mes + 1;
	ano_real = mes / duracao_ano;
	mes_real = mes % duracao_ano + 1;
   
	printf("%d/%d/%d\n", dia_real, mes_real, ano_real);
	return 0;
}

