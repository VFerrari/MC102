#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	
	int original[599][599], red[599][599], green[599][599], blue[599][599];
	int linhas, colunas, i=0, colatual, repeticoes, numero, matrizes, colfinal;
	
	
	//Criação da matriz "Original".
	scanf("%d %d", &colunas, &linhas);
	
	for (matrizes=1; matrizes<=3; matrizes++) {
		for(i=0; i<linhas; i++){
			for (colatual=0; colatual<colunas;) {
				
				scanf("%d %d", &repeticoes, &numero);
				
				printf("Certo1\n");
				
				colfinal = colatual + repeticoes;
				
				
				for(; colatual<colfinal; colatual++) {
					if (colatual == colunas) {
						i++;
						colatual = 0;
						colfinal-=colunas;
						printf("Certo6\n");
					}
					original[i][colatual] = numero;
					printf("Certo2\n");

				}
			}
		}
	
	
	// Colocar original em Red, Green e Blue
		switch (matrizes) {
			case 1:
				for (i=0; i<linhas; i++){
					for (colatual=0; colatual<colunas; colatual++) 
						red[i][colatual] = original[i][colatual];
										printf("Certo3\n");

				}
				break;
				
			case 2:
				for (i=0; i<linhas; i++){
					for (colatual=0; colatual<colunas; colatual++) 
						green[i][colatual] = original[i][colatual];	
										printf("Certo4\n");

				}
				break;
				
			case 3:
				for (i=0; i<linhas; i++){
					for (colatual=0; colatual<colunas; colatual++)
						blue[i][colatual] = original[i][colatual];
										printf("Certo5\n");

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
	for (i=0; i<linhas; i++){
		printf("\n");
		for (colatual=0; colatual<colunas; colatual++) 
			printf("%d ", green[i][colatual]);
	}			
	for (i=0; i<linhas; i++){
		printf("\n");
		for (colatual=0; colatual<colunas; colatual++) 
			printf("%d ", blue[i][colatual]);
	}			
			
	return 0; }
