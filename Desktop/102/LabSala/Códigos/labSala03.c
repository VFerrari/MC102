#include <stdio.h>

int main (){
	char tabuleiro[21][21];
	char palavra[21];
	int n, m, i, j, lin, col; //variáveis contadora para loops
	int posPalavra=0, qntLetras=0, acheiHor=0, acheiVer=0, cUltLetra, lUltLetra;

	scanf("%s", palavra);
	scanf("%d%d\n", &n, &m);

	//leitura do tabuleiro de caça palavras
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%c", &tabuleiro[i][j]);
	
	//Conta quantas letras tem a palavra a ser buscada
	while (palavra[qntLetras]!='\0')
		qntLetras++;

	//Buscar pela palavra
	for (i=0; i<n; i++){
		lin=i;
		if (acheiVer || acheiHor) //se encontrou a palavra, não verificar o resto do tabuleiro
			break;
		for (j=0; j<m; j++){
			col=j;
			if (tabuleiro[lin][col]==palavra[0]){ //se encontra a primeira letra
				while (posPalavra<qntLetras){ //busca o restante da palavra na horizontal
					if (tabuleiro[lin][col]==palavra[posPalavra]){
						posPalavra++;
						col++;
					}
					else {
						posPalavra=0;
						break;						
					}
				}
				if(posPalavra==qntLetras){ //se achou guardar valores para impressão
					acheiHor=1;
					lUltLetra=lin;
					cUltLetra=col;
					break;
				}
				posPalavra=0; //se não achou volta para o início da palavra
				col=j; 	//e reposiona coluna na primeira letra no tabuleiro		
				while (posPalavra<qntLetras){//busca o restante da palavra na vertical	
					if (tabuleiro[lin][col]==palavra[posPalavra]){
						posPalavra++;
						lin++;
					}
					else {
						posPalavra=0;
						break;						
					}
				}
				if(posPalavra==qntLetras){ //se achou guardar valores para impressão
					acheiVer=1;						
					lUltLetra=lin;
					cUltLetra=col;
					break;
				}
				posPalavra=0; //se não achou volta para o início da palavra
				lin=i; //e reposiona linha na primeira letra no tabuleiro
			}
		}
	}		

	//impressão da saida da esquerda para a direita ou cima para baixo	
	if (acheiHor)
		while (qntLetras>0){
			printf("L%dC%d ", lUltLetra+1, cUltLetra-qntLetras+1);//linhas e colunas vao de 1 a n (nao de 0 a n-1)
			qntLetras--;
		}
	else
		while (qntLetras>0){
			printf("L%dC%d ", lUltLetra-qntLetras+1, cUltLetra+1);//linhas e colunas vao de 1 a n (nao de 0 a n-1)
			qntLetras--;
		}
	
	return 0;
}
