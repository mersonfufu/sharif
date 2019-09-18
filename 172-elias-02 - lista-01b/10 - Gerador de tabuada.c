#include <stdio.h>

int main(){
	float n, k, i, s, cont, kf;
	scanf("%f %f %f %f", &n, &k, &i, &s);
	if(n >= 0 && n <= 9){
		printf("Tabuada de soma:\n");
		cont = 1;
		kf = k;
		while(cont <= i){
			printf("%.2f+%.2f=%.2f\n", n, kf, n + kf);
			kf = kf + s;
			cont++;
		}
		printf("Tabuada de subtracao:\n");
		cont = 1;
		kf = k;
		while(cont <= i){
			printf("%.2f-%.2f=%.2f\n", n, kf, n - kf);
			kf = kf + s;
			cont++;
		}
		printf("Tabuada de multiplicacao:\n");
		cont = 1;
		kf = k;
		while(cont <= i){
			printf("%.2f x%.2f=%.2f\n", n, kf, n * kf);
			kf = kf + s;
			cont++;
		}
		printf("Tabuada de divisao:\n");
		cont = 1;
		kf = k;
		while(cont <= i){
			printf("%.2f /%.2f=%.2f\n", n, kf, n / kf);
			kf = kf + s;
			cont++;
		}
	}
	return 0;
}