#include <stdio.h>

int main(){
	int um, dois;
	scanf("%d %d", &um, &dois);
	um = (um % 10) * 100 + ((um / 10) % 10) * 10 + um / 100;
	dois = (dois % 10) * 100 + ((dois / 10) % 10) * 10 + dois / 100;
	printf("%d", um > dois ? um : dois);
	return 0;
}