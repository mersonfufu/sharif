#include <stdio.h>

int quase_fibonacci(int numero){
	if(numero == 1) return 1;
	if(numero == 2) return 3;
	return quase_fibonacci(numero - 1) - quase_fibonacci(numero - 2);
}

int main(){
	int testes, numero, funcao;
	scanf("%d", &testes);
	while(testes--){
		scanf("%d", &numero);
		funcao = 0;
		while(numero){
			funcao += quase_fibonacci(numero);
			numero--;
		}
		printf("%d\n", funcao);
	}
	return 0;
}
