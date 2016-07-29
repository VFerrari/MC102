#include <stdio.h>

int main(int argc, char *argv[])
{
    int ilhas, contador, d=1, dia;
    double x0, y0, x1, y1, x2, y2, area=0, maiorx, maiory, menorx, menory, vol, areat=0;
    
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
    scanf("%d", &dia);
    printf("%lf %lf %lf %lf %lf %lf %d\n", area, maiorx, maiory, menorx, menory, vol, dia);
    
    
    
  return 0;
}
