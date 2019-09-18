#include <stdio.h>

int main(){
	float notau, notad, notat, media;
	scanf("%f %f %f", &notau, &notad, &notat);
	media = (notau + notad + notat) / 3;
	if(media >= 6)
		printf("MEDIA = %.2f\nAPROVADO\n", media);
	else
		printf("MEDIA = %.2f\nREPROVADO\n", media);
	return 0;
}