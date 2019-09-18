#include <stdio.h>

int main(){
	float n;
	int cont = 1, f = 1;
	scanf("%f", &n);
	while(cont <= 3){
		f *= 10;
		printf("%f \n", ((int)(n * f + 0.5)) / (f * 1.0));
		cont++;
	}
	return 0;
}