#define _VAR 'X'
#include <stdio.h>

struct Termo {
	float coeficiente;
	int expoente;
} Poliu[51], Polid[51], Polir[101];

/**
 * Funcao para ler termos de um polinomio.
 * @param quant quantidade de termos do polinomio.
 * @param vetor[] o vetor que recebe todos os termos de um polinomio.
 */
void ler_poli(int quant, struct Termo vetor[], int *maiorexp){
	int i;
	for(i = 0; i < quant; i++){
		scanf("%f %d", &vetor[i].coeficiente, &vetor[i].expoente);
		if(vetor[i].expoente > *maiorexp)
			*maiorexp = vetor[i].expoente;
	}
}

/**
 * Funcao para somar ou subtrair termos de dois polinomios.
 * @param Poliu[] o primeiro polinomio da operacao.
 * @param Polid[] o segundo polinomio da operacao.
 * @return quantidade de elementos do polinomio resultante.
 */
int operar_poli(
	struct Termo Poliu[], int quantu,
	struct Termo Polid[], int quantd,
	int maiorexp,
	char operacao
){
	int e, i, r = 0;
	float aux;
	for(e = maiorexp; e >= 0; e--){
		aux = 0;
		for(i = 0; i < quantu; i++)
			if(Poliu[i].expoente == e)
				aux += Poliu[i].coeficiente;
		//soma
		if(operacao == '+'){
			for(i = 0; i < quantd; i++)
				if(Polid[i].expoente == e)
					aux += Polid[i].coeficiente;
		} else {
			//subtracao
			if(operacao == '-')
				for(i = 0; i < quantd; i++)
					if(Polid[i].expoente == e)
						aux -= Polid[i].coeficiente;
		}
		//resultante
		if(aux != 0){
			Polir[r].coeficiente = aux;
			Polir[r].expoente = e;
			r++;
		}
	}
	return r;
}

int main(){
	char operacao;
	int testes, t, quantu, quantd, maiorexp, i;
	//entrada
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		maiorexp = 0;
		scanf("%c", &operacao);
		//1st
		scanf("%d", &quantu);
		ler_poli(quantu, Poliu, &maiorexp);
		//2nd
		scanf("%d", &quantd);
		ler_poli(quantd, Polid, &maiorexp);
		//saida
		quantu = operar_poli(Poliu, quantu, Polid, quantd, maiorexp, operacao);
		for(i = 0; i < quantu; i++){
			if(Polir[i].expoente >= 0 && Polir[i].coeficiente > 0)
				printf("+");
			printf("%.2f", Polir[i].coeficiente);
			if(Polir[i].expoente > 0)
				printf("%c^%d", _VAR, Polir[i].expoente);
		}
		printf("\n");
	}
	return 0;
}