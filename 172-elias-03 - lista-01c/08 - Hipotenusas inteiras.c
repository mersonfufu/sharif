#include <stdio.h>

int main(){
	int h, i, j, k, cont;
	scanf("%d", &h);
	for(cont = 1; cont <= h; cont++){
		for(i = 1; i <= cont; i++){
			for(j = 1; j <= cont; j++){
				if(i * i + j * j == cont * cont){
					if(i >= j)
						break;
					printf("hipotenusa = %d, catetos %d e %d\n", cont, i, j);
					break;
				}
			}
		}
	}
	return 0;
}