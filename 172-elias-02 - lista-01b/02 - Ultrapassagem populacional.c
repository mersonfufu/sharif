#include <stdio.h>

int main(){
	int a, b, anus;
	scanf("%d %d", &a, &b);
	while(a < b){
		a = a * 1.03;
		b = b * 1.015;
		anus++;
	}
	printf("ANOS=%d\n", anus);
	return 0;
}