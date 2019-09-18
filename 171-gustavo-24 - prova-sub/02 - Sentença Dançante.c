#define _TAMANHO 51
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
 * Converte letras maiusculas em letras minusculas.
 * @param *vetor o vetor com os caracteres que se quer converter.
 * @param caracteres quantidade de elementos nao-vazios do vetor.
 */
void converter_maiusculas_vetor(char *vetor, int caracteres){
	int i;
	for(i = 0; i < caracteres; i++)
		if(vetor[i] >= 'A' && vetor[i] <= 'Z')
			vetor[i] -= ('A' - 'a');
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

int main(){
	int caracteres, i, flag;
	char string[_TAMANHO];
	zerar_vetor(string);
	while(scanf("%[^\n]%*c", string) != EOF){
		caracteres = contar_vetor(string);
		converter_maiusculas_vetor(string, caracteres);
		i = 0;
		flag = 1;
		while(string[i] != '\0'){
			while(string[i] == ' ')
				i++;
			if(string[i] == '\0')
				break;
			if(flag == 1){
				string[i] -= ('a' - 'A');
				flag *= -1;
			} else
				flag *= -1;
			i++;
		}
		printf("%s\n", string);
	}
	return 0;
}