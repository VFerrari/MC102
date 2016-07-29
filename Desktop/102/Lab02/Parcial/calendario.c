#include <stdio.h>

int main (int argc, char *argv[]) {
	int adia, ames, anofinal, ano=2016, dias=0, mesatual, mes131, mes132, mes133, aux, contador=1;
	scanf("%d/%d %d", &adia, &ames, &anofinal);
	
	//Cálculo do número de sextas-feiras 13 nos anos entre o inicial (2016) e o final fornecido.
	for(; ano<=anofinal; ano++) {
		
		//Após o primeiro ano, é preciso retornar o valor destas variáveis ao original, para que erros não ocorram.
		mes131 = 0;
		mes132 = 0;
		mes133 = 0;
		mesatual = 1;

		//Teste do dia 13 de todos os meses do ano em questão. No método utilizado, os meses de janeiro e fevereiro (1 e 2) devem ser contados como meses 13 e 14 do ano anterior. A partir de março (3) o ano volta ao analisado.
		for (; mesatual <= 12; mesatual++) {
			if (mesatual == 1)
				mesatual=13;
			if (mesatual == 2)
				mesatual=14;
			for (; contador>0;contador--) {
				if (mesatual==13)
					ano--;}
			for (; contador<1;contador++){
				if (mesatual ==3)
						ano++;}
				
 printf ("%d %d %d %d %d %d\n", mesatual, ano, dias, mes131, mes132, mes133);
 
		// Cálculo de sextas-feiras 13. Trata-se de uma adaptação de uma fórmula equivalente à chamada Congruência de Zeller, para apenas calcular os dias da semana dos dias 13 de todos os meses.
		aux = 13 + (2*mesatual) + (3*(mesatual+1)/5) + ano + (ano/4) - (ano/100) + (ano/400) + 2;
		aux%=7;

		//Retorno dos valores de janeiro e fevereiro para 1 e 2 para comparação com o mês de aniversário obtido.
		if (mesatual == 13)
			mesatual = 1;
		if (mesatual == 14)
			mesatual = 2;

		//Isolamento do resultado 6, que indica sexta-feira, acréscimo de 1 nos dias nos quais a exposição estará aberta, identificação e separação dos meses que forneceram tal resultado.
		if (aux==6){
			dias++;
			if (mes131 == 0)
				mes131 = mesatual;
			else if (mes132 == 0)
				mes132 = mesatual;
			else
				mes133 = mesatual; } 
		
		}
	
	//Comparação com exceções. Se o aniversário for em certos dias, ele pode ou não ser adicionado à contagem de dias. Isso ocorre nos dias 12, 13, 14 (pois podem coincidir ou ser próximas de sextas-feiras 13) e, em anos bissextos, dia 29 de fevereiro.
	switch (adia) { 
		case 13: case 12: case 14:
			if (ames == mes131 || ames == mes132 || ames==mes133)
			dias--; 
			break;
			
		//Identificação de anos bissextos
		case 29:
			if (ames == 02) {
				if (ano % 4 == 0 && ano % 100 !=0)
					break;
				if (ano %400 == 0)
					break;
				else
					dias--;
					break;
			}
		}
dias++;
}	
	printf ("%d", dias);
	return 0; }
