#include <stdio.h> // xd
#include <stdlib.h> //flush
#include <time.h> //aleat�rio
#include <locale.h> //portugues

// DADO
void d(int opcao){
    int i;
    srand(time(NULL));
    printf("%d ", (rand() % opcao) + 1);
}

// STATUS DE PERSONAGENS
typedef struct personagem{
	float vida, defesa, forca;
}personagem;

// ITENS
typedef struct usoo{
	int foto, analgesico, arte_da_guerra;
}uso;

int main(void)
{
	setlocale(0,"portuguese");
	srand(time(NULL));
	
	personagem player={20, 3, 6}, demonio={30, 5, 8};
	int opcao;
	char prosseguir;
	uso item={1, 1, 1};
	
	printf("Bem Vindo ao Her�i de Programa \nSelecione as op��es: \n1 - Jogar \n2 - N�o Jogar \n3 - Simulador de Dados \n");
	scanf("%d", &opcao);
	switch(opcao)
	{
		// O JOGO
		case 1:
		{
			int combate = 1;
			
			//COMBATE
			while(combate == 1)
			{
				system("cls");
				
				//SPRITE E STATUS DO DEMONIO
				printf("\nInimigo");
				printf("\n  O \n /|\\ \n / \\");
				printf("\nVida: %.0f \nDefesa: %.0f \nFor�a: %.0f\n", demonio.vida, demonio.defesa, demonio.forca);
				
				//SPRITE E STATUS DO PLAYER
				printf("\nProganista (voc�)");
				printf("\n  O \n /|\\ \n / \\");
				printf("\nVida: %.0f \nDefesa: %.0f \nFor�a: %.0f\n", player.vida, player.defesa, player.forca);
				
				//VER SE ALGU�M MORREU
				if(demonio.vida <= 0){
					printf("\nAmea�a derrotada, voc� venceu!"); scanf("%d", &opcao);
					return combate = 2;
				}
				if(player.vida <= 0){
					printf("\nVoc� falhou na sua tarefa, fim de jogo"); scanf("%d", &opcao);
					return combate = 2;
				}
				
				//OP��ES DE COMBATE
				printf("\nOp��es de Combate\n");
				printf("Agredir = 1  Habilidade = 2  Item = 3  : ");
				scanf("%d", &opcao);
				switch(opcao)
				{
					case 1:
					// Agredir
						if(player.forca < demonio.defesa){
							printf("\nVoc� ataca o alvo com tudo que pode, mas n�o surte efeito");
							printf("\nDano: 0");
						}
						else{
							printf("\nVoc� ataca o alvo com tudo que pode.");
							demonio.vida -= player.forca - demonio.defesa;
							printf("\nDano: %.0f", player.forca - demonio.defesa);
						}
						break;
						
					case 2:
					// Habilidade
						printf("Encarar = 1  Reunir Coragem = 2  Engolir o Orgulho = 3  : ");
						scanf("%d", &opcao);
						switch(opcao){
							
							case 1:
							// Encarar
								printf("\nSeu olhar penetra a alma do inimigo, reduzindo sua capacidade de se defender.\n");
								demonio.defesa -= 3;
								if(demonio.defesa < 0){ 
									demonio.defesa = 0;
									printf("Voc� percebe que pior que isso ele n�o fica.\n");
								};
								break;
							
							case 2:
							// Reunir Coragem
								printf("\nVoc� lembra de todos os seus amigos e sua jornada at� aqui, se inspirando para superar seus limites.\n");
								player.forca += 3;
								break;
							
							case 3:
							// Engolir o Orgulho
								printf("\nVoc� se abstem dos sentimentos mundanos para focar no que realmente importa.\n");
								player.defesa += 3;
								break;
							
							default: printf("\nComando inv�lido, perdeu a vez\n"); break;
						}
						break;
						
					case 3:
					// Item
						printf("Foto da Fam�lia = 1  Analg�sicos = 2  Arte da Guerra = 3  : ");
						scanf("%d", &opcao);
						switch(opcao)
						{
							
							case 1:
							// Foto da Fam�lia
								if(item.foto == 0){
									printf("\nVoc� coloca a m�o no seu bolso e sente nada.");
									break;
								};
								printf("\nVer todos da sua fam�lia sorrindo da um aperto em seu cora��o, o sentimento de vingan�a lhe consome.\nA foto se desfaz perante sua �ra.\n");
								player.defesa -= 3;
								player.forca += 6;
								item.foto -= 1;
								break;
							
							case 2:
							// Analg�sicos
								if(item.analgesico == 0){
									printf("\nVoc� coloca a m�o no seu bolso e sente nada.");
									break;
								};
								printf("\nVoc� consome o analg�sico para anular sua dores e se concentrar melhor.\nVoc� consumiu todos.\n");
								player.vida += 10;
								item.analgesico -= 1;
								break;
							
							case 3:
							// Arte da Guerra
								if(item.arte_da_guerra == 0){
									printf("\nVoc� coloca a m�o no seu bolso e sente nada.");
									break;
								};
								printf("\nVoc� folheia o livro e a sensa��o � prazerosa, ampliando suas habilidades t�ticas.\nO livro se desfaz com sua forte folheada.\n");
								player.defesa += 3;
								player.forca -= 3;
								item.arte_da_guerra -= 1;
								break;
								
							default: printf("\nComando inv�lido, perdeu a vez\n"); break;
						
						
						}
						break;	
					default: printf("\nComando inv�lido, perdeu a vez\n"); break;
				}
				
				//TURNO DO INIMIGO
    				opcao = (rand() % 3) + 1;
    				switch(opcao){
    					case 1:
    					// Agredir
							if(demonio.forca < player.defesa){
								printf("\nEle lhe ataca, mas n�o surte efeito.");
								printf("\nDano: 0");
							}
							else{
								printf("\nEle lhe ataca");
								player.vida -= demonio.forca - player.defesa;
								printf("\nDano: %.0f", demonio.forca - player.defesa);
							}
							break;
    					case 2:
    					// Habilidade
    						printf("\nO alvo mexe com seus sentimentos com uma provoca��o, sua perseveran�a decai.");
    						player.forca -= 2;
    						player.defesa -= 2;
    						break;
    					case 3:
    					// Ataque Especial
    						if(demonio.forca < player.defesa){
								printf("\nEle lhe ataca, voc� sente o ataque sugando suas energias, mas n�o lhe causou dano direto.");
								printf("\nDano: 0");
								player.forca -= 2;
								demonio.forca += 2;
							}
							else{
								printf("\nEle lhe ataca, voc� sente o ataque sugando suas energias.");
								player.vida -= demonio.forca - player.defesa;
								printf("\nDano: %.0f", demonio.forca - player.defesa);
								player.forca -= 2;
								demonio.forca += 2;
							}
							break;
					}
				
				// SEM N�MEROS NEGATIVOS
				if(player.forca < 0){
					player.forca = 0;
				}
				if(player.defesa < 0){
					player.defesa = 0;
				}
				if(demonio.forca < 0){
					demonio.forca = 0;
				}
				if(demonio.defesa < 0){
					demonio.defesa = 0;
				}
				
				//PROSSEGUIR
				fflush(stdin);
				printf("\n\nAperte Enter para prosseguir: ");
				prosseguir = getchar();
			}	
		}
			
		// SAIR DO JOGO
		case 2: return 0; break;
		
		// SIMULADOR DE DADOS
		case 3:
			system("cls");
			printf("Bem Vindo ao Simulador de Dados... \nDados suportados: D4, D6, D8, D10, D12, D20, D100\n\n");
			
			int sussy = 1;
            while(sussy == 1)
            {
                printf("Diga o n�mero de lados do dado que ir� usar:");
                    scanf("%d", &opcao);

                switch(opcao)
                {
                    case 4:case 6:case 8:case 10:case 12:case 20:case 100: d(opcao); break;
                    default:
                        printf("\n\nVoc� cometeu um erro, esse dado n�o existe\n");
                }

                printf("\n\nQuer outra rolada? (Digite 1 para sim) "); fflush(stdin);
                scanf("%d", &sussy); if(sussy != 1)return 0;
            };		
	}
	
}
