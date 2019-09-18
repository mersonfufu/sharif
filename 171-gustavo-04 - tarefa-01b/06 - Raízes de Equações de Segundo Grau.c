//o enunciando esta errado em afirmar que-1 eh menor que-5
#include <math.h>
#include <stdio.h>

int main(){
	int a, b, c;
	float xum, xdois, aux;
	scanf("%d %d %d", &a, &b, &c);
	if(b * b - 4 * a * c < 0)
		printf("RAIZES IMAGINARIAS\n");
	else {
		xum = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		xdois = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		if(xum < xdois){
			aux = xum;
			xum = xdois;
			xdois = aux;
		}
		if(b * b - 4 * a * c == 0)
			printf("RAIZ UNICA\nX1 = %.2f", xum);
		else
			printf("RAIZES DISTINTAS\nX1 = %.2f\nX2 = %.2f", xum, xdois);
	}
	return 0;
}