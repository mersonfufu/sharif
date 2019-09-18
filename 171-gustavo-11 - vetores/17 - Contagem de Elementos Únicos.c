#include <stdio.h>

int main(){
	int num, i, j, igual, total = 0;
	int vetor[5001];
	scanf("%d", &num);
	for(i = 0; i < num; i++)
		scanf("%d", &vetor[i]);
	for(i = 0; i < num; i++){
		igual = 0;
		for(j = 0; j < num; j++){
			if(i == j)
				continue;
			if(vetor[i] == vetor[j])
				igual++;
		}
		if(igual == 0)
			total++;
	}
	printf("%d", total);
	return 0;
}