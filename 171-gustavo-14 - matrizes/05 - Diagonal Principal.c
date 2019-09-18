#include <stdio.h>

int main(){
	short i, j, n;
	short matriz[1000][1000];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &matriz[i][j]);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i == j)
				printf("%d\n", matriz[i][j]);
	return 0;
}