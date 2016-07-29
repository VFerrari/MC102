#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	
	switch (opcao) {
		case 5:
			
			for(i=0; i<=controle[0];i++) {
				if (nome[i][0] == '\0')
					break;
				printf("%s\n%lld\n", nome[i][0], cpf[i][0]);
				printf("%s\n%lld\n%lld\n", end[i][0], foneres[i][0], fonecel[i][0]); 
			}
			if (i !=0)
				sim++;
			break;
		case 6:
			
			for(i=0; i<=controle[1];i++) {
				if (nome[i][1] == '\0')
					break;
				printf("%s\n%lld\n", nome[i][1], cpf[i][1]);
				printf("%s\n%lld\n%lld\n", end[i][1], foneres[i][1], fonecel[i][1]); 
			}
			if (i !=0)
				sim++;
			break;
	}
	return 0; 
}
