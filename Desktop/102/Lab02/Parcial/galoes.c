#include <stdio.h>

int main (int argc, char *argv[]){
	int fornecedores, capacidade, dias, galoes;
	double vol, preco, precototal, precootimo=999999999999999999, galoesexatos;
	scanf("%d ", &fornecedores);

	//Comparação entre diferentes fornecedores de água para encontrar o preço ótimo.
	for (; fornecedores>0; fornecedores--){
		scanf("%d $%lf", &capacidade, &preco);
		
		//Cada fornecedor tem capacidades diferentes em seus galões. Cálculo do número de galões (sempre inteiro).
		galoes = vol/capacidade;
		galoesexatos = vol/capacidade;
		if (galoes-galoesexatos > 0)
		galoes++;
		
		//Cálculo do preço total do fornecedor (para todos os dias e galões) e comparação com o preço ótimo.
		precototal = galoes* preco * dias; 
		if (precototal < precootimo)
			precootimo = precototal;
			}
	printf ("A manutencao da maquete custara $%.2lf aos cofres publicos.", precootimo);
	
	return 0;
}
