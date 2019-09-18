#include <stdio.h>

int main(){
	int um, dois, tres, composto;
	scanf("%d %d %d", &um, &dois, &tres);
	if(um >= 10 || dois >= 10 || tres >= 10)
		printf("DIGITO INVALIDO");
	else {
		composto = um * 100 + dois * 10 + tres;
		printf("%d, %d", composto, composto * composto);
	}
	return 0;
}