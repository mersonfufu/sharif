#include <stdio.h>
#include <math.h>

int main(){
	char stringa[1001] = {0}, stringb[1001] = {0};
	int i;
	int vogaisa[5] = {0}, vogaisb[5] = {0}, erro = 0;
	float de = 0;
	scanf("%[^;]s", stringa);
	scanf("%[^\n]s", stringb);
	for(i = 0; i < 1001; i++){
		if(stringa[i] == ';' || stringb[i] == ';')
			erro++;
		if(erro >= 2){
			printf("FORMATO INVALIDO!");
			return 0;
		}
		if(stringa[i] == 'a' || stringa[i] == 'A')
			vogaisa[0]++;
		else if(stringa[i] == 'e' || stringa[i] == 'E')
			vogaisa[1]++;
		else if(stringa[i] == 'i' || stringa[i] == 'I')
			vogaisa[2]++;
		else if(stringa[i] == 'o' || stringa[i] == 'O')
			vogaisa[3]++;
		else if(stringa[i] == 'u' || stringa[i] == 'U')
			vogaisa[4]++;
		if(stringb[i] == 'a' || stringb[i] == 'A')
			vogaisb[0]++;
		else if(stringb[i] == 'e' || stringb[i] == 'E')
			vogaisb[1]++;
		else if(stringb[i] == 'i' || stringb[i] == 'I')
			vogaisb[2]++;
		else if(stringb[i] == 'o' || stringb[i] == 'O')
			vogaisb[3]++;
		else if(stringb[i] == 'u' || stringb[i] == 'U')
			vogaisb[4]++;
	}
	for(i = 0; i < 5; i++){
		i == 0 ? printf("(") : 0;
		printf("%d", vogaisa[i]);
		(i >= 0 && i < 4) ? printf(",") : 0;
		i == 4 ? printf(")\n") : 0;
	}
	for(i = 0; i < 5; i++){
		i == 0 ? printf("(") : 0;
		printf("%d", vogaisb[i]);
		(i >= 0 && i < 4) ? printf(",") : 0;
		i == 4 ? printf(")\n") : 0;
	}
	for(i = 0; i < 5; i++)
		de += (vogaisa[i] - vogaisb[i]) * (vogaisa[i] - vogaisb[i]);
	de = sqrt(de);
	printf("%.2f", de);
	return 0;
}