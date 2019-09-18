#include <stdio.h>

int main(){
	int t, n1, n2, c, d, u, cont = 1;
	scanf("%d", &t);
	while(cont <= t){
		scanf("%d %d", &n1, &n2);
		//primeiro
		c = n1 / 100;
		n1 = n1 % 100;
		d = n1 / 10;
		u = n1 % 10;
		n1 = u * 100 + d * 10 + c;
		//segundo
		c = n2 / 100;
		n2 = n2 % 100;
		d = n2 / 10;
		u = n2 % 10;
		n2 = u * 100 + d * 10 + c;
		//saida
		if(n1 > n2)
			printf("%d\n", n1);
		else
			printf("%d\n", n2);
		cont++;
	}
	return 0;
}