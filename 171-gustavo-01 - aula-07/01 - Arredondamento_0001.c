#include <stdio.h>

int main(){
	int i;
	float f1, f2;
	scanf("%f", &f1);
	//uma
	f2 = f1 * 10 + 0.5;
	i = f2;
	f2 = i;
	f2 /= 10;
	printf("%f \n", f2);
	//duas
	f2 = f1 * 100 + 0.5;
	i = f2;
	f2 = i;
	f2 /= 100;
	printf("%f \n", f2);
	//tres
	f2 = f1 * 1000 + 0.5;
	i = f2;
	f2 = i;
	f2 /= 1000;
	printf("%f \n", f2);
	return 0;
}