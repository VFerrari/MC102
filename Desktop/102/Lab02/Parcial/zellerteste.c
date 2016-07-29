
#include <stdio.h>

int main(int argc, char **argv)
{int aux, mesatual;
for (mesatual=3; mesatual<=14; mesatual++){
aux = 13 + (2*mesatual) + (3*(mesatual+1)/5) + 2016 + (2016/4) - (2016/100) + (2016/400) + 2;
aux%=7;
printf ("%d", aux);
}
	return 0;
}

