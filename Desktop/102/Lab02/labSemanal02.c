/* Victor Ferreira Ferrari, RA 187890, Turma S

	Este programa tem o objetivo de, ao ser executado e receber as devidas informações de entrada, retornar o quanto custará para manter uma maquete com água em datas específicas, em uma exposição.
Para tal, são fornecidos os valores de um número inteiro de ilhas, suas coordenadas reais, a data de aniversário da cidade (no qual a exposição acontecerá, além de todas as sextas-feiras 13), 
o ano de término da exposição, o número de fornecedores de água com a capacidade do galão e o preço.
	Para resolver tal problema, os polígonos oferecidos pelas coordenadas foram separados em triângulos, suas áreas calculadas e somadas. Encontrando o valor da área da maquete completa, é subtraída
a área das ilhas. Ao se multiplicar pela profundidade, tem-se o volume de água necessário. Após esse cálculo, foi encontrado o número de dias em que a exposição ficaria aberta, por meio de testes
realizados em todos os meses de 2016 ao ano final fornecido. O número de sextas-feiras 13 encontrado é somado com os aniversários da cidade, quando apropriado. Com esses valores, é encontrado o preço
ótimo ao se comparar o preço de todos os fornecedores de água, multiplicado pelo número de galões (razão entre o volume e a capacidade de cada galão) e o número de dias. */

#include <stdio.h>

int main (int argc, char *argv[]) {
    int ilhas, contador, d=1, adia, ames, anofinal, ano=2016, dias=0, mesatual, mes131, mes132, mes133, aux, fornecedores, capacidade, galoes;
    double x0, y0, x1, y1, x2, y2, area=0, maiorx, maiory, menorx, menory, vol, areat=0, preco, precototal, precootimo=999999999999999999, galoesexatos;
    
    scanf("%d ", &ilhas);
    
    //Deve-se calcular a área de cada ilha, ou seja, repetir o mesmo processo até que todas as ilhas tenham suas áreas calculadas.
    for (; ilhas>0; ilhas--) {
        scanf(" (%lf , %lf) (%lf , %lf) ", &x0, &y0, &x1, &y1);
        contador=1;
        
		//É preciso saber quais as maiores e menores coordenadas, para que se calcule a área da maquete. Essas coordenadas podem estar em x1 e y1, então pode-se iniciar as variáveis menorx, menory, maiorx e maiory com x1 e y1.
		//x0 e y0 serão testados, mas sempre são citados 2 vezes.
		for (; d>0; d--){ 
			maiorx = x1;
			maiory = y1;
			menory = y1;
			menorx = x1;}
		
		//Para os casos com mais de uma ilha, deve-se testar x1 e y1 também.
		if (x1 > maiorx)
			maiorx = x1;
		if (y1 > maiory)
			maiory = y1;
		if (x1 < menorx)
			menorx = x1;
		if (y1 < menory)
			menory = y1;
							
		//Com o laço, todas as coordenadas fornecidas da ilha em questão serão comparadas, uma a uma, com as maiores e menores, e a área da ilha será calculada por meio da divisão do polígono (sempre convexo) em triângulos.
        while (contador>0) {
              scanf(" (%lf , %lf) ", &x2, &y2);
              if (x2 > maiorx)
					maiorx = x2;

              if (y2 > maiory)
					maiory = y2;

			  if (x2 < menorx)
					menorx = x2;
						
			  if (y2 < menory)
					menory = y2;
			  
			  //Para saber quando parar de ler as coordenadas fornecidas, compara-se a coordenada em questão com a primeira, pois esta sempre será a última também. Caso a resposta seja positiva, não há triângulo para se calcular a área, então esta não é calculada e o contador é reduzido, acabando assim este laço.
              if (x2 == x0 && y2 == y0) {
                     contador--;}
              else {
                   
                   areat=((x0*y1)+(y0*x2)+(x1*y2)-(y1*x2)-(x0*y2)-(y0*x1))/2; //Caso o laço continue, é calculada a área do triângulo formado pelas três coordenadas obtidas, a primeira sendo sempre fixa. Isso é feito por calcular metade da linearização da determinante da matriz 3x3 formada por elas
              	   if (areat<0)
				       areat*=-1;
				   area+= areat; //Módulo da área do triângulo calculada, e esta é somada à dos outros triângulos.

                   y1=y2; //Para que se mantenha as últimas coordenadas obtidas, elas são copiadas às variáveis x1 e y1, pois os valores antigos já não são necessários.
                   x1=x2;}
		}
	}

	//Cálculo das bordas da maquete, a 0,5m de distância das maiores coordenadas, e de sua área (a maquete sempre é retangular).
	maiorx+= 0.5;
    maiory+= 0.5;
    menorx-= 0.5;
    menory-= 0.5;   

    area = (maiorx - menorx) * (maiory - menory) - area;  
    
    //Cálculo do volume e transformação de m³ em L.          
    vol = area * 0.5 *1000;   
    
    //Cálculo do número de sextas-feiras 13 nos anos entre o inicial (2016) e o final fornecido.
	scanf("%d/%d %d", &adia, &ames, &anofinal);
    
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
			for (; contador<1;contador++) {
				if (mesatual==13)
					ano--;}
			for (; contador>0;contador--){
				if (mesatual ==3)
						ano++;}
				
 
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
	
	//Comparação entre diferentes fornecedores de água para encontrar o preço ótimo.
	scanf("%d ", &fornecedores);

	for (; fornecedores>0; fornecedores--){
		scanf("%d $%lf", &capacidade, &preco);
		
		//Cada fornecedor tem capacidades diferentes em seus galões. Cálculo do número de galões (sempre inteiro).
		galoes = vol/capacidade;
		galoesexatos = vol/capacidade;
		if (galoesexatos-galoes > 0.0)
		galoes++;
		
		//Cálculo do preço total do fornecedor (para todos os dias e galões) e comparação com o preço ótimo.
		precototal = galoes* preco * dias; 
		if (precototal < precootimo)
			precootimo = precototal;
			}
	printf ("A manutencao da maquete custara $%.2lf aos cofres publicos.\n", precootimo);
	
	return 0; }
	
