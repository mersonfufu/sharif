#include <stdio.h>

int main(){
	int mat, pres;
	float p1, p2, p3, p4, p5, p6, p7, p8, e1, e2, e3, e4, e5, tf, final;
	while(1){
		scanf("%d %f %f %f %f %f %f %f %f %f %f %f %f %f %f %d",
			&mat, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &e1, &e2, &e3, &e4, &e5, &tf, &pres
		);
		if(mat == -1 && p1 == -1 && p2 == -1 && p3 == -1 && p4 == -1 && p5 == -1 && p6 == -1 && p7 == -1 && p8 == -1 && e1 == -1 && e2 == -1 && e3 == -1 && e4 == -1 && e5 == -1 && tf == -1 && pres == -1)
			return 0;
		final = 0.7 * ((p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8) / 8) + 0.15 * ((e1 + e2 + e3 + e4 + e5) / 5) + 0.15 * tf;
		printf("Matricula:%d,Nota Final:%.2f,Situacao Final: ", mat, final);
		if(pres >= 0.75 * 128 && final >= 6)
			printf("APROVADO\n");
		else if(pres < 0.75 * 128 && final >= 6)
			printf("REPROVADO POR FREQUENCIA\n");
		else if(pres >= 0.75 * 128 && final < 6)
			printf("REPROVADO POR NOTA\n");
		else if(pres < 0.75 * 128 && final < 6)
			printf("REPROVADO POR NOTA E POR FREQUENCIA\n");
	}
	return 0;
}