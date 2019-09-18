#include <stdio.h>

int main(){
	int n, divisores = 1, cont = 2;
	scanf("%d", &n);
	if(n < 0){
		printf("Numero invalido!");
		return 0;
	}
	if(n == 0)
		printf("NAO PRIMO");
	while(cont < n){
		if(n % cont == 0){
			divisores++;
			printf("NAO PRIMO");
			break;
		}
		cont++;
	}
	if(n != 0 && divisores == 1)
		printf("PRIMO");
	return 0;
}