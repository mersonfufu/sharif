#include <stdio.h>

int main(){
	int n, i, soma = 0;
	int vetor[5001];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &vetor[i]);
		soma += vetor[i];
	}
	printf("%d", soma);
	return 0;
}