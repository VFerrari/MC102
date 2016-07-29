#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	
	tipo--;
	scanf(" %[^\n]s",altera);
	for (i=0; i<10; i++){
		if (strcmp(altera, nome[i][tipo]) == 0) {
			scanf ("%lld", &cpf[i][tipo]);
			scanf(" %[^\n]s", end[i][tipo]);
			scanf("%lld %lld", &foneres[i][tipo], &fonecel[i][tipo]);
			break;
		}
	}
	if (i == 10)
		return 0;
	else
		return 1; 
}
