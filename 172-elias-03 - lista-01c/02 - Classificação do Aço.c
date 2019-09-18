#include <stdio.h>

int main(){
	int cc, dr, rt, grau = 0;
	scanf("%d %d %d", &cc, &dr, &rt);
	if(cc < 7)
		grau += 1;
	if(dr > 50)
		grau += 3;
	if(rt > 80000)
		grau += 5;
	if(grau == 9)
		grau = 10;
	else if(grau == 4)
		grau = 9;
	else if(grau == 1)
		grau = 8;
	else
		grau = 7;
	printf("ACO DE GRAU = %d\n", grau);
	return 0;
}