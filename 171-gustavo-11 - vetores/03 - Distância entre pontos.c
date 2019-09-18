#include <math.h>
#include <stdio.h>

int main(){
	int n, i, j;
	float distancia;
	float vetora[4], vetorb[4];
	scanf("%d", &n);
	for(j = 1; j < n; j++){
		if(j == 1){
			for(i = 0; i < 3; i++)
				scanf("%f", &vetora[i]);
			for(i = 0; i < 3; i++)
				scanf("%f", &vetorb[i]);
		} else {
			for(i = 0; i < 3; i++)
				vetora[i] = vetorb[i];
			for(i = 0; i < 3; i++)
				scanf("%f", &vetorb[i]);
		}
		distancia = 0;
		for(i = 0; i < 3; i++)
			distancia = distancia + (vetora[i] - vetorb[i]) * (vetora[i] - vetorb[i]);
		distancia = sqrt(distancia);
		printf("%.2f\n", distancia);
	}
	return 0;
}