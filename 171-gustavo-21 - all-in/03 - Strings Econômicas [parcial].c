#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n, i, t;
	char buffer[10000];
	char **vetor = NULL;
	scanf("%d", &n);
	vetor = (char **) malloc(sizeof(char *)*n);
	for(i = 0; i < n; i++){
		scanf("%[^\n]s", buffer);
		t = strlen(buffer);
		vetor[i] = (char *) malloc(sizeof(char) * (t + 1));
		strcpy(vetor[i], buffer);
	}
	for(i = 0; i < n; i++){
		free(vetor[i]);
		vetor[i] = NULL;
	}
	free(vetor);
	vetor = NULL;
	return 0;
}