#include <stdio.h>

struct Mercadoria {
	unsigned long int codigo;
	float precoc, precov, plucro;
	int nvendas;
} mercadorias[100];

int main(){
	int i = 0, j, mn10 = 0, e1020 = 0, mr20 = 0, imrlucro = 0, mrnvendas, imrnvendas = 0;
	float mrlucro, tcompras = 0, tvendas = 0, tlucro;
	while(scanf("%u", &mercadorias[i].codigo) != EOF){
		scanf("%f %f %d",
			&mercadorias[i].precoc,
			&mercadorias[i].precov,
			&mercadorias[i].nvendas
		);
		mercadorias[i].plucro = ((mercadorias[i].precov - mercadorias[i].precoc) / mercadorias[i].precoc) * 100;
		if(mercadorias[i].plucro >= 0 && mercadorias[i].plucro < 10)
			mn10++;
		else if(mercadorias[i].plucro >= 10 && mercadorias[i].plucro <= 20)
			e1020++;
		else
			mr20++;//totais
		tcompras = tcompras + mercadorias[i].precoc * mercadorias[i].nvendas;
		tvendas = tvendas + mercadorias[i].precov * mercadorias[i].nvendas;
		tlucro = ((tvendas - tcompras) / tcompras) * 100;
		i++;
	}
	for(j = 0; j < i; j++){
		//maior lucro
		if(j == 0)
			mrlucro = mercadorias[j].plucro;
		else if(mercadorias[j].plucro > mrlucro)
			imrlucro = j; //maior numero de vendas
		if(j == 0)
			mrnvendas = mercadorias[j].nvendas;
		else if(mercadorias[j].nvendas > mrnvendas)
			imrnvendas = j;
	}
	printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n", mn10);
	printf("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n", e1020);
	printf("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n", mr20);
	printf("Codigo da mercadoria que gerou maior lucro: %u\n", mercadorias[imrlucro].codigo);
	printf("Codigo da mercadoria mais vendida: %u\n", mercadorias[imrnvendas].codigo);
	printf("Valor total de compras: %.2f, valor total de vendas: %.2f e percentual de lucro total: %.2f%%\n", tcompras, tvendas, tlucro);
	return 0;
}