#include <stdio.h>
int calcula_potencia(int b, int e){
	if(e == 0)
		return 1;
	else
		return b * calcula_potencia(b, e - 1);
}

int main(){
	int testes, i, base, expoente;
	scanf("%d", &testes);
	for(i = 0; i < testes; i++){
		scanf("%d %d", &base, &expoente);
		printf("%d\n", calcula_potencia(base, expoente));
	}
	return 0;
}