/* Victor Ferreira Ferrari, RA 187890, Turma S 
	O propósito do programa é encontrar o funcionário do ano de uma
empresa por meio de cálculos recursivos para determinar a produtividade,
o salário e a qualidade do serviço de cada um, e retornar o nome, e o
índice de qualidade do vencedor. */

//Funções incluídas em um header.
#include "funcoes.h"

int main(int argc, char **argv)
{
	double gastoMes, qualMax=0; //Entrada e saída, respectivamente.
	int fatorQualidade; //Entrada, fator de regularização.
	int nFunc, funcAno, pres;  //Variáveis relacionadas a funcionarios.
	funcionario func[100]; //Struct dos funcionarios.
	int i; 
	
	scanf("%lf %d", &gastoMes, &fatorQualidade);
	scanf("%d", &nFunc);
	
	for (i=0;i<nFunc;i++)
		inicializaFunc(func, i);
	
	pres = estrutura(func, nFunc);
	
	for(i=0;i<nFunc;i++){
		salarios(func, i, nFunc, gastoMes);
	}
	salarios(func, pres, nFunc, gastoMes);
	
	//Determinação do funcionário do ano.
	for(i=0;i<nFunc;i++){
		calcQualidade(func, i, nFunc, gastoMes, fatorQualidade);
		if (func[i].qualidade>qualMax){
			qualMax = func[i].qualidade;
			funcAno = i;
		}
	}
	printf("%s %.2lf\n", func[funcAno].nome, qualMax);
	
	return 0;
}
