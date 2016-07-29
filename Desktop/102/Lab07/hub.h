
//Função para definição de operações.
TPconsulta operacoes(doenca *vetD, medico *vetM, int chave[2][2], int nDoenca, int nMed){
	char op[8];
	TPconsulta lista=NULL;

	while(1){
		scanf("%s", op); //Obtenção da operação desejada.
		if (op[0]=='0')
			break;
					
		switch(op[1]){
			case 'd': lista = insereOrd(chave, lista); break; //Add
			case 'm': lista = apaga(chave, lista); break; //Rm
			case 'l': altera(chave, lista, vetD, vetM, op[5], nDoenca, nMed); break; //Alt
		}
	}
	
	return lista; //Retorna o início da lista de consultas.
}

/**
 * Função para impressão do relatório
 * @param letra Letra de início do relatório.
 * @param início Apontador para o início da lista de consultas.
 * @param chave Chave para criptografia
*/
void imprimeRelat(TPconsulta inicio, char letra, int chave[2][2]){
	TPconsulta atual, anterior;
	
	atual = inicio;
	cripto(chave, atual->paciente, 'd');
	
	//Definição do início do relatório.
	while (atual->paciente[0]<letra){
		cripto(chave, atual->paciente, 'e');
		
		//Caso não haja letra posterior à desejada, é listado do começo.
		if (atual->prox == inicio){
			atual = inicio;
			cripto(chave, atual->paciente, 'd');
			break;
		}
		anterior = atual;
		atual = atual->prox;
		cripto(chave, atual->paciente, 'd');
	}
	
	inicio = atual;
	
	//Impressão do relatório, e liberação da memória.
	while(1){
		printf("%s %s %s %d\n", atual->paciente, atual->data, atual->codigo, atual->crm);
		anterior = atual;
		atual = atual->prox;
		free(anterior);
		if (atual == inicio)
			break;
		cripto(chave, atual->paciente, 'd');
	}
	
	return;
}
