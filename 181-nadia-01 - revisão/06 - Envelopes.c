#include <stdio.h>
#include <stdlib.h>

int main(){
	int qrotulos, ntipos, i, envelopes;
	int *tiposptr = NULL;
	scanf("%d %d", &qrotulos, &ntipos);
	if(!(tiposptr = (int *) calloc(ntipos, sizeof(int)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	while(qrotulos--){
		scanf("%d", &i);
		tiposptr[i - 1]++;
	}
	for(i = 0; i < ntipos; i++){
		if(i == 0)
			envelopes = tiposptr[i];
		else if(tiposptr[i] < envelopes)
			envelopes = tiposptr[i];
	}
	printf("%d", envelopes);
	free(tiposptr);
	tiposptr = NULL;
	return 0;
}
