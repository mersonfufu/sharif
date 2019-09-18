#include <stdio.h>

void trocar(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void selection(int *equipes, int *pontos, int num){
	int fixa, i;
	for(fixa = 0; fixa < num - 1; fixa++){
		for(i = fixa + 1; i < num; i++){
			if(pontos[fixa] < pontos[i]){
				trocar(&pontos[fixa], &pontos[i]);
				trocar(&equipes[fixa], &equipes[i]);
			} else {
				if(pontos[fixa] == pontos[i] && equipes[fixa] < equipes[i]){
					trocar(&pontos[fixa], &pontos[i]);
					trocar(&equipes[fixa], &equipes[i]);
				}
			}
		}
	}
}

int main(){
	int num, i, j;
	int equipes[1000], pontos[1000];
	scanf("%d", &num);
	if(num < 6 || num > 100){
		printf("CAMPEONATO INVALIDO!\n");
		return 0;
	} else {
		for(i = 0; i < num; i++)
			scanf("%d", &equipes[i]);
		for(i = 0; i < num; i++)
			scanf("%d", &pontos[i]);
		selection(equipes, pontos, num);
		printf("%d\n", num);
		for(j = 1; j <= num; j++)
			printf("%d %d %d\n", j, equipes[j], pontos[j]);
	}
	return 0;
}