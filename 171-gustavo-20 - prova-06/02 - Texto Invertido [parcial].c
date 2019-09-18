#include <stdio.h>

int main(){
	int i, j, cont, testes;
	char texto[10000], caractere;
	scanf("%i", &testes);
	scanf("\n");
	for(j = 0; j < testes; j++){
		cont = 0;
		for(i = 0; i < 10000; i++){
			scanf("%c", &caractere);
			if(caractere == '\n')
				break;
			else {
				texto[i] = caractere;
				cont++;
			}
		}
		for(i = cont - 1; i >= 0; i--)
			printf("%c", texto[i]);
		printf("\n");
	}
	return 0;
}