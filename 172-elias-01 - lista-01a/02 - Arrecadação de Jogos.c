#define _PPOP 1
#define _PGER 5
#define _PARQ 10
#define _PCAD 20
#include <stdio.h>

int main(){
	int i, testes, pessoas;
	float ppop, pger, parq, pcad, renda;
	scanf("%d", &testes);
	for(i = 0; i < testes; i++){
		scanf("%d %f %f %f %f", &pessoas, &ppop, &pger, &parq, &pcad);
		renda = pessoas / 100.0 * (ppop + pger * 5.0 + parq * 10.0 + pcad * 20.0);
		renda =
			(pessoas * ppop / 100 * _PPOP) +
			(pessoas * pger / 100 * _PGER) +
			(pessoas * parq / 100 * _PARQ) +
			(pessoas * pcad / 100 * _PCAD);
		printf("A RENDA DO JOGO N. %d E = %.2f\n", i + 1, renda);
	}
	return 0;
}