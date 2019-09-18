#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);
	if(num == 1)
		printf("Y=0\n");
	else if(num < 1)
		printf("Y=%d\n", num);
	else
		printf("Y=%d\n", num * num);
	return 0;
}