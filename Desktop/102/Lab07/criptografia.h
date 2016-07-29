
/**
 * Função de codificação do nome.
 * A matriz coluna com os códigos de duas letras multiplica a matriz chave.
 * Depois, é tirado o módulo com 26 de todos os valores.
 * @param cifra Código de duas letras do nome a ser codificado.
*/
void codifica(int chave[2][2], string novo, int cifra[2], int i){
	int result[2]; //Resultado
	
	result[0] = (chave[0][0] * cifra[0] + chave[0][1] * cifra[1])%26;
	result[1] = (chave[1][0] * cifra[0] + chave[1][1] * cifra[1])%26;
	
	//Transposição do resultado para a string "novo".
	novo[0+i] = (char)result[0] +65; 
	novo[1+i] = (char)result[1] +65;
	
	return;
}

/**
 * Função para decifrar um nome codificado.
 * Para tal, o processo é refeito com a matriz inversa módulo com 26 da chave.
 * Definição da matriz inversa módulo com 26.
*/
void decifra(int chave[2][2], string novo, int cifra[2], int i){
	static int inversa[2][2], aux=0;
	int detChave, detInv; //Determinantes da chave e da inversa.
	
	if (!aux){ //O cálculo da matriz só é feito uma vez, pois não muda.
		detChave = (chave[0][0] * chave[1][1]) - (chave[1][0] * chave[0][1]); 
	
		//Definição da determinante da inversa por força bruta.
		for (detInv=1; detInv<26; detInv++){
			if ((detChave*detInv)%26 == 1) 
			break;
		}
	
		inversa[0][0] = (detInv * chave[1][1]) % 26;
		inversa[0][1] = (detInv * chave[0][1]) %26;
		inversa[1][0] = (detInv * chave[1][0]) %26;
		inversa[1][1] = (detInv * chave[0][0])%26;
		
		inversa[0][1]=(inversa[0][1] - 26) *-1;
		inversa[1][0]=(inversa[1][0] - 26)*-1;
	aux++;
	}
	
	codifica(inversa, novo, cifra, i);
	
	return;
}

/**
 * Função de criptografia.
 * Comum para decifrar e codificar um nome.
 * @param tipo "d" para decifrar e "e" para codificar.
*/
void cripto(int chave[2][2], string nome, char tipo){
	int i, cifra[2];
	string novo; //Nova string onde será armazenado o nome após o processo.
	
	//Inicialização da string "novo".
	for(i=0;i<100;i++)
		novo[i]=0;
	i=0;
	
	//Duas a duas, as letras sofrem o processo de decifrar ou codificar.
	while (1){
		if (nome[0+i] == '\0')
			break;
		
		//Como as letras são maiúsculas, e o código usado é o para minúsculas,
		// ao código é subtraído 65.
		cifra[0] = (int)nome[0+i] - 65; 
		cifra[1] = (int)nome[1+i] - 65;
		if (tipo == 'e')
			codifica(chave, novo, cifra, i);
		else
			decifra(chave, novo, cifra, i);
		i+=2;
	}
	i++;
	
	//Caractere de finalização de string.
	novo[0+i] = '\0';
	
	//Transposição do nome após o processo da string "novo" para "nome".
	strcpy(nome, novo);
	
	return;
}
