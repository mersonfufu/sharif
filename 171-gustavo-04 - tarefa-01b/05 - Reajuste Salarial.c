#include <stdio.h>

int main(){
	float miseria;
	scanf("%f", &miseria);
	if(miseria <= 300)
		miseria = miseria * 1.5;
	else
		miseria = miseria * 1.3;
	printf("SALARIO COM REAJUSTE = %.2f\n", miseria);
	return 0;
}