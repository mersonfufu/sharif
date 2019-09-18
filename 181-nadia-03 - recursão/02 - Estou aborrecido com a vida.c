#include <stdio.h>

unsigned long int fatorial(int n){
	int f = 1;
	for(n; n; n--) f *= n;
	return f;
}

int mdc(int a, int b){
	if(b == 0) return a;
	else if(a % b == 0) return b;
	else mdc(b, a % b);
}

int main(){
	unsigned long int um, dois;
	scanf("%lu %lu", &um, &dois);
	if(um > dois) printf("%lu", mdc(fatorial(um), fatorial(dois)));
	else printf("%lu", mdc(fatorial(dois), fatorial(um)));
	return 0;
}
