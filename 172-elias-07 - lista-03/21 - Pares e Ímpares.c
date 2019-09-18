#include <stdio.h>

int main(){
	int n, i, j, imenor, aux;
	int vetor[100001];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &vetor[i]);
	for(i = 0; i < n; i++){
		imenor = i;
		for(j = i + 1; j < n; j++)
			if(vetor[j] < vetor[imenor])
				imenor = j;
		if(i != imenor){
			aux = vetor[i];
			vetor[i] = vetor[imenor];
			vetor[imenor] = aux;
		}
	}
	for(i = 0; i < n; i++)
		if(vetor[i] % 2 == 0)
			printf("%d\n", vetor[i]);
	for(i = n - 1; i >= 0; i--)
		if(vetor[i] % 2 == 1)
			printf("%d\n", vetor[i]);
	return 0;
}