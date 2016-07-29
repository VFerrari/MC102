#include "estrutura.h"

/**
 * Identificação do nível hierárquico do funcionário.
 * Nível = distância do topo da hierarquia (ou seja, do presidente).
 */
double nivelH(funcionario func[], int ind){
	if(func[ind].indChefe<0){
		if (!func[ind].nivel) 
			func[ind].nivel=1; 
		return 1; //O presidente tem nível 1.
	}
	else {
		if (!func[ind].nivel)
			func[ind].nivel = nivelH(func, func[ind].indChefe)+1;
		return func[ind].nivel;
	} 
}

/**
 * Cálculo da produtividade relativa do funcionário.
 * Dado pela relação entre a produtividade absoluta e a dos subordinados.
 * Se não houver subordinados, a produtividade relativa é igual à absoluta.
 */
double prodRelativa(funcionario func[], int ind){
	double prodSub=0, nSubR=0;
	
	//Caso o funcionário não tenha subordinados.
	if(func[ind].nSub ==0){
		if(!func[ind].prodRel) 
			func[ind].prodRel = func[ind].prodAbs;
		return func[ind].prodRel;
	}
	else {
		if (!func[ind].prodRel){
			for (int i=0;i<func[ind].nSub;i++)
				prodSub+= prodRelativa(func, func[ind].subord[i]); //Prod. dos subordinados.
			nSubR = func[ind].nSub; //Transformação de um valor int em double.
			func[ind].prodRel=(func[ind].prodAbs+((1/nSubR)*prodSub))/2;
		}
		return func[ind].prodRel;
	}
}

/**
 * Cálculo do salário do funcionário.
 * Identificação da relação entre o salário de todos e do presidente.
 * Identificação do salário do presidente.
 * Cálculo de cada parte que vai para os funcionários.
 * @param total = gasto mensal com salários
 */
double salarios(funcionario func[], int ind, int nFunc, double total){
	double nSubR=0;
	static double coef=0;
	static int ctrl=0, aux=0;
		
	if(func[ind].indChefe<0){
		if(!func[ind].salario){
			func[ind].salario = 1;
			coef++;ctrl++;
		}
		else if (ctrl==nFunc){
			func[ind].salario = total/coef;
			ctrl=-1;
			aux=ind;
		}
		return func[ind].salario;
	}
	if (!func[ind].salario){
		nSubR=func[func[ind].indChefe].nSub;
		func[ind].salario = nSubR/(nSubR+1);
		func[ind].salario*=salarios(func, func[ind].indChefe, nFunc, total);
		coef+=func[ind].salario;
		ctrl++;
	}
	else if(ctrl==-1)
		func[ind].salario*=func[aux].salario;
	return func[ind].salario;
}

/**
 * Cálculo do log*
 * @param x = nível hierárquico.
 */
double logstar(double x){
	
	if (x<=1.0)
		return 0;
	else
		return (1 + logstar(log2(x)));
}

/**
 * Cálculo do índice de qualidade.
 * Depende das características determinadas nas outras funções.
 * @param total = gasto mensal com salários.
 * @param fator = fator de regularização do índice.
 */
void calcQualidade (funcionario func[], int ind, int nFunc, double total, int fator){
	func[ind].qualidade = fator *(logstar(nivelH(func, ind))+1);
	func[ind].qualidade*= prodRelativa(func, ind)/log2(salarios(func, ind, nFunc, total));	
	return;
}
