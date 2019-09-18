#include <stdio.h>

int main(){
	int n, i, j;
	int vetor[1001];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &vetor[i]);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == 0){
				printf("%d\n", vetor[i]);
				break;
			} else if(vetor[i] != vetor[i - 1]){
				printf("%d\n", vetor[i]);
				break;
			}
		}
	}
	return 0;
}