#define _TAMANHO 5001
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
 * Remove caracteres desnecessarios de um vetor.
 * @param *vetor o vetor com os caracteres que se quer remover.
 * @param caracteres quantidade de elementos nao-vazios do vetor.
 */
void remover_etc_vetor(char *vetor, int caracteres){
	//etc=espacos e nao-letras
	int i;
	for(i = 0; i < caracteres; i++)
		if(vetor[i] != '\0' && (vetor[i] == ' ' || vetor[i] < 'a' || vetor[i] > 'z'))
			vetor[i] = '-';
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
	int i, j, k, caracteres, aliteracoes;
	char string[_TAMANHO];
	zerar_vetor(string);
	while(scanf("%[^\n]%*c", string) != EOF){
		caracteres = contar_vetor(string);
		converter_maiusculas_vetor(string, caracteres);
		for(i = 0; i + 1 < caracteres; i++)
			if(string[i] != ' ' && string[i + 1] != ' ')
				string[i + 1] = '-'; //remover caracteres secundarios
		remover_etc_vetor(string, caracteres);
		i = aliteracoes = 0;
		while(string[i] != '\0'){
			while(string[i] == '-')
				i++;//ignorar tracos
			j = i + 1;
			while(string[j] != '\0'){
				while(string[j] == '-')
					j++;//ignorar tracos
				if(string[j] == string[i]){
					aliteracoes++;
					k = j + 1;
					while(string[k] != '\0'){
						while(string[k] == '-')
							k++;//ignorar tracos
						if(string[k] == string[j])
							string[k] = '-';
						else
							break;
						k++;
					}
					string[j] = '-';
				} else {
					string[i] = '-';
					break;
				}
				j++;
			}
			i++;
		}
		printf("%d\n", aliteracoes);
		for(i = 0; i <= caracteres; i++)
			string[i] = 0;
	}
	return 0;
}