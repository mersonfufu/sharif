#define _SAL 937.00
#include <stdio.h>

int main(){
	float renda;
	int familia, escola, etnia, tl1 = 0, tl2 = 0, tl3 = 0, tl4 = 0, tnc = 0;
	scanf("%f", &renda);
	while(renda != -1){
		scanf("%d %d %d", &familia, &escola, &etnia);
		if(escola == 2 && renda / familia <= _SAL * 1.5 && etnia == 4){
			printf("ALUNO COTISTA (L1)\n");
			tl1++;
		} else if(escola == 2 && renda / familia <= _SAL * 1.5 && (etnia == 1 || etnia == 2 || etnia == 3)){
			printf("ALUNO COTISTA (L2)\n");
			tl2++;
		} else if(escola == 2 && etnia == 4){
			printf("ALUNO COTISTA (L3)\n");
			tl3++;
		} else if(escola == 2 && (etnia == 1 || etnia == 2 || etnia == 3)){
			printf("ALUNO COTISTA (L4)\n");
			tl4++;
		} else {
			printf("ALUNO NAO COTISTA\n");
			tnc++;
		}
		scanf("%f", &renda);
	}
	printf("TOTAL (L1): %d\nTOTAL (L2): %d\nTOTAL (L3): %d\nTOTAL (L4): %d\nTOTAL NAO COTISTA: %d", tl1, tl2, tl3, tl4, tnc);
	return 0;
}