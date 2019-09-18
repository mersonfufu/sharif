#include <stdio.h>
int main(){
	int testes, elementos, escolhas, i;
	int vetor[20];
	scanf("%d", &testes);
	while(testes--){
		scanf("%d %d", &elementos, &escolhas);
		i = 0;
		while(elementos--){
			scanf("%d", &vetor[i]);
			i++;
		}
	}
	return 0;
}