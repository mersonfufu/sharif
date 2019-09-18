#include <stdio.h>

int main(){
	int n, cont = 1;
	float fah, cel;
	scanf("%d", &n);
	while(cont <= n){
		scanf("%f", &fah);
		cel = ((fah - 32) * 5) / 9;
		printf("%.2f FAHRENHEIT EQUIVALE A %.2f CELSIUS\n", fah, cel);
		cont++;
	}
	return 0;
}