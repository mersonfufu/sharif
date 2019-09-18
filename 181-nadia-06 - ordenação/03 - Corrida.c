#include <stdio.h>
#include <stdlib.h>

typedef struct competidor {
	int nome, tempo;
} stCompetidor;

int main(){
	int i, ncompetidores, nvoltas, winner;
	stCompetidor *competidorptr = NULL;
	
	scanf("%d %d", &ncompetidores, &nvoltas);
	if(!(competidorptr = (stCompetidor *) calloc(ncompetidores, sizeof(stCompetidor)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	for(i = 0; i < ncompetidores; i++)
		competidorptr[i].nome = i + 1;
	
	for(i = 0; i < ncompetidores; i++){
		int j, volta, soma = 0;
		for(j = 0; j < nvoltas; j++){
			scanf("%d", &volta);
			soma += volta;
		}
		competidorptr[i].tempo = soma;
	}
	
	winner = 0;
	for(i = 1; i < ncompetidores; i++)
		if(competidorptr[i].tempo < competidorptr[winner].tempo)
			winner = i;
	
	printf("%d", competidorptr[winner].nome);
	
	free(competidorptr);
	competidorptr = NULL;
	return 0;
}
