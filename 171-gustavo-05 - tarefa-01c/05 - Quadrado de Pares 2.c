#include <stdio.h>

int main(){
	int n, cont = 1;
	scanf("%d", &n);
	while(cont <= n){
		if(cont % 2 == 0)
			printf("%d^2 = %d\n", cont, cont * cont);
		cont++;
	}
	return 0;
}