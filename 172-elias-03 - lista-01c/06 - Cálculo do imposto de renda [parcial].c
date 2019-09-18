#include <stdio.h>

int main(){
	int matricula, encostos;
	float minimo, salario, taxa, ibruto, iliquido, pagamento;
	scanf("%d %f %d %f %f", &matricula, &minimo, &encostos, &salario, &taxa);
	//bruto
	if(salario > 12 * minimo)
		ibruto = salario * 0.2;
	else if(salario > 5 * minimo)
		ibruto = salario * 0.08;
	else
		ibruto = 0;
	//liquido
	iliquido = ibruto - 300 * encostos;
	//pagamento
	pagamento = -1 * salario * taxa * 0.01 + iliquido;
	//pagamento=-1*ibruto+iliquido;
	//saida
	printf("Matricula = %d\n", matricula);
	printf("IMPOSTO BRUTO = %.2f\n", ibruto);
	printf("IMPOSTO LIQUIDO = %.2f\n", iliquido);
	printf("RESULTADO = %.2f\n", pagamento);
	if(pagamento == 0)
		printf("IMPOSTO QUITADO\n");
	else if(pagamento < 0)
		printf("IMPOSTO A RECEBER\n");
	else
		printf("IMPOSTO A PAGAR\n");
	return 0;
}