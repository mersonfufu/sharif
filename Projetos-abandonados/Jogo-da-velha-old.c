#define NPULO 1
#define NNIVEL-1
#define NJOGOS 1
#define NNOMES 2
#define NJOGAR 3
#define NCREDITOS 4
#define NSAIR 0
#include <stdio.h>

int main(){
	char inicio = 'n';
	int i, j, opcao, rodada, turno, winx, wino, vitoria;
	int dificuldade = 666, rodadas = 3, jogador = 1;
	char nomex[12] = "X", nomeo[12] = "O";
	int milf[3][3];
	do {
		if(inicio == 's')
			for(i = 0; i < NPULO; i++)
				printf("\n");
		inicio = 's';
		printf("---------------------------------\n");
		printf("---JOGO DA VELHA MULTIPLAYER---\n");
		printf("---------------------------------\n");
		/*
		printf("(%d) Nivel do jogo ",NNIVEL);
		if(dificuldade==666) printf("(S)\n");
		else printf("(D)\n");
		*/
		printf("(%d) Jogos por rodada ", NJOGOS);
		if(rodadas < 100)
			printf(" ");
		if(rodadas < 10)
			printf(" ");
		printf("(%d)\n", rodadas);
		printf("(%d) Definir nomes\n", NNOMES);
		printf("(%d) Iniciar jogo\n", NJOGAR);
		printf("(%d) Creditos\n", NCREDITOS);
		printf("(%d) Sair\n", NSAIR);
		printf("---------------------------------\n");
		printf("Escolha... ");
		scanf("%d", &opcao);
		switch(opcao){
			/*
			case NNIVEL:
			do{
			for(i=0;i<NPULO;i++) printf("\n");
			printf("-------------------------\n");
			printf("---Nivel do oponente---\n");
			printf("-------------------------\n");
			printf("(1) Decepcionante");
			if(dificuldade==1) printf("<<\n");
			else printf("\n");
			printf("(666) Satanico");
			if(dificuldade==666) printf("<<\n");
			else printf("\n");
			printf("-------------------------\n");
			printf("Escolha... ");
			scanf("%d",&dificuldade);
			} while (dificuldade!=1 && dificuldade!=666);
			break;
			*/
			case NJOGOS:
				do {
					for(i = 0; i < NPULO; i++)
						printf("\n");
					printf("---------------------------------\n");
					printf("---Quantos jogos por rodada?---\n");
					printf("---------------------------------\n");
					printf("Escolha (3~999)... ");
					scanf("%d", &rodadas);
				} while(rodadas == 0 || rodadas < 3 || rodadas > 999);
				break;
			case NNOMES:
				do {
					for(i = 0; i < NPULO; i++)
						printf("\n");
					printf("-------------------------\n");
					printf("---Nome do player 1?---\n");
					printf("-------------------------\n");
					printf("Escolha (12 carac)... ");
					scanf("%s", nomex);
					for(i = 0; i < NPULO; i++)
						printf("\n");
					printf("-------------------------\n");
					printf("---Nome do player 2?---\n");
					printf("-------------------------\n");
					printf("Escolha (12 carac)... ");
					scanf("%s", nomeo);
					for(i = 0; i < NPULO; i++)
						printf("\n");
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
				} while(i != 1);
				break;
			case NJOGAR:
				winx = 0;
				wino = 0;
				//rodada
				for(rodada = 0; rodada < rodadas; rodada++){
					for(i = 0; i < 3; i++)
						for(j = 0; j < 3; j++)
							milf[i][j] = 0;
					//turno
					for(turno = 0; turno <= 9; turno++){
						if(turno >= 0 && turno <= 8){
							do {
								//info
								for(i = 0; i < NPULO; i++)
									printf("\n");
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
								//movimentos
								printf("\nQual seu movimento ");
								if(jogador == 1)
									printf("%s?\n", nomex);
								else
									printf("%s?\n", nomeo);
								printf("Coordenadas entre 1 e 3... ");
								scanf("%d %d", &i, &j);
								//movimentos
							} while(milf[i - 1][j - 1] != 0 || (i != 1 && i != 2 && i != 3) || (j != 1 && j != 2 && j != 3));
							if(jogador == 1)
								milf[i - 1][j - 1] = 1;
							else if(jogador == -1)
								milf[i - 1][j - 1] = -1;
							jogador *= -1;
							if(turno >= 5){
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
								}
								//fim do resultado
							}
							//vitoria
						} else {
							//info
							for(i = 0; i < NPULO; i++)
								printf("\n");
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
			case NCREDITOS:
				for(i = 0; i < NPULO; i++)
					printf("\n");
				printf("------------------------------\n");
				printf("---Criadores dessa bagaca---\n");
				printf("------------------------------\n");
				printf("(J) Jakeline Faria\n");
				printf("(H) Hemerson Barcelos\n");
				printf("------------------------------\n");
				printf("Digite qualquer numero... ");
				scanf("%d", &opcao);
				if(opcao == 0)
					opcao++;
				break;
			case NSAIR:
				for(i = 0; i < NPULO; i++)
					printf("\n");
				printf("-------------------\n");
				printf("---Fim de jogo---\n");
				printf("-------------------\n");
				return 0;
			default:
				break;
		}
	} while(opcao != NSAIR);
	return 0;
}