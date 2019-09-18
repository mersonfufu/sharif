#include <stdio.h>
#include <string.h>

int main(){
	char string[1000], letra;
	FILE *ponteiro = NULL;
	scanf("%[^\n]s", string);
	ponteiro = fopen(string, "a+");
	if(ponteiro == NULL)
		return 1;
	do {
		scanf("%[^\n]s", string);
		if(string[0] == '.' && string[1] == '\0')
			break;
		else
			fprintf(ponteiro, "%s\n", string);
	} while(1);
	while(!feof(ponteiro)){
		letra = fgetc(ponteiro);
		printf("%c", letra);
	}
	fseek(ponteiro, 0, SEEK_END);
	printf("%ld\n", ftell(ponteiro));
	fclose(ponteiro);
	ponteiro = NULL;
	return 0;
}