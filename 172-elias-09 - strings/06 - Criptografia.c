#include <stdio.h>

int main(){
	int i, j, cont, testes;
	char texto[1000], caractere;
	scanf("%i", &testes);
	scanf("\n");
	for(j = 0; j < testes; j++){
		cont = 0;
		for(i = 0; i < 1000; i++){
			scanf("%c", &caractere);
			if(caractere == '\n')
				break;
			else {
				texto[i] = caractere;
				cont++;
			}
		}
		//1a etapa
		for(i = 0; i < cont; i++){
			if((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z'))
				texto[i] += 3;
		}
		//2a etapa
		for(i = 0; i < cont / 2; i++){
			caractere = texto[i];
			texto[i] = texto[cont - i - 1];
			texto[cont - i - 1] = caractere;
		}
		//3a etapa
		for(i = 0; i < cont; i++){
			if(i < cont / 2)
				continue;
			else
				texto[i]--;
		}
		//impressao
		for(i = 0; i < cont; i++)
			printf("%c", texto[i]);
		printf("\n");
	}
}
