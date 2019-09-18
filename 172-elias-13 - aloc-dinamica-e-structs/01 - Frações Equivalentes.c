#define FOR(var, inicio, fim) for(var = inicio; var < fim; var++)
#include <stdio.h>

typedef struct Fracao {
	float n, d;
} stFracao;

int main(){
	int casos, c, fracoes, f, i, vazio;
	stFracao aux;
	stFracao Fracoes[51];
	//entrada
	scanf("%d", &casos);
	FOR(c, 0, casos){
		vazio = 0;
		printf("Caso de teste %d\n", c + 1);
		scanf("%d", &fracoes);
		FOR(f, 0, fracoes){
			scanf("%f/%f", &Fracoes[f].n, &Fracoes[f].d);
		}
		//saida
		FOR(f, 0, fracoes){
			aux = Fracoes[f];
			FOR(i, f + 1, fracoes){
				if(aux.n / aux.d == Fracoes[i].n / Fracoes[i].d){
					printf("%.0f/%.0f equivalente a %.0f/%.0f\n", aux.n, aux.d, Fracoes[i].n, Fracoes[i].d);
					vazio++;
				}
			}
		}
		vazio == 0 ? printf("Nao ha fracoes equivalentes na sequencia\n") : 0;
	};
	return 0;
}