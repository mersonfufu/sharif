#include <stdio.h>

int main(){
	int um, dois, tres, quatro;
	scanf("%d %d %d %d", &um, &dois, &tres, &quatro);
	if(um >= dois && um >= tres && um >= quatro)
		quatro = dois + tres + quatro;
	else if(dois >= um && dois >= tres && dois >= quatro)
		quatro = um + tres + quatro;
	else if(tres >= um && tres >= dois && tres >= quatro)
		quatro = um + dois + quatro;
	else if(quatro >= um && quatro >= dois && quatro >= tres)
		quatro = um + dois + tres;
	printf("%d", quatro);
	return 0;
}