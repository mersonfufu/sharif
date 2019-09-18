#include <stdio.h>

int main(){
	int hh, mm, ss, sss;
	scanf("%d %d %d", &hh, &mm, &ss);
	sss = hh * 60 * 60 + mm * 60 + ss;
	printf("O TEMPO EM SEGUNDOS E = %d\n", sss);
	return 0;
}