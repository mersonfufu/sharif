#include <stdio.h>
#include <string.h>

int main(){
	char pais[101];
	//entrada
	while(scanf("%[^\n]%*c", pais) != EOF){
		//saida
		if(strcmp(pais, "alemanha") == 0)
			printf("Frohliche Weihnachten!\n");
		else if(strcmp(pais, "antardida") == 0)
			printf("Merry Christmas!\n");
		else if(strcmp(pais, "argentina") == 0)
			printf("Feliz Navidad!\n");
		else if(strcmp(pais, "australia") == 0)
			printf("Merry Christmas!\n");
		else if(strcmp(pais, "austria") == 0)
			printf("Frohe Weihnacht!\n");
		else if(strcmp(pais, "belgica") == 0)
			printf("Zalig Kerstfeest!\n");
		else if(strcmp(pais, "brasil") == 0)
			printf("Feliz Natal!\n");
		else if(strcmp(pais, "canada") == 0)
			printf("Merry Christmas!\n");
		else if(strcmp(pais, "chile") == 0)
			printf("Feliz Navidad!\n");
		else if(strcmp(pais, "coreia") == 0)
			printf("Chuk Sung Tan!\n");
		else if(strcmp(pais, "espanha") == 0)
			printf("Feliz Navidad!\n");
		else if(strcmp(pais, "estados-unidos") == 0)
			printf("Merry Christmas!\n");
		else if(strcmp(pais, "grecia") == 0)
			printf("Kala Christougena!\n");
		else if(strcmp(pais, "inglaterra") == 0)
			printf("Merry Christmas!\n");
		else if(strcmp(pais, "irlanda") == 0)
			printf("Nollaig Shona Dhuit!\n");
		else if(strcmp(pais, "italia") == 0)
			printf("Buon Natale!\n");
		else if(strcmp(pais, "japao") == 0)
			printf("Merii Kurisumasu!\n");
		else if(strcmp(pais, "libia") == 0)
			printf("Buon Natale!\n");
		else if(strcmp(pais, "marrocos") == 0)
			printf("Milad Mubarak!\n");
		else if(strcmp(pais, "mexico") == 0)
			printf("Feliz Navidad!\n");
		else if(strcmp(pais, "portugal") == 0)
			printf("Feliz Natal!\n");
		else if(strcmp(pais, "siria") == 0)
			printf("Milad Mubarak!\n");
		else if(strcmp(pais, "suecia") == 0)
			printf("God Jul!\n");
		else if(strcmp(pais, "turquia") == 0)
			printf("Mutlu Noeller\n");
		else
			printf("--NOT FOUND--\n");
	}
	return 0;
}