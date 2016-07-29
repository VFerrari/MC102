#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	
	int red[599][599], blue[599][599], green[599][599], cinza[599][599];
	int linhas, colunas, colatual, i;
	
	for (i=0; i<linhas; i++){
		for (colatual=0; colatual<colunas; colatual++){
			cinza[i][colatual] = (red[i][colatual] + green[i][colatual] + blue[i][colatual]) / 3;
			
		}
	}
	
	
	return 0;}
