#include <stdio.h>

int main(){
	int ta, ca[101], tb, cb[101], i, j, num, ignorar, cr[101];
	do {
		scanf("%d", &ta);
	} while(ta < 1 || ta > 100);
	do {
		scanf("%d", &tb);
	} while(tb < 1 || tb > 100);
	//vetora
	for(i = 0; i < ta; i++){
		scanf("%d", &num);
		if(i == 0)
			ca[0] = num;
		else {
			ignorar = 0;
			for(j = 0; j <= i; j++){
				if(num == ca[j]){
					ignorar = 1;
					break;
				}
			}
			if(ignorar == 0)
				ca[i] = num;
			else
				i = i - 1;
		}
	}
	//vetorb
	for(i = 0; i < tb; i++){
		scanf("%d", &num);
		if(i == 0)
			cb[0] = num;
		else {
			ignorar = 0;
			for(j = 0; j <= i; j++){
				if(num == cb[j]){
					ignorar = 1;
					break;
				}
			}
			if(ignorar == 0)
				cb[i] = num;
			else
				i = i - 1;
		}
	}
	//resultante
	for(i = 0; i < ta; i++)
		cr[i] = ca[i];
	for(i = 0; i < ta + tb; i++)
		cr[ta + i] = cb[i];
	//saida
	printf("(");
	for(i = 0; i < ta + tb; i++){
		if(i == 0){
			printf("%d,", cr[i]);
			continue;
		} else {
			ignorar = 0;
			for(j = 0; j < i; j++){
				if(cr[i] == cr[j]){
					ignorar = 1;
					break;
				}
			}
			if(ignorar == 0)
				printf("%d", cr[i]);
		}
	}
	printf(")");
	return 0;
}