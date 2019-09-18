/**
 * Trabalho de AED1
 * Hemerson e Paulo Henrique Santos
 *
 * Comparativo entre alocassaum estahtica e dinamica com variahvel local e global
 */

/**
 * Testado em Dell Latitude E6430, Intel i5, 2.7GHz, 4GB, Windows 10 64-bits e IDE Dev-Cpp 5.11 GCC 4.9.2
 *     Aproximacao do maior valor alocado estaticamente com variavel local:      520.000 ~     521.000
 *     Aproximacao do maior valor alocado estaticamente com variavel global: 499.000.000 ~ 500.000.000
 *     Aproximacao do maior valor alocado dinamicamente com variavel local:  824.000.000 ~ 825.000.000
 *     Aproximacao do maior valor alocado dinamicamente com variavel global: 910.000.000 ~ 920.000.000
 * Resultado: (global > local) e (dinamica > estahtica)
 * 
 * Testado em Dell Inspirion 5458, Intel i5, 2.2GHz, 8GB, GeForce 920M (2GB), Windows 10 64-bits e IDE Dev-Cpp 5.11 GCC 4.9.2
 *     Aproximacao do maior valor alocado estaticamente com variavel local:       510.000 ~       518.000
 *     Aproximacao do maior valor alocado estaticamente com variavel global:  490.000.000 ~   499.000.000
 *     Aproximacao do maior valor alocado dinamicamente com variavel local: 2.000.000.000 ~ 2.100.000.000
 *     Aproximacao do maior valor alocado dinamicamente com variavel global:  490.000.000 ~   499.000.000
 * Resultado: (dinamica e local) > (estatica e local) > (estatica/dinamica e global)
 * 
 * Testado em Dell Inspirion 5458, Intel i5, 2.2GHz, 7.7GB, GeForce 920M (2GB) e Ubuntu 18.04 LTS
 *     Aproximacao do maior valor alocado estaticamente com variavel local:      1.900.000 ~     2.000.000
 *     Aproximacao do maior valor alocado estaticamente com variavel global:   900.000.000 ~ 1.000.000.000
 *     Aproximacao do maior valor alocado dinamicamente com variavel local:  1.400.000.000 ~ 1.500.000.000
 *     Aproximacao do maior valor alocado dinamicamente com variavel global: 1.000.000.000 ~ 2.000.000.000
 * Resultado: (global > local) e (dinamica > estahtica)
*/

#define MAX 910000000
#include <stdio.h>
#include <stdlib.h>

void aloc_dinamica(int *, int);
void aloc_estatica(int);
void dados_vetor(int *, int);

/************************************************** Testar alocassaum **************************************************/

/* Main para alocassaum */
int main_alocassaum(){
	int *ptr = NULL;
	char memoria;
	do {
		printf("[E]stahtica ou [D]inamica... ");
		scanf(" %c", &memoria);
//		memoria = 'e'; //entrada
//		memoria = 'd'; //entrada
		if(memoria == 'e' || memoria == 'E')
			aloc_estatica(MAX);
		else if(memoria == 'd' || memoria == 'D')
			aloc_dinamica(ptr, MAX);
	} while(memoria != 'e' && memoria != 'd' && memoria != 'E' && memoria != 'D');
	if(ptr){
		free(ptr);
		ptr = NULL;
	}
	return 0;
}

/************************************************** Testar escopo **************************************************/

/* Global estahtica */
//int vetorglobal[MAX];
//
//int main_estatica(){
//	dados_vetor(vetorglobal, MAX);
//}

/************************************************** Testar escopo **************************************************/

/* Global dinamica */
//int *ptr = NULL;
//
//int main_dinamica(){
//	if(!(ptr = calloc(MAX, sizeof(int))))
//		printf("Falha de alocassaum");
//	dados_vetor(ptr, MAX);
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

/************************************************** Funcoes **************************************************/

/**
 * Hemerson
 */
void aloc_dinamica(int *ptr, int elementos){
	if(ptr = calloc(elementos, sizeof(int))){
		printf("Alocassaum OK\n");
		dados_vetor(ptr, elementos);
	}
	else
		printf("Falha de alocassaum\n");
}

/**
 * Hemerson
 */
void aloc_estatica(int elementos){
	int vetor[elementos];
	if(vetor){
		printf("Alocassaum OK\n");
		dados_vetor(vetor, elementos);
	}
	else
		printf("Falha de alocassaum\n");
}

/**
 * Hemerson
 */
void dados_vetor(int *vetor, int elementos){
	int i;
	for(i = 0; i < elementos; i++)
		vetor[i] = 69;
	for(i = 0; i < elementos; i++)
		printf("%d ", vetor[i]);
}