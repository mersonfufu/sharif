#include <stdio.h>

int main(){
	int i, j, testes, t, acertos, sena = 0, quina = 0, quadra = 0;
	int sorteadas[7], aposta[7];
	for(i = 0; i < 6; i++)
		scanf("%d", &sorteadas[i]);
	scanf("%d", &testes);
	for(t = 1; t <= testes; t++){
		for(i = 0; i < 6; i++)
			scanf("%d", &aposta[i]);
		acertos = 0;
		for(i = 0; i < 6; i++){
			for(j = 0; j < 6; j++){
				if(aposta[i] == sorteadas[j]){
					acertos++;
					break;
				}
			}
		}
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