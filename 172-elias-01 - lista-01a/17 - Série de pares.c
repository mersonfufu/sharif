#include <stdio.h>

int main(){
	int x, y, cont = 0;
	scanf("%d %d", &x, &y);
	if(x % 2 != 0)
		printf("O PRIMEIRO NUMERO NAO E PAR\n");
	else
		while(cont < y){
			printf("%d ", x + 2 * cont);
			cont++;
		}
		printf("\n");
	return 0;
}