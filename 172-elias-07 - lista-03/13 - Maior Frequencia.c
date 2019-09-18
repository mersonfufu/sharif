#include <stdio.h>

int main(){
	int n, i, j, isegundo, iprimeiro, freq, mfreq, aux;
	int vetor[100001];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &vetor[i]);
	for(i = 0; i < n; i++){
		freq = 0;
		for(j = 0; j < n; j++)
			if(vetor[i] == vetor[j])
				freq++;
		if(i == 0){
			mfreq = freq;
			isegundo = i;
			iprimeiro = i;
		} else {
			if(freq > mfreq){
				mfreq = freq;
				isegundo = iprimeiro;
				iprimeiro = i;
			} else if(freq == mfreq){
				if(vetor[i] < vetor[iprimeiro]){
					isegundo = iprimeiro;
					iprimeiro = i;
				}
			}
		}
	}
	printf("%d\n%d", vetor[iprimeiro], mfreq);
	return 0;
}