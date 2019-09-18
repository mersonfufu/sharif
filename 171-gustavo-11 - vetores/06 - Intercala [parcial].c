#include <stdio.h>

int main(){
	int q1, q2, i, j, imenor, aux;
	int vetor1[50001], vetor2[50001], vetorr[50001];
	scanf("%d %d", &q1, &q2);
	for(i = 0; i < q1; i++){
		scanf("%d", &vetor1[i]);
		vetorr[i] = vetor1[i];
	}
	for(i = 0; i < q2; i++){
		scanf("%d", &vetor2[i]);
		vetorr[q1 + i] = vetor2[i];
	}
	for(i = 0; i < q1 + q2; i++){
		imenor = i;
		for(j = i + 1; j < q1 + q2; j++)
			if(vetorr[j] < vetorr[imenor])
				imenor = j;
		if(i != imenor){
			aux = vetorr[i];
			vetorr[i] = vetorr[imenor];
			vetorr[imenor] = aux;
		}
	}
	for(i = 0; i < q1 + q2; i++){
		if(i == 0 || vetorr[i] != vetorr[i - 1]){
			printf("%d", vetorr[i]);
			if(i < q1 + q2 - 1)
				printf("\n");
		}
	}
	return 0;
}