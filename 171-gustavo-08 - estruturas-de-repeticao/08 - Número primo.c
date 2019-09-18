#include <stdio.h>

int main(){
	int n, divisores = 0, cont = 1;
	scanf("%d", &n);
	if(n < 0)
		printf("Numero invalido!");
	else if(n <= 1)
		printf("NAO PRIMO");
	else {
		for(cont; cont <= n; cont++)
			if(n % cont == 0)
				divisores++;
		if(divisores > 2)
			printf("NAO PRIMO");
		else
			printf("PRIMO");
	}
	return 0;
}