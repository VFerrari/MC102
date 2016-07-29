#include <stdio.h>
#include <string.h>

//Codificação das datas de aniversário.
int main (int argc, char *argv[]) {
    int diaa, mesa, anoa, codigo, idade, anocod, diad, mesd, anod;
    char cod[4];
    
    scanf("%d/%d/%d", &diaa, &mesa, &anoa);
    scanf("%d/%d/%d", &diad, &mesd, &anod);
    
    //Soma dos algarismos do ano, com o mês e o dia de aniversário.
    anocod = anoa/10000 + ((anoa%10000)/1000) + ((anoa%1000)/100) + ((anoa%100)/10) + (anoa%10);
    codigo=diaa+mesa+anocod;

	//Caso a soma resultante tenha mais de um algarismo, eles são somados até que se tenha um só.
    while (codigo/10 != 0)
		codigo = (codigo/10) + (codigo%10);
   
   //Cálculo da idade da pessoa
    idade = anod-anoa;
    if (mesa-mesd > 0)
		idade--;
    else if (mesd == mesa && diaa-diad>0)
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
	

		sprintf(cod, "%d", codigo); //Transformação em vetor de char;
		printf("%s\n", cod);
    return 0;
}
