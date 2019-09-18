#include <stdio.h>

int main(){
	int n, i;
	int vetor[5001];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &vetor[i]);
	for(i = n - 1; i >= 0; i--){
		printf("%d", vetor[i]);
		if(i != 0)
			printf(" ");
	}
	return 0;
}