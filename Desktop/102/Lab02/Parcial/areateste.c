#include <stdio.h>

int main(int argc, char *argv[])
{
    int ilhas, i=1;
    double x0, y0, x1, y1, x2, y2, area=0, maiorx, maiory, menorx, menory, vol;
    
    scanf("%d ", &ilhas);
    for (; ilhas>0; ilhas--) {
        scanf(" (%lf , %lf) (%lf , %lf) ", &x0, &y0, &x1, &y1);

        maiorx = x1;
        maiory = y1;
        menory = y1;
        menorx = x1;
        		    printf("35 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);
	
				
        while (i>0) {
              scanf(" (%lf , %lf) ", &x2, &y2);
              if (x2 > maiorx)
					maiorx = x2;
					    printf("48 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);

              if (y2 > maiory)
					maiory = y2;
					    printf("51 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);

			  if (x2 < menorx)
					menorx = x2;
						printf("52 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);
						
			  if (y2 < menory)
					menory = y2;
					printf("53 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);
					
		
                   
              if (x2 == x0 && y2 == y0) {
                  printf(" 54 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);
                     i--;}
              else {
                   
                   area+=((x0*y1)+(y0*x2)+(x1*y2)-(y1*x2)-(x0*y2)-(y0*x1))/2; 
                       printf(" 55 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);
               

                   y1=y2;
                   x1=x2;
}
}
}
	if (area<0)
	area*=-1;
	                       printf(" 65 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);

	
	maiorx+= 0.5;
    maiory+= 0.5;
    menorx-= 0.5;
    menory-= 0.5;
   
                          printf(" 75 %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory);

    area = (maiorx - menorx) * (maiory - menory) - area;            
    vol = area * 0.5 *1000;   
    printf("%lf %lf %lf %lf %lf %lf\n", area, maiorx, maiory, menorx, menory, vol);
    
  return 0;
}
