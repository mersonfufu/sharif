#include <stdio.h>
int calculanorelhas(int inicial, int final){
	if(final == 1)
		return 2;
	else if(final % 2 == 1)
		return 2 + calculanorelhas(1, final - 1);
	else
		return 3 + calculanorelhas(1, final - 1);
}

int main(){
	int testes, i, limite;
	scanf("%d", &testes);
	for(i = 0; i < testes; i++){
		scanf("%d", &limite);
		printf("%d\n", calculanorelhas(1, limite));
	}
	return 0;
}