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
	if(n % 2 == 1)
		printf("%.2f", vetor[n / 2] / 1.0);
	else
		printf("%.2f", (vetor[n / 2] + vetor[(n / 2) - 1]) / 2.0);
	return 0;
}