#include <stdio.h>

int main(){
	int ta, tb, i, j, teste, existe, cont;
	int ca[100], cb[100], cr[100];
	do
		scanf("%d", &ta);
	while(ta < 1 || ta > 100);
	do
		scanf("%d", &tb);
	while(tb < 1 || tb > 100);
	for(i = 0; i < ta; i++){
		if(i == 0)
			scanf("%d", &ca[i]);
		else {
			scanf("%d", &teste);
			existe = 0;
			for(j = 0; j < i; j++)
				if(teste == ca[j] && i != j)
					existe = 1;
			if(existe == 1){
				i = i - 1;
				continue;
			} else
				ca[i] = teste;
		}
	}
	for(i = 0; i < tb; i++){
		if(i == 0)
			scanf("%d", &cb[i]);
		else {
			scanf("%d", &teste);
			existe = 0;
			for(j = 0; j < i; j++)
				if(teste == cb[j] && i != j)
					existe = 1;
			if(existe == 1){
				i = i - 1;
				continue;
			} else
				cb[i] = teste;
		}
	}
	for(i = 0; i < ta; i++){
		if(i == 0)
			printf("(");
		printf("%d", ca[i]);
		if(i < ta - 1)
			printf(",");
		if(i == ta - 1)
			printf(")\n");
	}
	for(i = 0; i < tb; i++){
		if(i == 0)
			printf("(");
		printf("%d", cb[i]);
		if(i < tb - 1)
			printf(",");
		if(i == tb - 1)
			printf(")\n");
	}
	cont = 0;
	for(i = 0; i < ta; i++){
		existe = 0;
		for(j = 0; j < tb; j++){
			if(ca[i] == cb[j]){
				existe = 1;
				continue;
			}
		}
		if(existe == 0){
			cr[cont] = ca[i];
			cont++;
		}
	}
	if(cont == 0)
		printf("()\n");
	else {
		for(i = 0; i < cont; i++){
			if(i == 0)
				printf("(");
			printf("%d", cr[i]);
			if(i < cont - 1)
				printf(",");
			if(i == cont - 1)
				printf(")\n");
		}
	}
	cont = 0;
	for(i = 0; i < ta; i++)
		for(j = 0; j < tb; j++){
			if(i == 0 && j == 0)
				printf("(");
			printf("(%dx%d)", ca[i], cb[j]);
			cont++;
			if(cont < ta * tb)
				printf(",");
			if(i == ta - 1 && j == tb - 1)
				printf(")\n");
		}
	return 0;
}