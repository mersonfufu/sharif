#include <stdio.h>

int main(){
	short i, j, n, e;
	short matriz[1000][1000];
	scanf("%d", &n);
	e = n - 1;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			scanf("%d", &matriz[i][j]);
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(j == e)
				printf("%d\n", matriz[i][j]);
			continue;
		}
		e--;
	}
	return 0;
}