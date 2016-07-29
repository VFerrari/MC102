#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	
	int ordem, divisor, i, colatual, colunas, linhas, bordas, contador;
	int convolucao[8][8], cinza[599][599], original[599][599];
	
	scanf("%d %d", &divisor, &ordem);
	bordas = ordem/2;
	
	for (i=0; i<ordem; i++) {
		for (colatual=0; colatual<ordem; colatual++) {
			scanf("%d", &convolucao[i][colatual]); 
		}
	}
	
	for (i=0; i<linhas; i++) {
		for (colatual=0; colatual<colunas;) {
			original[i][colatual] = cinza[i][colatual];
			
		}
	}
		for(i=bordas; i<(linhas-bordas); i++) {

		for(colatual=bordas; colatual<(colunas-bordas); colatual++){
			original[i][colatual] = 0;

			for (contador=(bordas*-1); contador<=bordas; contador++) {
				for (contador2=(bordas*-1); contador2<=bordas; contador2++) {
					original[i][colatual]+= convolucao[bordas+contador][bordas+contador2] * cinza[i+contador][colatual+contador2];
				}
			}
			original[i][colatual]/= divisor;
			
			if (original[i][colatual]<0)
				original[i][colatual]=0;
				
			if (original[i][colatual]>255)
				original[i][colatual]=255;


		}
	}
	
	
	
	printf("P2\n");
	printf("%d %d\n255", colunas, linhas);
	
	for (i=0; i<linhas; i++){
		printf("\n");
		for (colatual=0; colatual<colunas; colatual++){	
			printf("%d ", original[i][colatual]);
		}
	}
	
	return 0; }
