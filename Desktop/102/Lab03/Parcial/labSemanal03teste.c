#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	
	int original[600][600], red[600][600], green[600][600], blue[600][600], cinza[600][600], convolucao[9][9];
	int linhas, colunas, i, colatual, repeticoes, numero, matrizes, colfinal, contador, ordem, divisor, bordas, contador2;
	
	
	//Criação da matriz "Original".
	scanf("%d %d", &colunas, &linhas);
	
	for (matrizes=1; matrizes<=3; matrizes++) {
		for(i=0; i<linhas; i++){
			for (colatual=0; colatual<colunas;) {
				
				scanf("%d %d", &repeticoes, &numero);
								
				colfinal = colatual + repeticoes;
				
				
				for(; colatual<colfinal; colatual++) {
					if (colatual == colunas) {
						i++;
						colatual = 0;
						colfinal-=colunas;
					}
					original[i][colatual] = numero;

				}
			}
		}
	
	
	// Colocar original em Red, Green e Blue
		switch (matrizes) {
			case 1:
				for (i=0; i<linhas; i++){
					for (colatual=0; colatual<colunas; colatual++) 
						red[i][colatual] = original[i][colatual];
				}
				break;
				
			case 2:
				for (i=0; i<linhas; i++){
					for (colatual=0; colatual<colunas; colatual++) 
						green[i][colatual] = original[i][colatual];	

				}
				break;
				
			case 3:
				for (i=0; i<linhas; i++){
					for (colatual=0; colatual<colunas; colatual++)
						blue[i][colatual] = original[i][colatual];

				}
				break;					
		}	
	}
	
	//Print (debug)
	for (i=0; i<linhas; i++){
		printf("\n");
		for (colatual=0; colatual<colunas; colatual++) 
			printf("%d ", red[i][colatual]);
	}
	printf("\n\n\n");

	for (i=0; i<linhas; i++){
		printf("\n");
		for (colatual=0; colatual<colunas; colatual++) 
			printf("%d ", green[i][colatual]);
	}			
	printf("\n\n\n");
	for (i=0; i<linhas; i++){
		printf("\n");
		for (colatual=0; colatual<colunas; colatual++) 
			printf("%d ", blue[i][colatual]);
	}			
	printf("\n\n\n");
			
			
	//Escala de Cinza
	for (i=0; i<linhas; i++){
		for (colatual=0; colatual<colunas; colatual++){
			cinza[i][colatual] = (red[i][colatual] + green[i][colatual] + blue[i][colatual]) / 3;	
		}
	}
	
	for (i=0; i<linhas; i++){
		printf("\n");
		for (colatual=0; colatual<colunas; colatual++) 
			printf("%d ", cinza[i][colatual]);
	}			
	printf("\n\n\n");
	
	
	//Convolução de Matrizes:
	scanf("%d %d", &divisor, &ordem);
	bordas = ordem/2;
	
	for (i=0; i<ordem; i++) {
		for (colatual=0; colatual<ordem; colatual++) {
			scanf("%d", &convolucao[i][colatual]); 
		}
	}
	
	
	
	for (i=0; i<linhas; i++) {
		for (colatual=0; colatual<colunas; colatual++) {
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
