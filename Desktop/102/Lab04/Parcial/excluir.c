#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	
	int aux;
	tipo--;
    scanf(" %[^\n]s",exclui);
    for (i=0;i<10;i++) {
		if (strcmp(exclui, nome[i][tipo])==0){
			for (aux=i; aux<controle[tipo]; aux++) {
				strcpy(nome[aux+1][tipo], nome[aux][tipo]);
				strcpy(end[aux+1][tipo], end[aux][tipo]);
				cpf[aux][tipo] = cpf[aux+1][tipo];
				foneres[aux][tipo] = foneres[aux+1][tipo];
				fonecel[aux][tipo] = fonecel[aux+1][tipo];
			}
			nome[controle[tipo]][tipo] =;
			end[controle[tipo]][tipo] =;
			cpf[controle[tipo]][tipo] =;
			foneres[controle[tipo]][tipo] =;
			fonecel[controle[tipo]][tipo] =;
			controle[tipo]--;
			break;
		}
	}
	if (i == 10)
		return 0;
	
	return 1; 
}
