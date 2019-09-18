#define _TAMANHO 10001
#include <stdio.h>

/**
 * Conta a quantidade de elementos nao-vazios de um vetor.
 * @param *vetor o vetor que se quer contar os elementos.
 * @return a quantidade de elementos nao-vazios.
 */
int contar_vetor(char *vetor){
	int i = 0, elementos = 0;
	while(vetor[i] != '\0'){
		elementos++;
		i++;
	}
	return elementos;
}

/**
 * Preenche vetores com NULL em toda sua extensao.
 * @param *vetor o vetor que se quer preencher.
 */
void zerar_vetor(char *vetor){
	int i;
	for(i = 0; i < _TAMANHO; i++)
		vetor[i] = 0;
}

/**
 * Conta a quantidade de vogais e consoantes de um string.
 * @param *vogais quantidade de vogais.
 * @param *consoantes quantidade de consoantes.
 * @param *string o texto que se quer analisar.
 */
void totalizar_vogais_consoantes(int *vogais, int *consoantes, char *string){
	int caracteres, i;
	caracteres = contar_vetor(string);
	*vogais = *consoantes = 0;
	for(i = 0; i < caracteres; i++){
		if(
			(string[i] >= 65 && string[i] <= 90) ||
			(string[i] >= 97 && string[i] <= 122)
		)
			(*consoantes)++;
		if(
			string[i] == 65 ||
			string[i] == 69 ||
			string[i] == 73 ||
			string[i] == 79 ||
			string[i] == 85 ||
			string[i] == 97 ||
			string[i] == 101 ||
			string[i] == 105 ||
			string[i] == 111 ||
			string[i] == 117
		)
			(*vogais)++;
	}
	(*consoantes) -= (*vogais);
}

int main(){
	int testes, t, i, vogais, consoantes;
	char string[_TAMANHO];
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		zerar_vetor(string);
		scanf("% [^\n]s", string);
		totalizar_vogais_consoantes(&vogais, &consoantes, string);
		printf("Letras = %d\nVogais = %d\nConsoantes = %d\n", vogais + consoantes, vogais, consoantes);
	}
	return 0;
}