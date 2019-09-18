#include <stdio.h>

/**
 * Calcula o valor absoluto de um numero.
 * @param numero eh o numero do qual se deseja obter o valor absoluto.
 */
void converter_absoluto(double *numero){
	if(*numero < 0)
		*numero *= -1;
}

/**
 * Calcula a raiz quadrada aproximada de um numero pelo metodo babilonico.
 * @param numero eh o numero do qual se deseja obter o valor da raiz quadrada.
 * @param raiz eh o valor da raiz quadrada de numero.
 * @param erro eh especificado pelo usuario que serve como aproximacao da raiz.
 * @return a raiz quadrada do numero.
 */
void imprimir_raiz_babilonica(double numero, double *raiz, double erro){
	double diferenca;
	diferenca = numero - *raiz * (*raiz);
	while(diferenca > erro){
		*raiz = ((*raiz) + numero / (*raiz))/2;
		diferenca = numero - (*raiz) * (*raiz);
		converter_absoluto(&diferenca);
		printf("r: %.9lf, err: %.9lf\n", *raiz, diferenca);
	}
}

int main(){
	double numero, raiz = 1, erro, diferenca;
	scanf("%lf %lf", &numero, &erro);
	imprimir_raiz_babilonica(numero, &raiz, erro);
	return 0;
}