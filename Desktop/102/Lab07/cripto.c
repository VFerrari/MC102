#include <stdio.h>
#include <string.h>

typedef char string[101];

void codifica(int chave[2][2], string novo, int cifra[2], int i){
	int result[2];
	
	result[0] = (chave[0][0] * cifra[0] + chave[0][1] * cifra[1])%26;
	result[1] = (chave[1][0] * cifra[0] + chave[1][1] * cifra[1])%26;
	
	novo[0+i] = (char)result[0] +65; 
	novo[1+i] = (char)result[1] +65;
	
	return;
}


void decifra(int chave[2][2], string novo, int cifra[2], int i){
	static int inversa[2][2], aux=0;
	int detChave, detInv;
	
	if (!aux){
		detChave = (chave[0][0] * chave[1][1]) - (chave[1][0] * chave[0][1]); 
	
		for (detInv=1; detInv<26; detInv++){
			if ((detChave*detInv)%26 == 1) 
			break;
		}
	
		inversa[0][0] = (detInv * chave[1][1]) % 26;
		inversa[0][1] = (detInv * chave[0][1])%26;
		inversa[1][0] = (detInv * chave[1][0])%26;
		inversa[1][1] = (detInv * chave[0][0])%26;
		
		inversa[0][1]=(inversa[0][1] - 26) *-1;
		inversa[1][0]=(inversa[1][0] - 26)*-1;
	}
		
	codifica(inversa, novo, cifra, i);
	
	return;
}


int main(int argc, char *argv[]){
	int i=0, cifra[2], chave[2][2];
	string novo, nome;
	char tipo;

	for(i=0;i<100;i++)
		novo[i]=0;

	i=0;

	scanf("%s", nome);
	scanf("%d %d", &chave[0][0], &chave[0][1]);
	scanf("%d %d", &chave[1][0], &chave[1][1]);
	scanf(" %c", &tipo);
	
	while (i<strlen(nome)){
		cifra[0] = (int)nome[0+i] - 65;
		cifra[1] = (int)nome[1+i] - 65;
		if (tipo == 'e')
			codifica(chave, novo, cifra, i);
		else
			decifra(chave, novo, cifra, i);
		i+=2;
	}
	
	strcpy(nome, novo);
	
	printf("%s\n", nome);
	
	return 0 ;
}
