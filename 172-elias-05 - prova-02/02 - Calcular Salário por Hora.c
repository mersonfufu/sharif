#include <stdio.h>

int main(){
	double vhora, inss, ssal = 0, sinss = 0;
	int codigo = 0, horas;
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
	return 0;
}