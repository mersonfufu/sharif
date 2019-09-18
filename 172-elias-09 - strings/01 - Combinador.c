#include <stdio.h>

int main(){
	int testes, t, i;
	char stringa[51], stringb[51];
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		for(i = 0; i < 51; i++)
			stringa[i] = stringb[i] = 0;
		scanf("%s", stringa);
		scanf("%s", stringb);
		for(i = 0; i < 51; i++){
			if(stringa[i] != '\0')
				printf("%c", stringa[i]);
			if(stringb[i] != '\0')
				printf("%c", stringb[i]);
		};
		printf("\n");
	}
	return 0;
}