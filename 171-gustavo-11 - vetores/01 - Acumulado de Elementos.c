#include <stdio.h>

int main(){
	int tamanho, i, j, maior, cont;
	int vetor[10001];
	scanf("%d", &tamanho);
	do {
		for(i = 0; i < tamanho; i++){
			scanf("%d", &vetor[i]);
			if(i == 0)
				maior = vetor[i];
			else if(vetor[i] > maior)
				maior = vetor[i];
		}
		for(i = 0; i <= maior; i++){
			cont = 0;
			for(j = 0; j < tamanho; j++)
				if(vetor[j] <= i)
					cont++;
			printf("(%d) %d\n", i, cont);
		}
		scanf("%d", &tamanho);
	} while(tamanho != 0);
	return 0;
}