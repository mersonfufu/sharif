#define _ALFABETO 27
#define _TAMANHO 201
#include <stdio.h>

/**
 * Conta a quantidade de cada uma das letras em um vetor.
 * @param *string o vetor com as letras a serem quantificadas.
 * @param *stringletras outro vetor que armazena a quantidade de cada letra do vetor.
 * @param caracteres quantidade de elementos nao-vazios do vetor.
 */
void contar_letras_vetor(char *string, int *stringletras, int caracteres){
	int i;
	for(i = 0; i < caracteres; i++)
		if(string[i] >= 'a' && string[i] <= 'z')
			stringletras[(int)string[i] - 'a']++;
}

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
 * Encontra o maior valor numerico de um vetor.
 * @param *string o vetor do qual se quer o maior valor.
 * @return o maior valor do vetor.
 */
int maior_valor_vetor(int *stringletras){
	int i, maior;
	maior = stringletras[0];
	for(i = 1; i < _ALFABETO; i++)
		if(stringletras[i] > maior)
			maior = stringletras[i];
	return maior;
}

/**
 * Preenche vetores com NULL em toda sua extensao.
 * @param *vetor o vetor que se quer preencher.
 */
void zerar_vetor_char(char *vetor){
	int i;
	for(i = 0; i < _TAMANHO; i++)
		vetor[i] = 0;
}

/**
 * Preenche vetores com 0 em toda sua extensao.
 * @param *vetor o vetor que se quer preencher.
 */
void zerar_vetor_int(int *vetor){
	int i;
	for(i = 0; i < _ALFABETO; i++)
		vetor[i] = 0;
}

int main(){
	int testes, t, caracteres, maior, i;
	char string[_TAMANHO];
	int stringletras[_ALFABETO];
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		zerar_vetor_char(string);
		zerar_vetor_int(stringletras);
		scanf("%[^\n]s", string);
		caracteres = contar_vetor(string);
		converter_maiusculas_vetor(string, caracteres);
		contar_letras_vetor(string, stringletras, caracteres);
		maior = maior_valor_vetor(stringletras);
		for(i = 0; i < _ALFABETO; i++)
			stringletras[i] == maior ? printf("%c", i + 'a') : 0;
		printf("\n");
	}
	return 0;
}