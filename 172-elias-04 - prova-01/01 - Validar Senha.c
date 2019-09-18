#include <stdio.h>

int main(){
	int senha;
	char user;
	scanf("%d %c", &senha, &user);
	if(senha <= 99999)
		printf("SENHA INVALIDA\n");
	else if(user != 'A' && user != 'G' && user != 'U')
		printf("CATEGORIA INVALIDA\n");
	else if(
		(user == 'A' && senha == 321456) ||
		(user == 'G' && senha == 9510753) ||
		(user == 'U' && senha == 78955632)
	)
		printf("ACESSO PERMITIDO\n");
	else
		printf("ACESSO NEGADO\n");
	return 0;
}