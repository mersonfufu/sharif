#include <stdio.h>

int main(){
	int numero, i, inicial;
	int vetor[32] = {0};
	while(scanf("%d", &numero)){
		for(i = 31; i >= 0; i--){
			vetor[i] = numero % 2;
			numero /= 2;
			if(numero == 0)
				break;
		}
		inicial = 31;
		for(i = 0; i <= 31; i++)
			if(vetor[i] == 1){
				inicial = i;
				break;
			}
		for(i = inicial; i < 32; i++)
			printf("%d", vetor[i]);
		printf("\n");
	}
	return 0;
}