#include <stdio.h>

int main(){
	int hh, mm, ss;
	scanf("%d %d %d", &hh, &mm, &ss);
	hh = hh * 60 * 60 + mm * 60 + ss;
	printf("O TEMPO EM SEGUNDOS E = %d", hh);
	return 0;
}