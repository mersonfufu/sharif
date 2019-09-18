#include <stdio.h>

int main(){
	int i, j, k, tapostas, acertos, sena = 0, quina = 0, quadra = 0;
	int apostas[500][500], resultado[1][6];
	scanf("%d", &tapostas);
	for(i = 0; i < tapostas; i++)
		for(j = 0; j < 6; j++)
			scanf("%d", &apostas[i][j]);
	for(j = 0; j < 6; j++)
		scanf("%d", &resultado[0][j]);
	for(i = 0; i < tapostas; i++){
		acertos = 0;
		for(j = 0; j < 6; j++)
			for(k = 0; k < 6; k++)
				if(resultado[0][k] == apostas[i][j])
					acertos++;
		if(acertos == 4)
			quadra++;
		else if(acertos == 5)
			quina++;
		else if(acertos == 6)
			sena++;
	}
	if(sena == 0)
		printf("Nao houve acertador para sena");
	else
		printf("Houve %d acertador(es) da sena", sena);
	printf("\n");
	if(quina == 0)
		printf("Nao houve acertador para quina");
	else
		printf("Houve %d acertador(es) da quina", quina);
	printf("\n");
	if(quadra == 0)
		printf("Nao houve acertador para quadra");
	else
		printf("Houve %d acertador(es) da quadra", quadra);
	printf("\n");
	return 0;
}