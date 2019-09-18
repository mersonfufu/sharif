#define _TAMANHO 10001
#include <stdio.h>

/**
 * Conta a quantidade de avancos para duas letras se tornarem iguais.
 * @param primeiro o codigo ASCII da primeira letra da comparacao.
 * @param segundo o codigo ASCII da segunda letra da comparacao.
 * @return a quantidade de avancos da operacao de igualar as letras.
 */
int avancar_letras(int primeiro, int segundo){
	int avancos;
	if(segundo > primeiro)
		avancos = segundo - primeiro;
	else if(segundo < primeiro)
		avancos = segundo - primeiro + 26;
	else
		avancos = 0;
	return avancos;
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
 * Preenche vetores com NULL em toda sua extensao.
 * @param *vetor o vetor que se quer preencher.
 */
void zerar_vetor(char *vetor){
	int i;
	for(i = 0; i < _TAMANHO; i++)
		vetor[i] = 0;
}

int main(){
	int testes, t, caracteres, i, total;
	char stringa[_TAMANHO], stringb[_TAMANHO];
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		zerar_vetor(stringa);
		zerar_vetor(stringb);
		scanf("%s %s", stringa, stringb);
		caracteres = contar_vetor(stringa);
		total = 0;
		for(i = 0; i < caracteres; i++)
			total += avancar_letras((int)stringa[i], (int)stringb[i]);
		printf("%d\n", total);
	}
	return 0;
}