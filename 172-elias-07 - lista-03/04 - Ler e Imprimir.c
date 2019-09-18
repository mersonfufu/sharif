#include <stdio.h>

int main(){
	int n, i;
	int vetor[5001];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &vetor[i]);
	for(i = 0; i < n; i++)
		printf("%d ", vetor[i]);
	return 0;
}