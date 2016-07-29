#include<stdio.h>

int main (void){
    int n, pontae, pontad, peca1, peca2, esquerda=0, direita=0;

	scanf("%d", &n);
	scanf("%d:%d", &pontae, &pontad);
	n--;

	while (n>0){
		scanf("%d:%d", &peca1, &peca2);
		n--;
		if (pontad==peca1 || pontad==peca2){ //se encaixa na direita
			if (pontad<=pontae){ //e direita eh ponta menor -> encaixa na direita
				direita++;
				if(pontad==peca1)
					pontad=peca2;
				else
					pontad=peca1;
			}
			else if (pontae!=peca1 && pontae!=peca2){ //se encaixa na direita e nao encaixa na esquerda -> encaixa na direita
				direita++;
				if(pontad==peca1)
					pontad=peca2;
				else
					pontad=peca1;							
			}
			else { // se encaixa na esquerda tbm, e esqueda é a ponta menor
				esquerda++;
				if(pontae==peca1)
					pontae=peca2;
				else
					pontae=peca1;							
			}
		}
		else { //se encaixa apenas na direita
			esquerda++;
			if(pontae==peca1)
				pontae=peca2;
			else
				pontae=peca1;							
		}
	}
	printf("%d\n", direita-esquerda);

    return 0;
}
