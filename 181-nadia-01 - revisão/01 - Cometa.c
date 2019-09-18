#include <stdio.h>

int main(){
	int ano;
	scanf("%d", &ano);
	printf("%d", ((ano / 76) * 76) + 10 > ano ? ((ano / 76) * 76) + 10 : ((ano / 76 + 1) * 76) + 10);
	return 0;
}