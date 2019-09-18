#include <stdio.h>

int main(){
	double n, i, total = 0;
	scanf("%lf", &n);
	total = n;
	for(i = 1; i <= 63; i++){
		total = total + 2 * n;
		total = total + n;
	}
	printf("%.0lf", total / 2);
	return 0;
}