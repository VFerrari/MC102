
/**
 * Função de inserção de uma consulta na lista.
 * Inserção ordenada alfabeticamente.
*/
TPconsulta insereOrd(int chave[2][2], TPconsulta inicio){
	TPconsulta novo, anterior, atual;
	
	//Alocação de memória para a consulta.
	novo = (TPconsulta)malloc(sizeof(Tconsulta));

	scanf(" %s %s %s %d", novo->paciente, novo->data, novo->codigo, &novo->crm);
	cripto(chave, novo->paciente, 'd'); //Deciframento do nome.
	
	atual = inicio;
	
	//Caso a lista esteja vazia.
	if (inicio==NULL){
		inicio = novo;
		novo->prox = inicio;
		cripto(chave, novo->paciente, 'e'); //Codificação do nome.
		return inicio;
	}
	
	cripto(chave, atual->paciente, 'd');
	
	//Caso a consulta deva ser inserida no começo da lista.
	if (strcmp(atual->paciente, novo->paciente)>0){
		
		while (atual->prox != inicio)
			atual=atual->prox;
		atual->prox = novo;
		atual = inicio;
		novo->prox = atual;
		inicio = novo;		
		cripto (chave, atual->paciente, 'e');
	}
	else{ //Caso contrário, busca na lista.
		cripto(chave, atual->paciente, 'e');
		anterior = atual;
		atual = atual->prox;
		
		while(atual != inicio){
			cripto(chave, atual->paciente, 'd');
			
			//Quando o lugar correto é encontrado, o loop é interrompido.
			if (strcmp(atual->paciente, novo->paciente)>0){
				cripto(chave, atual->paciente, 'e');
				break;
			}
			else{
				cripto(chave, atual->paciente, 'e');
				anterior=atual;
				atual = atual->prox;
			}
		}
		//Inserção no local imediatamente anterior ao analisado.
		novo->prox = atual;
		anterior->prox = novo;
	}
	
	cripto(chave, novo->paciente, 'e');
	
	return inicio;
}

/**
 * Função para apagar consultas da lista.
 * Busca pelo nome do paciente na lista, e apaga a consulta.
*/
TPconsulta apaga(int chave[2][2], TPconsulta inicio){
	TPconsulta atual, anterior, alvo;
	string nome;
	
	scanf(" %s", nome);
	atual = inicio;
	
	//Se a primeira consulta for a desejada.
	cripto(chave, atual->paciente, 'd');
	
	if (strcmp(nome, atual->paciente) == 0){
		alvo = atual;
		while (atual->prox != inicio)		
			atual = atual->prox; //Procura pelo último.
		inicio = alvo->prox; //Mudança de posição do apontador de início.		
		atual->prox = inicio; //Conexão do último com o início.
		free(alvo);
		return inicio;
	}
		
	//Caso contrário, busca.
	while (strcmp(nome, atual->paciente) != 0){
		cripto(chave, atual->paciente, 'e');
		anterior = atual; 
		atual=atual->prox;
		cripto(chave, atual->paciente, 'd');
	}
	
	anterior->prox=atual->prox; //Conexão entre as consultas anterior e posterior.
	free(atual); //Liberação da memória alocada anteriormente.
	
	return inicio;
}

/**
 * Função de alteração de doença.
 * Busca do nome da doença, e reposição do código na consulta.
 * @param cons Consulta que deve ser alterada.
*/
void altDiag(TPconsulta cons, doenca *vetD, int numero){
	string novaD;
	
	scanf(" %[^\n]s", novaD);
	
	//Busca pelo nome da doença.
	for(int i=0;i<numero;i++){
		if (strcmp((vetD+i)->nome, novaD)==0){
			strcpy(cons->codigo, (vetD+i)->codigo); //Reposição
			break;
		}
	}
	
	return;
}

/**
 * Função de alteração de médico.
 * Busca do nome do médico, e reposição do CRM responsável pela consulta.
 * @param cons Consulta que deve ser alterada.
*/
void altMed(TPconsulta cons, medico *vetM, int numero){
	string novoM;

	scanf(" %[^\n]s", novoM);
	
	//Busca pelo nome do médico.
	for(int i=0; i<numero;i++){
		if(strcmp((vetM+i)->nome, novoM)==0){
			cons->crm = (vetM+i)->crm; //Reposição
			break;
		}
	}
	
	return;
}

/**
 * Função para alteração de dados em uma consulta.
 * Podem ser alterados a data, o diagnóstico e o médico responsável.
 * @param tipo Símbolo do que deve ser alterado.
 * @param nD, nM, número de doenças e de médicos.
*/
void altera(int chave[2][2], TPconsulta inicio, doenca *vetD, medico *vetM, char tipo, int nD, int nM){
	TPconsulta atual;
	string nome, novadata;
	
	scanf(" %s", nome);
	atual = inicio;
	
	cripto(chave, atual->paciente, 'd');
	
	//Busca do nome do paciente na lista de consultas.
	while (strcmp(nome, atual->paciente) != 0){
		cripto(chave, atual->paciente, 'e');
		atual = atual->prox;
		cripto(chave, atual->paciente, 'd');
	}
	cripto(chave, atual->paciente, 'e');
	
	//Alteração dos dados.
	if(tipo=='t'){
		scanf(" %s", novadata);
		strcpy (atual->data, novadata);
	}
	else if(tipo=='a')
		altDiag(atual, vetD, nD);
	else if(tipo=='d')
		altMed(atual, vetM, nM);
	
	return;
}
