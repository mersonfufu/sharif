#include <stdio.h>
#include <stdlib.h>

int main(){
	int npedras, nsapos, pos, dist;
	int *posptr = NULL;
	scanf("%d %d", &npedras, &nsapos);
	if(!(posptr = (int *) calloc(npedras, sizeof(int)))){
		printf("Erro de alocassaum");
		return 1;
	}
	while(nsapos--){
		scanf("%d %d", &pos, &dist);
		pos--;
		while(pos > 0)
			pos -= dist;
		while(pos < npedras){
			if(pos >= 0)
				posptr[pos] = 1;
			pos += dist;
		}
	}
	for(pos = 0; pos < npedras; pos++)
		printf("%d\n", posptr[pos]);
	free(posptr);
	posptr = NULL;
	return 0;
}
