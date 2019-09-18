#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[51];
	float preco;
} stProduto;

int main(){
	int idas, i, produtos, p, lista, j;
	float total;
	stProduto Produtos[101], Compras[101];
	//entrada
	scanf("%d", &idas);
	for(i = 0; i < idas; i++){
		//lista do mercado
		scanf("%d", &produtos);
		for(p = 0; p < produtos; p++){
			scanf("%s", Produtos[p].nome);
			scanf("%f", &Produtos[p].preco);
		}
		//lista da velha
		scanf("%d", &lista);
		for(p = 0; p < lista; p++){
			scanf("%s", Compras[p].nome);
			scanf("%f", &Compras[p].preco);
		}
		//valor da compra
		total = 0;
		for(p = 0; p < lista; p++){
			for(j = 0; j < produtos; j++){
				if(strcmp(Compras[p].nome, Produtos[j].nome) == 0){
					total += Produtos[j].preco * Compras[p].preco;
					continue;
				}
			}
		}
		//saida
		printf("R$ %.2f\n", total);
	}
	return 0;
}