#define _salario 937.00
#include <stdio.h>
int main(){
	float renda;
	int familia, escola, etnia, totall1 = 0, totall2 = 0, totall3 = 0, totall4 = 0, totalnc = 0; //entrada
	scanf("%f", &renda);
	while(renda != -1){
		scanf("%d %d %d", &familia, &escola, &etnia); //saida
		if(escola == 2 && renda / familia <= _salario * 1.5 && etnia == 4){
			printf("ALUNO COTISTA (L1)\n");
			totall1++;
		} else if(escola == 2 && renda / familia <= _salario * 1.5 && (etnia == 1 || etnia == 2 || etnia == 3)){
			printf("ALUNO COTISTA (L2)\n");
			totall2++;
		} else if(escola == 2 && etnia == 4){
			printf("ALUNO COTISTA (L3)\n");
			totall3++;
		} else if(escola == 2 && (etnia == 1 || etnia == 2 || etnia == 3)){
			printf("ALUNO COTISTA (L4)\n");
			totall4++;
		} else {
			printf("ALUNO NAO COTISTA\n");
			totalnc++;
		}
		scanf("%f", &renda);
	}
	printf("TOTAL (L1): %d\nTOTAL (L2): %d\nTOTAL (L3): %d\nTOTAL (L4): %d\nTOTAL NAO COTISTA: %d", totall1, totall2, totall3, totall4, totalnc);
	return 0;
}