#include <stdio.h>
#include <math.h>
#include <string.h>

typedef char string[31];
typedef struct{
			   string nome;
			   double prodAbs;
			   int indChefe;
			   int nSub;
			   int subord[99];
			   double prodRel;
			   double nivel;
			   double salario;
			   double qualidade;
			  } funcionario; //Características de todo funcionário.


//Inicialização das structs.
void inicializaFunc(funcionario func[], int j){
	for (int i=0; i<99; i++){
		func[j].subord[i]=-1;
	}
	func[j].indChefe=-1;
	func[j].nSub=0;
	func[j].nivel=0;
	func[j].prodRel=0;
	func[j].salario=0;
	func[j].qualidade=0;
}

/**
 * Estruturação hierárquica da empresa.
 * Leitura dos dados de subordinação.
 * Armazenamento nas structs de funcionários.
 */
int estrutura(funcionario func[], int nFunc) {
	string subordinado, chefe;
	int i, j, aux;
	int indSub, indBoss, indPres;
	
	for(i=0; i<nFunc;i++)
		scanf(" %s %lf", func[i].nome, &func[i].prodAbs);
	
	for(i=0;i<nFunc-1;i++){
		scanf(" %s %s", subordinado, chefe); 
		aux=0;
		for(j=0;j<nFunc;j++){
			
			//Identificação do subordinado.
			if (strcmp(subordinado, func[j].nome)==0){
				indSub=j;
				aux++;
			}
			
			//Identificação do chefe.
			if (strcmp(chefe, func[j].nome)==0){
				indBoss=j;
				aux++;
			}

			if (aux==2) {
				func[indSub].indChefe = indBoss; //Índice do chefe do funcionario.
				func[indBoss].subord[func[indBoss].nSub]=indSub;//Índice do subordinado.
				func[indBoss].nSub++; //Aumento no número de subordinados.
				break;
			}
		}
	}
	for (i=0; i<nFunc;i++){
		if (func[i].indChefe == -1)
			indPres = i;
	}
	return indPres;
}
