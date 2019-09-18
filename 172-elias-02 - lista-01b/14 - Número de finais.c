#include <stdio.h>

int main(){
	int ntimes, i, j, cont = 0;
	scanf("%d", &ntimes);
	if(ntimes < 2){
		printf("Campeonato invalido!");
		return 0;
	}
	for(i = 0; i < ntimes; i++){
		for(j = i + 1; j < ntimes; j++){
			cont++;
			printf("Final %d: Time %d X Time %d\n", cont, i + 1, j + 1);
		}
	}
	return 0;
}