#include <stdio.h>

int main(){
	int alunos, minima, i, presentes = 0;
	int vetor[1001];
	scanf("%d %d", &alunos, &minima);
	for(i = 0; i < alunos; i++){
		scanf("%d", &vetor[i]);
		if(vetor[i] <= 0)
			presentes++;
	}
	if(presentes < minima)
		printf("SIM\n");
	else {
		printf("NAO\n");
		for(i = alunos - 1; i >= 0; i--)
			if(vetor[i] <= 0)
				printf("%d\n", i + 1);
	}
	return 0;
}