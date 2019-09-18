#include <stdio.h>

int main(){
	int n, nc;
	long int f = 1;
	scanf("%d", &n);
	nc = n;
	for(n; n; n--)
		f *= n;
	printf("%d! = %li\n", nc, f);
	return 0;
}