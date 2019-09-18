#include <stdio.h>

int main(){
	int num, inicial, div = 2, produto = 1;
	do {
		scanf("%d", &num);
		if(num <= 1)
			printf("Fatoracao nao e possivel para o numero %d!\n", num);
	} while(num <= 1);
	printf("%d = ", num);
	inicial = num;
	while(num != 1){
		if(num % div == 0){
			printf("%d", div);
			if(div * produto != inicial)
				printf(" x ");
			produto = produto * div;
			num = num / div;
			if(num % div != 0)
				div++;
		} else
			div++;
	}
	return 0;
}