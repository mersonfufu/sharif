#include <stdio.h>

int main(){
	int num, dd, mm, aa;
	scanf("%d", &num);
	if(num < 1000000 || num > 31129999)
		printf("Data invalida!");
	else {
		dd = num / 1000000;
		num = num % 1000000;
		mm = num / 10000;
		aa = num % 10000;
		if(
			dd < 1 ||
			dd > 31 ||
			mm < 1 ||
			mm > 12 ||
			(mm == 2 && dd > 28) ||
			(mm == 4 && dd > 30) ||
			(mm == 6 && dd > 30) ||
			(mm == 9 && dd > 30) ||
			(mm == 11 && dd > 30)
		)
			printf("Data invalida!");
		else {
			printf("%d de ", dd);
			if(mm == 1)
				printf("janeiro de ");
			else if(mm == 2)
				printf("fevereiro de ");
			else if(mm == 3)
				printf("marco de ");
			else if(mm == 4)
				printf("abril de ");
			else if(mm == 5)
				printf("maio de ");
			else if(mm == 6)
				printf("junho de ");
			else if(mm == 7)
				printf("julho de ");
			else if(mm == 8)
				printf("agosto de ");
			else if(mm == 9)
				printf("setembro de ");
			else if(mm == 10)
				printf("outubro de ");
			else if(mm == 11)
				printf("novembro de ");
			else if(mm == 12)
				printf("dezembro de ");
			printf("%d", aa);
		};
	}
	return 0;
}