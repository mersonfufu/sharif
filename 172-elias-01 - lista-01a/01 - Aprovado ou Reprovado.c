#include <stdio.h>

int main(){
	float n1, n2, n3, media;
	scanf("%f %f %f", &n1, &n2, &n3);
	media = (n1 + n2 + n3) / 3;
	if(media >= 6)
		printf("MEDIA = %.2f\nAPROVADO\n", media);
	else
		printf("MEDIA = %.2f\nREPROVADO\n", media);
	return 0;
}