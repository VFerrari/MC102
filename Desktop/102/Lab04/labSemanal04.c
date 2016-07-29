/*Victor Ferreira Ferrari, RA 187890, Turma S 
	O programa consiste em uma "agenda telefônica", ou seja, são fornecidas
opções para o usuário, e dependendo da escolha, o programa pode inserir,
excluir, alterar ou buscar contatos, ou listá-los (segundo suas categorias,
ou todos). O programa para quando o usuário quiser, e fornecer a instrução.
	A entrada consiste em um número (a escolha da função), e os dados do
contato que se quer inserir, excluir, alterar ou buscar, quando necessário.
	A saída é uma série de mensagens que deixa claro o resultado da instrução
dada pelo usuário (se o contato foi inserido, a agenda está lotada, etc), se
a tarefa foi bem-sucedida ou não. Também pode incluir os dados de certos
contatos, caso a opção "listar" for escolhida.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[60];

int inserir (int tipo, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]); 
int excluir (int tipo, string exclui, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]); 
int alterar (int tipo, string altera, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]); 
int buscar (int tipo, string busca, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]); 
int listar (char opcao, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]); 


int i, controle[2] = {0,0}; // Estas variáveis são globais pois serão usadas em múltiplas funções.

int main (int argc, char *argv[]) {
	signed char opcao;
	int tipo; //O tipo do contato a ser inserido/excluído/alterado/buscado, sendo 1-Pessoal ou 2-Profissional.
	int sim; //Variável retornada para seleção de mensagem (se a operação foi bem-sucedida)
	string nome[10][2], endereco[10][2], procura; 
	long long int cpf[10][2], foneres[10][2], fonecel[10][2];
					
	do {
		sim=0;
		scanf("%hhd", &opcao);
		
		//Escolha da tarefa desejada.
		switch (opcao){
			
			//Inserir um contato na agenda
			case 1:
				
                scanf ("%d", &tipo); 
                sim = inserir(tipo, nome, endereco, cpf, foneres, fonecel);
                 
				if (sim)
					printf("Inserido com sucesso!\n");
                else
                    printf("Desculpe, agenda lotada!\n");
				break;
				
			//Excluir um contato da agenda
			case 2:
                
                scanf ("%d", &tipo);        
                sim = excluir(tipo, procura, nome, endereco, cpf, foneres, fonecel);
                
				if (sim)
                    printf("Excluido com sucesso!\n");
                else
                    printf("Desculpe, contato %s nao existe!\n", procura);
				break;
				
			//Alterar um contato já presente na agenda
			case 3:

                scanf ("%d", &tipo);        
	            sim = alterar(tipo, procura, nome, endereco, cpf, foneres, fonecel);
       	
                if (sim)
                    printf("Alterado com sucesso!\n");
                else
                    printf("Desculpe, contato %s nao existe!\n", procura);
				break;
				
			//Buscar um contato na agenda
			case 4:
                        
                scanf ("%d", &tipo);
				sim = buscar(tipo, procura, nome, endereco, cpf, foneres, fonecel);
                
                if (sim)
                    printf("Buscado com sucesso!\n");
                else
                    printf("Desculpe, contato %s nao existe!\n", procura);
				break;
				
			//Listar certos contatos da agenda (5-pessoais, 6-profissionais)
			case 5: case 6: 
                        
                sim = listar(opcao, nome, endereco, cpf, foneres, fonecel);
                        
                if (sim)
                    printf("Listado com sucesso!\n");
                else
                    printf("Desculpe, agenda vazia!\n");
				break;
			
			//Listar todos os contatos da agenda
			case 7:
				
				//Pessoais
				opcao = 5;
                sim = listar(opcao, nome, endereco, cpf, foneres, fonecel);	
				if (sim)
                    printf("Listado com sucesso!\n");
                else
                    printf("Desculpe, agenda vazia!\n");
                
                //Profissionais
				sim = 0;
                opcao = 6;
                sim = listar(opcao, nome, endereco, cpf, foneres, fonecel);
				if (sim)
                    printf("Listado com sucesso!\n");
                else
                    printf("Desculpe, agenda vazia!\n");
				break;
		}
	} while (opcao != 0); //A opção 0 termina a execução do programa.
	
	printf ("Obrigado!\n");	
	return 0;	
}

int inserir (int tipo, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]){
	
	//Variáveis temporárias, pois é preciso ler todos os dados, mesmo quando a agenda está lotada.
	long long int cpf2, foneres2, fonecel2;
	string nome2, end2;
	
	tipo--; /*A variável "tipo" é usada como índice de matriz, então é transformada
	de índice 1 para 0*/ 
	
	scanf(" %[^\n]s", nome2);
	scanf("%lld", &cpf2);
	scanf(" %[^\n]s", end2);
	scanf("%lld %lld", &foneres2, &fonecel2);
	
	//Caso a agenda estiver lotada para certo tipo, os dados não são armazenados.
	if (controle[tipo] == 10)
		return 0;
	
	//Armazenamento dos contatos.
	else {
		strcpy(nome[controle[tipo]][tipo], nome2);
		cpf[controle[tipo]][tipo] = cpf2;
		strcpy(end[controle[tipo]][tipo], end2);
		foneres[controle[tipo]][tipo] = foneres2;
		fonecel[controle[tipo]][tipo] = fonecel2;
		controle[tipo]++;
		return 1;
	} 
}

int excluir (int tipo, string exclui, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]){
	
	int aux, sim=0; 
	tipo--;
    scanf(" %[^\n]s",exclui); //Leitura do contato a ser excluído.
    for (i=0;i<10;i++) {
		if (strcmp(exclui, nome[i][tipo])==0){
			
			/*Ao encontrar o contato, para excluí-lo desloca-se todos os contatos
em posições inferiores para cima, e diminui-se a variável controle em 1*/
			for (aux=i; aux<controle[tipo]; aux++) {
				strcpy(nome[aux][tipo], nome[aux+1][tipo]);
				strcpy(end[aux][tipo], end[aux+1][tipo]);
				cpf[aux][tipo] = cpf[aux+1][tipo];
				foneres[aux][tipo] = foneres[aux+1][tipo];
				fonecel[aux][tipo] = fonecel[aux+1][tipo];
			}
			controle[tipo]--;
			sim++;
			break;
		}
	}
	//Caso o contato não seja encontrado, a variável "sim" terá valor 0, e isso será notificado.
	return sim; 
}

int alterar (int tipo, string altera, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]){

	int sim=0;
	tipo--;
	scanf(" %[^\n]s",altera); //Leitura do contato a ser alterado.
	for (i=0; i<10; i++){
		if (strcmp(altera, nome[i][tipo]) == 0) {
			
			//Ao encontrar o contato, os dados novos sobrescrevem os antigos.
			scanf ("%lld", &cpf[i][tipo]);
			scanf(" %[^\n]s", end[i][tipo]);
			scanf("%lld %lld", &foneres[i][tipo], &fonecel[i][tipo]);
			sim++; //Se o contato foi encontrado, a tarefa foi bem-sucedida.
			break;
		}
	}
	return sim; 
}

int buscar (int tipo, string busca, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]) {
	
	int sim=0;
	scanf(" %[^\n]s",busca); //Leitura do contato a ser buscado
	tipo--;
	for (i=0; i<10;i++){
		
		//Listagem dos dados do contato encontrado
		if (strcmp (nome[i][tipo], busca) == 0){
			printf("%s\n%lld\n", nome[i][tipo], cpf[i][tipo]);
			printf("%s\n%lld\n%lld\n", end[i][tipo], foneres[i][tipo], fonecel[i][tipo]);
			sim++; //Se o contato foi encontrado, a operação foi bem-sucedida.
			break;	
		}
	}
	return sim; 
}

int listar (char opcao, string nome[][2], string end[][2], long long int cpf[][2], long long int foneres[][2], long long int fonecel[][2]){
		
	int sim=0;
	
	//O usuário tem 3 opções para listagem. A terceira realiza as duas operações.
	
	switch (opcao) {
		//Contatos pessoais (tipo 1)
		case 5:
			
			for(i=0; i<controle[0];i++) {
				
				//Se for encontrado um valor nulo, a listagem para (todos os contatos já foram listados).
				if (nome[i][0] == '\0') 
					break;
				printf("%s\n%lld\n", nome[i][0], cpf[i][0]);
				printf("%s\n%lld\n%lld\n", end[i][0], foneres[i][0], fonecel[i][0]); 
			}
			//Caso ao menos um contato seja listado, a tarefa foi bem-sucedida.
			if (i !=0)
				sim++;
			break;
			
		//Contatos profissionais (tipo 2)
		case 6:
			
			for(i=0; i<controle[1];i++) {
				if (nome[i][1] == '\0')
					break;
				printf("%s\n%lld\n", nome[i][1], cpf[i][1]);
				printf("%s\n%lld\n%lld\n", end[i][1], foneres[i][1], fonecel[i][1]); 
			}
			if (i !=0)
				sim++;
			break;
	}
	return sim; 
}

