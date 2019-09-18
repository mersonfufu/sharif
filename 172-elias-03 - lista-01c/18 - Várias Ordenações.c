#include <stdio.h>

int main(){
	int i;
	float x, y, z, menor, meio, maior;
	scanf("%d %f %f %f", &i, &x, &y, &z);
	if(x <= y && x <= z && y <= z){
		menor = x;
		meio = y;
		maior = z;
	} else if(x <= z && x <= y && z <= y){
		menor = x;
		meio = z;
		maior = y;
	} else if(y <= x && y <= z && x <= z){
		menor = y;
		meio = x;
		maior = z;
	} else if(y <= z && y <= x && z <= x){
		menor = y;
		meio = z;
		maior = x;
	} else if(z <= x && z <= y && x <= y){
		menor = z;
		meio = x;
		maior = y;
	} else if(z <= y && z <= x && y <= x){
		menor = z;
		meio = y;
		maior = x;
	}
	if(i == 1)
		printf("%.2f %.2f %.2f\n", menor, meio, maior);
	else if(i == 2)
		printf("%.2f %.2f %.2f\n", maior, meio, menor);
	else if(i == 3)
		printf("%.2f %.2f %.2f\n", meio, maior, menor);
	return 0;
}