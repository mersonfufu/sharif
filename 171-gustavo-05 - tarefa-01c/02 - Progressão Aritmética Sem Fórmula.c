#include <stdio.h>

int main(){
	int i, r, n, cont = 0, soma = 0;
	scanf("%d %d %d", &i, &r, &n);
	while(cont < n){
		soma = soma + (i + cont * r);
		cont++;
	}
	printf("%d\n", soma);
	return 0;
}