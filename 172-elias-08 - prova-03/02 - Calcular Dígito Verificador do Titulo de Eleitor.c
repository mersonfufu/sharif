#include <stdio.h>

/**
 * Funcao que calcula os digitos verificadores do Titulo de Eleitor.
 * @param numSeq Numero sequencial do titulo de eleitor.
 * @param codUF Codigo da Unidade da Federacao
 * @param dv1 Primeiro numero do digito verificador. Parametro por referencia.
 * @param dv2 Primeiro numero do digito verificador. Parametro por referencia.
 */
void calcular_dv_titulo_eleitor(int numSeq, int codUF, int *dv1, int *dv2){
	int vnum[8] = {0}, vuf[2] = {0};
	int i = 0; //numero
	while(numSeq > 0){
		vnum[7 - i] = numSeq % 10;
		numSeq /= 10;
		i++;
	}
	//uf
	vuf[1] = codUF;
	if(vuf[1] >= 10){
		vuf[0] = vuf[1] / 10;
		vuf[1] = vuf[1] % 10;
	}
	//dv1
	*dv1 = (2 * vnum[0] + 3 * vnum[1] + 4 * vnum[2] + 5 * vnum[3] + 6 * vnum[4] + 7 * vnum[5] + 8 * vnum[6] + 9 * vnum[7]) % 11;
	*dv1 == 10 ? *dv1 = 0 : 0; //dv2
	*dv2 = (7 * vuf[0] + 8 * vuf[1] + 9 * *dv1) % 11;
	*dv2 == 10 ? *dv2 = 0 : 0;
}

int main(){
	int num, uf, dv1, dv2;
	scanf("%d %d", &num, &uf);
	if(uf < 1 || uf > 28){
		printf("CODIGO DA UF INVALIDO!\n");
		return 0;
	} else {
		calcular_dv_titulo_eleitor(num, uf, &dv1, &dv2);
		printf("%d%d/%d%d\n", num, uf, dv1, dv2);
	}
	return 0;
}