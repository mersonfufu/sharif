#include <stdio.h>

int main(){
	int c, d, u, num;
	scanf("%d %d %d", &c, &d, &u);
	if(c < 0 || c > 9 || d < 0 || d > 9 || u < 0 || u > 9){
		printf("DIGITO INVALIDO");
		return 0;
	}
	num = c * 100 + d * 10 + u;
	printf("%d, %d", num, num * num);
	return 0;
}