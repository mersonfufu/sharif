#include <stdio.h>

int main(){
	int maior, um, dois;
	char op;
	scanf("%d %d %c %d", &maior, &um, &op, &dois);
	if(
		(op == '+' && um + dois > maior) ||
		(op == '*' && um * dois > maior)
	)
		printf("OVERFLOW");
	else
		printf("OK");
	return 0;
}