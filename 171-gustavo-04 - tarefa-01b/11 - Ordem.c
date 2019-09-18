#include <stdio.h>

int main(){
	int um, dois, tres, maior, meio, menor;
	char primeiro, segundo, terceiro;
	scanf("%d %d %d", &um, &dois, &tres);
	scanf("\n");
	scanf("%c%c%c", &primeiro, &segundo, &terceiro);
	if(um <= dois && um <= tres){
		if(dois <= tres){
			maior = tres;
			meio = dois;
			menor = um;
		} else {
			maior = dois;
			meio = tres;
			menor = um;
		}
	} else {
		if(dois <= um && dois <= tres){
			if(um <= tres){
				maior = tres;
				meio = um;
				menor = dois;
			} else {
				maior = um;
				meio = tres;
				menor = dois;
			}
		} else {
			if(um <= dois){
				maior = dois;
				meio = um;
				menor = tres;
			} else {
				maior = um;
				meio = dois;
				menor = tres;
			}
		}
	}
	if(primeiro == 'A' && segundo == 'B' && terceiro == 'C')
		printf("%d %d %d", menor, meio, maior);
	else if(primeiro == 'A' && segundo == 'C' && terceiro == 'B')
		printf("%d %d %d", menor, maior, meio);
	else if(primeiro == 'B' && segundo == 'A' && terceiro == 'C')
		printf("%d %d %d", meio, menor, maior);
	else if(primeiro == 'B' && segundo == 'C' && terceiro == 'A')
		printf("%d %d %d", meio, maior, menor);
	else if(primeiro == 'C' && segundo == 'A' && terceiro == 'B')
		printf("%d %d %d", maior, menor, meio);
	else if(primeiro == 'C' && segundo == 'B' && terceiro == 'A')
		printf("%d %d %d", maior, meio, menor);
	return 0;
}