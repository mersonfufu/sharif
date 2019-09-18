#include <stdio.h>

int main(){
	int testes, t, num, i, j, dist, mndist;
	int vetor[1001];
	scanf("%d", &testes);
	for(t = 1; t <= testes; t++){
		scanf("%d", &num);
		if(num == 0 || num == 1)
			continue;
		for(i = 0; i < num; i++)
			scanf("%d", &vetor[i]);
		for(i = 0; i < num; i++){
			for(j = 0; j < num; j++){
				if(i == j)
					continue;
				dist = vetor[i] - vetor[j];
				if(dist < 0)
					dist = dist * -1;
				if(i == 0 && j == 1)
					mndist = dist;
				if(dist < mndist)
					mndist = dist;
			}
		}
		printf("%d %d\n", mndist, num * num);
	}
	return 0;
}