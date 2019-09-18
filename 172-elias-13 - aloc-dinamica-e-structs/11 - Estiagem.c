#define alocar_vetor(quantidade, tamanho) calloc(quantidade, tamanho)
#define realocar_vetor(vetor, novo_tamanho) realloc(vetor, novo_tamanho)
#define testar_alocacao(vetor) if(vetor == NULL){printf("Erro de alocacao. O programa sera finalizado\n");return 1;}
#include <stdio.h>
#include <stdlib.h>

typedef struct Casa {
	int npessoas, consumo;
} stCasa;

int main(){
	int tcasas, casa, cidade = 1, tmoradores, tconsumo, i, aux;
	stCasa *casasptr = NULL;
	//entrada
	scanf("%d", &tcasas);
	casasptr = (stCasa *) alocar_vetor(tcasas, sizeof(stCasa));
	testar_alocacao(casasptr);
	while(tcasas > 0){
		tmoradores = tconsumo = 0;
		for(casa = 0; casa < tcasas; casa++){
			scanf("%d %d", &casasptr[casa].npessoas, &casasptr[casa].consumo);
			tconsumo += casasptr[casa].consumo;
			tmoradores += casasptr[casa].npessoas;
			casasptr[casa].consumo = (int)(casasptr[casa].consumo / casasptr[casa].npessoas);
		}
		//ordenacao
		for(casa = 0; casa < tcasas; casa++)
			for(i = casa + 1; i < tcasas; i++){
				if(casasptr[casa].consumo != 0 && casasptr[casa].consumo == casasptr[i].consumo){
					casasptr[casa].npessoas += casasptr[i].npessoas;
					casasptr[i].npessoas = casasptr[i].consumo = 0;
					casa = 0;
				} else if(casasptr[casa].consumo > casasptr[casa + 1].consumo){
					aux = casasptr[casa].consumo;
					casasptr[casa].consumo = casasptr[casa + 1].consumo;
					casasptr[casa + 1].consumo = aux;
					aux = casasptr[casa].npessoas;
					casasptr[casa].npessoas = casasptr[casa + 1].npessoas;
					casasptr[casa + 1].npessoas = aux;
					casa = 0;
				}
			}
		//saida
		if(cidade != 1)
			printf("\n");
		printf("Cidade# %d:\n", cidade);
		cidade++;
		for(casa = 0; casa < tcasas; casa++)
			if(casasptr[casa].npessoas != 0 && casasptr[casa].consumo != 0){
				printf("%d-%d", casasptr[casa].npessoas, casasptr[casa].consumo);
				casa != tcasas - 1 ? printf(" ") : 0;
			}
		printf("\nConsumo medio: %.2f m3.\n", (int)(100.0 * tconsumo / tmoradores) / 100.0);
		scanf("%d", &tcasas);
		casasptr = (stCasa *) realocar_vetor(casasptr, tcasas * sizeof(stCasa));
		testar_alocacao(casasptr);
	}
	free(casasptr);
	casasptr = NULL;
	return 0;
}