#include <stdio.h>

int main(){
	int aa, mm, dd;
	scanf("%d %d %d", &dd, &mm, &aa);
	if(
		aa < 1900 ||
		aa > 2036 ||
		mm < 1 ||
		mm > 12 ||
		(mm == 2 && dd > 29) ||
		(mm == 4 && dd > 30) ||
		(mm == 6 && dd > 30) ||
		(mm == 9 && dd > 30) ||
		(mm == 11 && dd > 30) ||
		dd < 1 ||
		dd > 31 ||
		(mm == 2 && dd == 29 && aa % 400 != 0 && aa % 100 == 0) ||
		(mm == 2 && dd == 29 && aa % 400 != 0 && aa % 100 != 0 && aa % 4 != 0)
	)
		printf("DATA INVALIDA\n");
	else
		printf("%d/%d/%d\n", dd, mm, aa);
	return 0;
}