#include <stdio.h>

int main(){
	int mat = 1, h;
	float vh, sal;
	while(mat != 0){
		scanf("%d %d %f", &mat, &h, &vh);
		sal = h * vh;
		if(mat != 0)
			printf("%d %.2f\n", mat, sal);
	}
	return 0;
}