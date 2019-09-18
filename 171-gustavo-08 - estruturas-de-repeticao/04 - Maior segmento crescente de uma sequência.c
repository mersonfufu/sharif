#include <stdio.h>

int main(){
	int quant, cont, numero, anterior, pontos = 1, mpontos = 1;
	cin >> quant;
	if(quant == 0)
		cout << "O comprimento do segmento crescente maximo e: 0\n";
	else {
		for(cont = 1; cin >> numero; cont++){
			if(cont == 1)
				anterior = numero;
			else {
				if(anterior < numero){
					pontos++;
					if(pontos > mpontos)
						mpontos = pontos;
					anterior = numero;
				} else {
					pontos = 1;
					anterior = numero;
				}
			}
			if(cont == quant)
				break;
		}
		cout << "O comprimento do segmento crescente maximo e: " << mpontos << "\n";
	}
	return 0;
}