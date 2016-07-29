#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
		
    scanf(" %[^\n]s",busca);
	tipo--;
	for (i=0; i<10;i++){
		if (strcmp (nome[i][tipo], buscar) == 0){
			printf("%s\n%lld\n", nome[i][tipo], cpf[i][tipo]);
			printf("%s\n%lld\n%lld\n", endereco[i][tipo], foneres[i][tipo], fonecel[i][tipo]);
			sim++;
			break;	
		}
	}
	
	return 0; 
}
