#define _TAMANHO 6
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
 * Funcao que identifica todas as possibilidades de escrita por extenso em ingles de 1,2 e 3 com a quantidade certa de caracteres.
 * @param *string a palavra que se quer analisar.
 * @return o numero que corresponde a palavra digitada.
 */
int identifica_palavra(char *string){
	int caracteres;
	caracteres = contar_vetor(string);
	if(caracteres == 3){
		if(
			//one
			((string[0] >= 'a' && string[0] <= 'z') && string[1] == 'n' && string[2] == 'e') ||
			(string[0] == 'o' && (string[1] >= 'a' && string[1] <= 'z') && string[2] == 'e') ||
			(string[0] == 'o' && string[1] == 'n' && (string[2] >= 'a' && string[2] <= 'z'))
		)
			return 1;
		else if(
			//two
			((string[0] >= 'a' && string[0] <= 'z') && string[1] == 'w' && string[2] == 'o') ||
			(string[0] == 't' && (string[1] >= 'a' && string[1] <= 'z') && string[2] == 'o') ||
			(string[0] == 't' && string[1] == 'w' && (string[2] >= 'a' && string[2] <= 'z'))
		)
			return 2;
	} else if(caracteres == 5){
		if(
			//three
			((string[0] >= 'a' && string[0] <= 'z') && string[1] == 'h' && string[2] == 'r' && string[3] == 'e' && string[4] == 'e') ||
			(string[0] == 't' && (string[1] >= 'a' && string[1] <= 'z') && string[2] == 'r' && string[3] == 'e' && string[4] == 'e') ||
			(string[0] == 't' && string[1] == 'h' && (string[2] >= 'a' && string[2] <= 'z') && string[3] == 'e' && string[4] == 'e') ||
			(string[0] == 't' && string[1] == 'h' && string[2] == 'r' && (string[3] >= 'a' && string[3] <= 'z') && string[4] == 'e') ||
			(string[0] == 't' && string[1] == 'h' && string[2] == 'r' && string[3] == 'e' && (string[4] >= 'a' && string[4] <= 'z'))
		)
			return 3;
	}
}

int main(){
	int testes, t, i;
	char string[_TAMANHO];
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		zerar_vetor(string);
		scanf("%s", string);
		printf("%d\n", identifica_palavra(string));
	}
	return 0;
}