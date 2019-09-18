#include <stdio.h>

/**
 * Forma o maior numero possivel removendo uma quantidade definida de digitos de um numero.
 * @param inicial quantidade de digitos do numero.
 * @param final quantidade de digitos do numero apos a remocao.
 * @param vetor[] vetor com os digitos do numero do qual se quer remover digitos.
 */
void remover_digitos(int inicial, int final, long int vetor[]){
	int i, imenor;
	while(inicial > final){
		imenor = 0;
		for(i = 1; i < inicial; i++)
			vetor[i] < vetor[imenor] ? imenor = i : 0;
		for(i = imenor; i < inicial; i++)
			vetor[i] = vetor[i + 1];
		inicial--;
	}
}

/**
 * Separa um numero digito a digito.
 * @param inicial quantidade inicial de digitos de um numero.
 * @param vetor[] vetor que sera usado para guardar os digitos do numero.
 */
void separar_numero(int inicial, long int vetor[]){
	int i = 0;
	while(vetor[inicial] >= 10){
		vetor[inicial - 1 - i] = vetor[inicial] % 10;
		vetor[inicial] /= 10;
		i++;
	}
	vetor[0] = vetor[inicial];
	vetor[inicial] = 0;
}

int main(){
	int i, inicial = 1, final = 1;
	long int vetor[20] = {0};
	while(1){
		scanf("%d %d", &inicial, &final);
		if(inicial == 0 || final == 0)
			break;
		for(i = 0; i < inicial; i++)
			vetor[i] = 0;
		scanf("%ld", &vetor[inicial]);
		separar_numero(inicial, vetor);
		remover_digitos(inicial, final, vetor);
		for(i = 0; i < final; i++)
			printf("%ld", vetor[i]);
		printf("\n");
	}
	return 0;
}