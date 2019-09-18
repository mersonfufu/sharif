#include <stdio.h>
#include <string.h>
int xnobuffer(char *buffer, int tamanho){
	return 0;
}int main(){
	int testes, i;
	char buffer[5000];
	scanf("%d", &testes);
	for(i = 0; i < testes; i++){
		scanf("%[^\n]s", buffer);
		xnobuffer(buffer, strlen(buffer));
	}
	return 0;
}