organizar(){
	//rodada
	for(rodada = 0; rodada < rodadas; rodada++){
		for(i = 0; i < 9; i++)
			milf[i] = 0;
		//turno
		for(turno = 0; turno <= 9; turno++){
			//apagar isso
		} else if(turno >= 5 && turno <= 8){
			imprime_tabuleiro();
			verificar_vitoria();
			if(vitoria == 0)
				solicitar_movimento();
		} else
			verificar_vitoria();
		//apagar isso
		//desenvolver
		if(turno >= 0 && turno <= 4){
			do {
				imprime_tabuleiro();
				solicitar_movimento();
			} while(i < 1 || i > 9);
			if(jogador == 1)
				milf[i - 1] = 1;
			else if(jogador == -1)
				milf[i - 1] = -1;
			jogador *= -1;
		} else if(turno >= 5 && turno <= 8){
			//desenvolver
		}
		if(turno >= 5){
			//vitoria
			if(vitoria == 3 || vitoria == -3){
				if(vitoria == 3)
					winx++;
				else if(vitoria == -3)
					wino++;
				//resultado
				printf("\n--------------------\n");
				printf("Vitoria de ");
				if(vitoria == 3)
					printf("%s!\n", nomex);
				else if(vitoria == -3)
					printf("%s!\n", nomeo);
				printf("--------------------\n");
				printf("(%s)%i\n", nomex, winx);
				printf("(%s)%i\n", nomeo, wino);
				printf("--------------------\n");
				printf("Digite qualquer numero... ");
				scanf("%d", &opcao);
				if(opcao == 0)
					opcao++;
				break;
			}
			//fim do resultado
		}
		//vitoria
	} else {
		//info
		mostra_espacos();
		printf("---------------------\n");
		printf("---Jogo ");
		if(rodada + 1 < 10)
			printf("0");
		printf("%d de ", rodada + 1);
		if(rodadas < 10)
			printf("0");
		printf("%d---\n", rodadas);
		printf("---------------------\n\n");
		//info
		//tabuleiro
		for(i = 0; i < 3; i++){
			printf(" ");
			for(j = 0; j < 3; j++){
				if(milf[i][j] == 1)
					printf("X");
				else if(milf[i][j] == -1)
					printf("O");
				else
					printf("-");
				if(j < 2)
					printf(" | ");
				else
					printf("\n");
			}
		}
		//tabuleiro
		//vitoria
		vitoria = 0;
		if((milf[0][0] + milf[0][1] + milf[0][2]) == 3)
			vitoria = 3;
		else if((milf[1][0] + milf[1][1] + milf[1][2]) == 3)
			vitoria = 3;
		else if((milf[2][0] + milf[2][1] + milf[2][2]) == 3)
			vitoria = 3;
		else if((milf[0][0] + milf[1][0] + milf[2][0]) == 3)
			vitoria = 3;
		else if((milf[0][1] + milf[1][1] + milf[2][1]) == 3)
			vitoria = 3;
		else if((milf[0][2] + milf[1][2] + milf[2][2]) == 3)
			vitoria = 3;
		else if((milf[0][0] + milf[1][1] + milf[2][2]) == 3)
			vitoria = 3;
		else if((milf[0][2] + milf[1][1] + milf[2][0]) == 3)
			vitoria = 3;
		else if((milf[0][0] + milf[0][1] + milf[0][2]) == -3)
			vitoria = -3;
		else if((milf[1][0] + milf[1][1] + milf[1][2]) == -3)
			vitoria = -3;
		else if((milf[2][0] + milf[2][1] + milf[2][2]) == -3)
			vitoria = -3;
		else if((milf[0][0] + milf[1][0] + milf[2][0]) == -3)
			vitoria = -3;
		else if((milf[0][1] + milf[1][1] + milf[2][1]) == -3)
			vitoria = -3;
		else if((milf[0][2] + milf[1][2] + milf[2][2]) == -3)
			vitoria = -3;
		else if((milf[0][0] + milf[1][1] + milf[2][2]) == -3)
			vitoria = -3;
		else if((milf[0][2] + milf[1][1] + milf[2][0]) == -3)
			vitoria = -3;
		if(vitoria == 3 || vitoria == -3){
			if(vitoria == 3)
				winx++;
			else if(vitoria == -3)
				wino++;
			//resultado
			printf("\n--------------------\n");
			printf("Vitoria de ");
			if(vitoria == 3)
				printf("%s!\n", nomex);
			else if(vitoria == -3)
				printf("%s!\n", nomeo);
			printf("--------------------\n");
			printf("(%s)%i\n", nomex, winx);
			printf("(%s)%i\n", nomeo, wino);
			printf("--------------------\n");
			printf("Digite qualquer numero... ");
			scanf("%d", &opcao);
			if(opcao == 0)
				opcao++;
			break;
		} else {
			printf("\n--------------------\n");
			printf("Empate / Velha\n");
			printf("--------------------\n");
			printf("(%s)%i\n", nomex, winx);
			printf("(%s)%i\n", nomeo, wino);
			printf("--------------------\n");
			printf("Digite qualquer numero... ");
			scanf("%d", &opcao);
			if(opcao == 0)
				opcao++;
			break;
		}
		//fim do resultado
	}
	//vitoria
}
//fim dos turnos
//aqui
}
//fim das rodadas
break;
}

} while(opcao != NSAIR);
}
#define NPULO 2
#define NSAIR 0
#define NPVSNPC 1
#define NPVSP 2
#define NCONFIG 3
#define NCREDITOS 4
#define NNIVELNPC 1
#define NJOGOS 2
#define NNOMES 3
#include <stdio.h>
char inicio = 'n', nomex[12] = "X", nomeo[12] = "O";
int i, opcao, rodada, turno, vitoria, winx, wino;
int dificuldade = 666, rodadas = 3, jogador = 1;
int milf[9];
void mostra_espacos(){
	for(i = 0; i < NPULO; i++)
		printf("\n");
}
char menu_inicial(){
	if(inicio == 's')
		mostra_espacos();
	inicio = 's';
	printf("---------------------------\n");
	printf("------JOGO DA VELHA------\n");
	printf("---------------------------\n");
	printf("(%d) PLAYER VS NPC\n", NPVSNPC);
	printf("(%d) PLAYER VS PLAYER\n", NPVSP);
	printf("(%d) CONFIGURACOES\n", NCONFIG);
	printf("(%d) CREDITOS\n", NCREDITOS);
	printf("(%d) SAIR\n", NSAIR);
	printf("---------------------------\n");
	printf("Escolha... ");
	scanf("%d", &opcao);
}
void menu_configuracoes(){
	mostra_espacos();
	printf("---------------------------\n");
	printf("------CONFIGURACOES------\n");
	printf("---------------------------\n");
	printf("(%d) NIVEL DO NPC ", NNIVELNPC);
	if(dificuldade == 666)
		printf("(%d)\n", dificuldade);
	else
		printf(" (%d)\n", dificuldade);
	printf("(%d) JOGOS POR RODADA ", NJOGOS);
	if(rodadas < 100)
		printf(" ");
	if(rodadas < 10)
		printf(" ");
	printf("(%d)\n", rodadas);
	printf("(%d) DEFINIR NOMES\n", NNOMES);
	printf("(%d) SAIR\n", NSAIR);
	printf("---------------------------\n");
	printf("Escolha... ");
	scanf("%d", &opcao);
	switch(opcao){
		case NNIVELNPC:
			do {
				menu_nivelnpc();
			} while(dificuldade != 1 && dificuldade != 666);
			break;
		case NJOGOS:
			do {
				menu_njogos();
			} while(rodadas == 0 || rodadas < 3 || rodadas > 999);
			break;
		case NNOMES:
			do {
				menu_nomes();
			} while(i != 1);
			break;
			//default:
	}
}
int menu_nivelnpc(){
	mostra_espacos();
	printf("-------------------------\n");
	printf("---Nivel do oponente---\n");
	printf("-------------------------\n");
	printf("(1) Decepcionante");
	if(dificuldade == 1)
		printf("<<\n");
	else
		printf("\n");
	printf("(666) Satanico");
	if(dificuldade == 666)
		printf("<<\n");
	else
		printf("\n");
	printf("-------------------------\n");
	printf("Escolha... ");
	scanf("%d", &dificuldade);
}
int menu_njogos(){
	mostra_espacos();
	printf("---------------------------------\n");
	printf("---Quantos jogos por rodada?---\n");
	printf("---------------------------------\n");
	printf("Escolha (3~999)... ");
	scanf("%d", &rodadas);
}
int menu_nomes(){
	mostra_espacos();
	printf("-------------------------\n");
	printf("---Nome do player 1?---\n");
	printf("-------------------------\n");
	printf("Escolha (12 carac)... ");
	scanf("%s", nomex);
	mostra_espacos();
	printf("-------------------------\n");
	printf("---Nome do player 2?---\n");
	printf("-------------------------\n");
	printf("Escolha (12 carac)... ");
	scanf("%s", nomeo);
	mostra_espacos();
	printf("-------------------------\n");
	printf("---Nomes dos players---\n");
	printf("-------------------------\n");
	printf("(X)%s\n", nomex);
	printf(" VS\n");
	printf("(O)%s\n", nomeo);
	printf("-------------------------\n");
	printf("(1) Confirmar\n");
	printf("(0) Corrigir\n");
	printf("-------------------------\n");
	printf("Escolha... ");
	scanf("%d", &i);
}
int menu_creditos(){
	mostra_espacos();
	printf("------------------------------\n");
	printf("---Criadores dessa bagaca---\n");
	printf("------------------------------\n");
	printf("(J) Jakeline Faria\n");
	printf("(H) Hemerson Barcelos\n");
	printf("------------------------------\n");
	printf("Digite qualquer numero... ");
	scanf("%d", &opcao);
}
void zerar_placar(){
	winx = 0;
	wino = 0;
}
void imprime_tabuleiro(){
	mostra_espacos();
	printf("---------------------\n");
	printf("---Jogo ");
	if(rodada + 1 < 10)
		printf("0");
	printf("%d de ", rodada + 1);
	if(rodadas < 10)
		printf("0");
	printf("%d---\n", rodadas);
	printf("---------------------\n\n");
	for(i = 0; i < 3; i++){
		printf(" ");
		for(j = 0; j < 3; j++){
			if(milf[i][j] == 1)
				printf("X");
			else if(milf[i][j] == -1)
				printf("O");
			else
				printf("-");
			if(j < 2)
				printf(" | ");
			else
				printf("\n");
		}
	}
}
void solicitar_movimento(){
	printf("\nQual seu movimento ");
	if(jogador == 1)
		printf("%s?\n", nomex);
	else
		printf("%s?\n", nomeo);
	printf("Numero entre 1 e 9... ");
	scanf("%d", &i);
}
void verificar_vitoria(){
	if((milf[0] + milf[1] + milf[2]) == 3)
		vitoria = 3;
	else if((milf[3] + milf[4] + milf[5]) == 3)
		vitoria = 3;
	else if((milf[6] + milf[7] + milf[8]) == 3)
		vitoria = 3;
	else if((milf[0] + milf[3] + milf[6]) == 3)
		vitoria = 3;
	else if((milf[1] + milf[4] + milf[7]) == 3)
		vitoria = 3;
	else if((milf[2] + milf[5] + milf[8]) == 3)
		vitoria = 3;
	else if((milf[0] + milf[4] + milf[8]) == 3)
		vitoria = 3;
	else if((milf[2] + milf[4] + milf[6]) == 3)
		vitoria = 3;
	else if((milf[0] + milf[1] + milf[2]) == -3)
		vitoria = -3;
	else if((milf[3] + milf[4] + milf[5]) == -3)
		vitoria = -3;
	else if((milf[6] + milf[7] + milf[8]) == -3)
		vitoria = -3;
	else if((milf[0] + milf[3] + milf[6]) == -3)
		vitoria = -3;
	else if((milf[1] + milf[4] + milf[7]) == -3)
		vitoria = -3;
	else if((milf[2] + milf[5] + milf[8]) == -3)
		vitoria = -3;
	else if((milf[0] + milf[4] + milf[8]) == -3)
		vitoria = -3;
	else if((milf[2] + milf[4] + milf[6]) == -3)
		vitoria = -3;
}
void jogo_multiplayer(){
}

int main(){
	do {
		menu_inicial();
		switch(opcao){
			case NPVSNPC:
				printf("fazer...\n");
				break;
			case NPVSP:
				printf("organizar...\n");
				break;
			case NCONFIG:
				do {
					menu_configuracoes();
				} while(opcao != NSAIR);
				if(opcao == NSAIR)
					opcao++;
				break;
			case NCREDITOS:
				menu_creditos();
				if(opcao == NSAIR)
					opcao++;
				break;
			case NSAIR:
				mostra_espacos();
				printf("-------------------\n");
				printf("---Fim de jogo---\n");
				printf("-------------------\n");
				return 0;
				//default:
		}
	} while(opcao != NSAIR);
	return 0;
}