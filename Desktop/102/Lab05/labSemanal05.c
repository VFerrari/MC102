/* Victor Ferreira Ferrari, RA 187890, Turma S
	O programa tem o objetivo de calcular a maior sintonia entre a pessoa mais
popular dentre as fornecidas e as outras. Para isso, serão fornecidos como
entrada os dados e a afinidade com cada um, por pessoa. Com essas informações,
será feita uma estrutura de grafo, sendo que os vértices são as pessoas e as
arestas são a média entre as afinidades que cada um tem pelo outro (mínimo de 5).
	Pelo número de arestas, será encontrada a pessoa mais popular, e a sintonia
com o resto será calculada por meio da codificação do nome (pelo algoritmo Soundex)
e da data de aniversário (por numerologia). Aplicando os resultados em uma fórmula,
encontra-se a maior sintonia. */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Definição do tipo string, para melhor organização de nomes.
typedef char string[201];

//Definição de structs:
struct data {int dia, mes, ano;};

//Cada vértice do grafo é uma pessoa, com tais características
typedef struct
{string nome; struct data datanasc; char genero, preferencia;}pessoas;

//Aresta entre dois vértices (pessoas) do grafo.
typedef struct
{double peso; pessoas *p1, *p2;}arestas;


int grafo(pessoas pessoa[], arestas aresta[], int alunos);
pessoas *popular(pessoas pessoa[], arestas aresta[], int alunos, int k);
double sintonia (struct data dataform, arestas aresta, pessoas *pop);
void soundex (string nome, char cod[]);
void numerologia (struct data form, struct data nasc, char codidade[]);
double sim (char cod1[], char cod2[]);


int main (int argc, char *argv[]){
	pessoas pessoa[40], *maispop; //O número máximo de alunos é 40, e há um apontador para o mais popular.
	arestas aresta[780]; //O número máximo de arestas é 780, se todas entre 40 alunos existirem.
	struct data dataform; //O dia no qual o formulário foi aplicado.
	int alunos, narestas, c, asint; //Variáveis de controle.
	double sint1, maiorsint=0;
	
	scanf("%d/%d/%d", &dataform.dia, &dataform.mes, &dataform.ano);
	scanf("%d", &alunos);
	
	//Estruturação do grafo, e leitura dos dados.
	narestas = grafo(pessoa, aresta, alunos);
	
	//Definição da pessoa mais popular, que possui mais arestas.
	maispop = popular(pessoa, aresta, alunos, narestas);
		
	/*A partir de pessoas que possuem como gênero a preferência do outro (uma sendo a mais popular)
calcula-se a sintonia*/
	for (c=0; c<narestas; c++){
		if (aresta[c].p1 == maispop || aresta[c].p2==maispop) {
			if(aresta[c].p1->genero==aresta[c].p2->preferencia) {
				if (aresta[c].p1->preferencia == aresta[c].p2->genero)
					sint1 = sintonia (dataform, aresta[c], maispop);
			}
		}
		//Armazenamento da maior sintonia.
		if (sint1>maiorsint) {
			maiorsint = sint1;
			asint=c;
		}
	}
	
	if (aresta[asint].p1 == maispop)
		printf("%s combina com %s com %.2lf de sintonia s2\n", aresta[asint].p1->nome, aresta[asint].p2->nome, maiorsint);
	else
		printf("%s combina com %s com %.2lf de sintonia s2\n", aresta[asint].p2->nome, aresta[asint].p1->nome, maiorsint);
		
	return 0;
}


int grafo(pessoas pessoa[], arestas aresta[], int alunos){
	int k=0, i, j, aux=0; //Contadores. K é o número de arestas
	double afinidade[40][40]; //Cada pessoa tem até 39 valores de afinidade com cada outra.
	
	//Leitura dos dados de cada pessoa.
	for (i=0; i<alunos; i++) {
		scanf(" %[^\n]s", pessoa[i].nome);
		scanf("%d/%d/%d %c %c", &pessoa[i].datanasc.dia, &pessoa[i].datanasc.mes, &pessoa[i].datanasc.ano, &pessoa[i].genero, &pessoa[i].preferencia);
		for (j=0; j<alunos;j++) {
			if (j==i) j++; //Como a pessoa não coloca valor de afinidade para ela mesma, a posição é pulada.
			scanf("%lf ", &afinidade[i][j]);
		}
	}
	
	//Cálculo da média entre as afinidades entre duas pessoas, e criação da aresta.
	for (i=0; i<alunos; i++) {
		for(j=aux; j<alunos;j++) {
			if (j==i) j++; //Não há valor de afinidade para a própria pessoa, então a posição é pulada.
			aresta[k].peso = sqrt(afinidade[i][j]*afinidade[j][i]); //Média geométrica.
						
			//Apontadores para os vértices ligados pela aresta.
			aresta[k].p1 = &pessoa[i];
			aresta[k].p2 = &pessoa[j];
			
			if (aresta[k].peso>=5.00) k++; //A aresta é criada se a média for maior que 5.
		}
		aux++;
	}
	return k; //Retorno do número de arestas.
}


pessoas *popular(pessoas pessoa[], arestas aresta[], int alunos, int k){
	int popularidade[40], i, j, maiorvalor=0, maiorpop;
	pessoas *pop;
	
	for (j=0;j<alunos; j++) popularidade[j]= 0;
	
	//Contando quantas arestas cada pessoa possui.
	for (i=0; i<k; i++){
		for(j=0; j<alunos;j++){
			if (aresta[i].p1 ==&pessoa[j] || aresta[i].p2==&pessoa[j])
				popularidade[j]++;
				
		}
	}
	
	//Comparação entre as quantidades de aresta, e a pessoa que tiver mais é a mais popular.
	for (j=0; j<alunos; j++){
		if (popularidade[j]>maiorvalor) {
			maiorvalor=popularidade[j];
			maiorpop = j; //Indicação da posição da pessoa mais popular.
			
		}
	}
	
	pop = &pessoa[maiorpop]; //Apontador para a pessoa mais popular.
	
	return pop;
}


double sintonia (struct data dataform, arestas aresta, pessoas *pop){
	char codnome1[5], codidade1[5], codnome2[5], codidade2[5]; //Códigos de nome e idade;
	double sint;
	
	//Codificação do nome e idade (data de nascimento) dos dois envolvidos.
	soundex(aresta.p1->nome, codnome1);
	soundex(aresta.p2->nome, codnome2);
	numerologia(dataform, aresta.p1->datanasc, codidade1);
	numerologia(dataform, aresta.p2->datanasc, codidade2);
	
	//Cálculo da sintonia, a partir dos cálculos dos códigos.
	sint = (3*sim(codnome1,codnome2) + 5*sim(codidade1, codidade2) + 2*(aresta.peso/10))/10;
	
	return sint;
}


//Algoritmo Soundex para codificação do primeiro nome.
void soundex (string nome, char cod[]){
	int aux=0, j;
	char vogal=0, consoante=0;
	
	//Inicializando o vetor
	for(j=0; j<5; j++) cod[j] = 0;
		
	nome[0] = tolower (nome[0]);
	
	j=0;
	
	//Codificando as três primeiras consoantes do nome, de acordo com uma tabela.
	do {	
		switch (nome[j]) {
			case 'g': case 'j': strcpy (cod+aux, "1"); consoante=1; break;
			case 's': case 'z': case 'x': strcpy (cod+aux, "2"); consoante=1; break;
			case 'c': case 'k': case 'q': strcpy (cod+aux, "3"); consoante=1; break;
			case 'b': case 'p': strcpy (cod+aux, "4"); consoante=1; break;
			case 'm': case 'n': strcpy (cod+aux, "5"); consoante=1; break;
			case 'd': case 't': strcpy (cod+aux, "6"); consoante=1; break;
			case 'f': case 'v': strcpy (cod+aux, "7"); consoante=1; break;
			case 'l': strcpy (cod+aux, "8"); consoante=1; break;
			case 'r': strcpy (cod+aux, "9"); consoante=1; break;				
			default: if (aux!=0) aux--; vogal=1, consoante=0; break;
		}
		
		//Verificação de repetições no código
		if(vogal==0 && cod[aux-1]==cod[aux] && aux!=0) aux--;
		if (vogal==1 && consoante==1) vogal=0;
		
		j++; aux++;

		if (aux==4) break; //Quando três consoantes forem codificadas, o processo acaba.
	} while (nome[j] != ' ');
	
	//Adição de zeros ao código, na falta de consoantes ou repetições
	if (aux == 1)
		strcpy (cod+1, "000");
	else if (aux == 2)
		strcpy (cod+2, "00");
	else if (aux == 3)
		strcpy (cod+3, "0");
	
	cod[0] = toupper (nome[0]);
	nome[0] = cod[0];
}


//Codificação das idades e datas de nascimento.
void numerologia (struct data form, struct data nasc, char codidade[]){
	int anocod, codigo, idade;
	
	//Soma dos algarismos do ano, com o mês e o dia de aniversário.
    anocod = nasc.ano/10000 + ((nasc.ano%10000)/1000) + ((nasc.ano%1000)/100) + ((nasc.ano%100)/10) + (nasc.ano%10);
    codigo=nasc.dia+nasc.mes+anocod;

	//Caso a soma resultante tenha mais de um algarismo, eles são somados até que se tenha um só.
    while (codigo/10 != 0)
		codigo = (codigo/10) + (codigo%10);
   
   //Cálculo da idade da pessoa
    idade = form.ano-nasc.ano;
    if (nasc.mes-form.mes > 0)
		idade--;
    else if (form.mes == nasc.mes && nasc.dia-form.dia>0)
		idade--; 
	
	//Adição da idade ao código. Caso a idade tenha 2 dígitos, ela é adicionada ao final.
	if (idade/10>0 && idade/10<10)
		codigo= codigo*100 + idade;		
	else if (idade/10==0)
		codigo = codigo*100 + idade*10; //Se tiver menos, é adicionado um zero no final.
	else if (idade/10>=10 && idade/10<100)
		codigo = codigo*100 + idade/10;//Se tiver mais, só são considerados os 2 primeiros dígitos.
	else
		codigo = codigo*100 + idade/100;

		sprintf(codidade, "%d", codigo); //Transformação em vetor de char;
}


//Função de similaridade.
double sim (char cod1[], char cod2[]){
	int igual=0, i;
	double sim, j;
	
	//Como strings com tamanhos diferentes podem ser usadas, calcula-se o tamanho.
	j = strlen(cod1);
	
	//Compara-se as duas strings em cada caractere.
	for(i=0; i<j; i++) {
		if (cod1[i]==cod2[i]) 
			igual++;
	}
	//A similaridade é dada pelo número de caracteres iguais, dividido pelo tamanho (porcentagem).
	sim = igual/j;
	
	return sim;
}
