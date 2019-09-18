#include <stdio.h>

int main(){
	int numero, i, j, cont = 1;
	scanf("%d", &numero);
	for(cont; cont <= numero; cont++){
		printf("%d*%d*%d = ", cont, cont, cont);
		for(j = cont * (cont - 1) + 1; j <= cont * (cont + 1) - 1; j = j + 2){
			printf("%d", j);
			if(j != cont * (cont + 1) - 1)
				printf("+");
			else
				printf("\n");
		}
	}
	return 0;
}