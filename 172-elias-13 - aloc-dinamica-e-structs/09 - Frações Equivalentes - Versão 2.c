#define alocar_vetor(quantidade, tamanho) calloc(quantidade, tamanho)
#define realocar_vetor(vetor, novo_tamanho) realloc(vetor, novo_tamanho)
#define testar_alocacao(vetor) if(vetor == NULL){printf("Erro de alocacao. O programa sera finalizado\n");return 1;}
#include <stdio.h>
#include <stdlib.h>

typedef struct Fracao {
	float numerador, denominador;
} stFracao;

int main(){
	char teste;
	int caso, tcasos, fracao, flag, tfracoes, i;
	stFracao auxiliar;
	stFracao *fracoesptr;
	//entrada
	scanf("%d", &tcasos);
	for(caso = 0; caso < tcasos; caso++){
		flag = 1;
		tfracoes = 0;
		printf("Caso de teste %d\n", caso + 1);
		if(caso == 0)
			fracoesptr = (stFracao *) alocar_vetor(1, sizeof(stFracao));
		else
			fracoesptr = (stFracao *) realocar_vetor(fracoesptr, sizeof(stFracao));
		testar_alocacao(fracoesptr);
		for(fracao = 0;; fracao++){
			if(flag == 1){
				scanf("%f/%f", &fracoesptr[fracao].numerador, &fracoesptr[fracao].denominador);
				tfracoes++;
				flag = -flag;
			} else if(flag == -1){
				scanf("%c", &teste);
				if(teste == '\n' || teste == EOF)
					break;
				else {
					flag = -flag;
					fracoesptr = (stFracao *) realocar_vetor(fracoesptr, (tfracoes + 1) * sizeof(stFracao));
					testar_alocacao(fracoesptr);
					fracao--;
				}
			}
		}
		teste = '0';
		//saida
		for(fracao = 0; fracao < tfracoes; fracao++){
			auxiliar = fracoesptr[fracao];
			for(i = fracao + 1; i < tfracoes; i++){
				if(auxiliar.numerador / auxiliar.denominador == fracoesptr[i].numerador / fracoesptr[i].denominador){
					printf("%.0f/%.0f equivalente a %.0f/%.0f\n",
						auxiliar.numerador, auxiliar.denominador, fracoesptr[i].numerador, fracoesptr[i].denominador);
					teste = '1';
				}
			}
		}
		teste == '0' ? printf("Nao ha fracoes equivalentes na sequencia\n") : 0;
	};
	//free
	free(fracoesptr);
	fracoesptr = NULL;
	return 0;
}