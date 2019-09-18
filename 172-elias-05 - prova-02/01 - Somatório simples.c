#include <stdio.h>

int main(){
	int num, i;
	double soma = 0;
	scanf("%d", &num);
	if(num < 3){
		printf("Numero invalido!");
		return 0;
	}
	for(i = 1; i <= num; i++)
		soma = soma + (double)num / (i * i);
	printf("%.5f", soma);
	return 0;
}