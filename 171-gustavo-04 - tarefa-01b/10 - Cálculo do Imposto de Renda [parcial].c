#include <stdio.h>

int main(){
	int matricula, encostos;
	float minimo, funcionario, inormal, ibruto, iliquido, vfinal;
	scanf("%d %f %d %f %f", &matricula, &minimo, &encostos, &funcionario, &inormal);
	if(funcionario > 12 * minimo)
		ibruto = funcionario * 0.2;
	else if(funcionario > 5 * minimo)
		ibruto = funcionario * 0.08;
	else
		ibruto = 0;
	iliquido = ibruto - 300 * encostos;
	vfinal = iliquido - (0.01 * inormal * funcionario);
	printf("Matricula = %d\n", matricula);
	printf("IMPOSTO BRUTO = %.2f\n", ibruto);
	printf("IMPOSTO LIQUIDO = %.2f\n", iliquido);
	printf("RESULTADO = %.2f\n", vfinal);
	if(vfinal == 0)
		printf("IMPOSTO QUITADO\n");
	else if(vfinal < 0)
		printf("IMPOSTO A RECEBER\n");
	else
		printf("IMPOSTO A PAGAR\n");
	return 0;
}