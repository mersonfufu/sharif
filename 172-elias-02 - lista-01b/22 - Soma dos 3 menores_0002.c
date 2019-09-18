#include <stdio.h>

int main(){
	int x, y, z, w, menor;
	scanf("%d %d %d %d", &x, &y, &z, &w);
	if(x < 0 || y < 0 || z < 0 || w < 0)
		return 0;
	menor = x + y + z;
	if(x + y + w < menor)
		menor = x + y + w;
	else if(x + z + w < menor)
		menor = x + z + w;
	else if(y + z + w < menor)
		menor = y + z + w;
	printf("%d", menor);
	return 0;
}