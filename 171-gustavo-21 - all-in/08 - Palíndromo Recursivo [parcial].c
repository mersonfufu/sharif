#include <stdio.h>

int main(){
	int testes, i, j, letras;
	char palavra[2000];
	scanf("%d", &testes);
	for(i = 0; i < testes; i++){
		scanf("%d", &letras);
		for(j = 0; j < letras; j++){
			scanf("\n");
			scanf("%c", &palavra[i]);
		}
		for(j = 0; j < letras; j++)
			printf("%c", palavra[i]);
	}
	return 0;
}