#include <stdio.h>

int main(){
	int i, j, cont, testes;
	char texto[1000], caractere;
	scanf("%d", &testes);
	scanf("\n");
	for(i = 0; i < 1000; i++)
		texto[i] = 0;
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
		//primeiro
		for(i = 0; i < cont; i++)
			if(
				(texto[i] >= 'A' && texto[i] <= 'Z') ||
				(texto[i] >= 'a' && texto[i] <= 'z') ||
				(texto[i] >= '0' && texto[i] <= '9')
			)
				texto[i] += 3; //segundo
		for(i = 0; i < cont; i++){
			//if(texto[i+1]=='\0') printf("f");if(i%2==0 && i<cont-1){
			caractere = texto[i];
			texto[i] = texto[i + 1];
			texto[i + 1] = caractere;
		}
	}
	//terceiro
	for(i = 0; i < cont; i++){
		if(texto[i] == ' ')
			texto[i] = '+';
		else if(texto[i] == '+')
			texto[i] = ' ';
	}
	//imprimir
	for(i = 0; i < cont; i++)
		printf("%c", texto[i]);
	printf("\n");
}
}