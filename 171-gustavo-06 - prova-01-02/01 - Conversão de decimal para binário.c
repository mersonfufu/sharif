#include <stdio.h>

int main(){
	int num, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	scanf("%d", &num);
	if(num < 0 || num > 255){
		printf("Numero invalido!");
		return 0;
	} else {
		if(num != 0){
			h = num % 2;
			num = num / 2;
		}
		if(num != 0){
			g = num % 2;
			num = num / 2;
		}
		if(num != 0){
			f = num % 2;
			num = num / 2;
		}
		if(num != 0){
			e = num % 2;
			num = num / 2;
		}
		if(num != 0){
			d = num % 2;
			num = num / 2;
		}
		if(num != 0){
			c = num % 2;
			num = num / 2;
		}
		if(num != 0){
			b = num % 2;
			num = num / 2;
		}
		if(num != 0){
			a = num % 2;
			num = num / 2;
		}
		printf("%d%d%d%d%d%d%d%d", a, b, c, d, e, f, g, h);
	}
	return 0;
}