#include <stdio.h>

void imprimir_natural(int inicial, int final){
	if(inicial == final)
		printf("%d", final);
	else {
		printf("%d ", inicial);
		imprimir_natural(inicial + 1, final);
	}
}

int main(){
	int inicial = 1, final;
	scanf("%d", &final);
	imprimir_natural(inicial, final);
	return 0;
}