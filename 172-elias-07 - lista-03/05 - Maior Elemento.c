#include <stdio.h>

int main(){
	int tamanho, i, mm, pos;
	int vetor[10001];
	scanf("%d", &tamanho);
	do {
		for(i = 0; i < tamanho; i++){
			scanf("%d", &vetor[i]);
			if(i == 0){
				mm = vetor[i];
				pos = i;
			} else if(vetor[i] > mm){
				mm = vetor[i];
				pos = i;
			}
		}
		printf("%d %d\n", pos, mm);
		scanf("%d", &tamanho);
	} while(tamanho != 0);
	return 0;
}