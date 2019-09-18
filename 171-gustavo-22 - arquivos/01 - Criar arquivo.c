#include <stdio.h>
#include <string.h>

int main(){
	char string[100];
	int i;
	FILE *ponteiro = NULL;
	printf("Digite o nome do arquivo... ");
	scanf("%[^\n]s", string);
	ponteiro = fopen(string, "a+");
	if(!ponteiro)
		return 1;
	do {
		printf("Digite texto pra adicionar... ");
		scanf("%[^\n]s", string);
		if(strcmp(string, "*") != 1)
			break;
		else
			for(i = 0; string[i]; i++)
				putc(string[i], ponteiro);
	} while(1);
	fclose(ponteiro);
	ponteiro = NULL;
	return 0;
}