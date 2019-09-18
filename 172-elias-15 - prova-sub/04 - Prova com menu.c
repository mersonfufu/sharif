#define _salario 937.00
#include <stdio.h>

/**
 * Questao 01
 */
void questao1(){
	int n, cont = 2;
	double soma = 0;
	//entrada
	scanf("%d", &n);
	//saida
	if(n < 3)
		printf("Numero invalido!");
	else {
		while(cont <= n){
			soma = soma + ((float)n / (cont * cont));
			cont++;
		}
		soma += n;
		printf("%.5f", soma);
	}
}

/**
 * Questao 02
 */
void questao2(){
	double vhora, inss, ssal = 0, sinss = 0;
	int codigo = 0, horas;
	//entrada
	scanf("%lf %d", &vhora, &codigo);
	while(codigo != -1){
		scanf("%d", &horas);
		inss = (horas * vhora * 4.5) + (horas * vhora * 0.75);
		ssal += inss;
		if(inss <= 1659.38)
			inss *= 0.08;
		else if(inss <= 2765.66)
			inss *= 0.09;
		else if(inss <= 5531.31)
			inss *= 0.11;
		else
			inss = 5531.31 * 0.11;
		sinss += inss;
		//saida
		printf("%d => %.2lf + %.2lf = %.2lf - %.2lf = %.2f\n",
			codigo,
			horas * vhora * 4.5,
			horas * vhora * 0.75,
			(horas * vhora * 4.5) + (horas * vhora * 0.75),
			inss,
			(horas * vhora * 4.5) + (horas * vhora * 0.75) - inss
		);
		scanf("%d", &codigo);
	}
	printf("SOMA DOS SALARIOS BRUTOS: %.2lf\nSOMA DOS INSS: %.2lf", ssal, sinss);
}

/**
 * Questao 03
 */
void questao3(){
	float renda;
	int familia, escola, etnia, totall1 = 0, totall2 = 0, totall3 = 0, totall4 = 0, totalnc = 0;
	//entrada
	scanf("%f", &renda);
	while(renda != -1){
		scanf("%d %d %d", &familia, &escola, &etnia);
		//saida
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
}

int main(){
	char questao;
	do {
		printf("\n\n");
		printf("\t\t******************************\n");
		printf("\t\t*     PROVA SUBSTITUTIVA     *\n");
		printf("\t\t******************************\n");
		printf("\t\t Digite 0 para sair ou digite\n");
		printf("\t\t o numero da questao... ");
		scanf("%c", &questao);
		printf("\n\t\t******************************\n");
		printf("\n\n");
		if((char)questao < '0' || (char)questao > '3')
			printf("\t\tOpcao invalida!");
		else {
			switch(questao){
				case '1':
					questao1();
					break;
				case '2':
					questao2();
					break;
				case '3':
					questao3();
					break;
			}
		}
	} while(questao != '0');
	printf("\t\t\t\tQuero dez :)\n");
	return 0;
}