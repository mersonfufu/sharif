#include <stdio.h>

int main(){
	int n, i, j, k;
	float maior, mod;
	float vetora[4], vetorb[4], vetorab[4];
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
		for(i = 0; i < 3; i++)
			vetorab[i] = vetorb[i] - vetora[i];
		for(i = 0; i < 3; i++)
			if(vetorab[i] < 0)
				vetorab[i] = vetorab[i] * -1;
		//teste
		for(i = 0; i < n; i++){
			for(k = i + 1; k < n; k++){
				if(i == 0)
					maior = vetorab[i];
				else if(vetorab[i] > maior)
					maior = vetorab[i];
			}
		}
		printf("%.2f\n", maior);
	}
	return 0;
}