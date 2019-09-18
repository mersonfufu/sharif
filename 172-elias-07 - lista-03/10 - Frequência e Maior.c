#include <stdio.h>

int main(){
	int n, i, maior, freq = 0, indice = 0;
	int notas[10001];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &notas[i]);
		if(i == 0)
			maior = notas[i];
		else if(notas[i] > maior){
			maior = notas[i];
			indice = i;
		}
	}
	for(i = 0; i < n; i++){
		if(notas[i] == notas[n - 1])
			freq++;
	}
	printf("Nota %d, %d vezes\nNota %d, indice %d\n", notas[n - 1], freq, maior, indice);
	return 0;
}