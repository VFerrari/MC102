/*Victor Ferreira Ferrari, RA 187890, Turma S
	Este programa tem o objetivo de realizar processamento de imagens. Dada uma imagem
comprimida pelo RLE (Run Length Encoder), este deve descomprimir tal imagem, retirar as
cores (deixá-la em escala de cinza) e aplicar filtros à mesma.
	Ao descomprimir a matriz dada, recebe-se 3 matrizes diferentes, uma para
cada cor (Vermelho, Verde e Azul). 
	Os filtros são aplicados pelo método de convolução de matrizes, que consiste na 
aplicação de uma função matemática na vizinhança de cada elemento da matriz, por meio
de outra, uma "matriz de convolução", que será sobreposta à outra. */


#include <stdio.h>
#include <stdlib.h>

int original[600][600], red[600][600], green[600][600], blue[600][600], cinza[600][600], convolucao[9][9];

int main (int argc, char *argv[]) {
	
	int linhas, colunas, i, colatual, repeticoes, numero, matrizes, colfinal, contador, ordem, divisor, bordas, contador2;
	
	//Definição da matriz de convolução, que tem ordem ímpar de até 9.
	scanf("%d %d", &divisor, &ordem);
	
	for (i=0; i<ordem; i++) {
		for (colatual=0; colatual<ordem; colatual++) {
			scanf("%d", &convolucao[i][colatual]); 
		}
	}

	//Definição da matriz "original", que receberá os valores de cada matriz RGB.
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
	
	//Definição das matrizes RGB, que recebem os valores de "original".
		for (i=0; i<linhas; i++){
			for (colatual=0; colatual<colunas; colatual++){ 
				switch (matrizes) {
					case 1:
						red[i][colatual] = original[i][colatual];
						break;
				
					case 2:
						green[i][colatual] = original[i][colatual];	
						break;
				
					case 3:
						blue[i][colatual] = original[i][colatual];
						break;					
				}
			}
		}	
	}
			
	//Transformação da imagem em escala de cinza, por meio da média entre as 3 matrizes RGB.
	for (i=0; i<linhas; i++){
		for (colatual=0; colatual<colunas; colatual++){
			cinza[i][colatual] = (red[i][colatual] + green[i][colatual] + blue[i][colatual]) / 3;	
		}
	}
	
	/*Embora a variável "bordas" defina o número de linhas que não mudarão, ela será utilizada 
para outros fins também.*/
	bordas = ordem/2; 
	
	
	/*Para que as bordas permaneçam iguais, copia-se todos os elementos de "cinza" para
a matriz final, e os outros elementos são substituídos pelos obtidos na convolução. */
	for (i=0; i<linhas; i++) {
		for (colatual=0; colatual<colunas; colatual++) {
			original[i][colatual] = cinza[i][colatual];
		}
	}

	//Convolução de matrizes
	for(i=bordas; i<(linhas-bordas); i++) {
		for(colatual=bordas; colatual<(colunas-bordas); colatual++){
			original[i][colatual] = 0; //Renovação da matriz.

			//"Bordas" é utilizada como o ponto central da matriz (metade da ordem) nos eixos x e y.
			for (contador=(bordas*-1); contador<=bordas; contador++) {
				for (contador2=(bordas*-1); contador2<=bordas; contador2++) {
					
					original[i][colatual]+= convolucao[bordas+contador][bordas+contador2] * cinza[i+contador][colatual+contador2];
				}
			}
			original[i][colatual]/= divisor;
			
			//Truncamento dos valores menores que 0 e maiores que 255.
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
			if (colatual == colunas-1)
				printf("%d", original[i][colatual]);
			else
			printf("%d ", original[i][colatual]);
		}
	}
	printf ("\n");

	return 0; }
