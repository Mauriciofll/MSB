#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int Tab_Facil[10][10];
int Tab_Medio[15][15];
int Tab_Dificil[20][20];
int Tab_Mult_1[10][10];
int Tab_Mult_2[10][10];

int acertos, erros, vidas, sair, slin, scol, plin, pcol, option, op, nemb, acertos_p1, acertos_p2, erros_p1, erros_p2, vidas_p1, vidas_p2, n1;
int lin, col, x, xl, v1, v2, cont, cont2, ncont, posicao;

void Menu();
void Facil();
void Medio();
void Dificil();
void Manual();
void Multijogador();

void Preenche_Facil();
void Pos_Submarino_Facil();
void Pos_Contratorpedeiro_Facil();
void Pos_Cruzador_Facil();
void Pos_Encouracado_Facil();
void Pos_Porta_Avioes_Facil();

void Preenche_Medio();
void Pos_Submarino_Medio();
void Pos_Contratorpedeiro_Medio();
void Pos_Cruzador_Medio();
void Pos_Encouracado_Medio();
void Pos_Porta_Avioes_Medio();

void Preenche_Dificil();
void Pos_Submarino_Dificil();
void Pos_Contratorpedeiro_Dificil();
void Pos_Cruzador_Dificil();
void Pos_Encouracado_Dificil();
void Pos_Porta_Avioes_Dificil();

void Preenche_Multijogador_1();
void Imprime_Preenche_Multijogador_1();
void Pos_Submarino_Multijogador_1();
void Pos_Contratorpedeiro_Multijogador_1();
void Pos_Cruzador_Multijogador_1();
void Pos_Encouracado_Multijogador_1();
void Pos_Porta_Avioes_Multijogador_1();
void Imprime_Multijogador_1();
void Imprime_Multijogador_1_Resultado();
	
void Preenche_Multijogador_2();
void Imprime_Preenche_Multijogador_2();
void Pos_Submarino_Multijogador_2();
void Pos_Contratorpedeiro_Multijogador_2();
void Pos_Cruzador_Multijogador_2();
void Pos_Encouracado_Multijogador_2();
void Pos_Porta_Avioes_Multijogador_2();
void Imprime_Multijogador_2();
void Imprime_Multijogador_2_Resultado();

void Imprime_Facil();
void Imprime_Facil_Resultado();
void Imprime_Medio();
void Imprime_Medio_Resultado();
void Imprime_Dificil();
void Imprime_Dificil_Resultado();

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

int main(){
	Menu();
}

void Menu(){
	
	do{
		system("cls");
		printf("+===============================================+\n");
		printf("|            MSB - MINI SHIP BATTLE             |\n");
		printf("+===============================================+\n");
		printf("\n1. Facil");
		printf("\n2. Medio");
		printf("\n3. Dificil");
		printf("\n4. Multijogador");
		printf("\n5. Manual");
		printf("\n0. Sair");
		printf("\n\nEscolha uma Dificuldade ou 0 Para Sair: ");
		scanf("%d", &option);
		
		switch(option){
			case 1: Facil();
					break;
			case 2: Medio();
					break;
			case 3: Dificil();
					break;
			case 4: Multijogador();
					break;
			case 5: Manual();
					break;
			case 0: break;
			default: printf("\nOpção Invalida!!");
		}
	}while(option != 0);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Facil(){
	
	Preenche_Facil();
	Pos_Submarino_Facil();
	Pos_Contratorpedeiro_Facil();
	Pos_Cruzador_Facil();
	Pos_Encouracado_Facil();
	Pos_Porta_Avioes_Facil();
	
	acertos = 0;
	erros = 0;
	vidas = 50;
	sair = 0;
	
	do {
		system("cls");
		printf("+=========================================+\n");
		printf("|               MODO  FACIL               |\n");
		printf("+=========================================+\n");
		Imprime_Facil();
		
		printf("\n+=========================================+");
		printf("\nQuantidade de SUBMARINOS (S): %d", 1);
		printf("\nQuantidade de CONTRATORPEDEIROS (T): %d", 3);
		printf("\nQuantidade de CRUZADORES (C): %d", 3);
		printf("\nQuantidade de ENCOURACADOS (E): %d", 2);
		printf("\nQuantidade de PORTA-AVIOES (P): %d\n", 1);
		printf("+=========================================+\n");
		printf("\nQuantidade de Acertos: %d", acertos);
		printf("\nQuantidade de Erros: %d", erros);
		printf("\nQuantidade de Vidas: %d", vidas);
		
		printf("\n\nDigite -1 Para COLUNA E Para LINHA Para Encerrar!!");
		
		printf("\n\nEscolha Uma LINHA: ");
		scanf("%d", &slin);
		printf("Escolha Uma COLUNA: ");
		scanf("%d", &scol);
		printf("\n");
		
		if(scol >= 0 && scol <= 9 && slin >= 0 && slin <= 9){
			if(Tab_Facil[slin][scol] == 0){
				Tab_Facil[slin][scol] = -1;
				erros = erros + 1;
				vidas = vidas - 1;
			} else{
				if(Tab_Facil[slin][scol] == 1 || Tab_Facil[slin][scol] == 2 || Tab_Facil[slin][scol] == 3 || Tab_Facil[slin][scol] == 4 || Tab_Facil[slin][scol] == 5){
					if(Tab_Facil[slin][scol] == 1){
						Tab_Facil[slin][scol] = 10;
						acertos = acertos + 1;
					} else {
						if(Tab_Facil[slin][scol] == 2){
							Tab_Facil[slin][scol] = 20;
							acertos = acertos + 1;
						} else {
							if(Tab_Facil[slin][scol] == 3){
								Tab_Facil[slin][scol] = 30;
								acertos = acertos + 1;	
							} else {
								if(Tab_Facil[slin][scol] == 4){
									Tab_Facil[slin][scol] = 40;
									acertos = acertos + 1;	
								} else {
									if(Tab_Facil[slin][scol] == 5){
										Tab_Facil[slin][scol] = 50;
										acertos = acertos + 1;	
									}
								}
							}
						}
					}
				}
			}
		} else{
			if(scol == -1 && slin == -1){
				sair = 1;
			} else{
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}
	}while(vidas != 0 && acertos != 29 && sair != 1);
	
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n\n");
			Imprime_Facil_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(vidas == 0){
		
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|               VOCE PERDEU               |\n");
			printf("+=========================================+\n\n");
			Imprime_Facil_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(acertos == 29){
		
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|           PARABENS VOCE VENCEU          |\n");
			printf("+=========================================+\n\n");
			Imprime_Facil_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Medio(){
		
	Preenche_Medio();
	Pos_Submarino_Medio();
	Pos_Contratorpedeiro_Medio();
	Pos_Cruzador_Medio();
	Pos_Encouracado_Medio();
	Pos_Porta_Avioes_Medio();
	
	acertos = 0;
	erros = 0;
	vidas = 60;
	sair = 0;
	
	do {
		system("cls");
		printf("\t\t\t\t\t+=================================================+\n");
		printf("\t\t\t\t\t|                   MODO  MEDIO                   |\n");
		printf("\t\t\t\t\t+=================================================+\n");
		Imprime_Medio();
		
		printf("\n+==================================================================+");
		printf("\nQuantidade de SUBMARINOS (S): %d", 2);
		printf("\nQuantidade de CONTRATORPEDEIROS (T): %d", 4);
		printf("\nQuantidade de CRUZADORES (C): %d", 4);
		printf("\nQuantidade de ENCOURACADOS (E): %d", 3);
		printf("\nQuantidade de PORTA-AVIOES (P): %d\n", 2);
		printf("+==================================================================+\n");
		printf("\nQuantidade de Acertos: %d", acertos);
		printf("\nQuantidade de Erros: %d", erros);
		printf("\nQuantidade de Vidas: %d", vidas);
		
		printf("\n\nDigite -1 Para COLUNA E Para LINHA Para Encerrar!!");

		printf("\n\nEscolha Uma LINHA: ");
		scanf("%d", &slin);
		printf("Escolha Uma COLUNA: ");
		scanf("%d", &scol);
		printf("\n");
		
		if(scol >= 0 && scol <= 14 && slin >= 0 && slin <= 14){
			if(Tab_Medio[slin][scol] == 0){
				Tab_Medio[slin][scol] = -1;
				erros = erros + 1;
				vidas = vidas - 1;
			} else{
				if(Tab_Medio[slin][scol] == 1 || Tab_Medio[slin][scol] == 2 || Tab_Medio[slin][scol] == 3 || Tab_Medio[slin][scol] == 4 || Tab_Medio[slin][scol] == 5){
					if(Tab_Medio[slin][scol] == 1){
						Tab_Medio[slin][scol] = 10;
						acertos = acertos + 1;
					} else {
						if(Tab_Medio[slin][scol] == 2){
							Tab_Medio[slin][scol] = 20;
							acertos = acertos + 1;
						} else {
							if(Tab_Medio[slin][scol] == 3){
								Tab_Medio[slin][scol] = 30;
								acertos = acertos + 1;	
							} else {
								if(Tab_Medio[slin][scol] == 4){
									Tab_Medio[slin][scol] = 40;
									acertos = acertos + 1;	
								} else {
									if(Tab_Medio[slin][scol] == 5){
										Tab_Medio[slin][scol] = 50;
										acertos = acertos + 1;	
									}
								}
							}
						}
					}
				}
			}
		} else{
			if(scol == -1 && slin == -1){
				sair = 1;
			} else{
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}
	}while(vidas != 0 && acertos != 44 && sair != 1);
	
	if(sair == 1){
		
		do{
			system("cls");
			printf("\t\t\t\t\t+=================================================+\n");
			printf("\t\t\t\t\t|                  VOCE ENCERROU                  |\n");
			printf("\t\t\t\t\t+=================================================+\n\n");
			Imprime_Medio_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(vidas == 0){
		
		do{
			system("cls");
			printf("\t\t\t\t\t+=================================================+\n");
			printf("\t\t\t\t\t|                   VOCE PERDEU                   |\n");
			printf("\t\t\t\t\t+=================================================+\n\n");
			Imprime_Medio_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(acertos == 44){
		
		do{
			system("cls");
			printf("\t\t\t\t\t+=================================================+\n");
			printf("\t\t\t\t\t|              PARABENS VOCE VENCEU               |\n");
			printf("\t\t\t\t\t+=================================================+\n\n");
			Imprime_Medio_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Dificil(){
		
	Preenche_Dificil();
	Pos_Submarino_Dificil();
	Pos_Contratorpedeiro_Dificil();
	Pos_Cruzador_Dificil();
	Pos_Encouracado_Dificil();
	Pos_Porta_Avioes_Dificil();
	
	acertos = 0;
	erros = 0;
	vidas = 70;
	sair = 0;
	
	do {
		system("cls");
		printf("\t\t\t\t\t\t+=========================================================================+\n");
		printf("\t\t\t\t\t\t|                              MODO  DIFICIL                              |\n");
		printf("\t\t\t\t\t\t+=========================================================================+\n");
		Imprime_Dificil();
		
		printf("\n+==================================================================+");
		printf("\nQuantidade de SUBMARINOS (S): %d", 3);
		printf("\nQuantidade de CONTRATORPEDEIROS (T): %d", 5);
		printf("\nQuantidade de CRUZADORES (C): %d", 5);
		printf("\nQuantidade de ENCOURACADOS (E): %d", 4);
		printf("\nQuantidade de PORTA-AVIOES (P): %d\n", 3);
		printf("+==================================================================+\n");
		printf("\nQuantidade de Acertos: %d", acertos);
		printf("\nQuantidade de Erros: %d", erros);
		printf("\nQuantidade de Vidas: %d", vidas);
		
		printf("\n\nDigite -1 Para COLUNA E Para LINHA Para Encerrar!!");		
		
		printf("\n\nEscolha Uma LINHA: ");
		scanf("%d", &slin);
		printf("Escolha Uma COLUNA: ");
		scanf("%d", &scol);
		printf("\n");
		
		if(scol >= 0 && scol <= 19 && slin >= 0 && slin <= 19){
			if(Tab_Dificil[slin][scol] == 0){
				Tab_Dificil[slin][scol] = -1;
				erros = erros + 1;
				vidas = vidas - 1;
			} else{
				if(Tab_Dificil[slin][scol] == 1 || Tab_Dificil[slin][scol] == 2 || Tab_Dificil[slin][scol] == 3 || Tab_Dificil[slin][scol] == 4 || Tab_Dificil[slin][scol] == 5){
					if(Tab_Dificil[slin][scol] == 1){
						Tab_Dificil[slin][scol] = 10;
						acertos = acertos + 1;
					} else {
						if(Tab_Dificil[slin][scol] == 2){
							Tab_Dificil[slin][scol] = 20;
							acertos = acertos + 1;
						} else {
							if(Tab_Dificil[slin][scol] == 3){
								Tab_Dificil[slin][scol] = 30;
								acertos = acertos + 1;	
							} else {
								if(Tab_Dificil[slin][scol] == 4){
									Tab_Dificil[slin][scol] = 40;
									acertos = acertos + 1;	
								} else {
									if(Tab_Dificil[slin][scol] == 5){
										Tab_Dificil[slin][scol] = 50;
										acertos = acertos + 1;	
									}
								}
							}
						}
					}
				}
			}	
		} else{
			if(scol == -1 && slin == -1){
				sair = 1;
			} else{
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}
	}while(vidas != 0 && acertos != 59 && sair != 1);
	
	if(sair == 1){
		
		do{
			system("cls");
			printf("\t\t\t\t\t\t+=========================================================================+\n");
			printf("\t\t\t\t\t\t|                              VOCE ENCERROU                              |\n");
			printf("\t\t\t\t\t\t+=========================================================================+\n\n");
			Imprime_Dificil_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(vidas == 0){
		
		do{
			system("cls");
			printf("\t\t\t\t\t\t+=========================================================================+\n");
			printf("\t\t\t\t\t\t|                               VOCE PERDEU                               |\n");
			printf("\t\t\t\t\t\t+=========================================================================+\n\n");
			Imprime_Dificil_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(acertos == 59){
		
		do{
			system("cls");
			printf("\t\t\t\t\t\t+========================================================================+\n");
			printf("\t\t\t\t\t\t|                          PARABENS VOCE VENCEU                          |\n");
			printf("\t\t\t\t\t\t+========================================================================+\n\n");
			Imprime_Dificil_Resultado();
			printf("\n\nQuantidade de Acertos: %d", acertos);
			printf("\nQuantidade de Erros: %d", erros);
			printf("\nQuantidade de Vidas: %d", vidas);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Multijogador(){
	
	Preenche_Multijogador_1();
	Pos_Submarino_Multijogador_1();
	Pos_Contratorpedeiro_Multijogador_1();
	Pos_Cruzador_Multijogador_1();
	Pos_Encouracado_Multijogador_1();
	Pos_Porta_Avioes_Multijogador_1();
	
	Preenche_Multijogador_2();
	Pos_Submarino_Multijogador_2();
	Pos_Contratorpedeiro_Multijogador_2();
	Pos_Cruzador_Multijogador_2();
	Pos_Encouracado_Multijogador_2();
	Pos_Porta_Avioes_Multijogador_2();
	
	acertos_p1 = 0;
	acertos_p2 = 0;
	erros_p1 = 0;
	erros_p2 = 0;
	vidas_p1 = 60;
	vidas_p2 = 60;
	sair = 0;
	
	do{
		do{
			system("cls");
			n1 = 0;
			printf("+===============================================+\n");
			printf("|               MODO MULTIJOGADOR               |\n");
			printf("+===============================================+\n");
			printf("|               VEZ DE: JOGADOR 1               |\n");
			printf("+===============================================+\n");
			
			Imprime_Multijogador_2();
			
			printf("\n+=========================================+");
			printf("\nQuantidade de SUBMARINOS (S): %d", 1);
			printf("\nQuantidade de CONTRATORPEDEIROS (T): %d", 3);
			printf("\nQuantidade de CRUZADORES (C): %d", 3);
			printf("\nQuantidade de ENCOURACADOS (E): %d", 2);
			printf("\nQuantidade de PORTA-AVIOES (P): %d\n", 1);
			printf("+=========================================+\n");
			printf("\nQuantidade de Acertos: %d", acertos_p1);
			printf("\nQuantidade de Erros: %d", erros_p1);
			printf("\nQuantidade de Vidas: %d", vidas_p1);
			
			printf("\n\nDigite -1 Para COLUNA E Para LINHA Para Encerrar!!");
			
			printf("\n\nEscolha Uma LINHA: ");
			scanf("%d", &slin);
			printf("Escolha Uma COLUNA: ");
			scanf("%d", &scol);
			printf("\n");
			
			if(scol >= 0 && scol <= 9 && slin >= 0 && slin <= 9){
				if(Tab_Mult_2[slin][scol] == 0){
					Tab_Mult_2[slin][scol] = -1;
					erros_p1 = erros_p1 + 1;
					vidas_p1 = vidas_p1 - 1;
					n1 = 1;
				} else{
					if(Tab_Mult_2[slin][scol] == 1 || Tab_Mult_2[slin][scol] == 2 || Tab_Mult_2[slin][scol] == 3 || Tab_Mult_2[slin][scol] == 4 || Tab_Mult_2[slin][scol] == 5){
						if(Tab_Mult_2[slin][scol] == 1){
							Tab_Mult_2[slin][scol] = 10;
							acertos_p1 = acertos_p1 + 1;
							n1 = 1;
						} else {
							if(Tab_Mult_2[slin][scol] == 2){
								Tab_Mult_2[slin][scol] = 20;
								acertos_p1 = acertos_p1 + 1;
								n1 = 1;
							} else {
								if(Tab_Mult_2[slin][scol] == 3){
									Tab_Mult_2[slin][scol] = 30;
									acertos_p1 = acertos_p1 + 1;
									n1 = 1;	
								} else {
									if(Tab_Mult_2[slin][scol] == 4){
										Tab_Mult_2[slin][scol] = 40;
										acertos_p1 = acertos_p1 + 1;
										n1 = 1;	
									} else {
										if(Tab_Mult_2[slin][scol] == 5){
											Tab_Mult_2[slin][scol] = 50;
											acertos_p1 = acertos_p1 + 1;
											n1 = 1;	
										}
									}
								}
							}
						}
					}
				}
			} else{
				if(scol == -1 && slin == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\n\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}while(n1 != 1);
		
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|               VEZ DE: JOGADOR 2               |\n");
		printf("+===============================================+\n");
		
		Imprime_Multijogador_1();
			
		printf("\n+=========================================+");
		printf("\nQuantidade de SUBMARINOS (S): %d", 1);
		printf("\nQuantidade de CONTRATORPEDEIROS (T): %d", 3);
		printf("\nQuantidade de CRUZADORES (C): %d", 3);
		printf("\nQuantidade de ENCOURACADOS (E): %d", 2);
		printf("\nQuantidade de PORTA-AVIOES (P): %d\n", 1);
		printf("+=========================================+\n");
		printf("\nQuantidade de Acertos: %d", acertos_p2);
		printf("\nQuantidade de Erros: %d", erros_p2);
		printf("\nQuantidade de Vidas: %d", vidas_p2);
		
		printf("\n\nDigite -1 Para COLUNA E Para LINHA Para Encerrar!!");
		
		printf("\n\nEscolha Uma LINHA: ");
		scanf("%d", &slin);
		printf("Escolha Uma COLUNA: ");
		scanf("%d", &scol);
		printf("\n");
		
		if(scol >= 0 && scol <= 9 && slin >= 0 && slin <= 9){
			if(Tab_Mult_1[slin][scol] == 0){
				Tab_Mult_1[slin][scol] = -1;
				erros_p2 = erros_p2 + 1;
				vidas_p2 = vidas_p2 - 1;
			} else{
				if(Tab_Mult_1[slin][scol] == 1 || Tab_Mult_1[slin][scol] == 2 || Tab_Mult_1[slin][scol] == 3 || Tab_Mult_1[slin][scol] == 4 || Tab_Mult_1[slin][scol] == 5){
					if(Tab_Mult_1[slin][scol] == 1){
						Tab_Mult_1[slin][scol] = 10;
						acertos_p2 = acertos_p2 + 1;
					} else {
						if(Tab_Mult_1[slin][scol] == 2){
							Tab_Mult_1[slin][scol] = 20;
							acertos_p2 = acertos_p2 + 1;
						} else {
							if(Tab_Mult_1[slin][scol] == 3){
								Tab_Mult_1[slin][scol] = 30;
								acertos_p2 = acertos_p2 + 1;
							} else {
								if(Tab_Mult_1[slin][scol] == 4){
									Tab_Mult_1[slin][scol] = 40;
									acertos_p2 = acertos_p2 + 1;
								} else {
									if(Tab_Mult_1[slin][scol] == 5){
										Tab_Mult_1[slin][scol] = 50;
										acertos_p2 = acertos_p2 + 1;	
									}
								}
							}
						}
					}
				}
			}
		} else{
			if(scol == -1 && slin == -1){
				sair = 1;
			} else{
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}
	}while(vidas_p1 != 0 && vidas_p2 != 0 && acertos_p1 !=29  && acertos_p2 != 29 && sair != 1);
	
	if(sair == 1){
		do{
			system("cls");
			printf("+================================================+\n");
			printf("|                 JOGO ENCERRADO                 |\n");
			printf("+================================================+\n\n\n");
			
			printf("+===============================================+\n");
			printf("|               MODO MULTIJOGADOR               |\n");
			printf("+===============================================+\n");
			printf("|                   JOGADOR 1                   |\n");
			printf("+===============================================+\n\n");
			Imprime_Multijogador_1_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 1: %d", acertos_p1);			
			printf("\nQuantidade de Erros Do Jogador 1: %d", erros_p1);			
			printf("\nQuantidade de Vidas Do Jogador 1: %d", vidas_p1);	
			printf("\n");		
			printf("+===============================================+\n");
			printf("|               MODO MULTIJOGADOR               |\n");
			printf("+===============================================+\n");
			printf("|                   JOGADOR 2                   |\n");
			printf("+===============================================+\n\n");
			Imprime_Multijogador_2_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 2: %d", acertos_p2);
			printf("\nQuantidade de Erros Do Jogador 2: %d", erros_p2);
			printf("\nQuantidade de Vidas Do Jogador 2: %d", vidas_p2);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	if(acertos_p1 == 29){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|           VITORIA DO JOGADOR 1          |\n");
			printf("+=========================================+\n\n");
			Imprime_Multijogador_2_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 1: %d", acertos_p1);
			printf("\nQuantidade de Erros Do Jogador 1: %d", erros_p1);	
			printf("\nQuantidade de Vidas Do Jogador 1: %d", vidas_p1);					
			printf("+=========================================+\n");
			printf("|           NAVIOS DO JOGADOR 1           |\n");
			printf("+=========================================+\n\n");
			Imprime_Multijogador_1_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 2: %d", acertos_p2);
			printf("\nQuantidade de Erros Do Jogador 2: %d", erros_p2);
			printf("\nQuantidade de Vidas Do Jogador 2: %d", vidas_p2);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(acertos_p2 == 29){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|           VITORIA DO JOGADOR 2          |\n");
			printf("+=========================================+\n\n");
			Imprime_Multijogador_1_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 1: %d", acertos_p2);
			printf("\nQuantidade de Erros Do Jogador 1: %d", erros_p2);	
			printf("\nQuantidade de Vidas Do Jogador 1: %d", vidas_p2);					
			printf("+=========================================+\n");
			printf("|           NAVIOS DO JOGADOR 2           |\n");
			printf("+=========================================+\n\n");
			Imprime_Multijogador_2_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 2: %d", acertos_p1);
			printf("\nQuantidade de Erros Do Jogador 2: %d", erros_p1);
			printf("\nQuantidade de Vidas Do Jogador 2: %d", vidas_p1);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(acertos_p1 == 29 && acertos_p2 == 29){
		do{
			system("cls");
			printf("+=================================================+\n");
			printf("|           EMPATE - NAVIOS DO JOGADOR 1          |\n");
			printf("+=================================================+\n\n");
			Imprime_Multijogador_2_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 1: %d", acertos_p1);
			printf("\nQuantidade de Erros Do Jogador 1: %d", erros_p1);	
			printf("\nQuantidade de Vidas Do Jogador 1: %d", vidas_p1);					
			printf("+=================================================+\n");
			printf("|           EMPATE - NAVIOS DO JOGADOR 2          |\n");
			printf("+=================================================+\n\n");
			Imprime_Multijogador_1_Resultado();
			printf("\n\nQuantidade de Acertos Do Jogador 2: %d", acertos_p2);
			printf("\nQuantidade de Erros Do Jogador 2: %d", erros_p2);
			printf("\nQuantidade de Vidas Do Jogador 2: %d", vidas_p2);
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Manual(){
	system("cls");
	printf("+====================================================================================================+\n");
	printf("|                                       MSB - MINI SHIP BATTLE                                       |\n");
	printf("+====================================================================================================+\n");
	printf("|                                         MANUAL E DESCRICAO                                         |\n");
	printf("+====================================================================================================+\n");
	printf("\n  DESCRICAO DO JOGO:");
	printf("\n");
	printf("\n  Mini Ship Battle consiste em um jogo de tabuleiro com varios navios espalhados por ele. O objetivo");
	printf("\n  do jogador sera encontrar os navios usando as colunas e linhas como referencia. O jogador possuira");
	printf("\n  um numero limitado de erros devendo encontrar todas as embarcacoes antes que suas vidas acabem, ou");
	printf("\n  entao, ira falhar na missao.");
	printf("\n\n");
	printf("+----------------------------------------------------------------------------------------------------+\n");
	printf("\n  CLASSES DE NAVIOS:");
	printf("\n");
	printf("\n  SUBMARINOS: Representados pela letra S, ocupam apenas 1 posicao do tabuleiro;");
	printf("\n");
	printf("\n  CONTRATORPEDEIROS: Representados pela letra T, ocupam 2 posicoes do tabuleiro;");
	printf("\n");
	printf("\n  CRUZADORES: Representados pela letra C, ocupam 3 posicoes do tabuleiro;");
	printf("\n");
	printf("\n  ENCOURACADOS: Representados pela letra E, ocupam 4 posicoes do tabuleiro;");
	printf("\n");
	printf("\n  PORTA-AVIOES: Representados pela letra P, ocupam 5 posicoes do tabuleiro;");
	printf("\n\n");
	printf("+----------------------------------------------------------------------------------------------------+\n");
	printf("\n  TAMANHO DO TABULEIRO E QUANTIDADE DE NAVIOS E VIDAS POR NIVEL DE DIFICULDADE:");
	printf("\n");
	printf("\n  MODO FACIL: Tabuleiro 10x10 - 50 vidas");
	printf("\n");
	printf("\n  SUBMARINOS: 1");
	printf("\n  CONTRATORPEDEIROS: 3");
	printf("\n  CRUZADORES: 3");
	printf("\n  ENCOURACADOS: 2");
	printf("\n  PORTA-AVIOES: 1");
	printf("\n");
	printf("\n  MODO MEDIO: Tabuleiro 15x15 - 60 vidas");
	printf("\n");
	printf("\n  SUBMARINOS: 2");
	printf("\n  CONTRATORPEDEIROS: 4");
	printf("\n  CRUZADORES: 4");
	printf("\n  ENCOURACADOS: 3");
	printf("\n  PORTA-AVIOES: 2");
	printf("\n");
	printf("\n  MODO DIFICIL: Tabuleiro 20x20 - 70 vidas");
	printf("\n");
	printf("\n  SUBMARINOS: 3");
	printf("\n  CONTRATORPEDEIROS: 5");
	printf("\n  CRUZADORES: 5");
	printf("\n  ENCOURACADOS: 4");
	printf("\n  PORTA-AVIOES: 3");
	printf("\n\n");	
	printf("+----------------------------------------------------------------------------------------------------+\n");
	printf("\n  COMO JOGAR:");
	printf("\n");
	printf("\n  Ao selecionar uma dificuldade o jogador devera escolher uma posicao aleatoria no tabuleirio usando");
	printf("\n  as linhas e colunas de referencia. Ao escolher, sera revelado o que havia na coordenada escolhida,");
	printf("\n  sendo que, se um '~' aparecer, o jogador nao acertou nenhuma embarcacao, apenas a agua, mas, se um");
	printf("\n  'S', 'T', 'C', 'E' ou 'P' for revelado, o jogador encontrou um dos navios correspondentes de acordo");
	printf("\n  com a tabela CLASSES DE NAVIOS. O jogo termina ao encontrar todas as embarcacoes ou quando acabarem");
	printf("\n  todas as vidas do jogador.");
	printf("\n\n");
	printf("+----------------------------------------------------------------------------------------------------+\n");
	printf("\n  BOA SORTE E DIVIRTA-SE COM O MSB - MINI SHIP BATTLE :)");
	printf("\n\n\nPressione Qualquer Tecla Para Voltar Ao Menu: ");
	getch();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Preenche_Facil(){
	
	for(lin = 0; lin < 10; lin++){
		for(col = 0; col < 10; col++){
			Tab_Facil[lin][col] = 0;
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Submarino_Facil(){
	
	srand(time(NULL));
	for(cont = 0; cont < 1; cont++){
		ncont = 0;
		while(ncont != 1){
			v1 = rand();
			col = v1 % 10;
			v2 = rand();
			lin = v2 % 10;
			if(Tab_Facil[lin][col] == 0){
				Tab_Facil[lin][col] = 1;
			ncont = 1;
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Contratorpedeiro_Facil(){

	srand(time(NULL));
	for(cont = 0; cont < 3; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 9;
				v2 = rand();
				lin = v2 % 10;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin][col + 1] == 0){
					for(cont2 = 0; cont2 < 2; cont2++){
						Tab_Facil[lin][col] = 2;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 10;
				v2 = rand();
				lin = v2 % 9;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin + 1][col] == 0){
					for(cont2 = 0; cont2 < 2; cont2++){
						Tab_Facil[lin][col] = 2;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Cruzador_Facil(){
	
	srand(time(NULL));
	for(cont = 0; cont < 3; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 8;
				v2 = rand();
				lin = v2 % 10;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin][col + 1] == 0 && Tab_Facil[lin][col + 2] == 0){
					for(cont2 = 0; cont2 < 3; cont2++){
						Tab_Facil[lin][col] = 3;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 10;
				v2 = rand();
				lin = v2 % 8;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin + 1][col] == 0 && Tab_Facil[lin + 2][col] == 0){
					for(cont2 = 0; cont2 < 3; cont2++){
						Tab_Facil[lin][col] = 3;
						lin = lin + 1;
					}
					ncont = 1;
				} 
			}			
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Encouracado_Facil(){

	srand(time(NULL));
	for(cont = 0; cont < 2; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 7;
				v2 = rand();
				lin = v2 % 10;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin][col + 1] == 0 && Tab_Facil[lin][col + 2] == 0 && Tab_Facil[lin][col + 3] == 0){
					for(cont2 = 0; cont2 < 4; cont2++){
						Tab_Facil[lin][col] = 4;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 10;
				v2 = rand();
				lin = v2 % 7;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin + 1][col] == 0 && Tab_Facil[lin + 2][col] == 0 && Tab_Facil[lin + 3][col] == 0){
					for(cont2 = 0; cont2 < 4; cont2++){
						Tab_Facil[lin][col] = 4;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Porta_Avioes_Facil(){

	srand(time(NULL));
	for(cont = 0; cont < 1; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 6;
				v2 = rand();
				lin = v2 % 10;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin][col + 1] == 0 && Tab_Facil[lin][col + 2] == 0 && Tab_Facil[lin][col + 3] == 0 && Tab_Facil[lin][col + 4] == 0){
					for(cont2 = 0; cont2 < 5; cont2++){
						Tab_Facil[lin][col] = 5;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 10;
				v2 = rand();
				lin = v2 % 6;
				if(Tab_Facil[lin][col] == 0 && Tab_Facil[lin + 1][col] == 0 && Tab_Facil[lin + 2][col] == 0 && Tab_Facil[lin + 3][col] == 0 && Tab_Facil[lin + 4][col] == 0){
					for(cont2 = 0; cont2 < 5; cont2++){
						Tab_Facil[lin][col] = 5;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Facil(){
	
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ", col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Facil[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Facil[lin][col] == 1){
					printf(" - ");
					} else {
						if (Tab_Facil[lin][col] == 2){
						printf(" - ");
						} else {
							if (Tab_Facil[lin][col] == 3){
							printf(" - ");
							} else {
								if (Tab_Facil[lin][col] == 4){
								printf(" - ");
								} else {
									if (Tab_Facil[lin][col] == 5){
									printf(" - ");
									} else {
										if (Tab_Facil[lin][col] == -1){
										printf(" ~ ");
										} else {
											if (Tab_Facil[lin][col] == 10){
											printf(" S ");
											} else {
												if (Tab_Facil[lin][col] == 20){
												printf(" T ");
												} else {
													if (Tab_Facil[lin][col] == 30){
													printf(" C ");
													} else {
														if (Tab_Facil[lin][col] == 40){
														printf(" E ");
														} else {
															if (Tab_Facil[lin][col] == 50){
															printf(" P ");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Facil_Resultado(){
	
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ",col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Facil[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Facil[lin][col] == 1){
					printf(" S ");
					} else {
						if (Tab_Facil[lin][col] == 2){
						printf(" T ");
						} else {
							if (Tab_Facil[lin][col] == 3){
							printf(" C ");
							} else {
								if (Tab_Facil[lin][col] == 4){
								printf(" E ");
								} else {
									if (Tab_Facil[lin][col] == 5){
									printf(" P ");
									} else {
										if (Tab_Facil[lin][col] == -1){
										printf(" ~ ");
										} else {
											if (Tab_Facil[lin][col] == 10){
											printf(" S ");
											} else {
												if (Tab_Facil[lin][col] == 20){
												printf(" T ");
												} else {
													if (Tab_Facil[lin][col] == 30){
													printf(" C ");
													} else {
														if (Tab_Facil[lin][col] == 40){
														printf(" E ");
														} else {
															if (Tab_Facil[lin][col] == 50){
															printf(" P ");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Preenche_Medio(){
	
	for(lin = 0; lin < 15; lin++){
		for(col = 0; col < 15; col++){
			Tab_Medio[lin][col] = 0;
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Submarino_Medio(){
	
	srand(time(NULL));
	for(cont = 0; cont < 2; cont++){
		ncont = 0;
		while(ncont != 1){
			v1 = rand();
			col = v1 % 15;
			v2 = rand();
			lin = v2 % 15;
			if(Tab_Medio[lin][col] == 0){
				Tab_Medio[lin][col] = 1;
			ncont = 1;
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Contratorpedeiro_Medio(){
	
	srand(time(NULL));
	for(cont = 0; cont < 4; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 14;
				v2 = rand();
				lin = v2 % 15;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin][col + 1] == 0){
					for(cont2 = 0; cont2 < 2; cont2++){
						Tab_Medio[lin][col] = 2;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 15;
				v2 = rand();
				lin = v2 % 14;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin + 1][col] == 0){
					for(cont2 = 0; cont2 < 2; cont2++){
						Tab_Medio[lin][col] = 2;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Cruzador_Medio(){	

	srand(time(NULL));
	for(cont = 0; cont < 4; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 13;
				v2 = rand();
				lin = v2 % 15;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin][col + 1] == 0 && Tab_Medio[lin][col + 2] == 0){
					for(cont2 = 0; cont2 < 3; cont2++){
						Tab_Medio[lin][col] = 3;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 15;
				v2 = rand();
				lin = v2 % 13;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin + 1][col] == 0 && Tab_Medio[lin + 2][col] == 0){
					for(cont2 = 0; cont2 < 3; cont2++){
						Tab_Medio[lin][col] = 3;
						lin = lin + 1;
					}
					ncont = 1;
				} 
			}			
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Encouracado_Medio(){
	
	srand(time(NULL));
	for(cont = 0; cont < 3; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 12;
				v2 = rand();
				lin = v2 % 15;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin][col + 1] == 0 && Tab_Medio[lin][col + 2] == 0 && Tab_Medio[lin][col + 3] == 0){
					for(cont2 = 0; cont2 < 4; cont2++){
						Tab_Medio[lin][col] = 4;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 15;
				v2 = rand();
				lin = v2 % 12;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin + 1][col] == 0 && Tab_Medio[lin + 2][col] == 0 && Tab_Medio[lin + 3][col] == 0){
					for(cont2 = 0; cont2 < 4; cont2++){
						Tab_Medio[lin][col] = 4;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Porta_Avioes_Medio(){
	
	srand(time(NULL));
	for(cont = 0; cont < 2; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 11;
				v2 = rand();
				lin = v2 % 15;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin][col + 1] == 0 && Tab_Medio[lin][col + 2] == 0 && Tab_Medio[lin][col + 3] == 0 && Tab_Medio[lin][col + 4] == 0){
					for(cont2 = 0; cont2 < 5; cont2++){
						Tab_Medio[lin][col] = 5;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 15;
				v2 = rand();
				lin = v2 % 11;
				if(Tab_Medio[lin][col] == 0 && Tab_Medio[lin + 1][col] == 0 && Tab_Medio[lin + 2][col] == 0 && Tab_Medio[lin + 3][col] == 0 && Tab_Medio[lin + 4][col] == 0){
					for(cont2 = 0; cont2 < 5; cont2++){
						Tab_Medio[lin][col] = 5;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Medio(){
	
	printf("\n\t");
	for(col = 0; col < 15; col++){
		printf(" %d\t", col);
	}
	printf("\n\n");
	for(lin = 0; lin < 15; lin++){
		printf("    %d\t", lin);
		for(col = 0; col < 15; col++){
			if (Tab_Medio[lin][col] == 0){
				printf(" -\t");
				} else{
					if (Tab_Medio[lin][col] == 1){
					printf(" -\t");
					} else {
						if (Tab_Medio[lin][col] == 2){
						printf(" -\t");
						} else {
							if (Tab_Medio[lin][col] == 3){
							printf(" -\t");
							} else {
								if (Tab_Medio[lin][col] == 4){
								printf(" -\t");
								} else {
									if (Tab_Medio[lin][col] == 5){
									printf(" -\t");
									} else {
										if (Tab_Medio[lin][col] == -1){
										printf(" ~\t");
										} else {
											if (Tab_Medio[lin][col] == 10){
											printf(" S\t");
											} else {
												if (Tab_Medio[lin][col] == 20){
												printf(" T\t");
												} else {
													if (Tab_Medio[lin][col] == 30){
													printf(" C\t");
													} else {
														if (Tab_Medio[lin][col] == 40){
														printf(" E\t");
														} else {
															if (Tab_Medio[lin][col] == 50){
															printf(" P\t");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Medio_Resultado(){
	
	printf("\n\t");
	for(col = 0; col < 15; col++){
		printf(" %d\t",col);
	}
	printf("\n\n");
	for(lin = 0; lin < 15; lin++){
		printf("    %d\t", lin);
		for(col = 0; col < 15; col++){
			if (Tab_Medio[lin][col] == 0){
				printf(" -\t");
				} else{
					if (Tab_Medio[lin][col] == 1){
					printf(" S\t");
					} else {
						if (Tab_Medio[lin][col] == 2){
						printf(" T\t");
						} else {
							if (Tab_Medio[lin][col] == 3){
							printf(" C\t");
							} else {
								if (Tab_Medio[lin][col] == 4){
								printf(" E\t");
								} else {
									if (Tab_Medio[lin][col] == 5){
									printf(" P\t");
									} else {
										if (Tab_Medio[lin][col] == -1){
										printf(" ~\t");
										} else {
											if (Tab_Medio[lin][col] == 10){
											printf(" S\t");
											} else {
												if (Tab_Medio[lin][col] == 20){
												printf(" T\t");
												} else {
													if (Tab_Medio[lin][col] == 30){
													printf(" C\t");
													} else {
														if (Tab_Medio[lin][col] == 40){
														printf(" E\t");
														} else {
															if (Tab_Medio[lin][col] == 50){
															printf(" P\t");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Preenche_Dificil(){
	
	for(lin = 0; lin < 20; lin++){
		for(col = 0; col < 20; col++){
			Tab_Dificil[lin][col] = 0;
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Submarino_Dificil(){
	
	srand(time(NULL));
	for(cont = 0; cont < 3; cont++){
		ncont = 0;
		while(ncont != 1){
			v1 = rand();
			col = v1 % 20;
			v2 = rand();
			lin = v2 % 20;
			if(Tab_Dificil[lin][col] == 0){
				Tab_Dificil[lin][col] = 1;
			ncont = 1;
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Contratorpedeiro_Dificil(){
	
	srand(time(NULL));
	for(cont = 0; cont < 5; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 19;
				v2 = rand();
				lin = v2 % 20;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin][col + 1] == 0){
					for(cont2 = 0; cont2 < 2; cont2++){
						Tab_Dificil[lin][col] = 2;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 20;
				v2 = rand();
				lin = v2 % 19;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin + 1][col] == 0){
					for(cont2 = 0; cont2 < 2; cont2++){
						Tab_Dificil[lin][col] = 2;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Cruzador_Dificil(){

	srand(time(NULL));
	for(cont = 0; cont < 5; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 18;
				v2 = rand();
				lin = v2 % 20;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin][col + 1] == 0 && Tab_Dificil[lin][col + 2] == 0){
					for(cont2 = 0; cont2 < 3; cont2++){
						Tab_Dificil[lin][col] = 3;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 20;
				v2 = rand();
				lin = v2 % 18;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin + 1][col] == 0 && Tab_Dificil[lin + 2][col] == 0){
					for(cont2 = 0; cont2 < 3; cont2++){
						Tab_Dificil[lin][col] = 3;
						lin = lin + 1;
					}
					ncont = 1;
				} 
			}			
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Encouracado_Dificil(){
	
	srand(time(NULL));
	for(cont = 0; cont < 4; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 17;
				v2 = rand();
				lin = v2 % 20;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin][col + 1] == 0 && Tab_Dificil[lin][col + 2] == 0 && Tab_Dificil[lin][col + 3] == 0){
					for(cont = 0; cont < 4; cont++){
						Tab_Dificil[lin][col] = 4;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 20;
				v2 = rand();
				lin = v2 % 17;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin + 1][col] == 0 && Tab_Dificil[lin + 2][col] == 0 && Tab_Dificil[lin + 3][col] == 0){
					for(cont2 = 0; cont2 < 4; cont2++){
						Tab_Dificil[lin][col] = 4;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Pos_Porta_Avioes_Dificil(){
	
	srand(time(NULL));
	for(cont = 0; cont < 3; cont++){
		x = rand();
		xl = x % 2;
		if(xl == 0){
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 16;
				v2 = rand();
				lin = v2 % 20;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin][col + 1] == 0 && Tab_Dificil[lin][col + 2] == 0 && Tab_Dificil[lin][col + 3] == 0 && Tab_Dificil[lin][col + 4] == 0){
					for(cont2 = 0; cont2 < 5; cont2++){
						Tab_Dificil[lin][col] = 5;
						col = col + 1;
					}
					ncont = 1;
				}
			}
		} else{
			ncont = 0;
			while(ncont != 1){
				v1 = rand();
				col = v1 % 20;
				v2 = rand();
				lin = v2 % 16;
				if(Tab_Dificil[lin][col] == 0 && Tab_Dificil[lin + 1][col] == 0 && Tab_Dificil[lin + 2][col] == 0 && Tab_Dificil[lin + 3][col] == 0 && Tab_Dificil[lin + 4][col] == 0){
					for(cont2 = 0; cont2 < 5; cont2++){
						Tab_Dificil[lin][col] = 5;
						lin = lin + 1;
					}
					ncont = 1;
				}
			}
		}
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Dificil(){
	
	printf("\n\t");
	for(col = 0; col < 20; col++){
		printf(" %d\t", col);
	}
	printf("\n\n");
	for(lin = 0; lin < 20; lin++){
		printf("    %d\t", lin);
		for(col = 0; col < 20; col++){
			if (Tab_Dificil[lin][col] == 0){
				printf(" -\t");
				} else{
					if (Tab_Dificil[lin][col] == 1){
					printf(" -\t");
					} else {
						if (Tab_Dificil[lin][col] == 2){
						printf(" -\t");
						} else {
							if (Tab_Dificil[lin][col] == 3){
							printf(" -\t");
							} else {
								if (Tab_Dificil[lin][col] == 4){
								printf(" -\t");
								} else {
									if (Tab_Dificil[lin][col] == 5){
									printf(" -\t");
									} else {
										if (Tab_Dificil[lin][col] == -1){
										printf(" ~\t");
										} else {
											if (Tab_Dificil[lin][col] == 10){
											printf(" S\t");
											} else {
												if (Tab_Dificil[lin][col] == 20){
												printf(" T\t");
												} else {
													if (Tab_Dificil[lin][col] == 30){
													printf(" C\t");
													} else {
														if (Tab_Dificil[lin][col] == 40){
														printf(" E\t");
														} else {
															if (Tab_Dificil[lin][col] == 50){
															printf(" P\t");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Dificil_Resultado(){
	
	printf("\n\t");
	for(col = 0; col < 20; col++){
		printf(" %d\t",col);
	}
	printf("\n\n");
	for(lin = 0; lin < 20; lin++){
		printf("    %d\t", lin);
		for(col = 0; col < 20; col++){
			if (Tab_Dificil[lin][col] == 0){
				printf(" -\t");
				} else{
					if (Tab_Dificil[lin][col] == 1){
					printf(" S\t");
					} else {
						if (Tab_Dificil[lin][col] == 2){
						printf(" T\t");
						} else {
							if (Tab_Dificil[lin][col] == 3){
							printf(" C\t");
							} else {
								if (Tab_Dificil[lin][col] == 4){
								printf(" E\t");
								} else {
									if (Tab_Dificil[lin][col] == 5){
									printf(" P\t");
									} else {
										if (Tab_Dificil[lin][col] == -1){
										printf(" ~\t");
										} else {
											if (Tab_Dificil[lin][col] == 10){
											printf(" S\t");
											} else {
												if (Tab_Dificil[lin][col] == 20){
												printf(" T\t");
												} else {
													if (Tab_Dificil[lin][col] == 30){
													printf(" C\t");
													} else {
														if (Tab_Dificil[lin][col] == 40){
														printf(" E\t");
														} else {
															if (Tab_Dificil[lin][col] == 50){
															printf(" P\t");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Preenche_Multijogador_2(){
	for(lin = 0; lin < 10; lin++){
		for(col = 0; col < 10; col++){
			Tab_Mult_2[lin][col] = 0;
		}
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Preenche_Multijogador_2(){
	
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ", col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Mult_2[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Mult_2[lin][col] == 1){
					printf(" S ");
					} else {
						if (Tab_Mult_2[lin][col] == 2){
						printf(" T ");
						} else {
							if (Tab_Mult_2[lin][col] == 3){
							printf(" C ");
							} else {
								if (Tab_Mult_2[lin][col] == 4){
								printf(" E ");
								} else {
									if (Tab_Mult_2[lin][col] == 5){
									printf(" P ");
									} else {
										printf("  #  ");
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//*******************************************************************************************************************************************************//

void Pos_Submarino_Multijogador_2(){
		
	do{	
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_2();
		
		printf("\nEmbarcacoes A Posicionar: 1 SUBMARINO (S)\n");
		printf("\nDigite -1 Para LINHA E COLUNA Para ENCERRAR!!\n");
		printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um SUBMARINO: ");
		scanf("%d", &plin);
		printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um SUBMARINO: ");
		scanf("%d", &pcol);
		
		if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 9){
			for(cont = 0; cont < 1; cont++){
				if(Tab_Mult_2[plin][pcol] == 0){
					Tab_Mult_2[plin][pcol] = 1;
					sair = 2;
				} else{
					printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um SUBMARINO!!");
				}
			}
		} else {
			if(plin == -1 && pcol == -1){
				sair = 1;
			} else{
				printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um SUBMARINO!!");
				getch();
			}
			
		}
	}while(sair != 1 && sair != 2);
	
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_2();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(sair == 2){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_2();
		printf("\nProxima Etapa: CONTRATORPEDEIROS");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Contratorpedeiro_Multijogador_2(){
	nemb = 3;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_2();
		
		printf("\nEmbarcacoes A Posicionar: %d CONTRATORPEDEIROS (T)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 2                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_2();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d CONTRATORPEDEIROS (T)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 8){
					if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin][pcol + 1] == 0){
						for(cont = 0; cont < 2; cont++){
							Tab_Mult_2[plin][pcol] = 2;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 2                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_2();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d CONTRATORPEDEIROS (T)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 8 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin + 1][pcol] == 0){
							for(cont = 0; cont < 2; cont++){
								Tab_Mult_2[plin][pcol] = 2;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_2();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_2();
		printf("\nProxima Etapa: CRUZADORES");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Cruzador_Multijogador_2(){
	nemb = 3;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_2();
		
		printf("\nEmbarcacoes A Posicionar: %d CRUZADORES (C)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 2                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_2();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d CRUZADORES (C)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um CRUZADOR: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CRUZADOR: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 7){
					if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin][pcol + 1] == 0 && Tab_Mult_2[plin][pcol + 2] == 0){
						for(cont = 0; cont < 3; cont++){
							Tab_Mult_2[plin][pcol] = 3;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 2                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_2();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d CRUZADORES (C)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um CRUZADOR: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CRUZADOR: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 7 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin + 1][pcol] == 0 && Tab_Mult_2[plin + 2][pcol] == 0){
							for(cont = 0; cont < 3; cont++){
								Tab_Mult_2[plin][pcol] = 3;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_2();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_2();
		printf("\nProxima Etapa: ENCOURACADOS");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Encouracado_Multijogador_2(){
	nemb = 2;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_2();
		
		printf("\nEmbarcacoes A Posicionar: %d ENCOURACADOS (E)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 2                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_2();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d ENCOURACADOS (E)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um ENCOURACADO: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um ENCOURACADO: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 6){
					if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin][pcol + 1] == 0 && Tab_Mult_2[plin][pcol + 2] == 0 && Tab_Mult_2[plin][pcol + 3] == 0){
						for(cont = 0; cont < 4; cont++){
							Tab_Mult_2[plin][pcol] = 4;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 2                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_2();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d ENCOURACADOS (E)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um ENCOURACADO: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um ENCOURACADO: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 6 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin + 1][pcol] == 0 && Tab_Mult_2[plin + 2][pcol] == 0 && Tab_Mult_2[plin + 3][pcol] == 0){
							for(cont = 0; cont < 4; cont++){
								Tab_Mult_2[plin][pcol] = 4;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_2();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_2();
		printf("\nProxima Etapa: PORTA_AVIOES");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Porta_Avioes_Multijogador_2(){
	nemb = 1;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_2();
		
		printf("\nEmbarcacoes A Posicionar: %d PORTA_AVIOES (P)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 2                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_2();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d PORTA_AVIOES (P)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um PORTA_AVIOES: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um PORTA_AVIOES: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 5){
					if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin][pcol + 1] == 0 && Tab_Mult_2[plin][pcol + 2] == 0 && Tab_Mult_2[plin][pcol + 3] == 0 && Tab_Mult_2[plin][pcol + 4] == 0){
						for(cont = 0; cont < 5; cont++){
							Tab_Mult_2[plin][pcol] = 5;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 2                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_2();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d PORTA_AVIOES (P)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 2: Digite Um Valor Para A LINHA Que Deseja Incluir Um PORTA_AVIOES: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 2: Digite Um Valor Para A COLUNA Que Deseja Incluir Um PORTA_AVIOES: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 5 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_2[plin][pcol] == 0 && Tab_Mult_2[plin + 1][pcol] == 0 && Tab_Mult_2[plin + 2][pcol] == 0 && Tab_Mult_2[plin + 3][pcol] == 0 && Tab_Mult_2[plin + 4][pcol] == 0){
							for(cont = 0; cont < 5; cont++){
								Tab_Mult_2[plin][pcol] = 5;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_2();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 2                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_2();
		printf("\nAgora E A Hora De Jogar: Passe Para A Proxima Tela Para O JOGADOR 1 Comecar O Jogo!!");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------------------//

void Preenche_Multijogador_1(){
	for(lin = 0; lin < 10; lin++){
		for(col = 0; col < 10; col++){
			Tab_Mult_1[lin][col] = 0;
		}
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Preenche_Multijogador_1(){
	
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ", col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Mult_1[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Mult_1[lin][col] == 1){
					printf(" S ");
					} else {
						if (Tab_Mult_1[lin][col] == 2){
						printf(" T ");
						} else {
							if (Tab_Mult_1[lin][col] == 3){
							printf(" C ");
							} else {
								if (Tab_Mult_1[lin][col] == 4){
								printf(" E ");
								} else {
									if (Tab_Mult_1[lin][col] == 5){
									printf(" P ");
									} else {
										printf("  #  ");
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

//*******************************************************************************************************************************************************//

void Pos_Submarino_Multijogador_1(){
		
	do{	
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_1();
		
		printf("\nEmbarcacoes A Posicionar: 1 SUBMARINO (S)\n");
		printf("\nDigite -1 Para LINHA E COLUNA Para ENCERRAR!!\n");
		printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um SUBMARINO: ");
		scanf("%d", &plin);
		printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um SUBMARINO: ");
		scanf("%d", &pcol);
		
		if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 9){
			for(cont = 0; cont < 1; cont++){
				if(Tab_Mult_1[plin][pcol] == 0){
					Tab_Mult_1[plin][pcol] = 1;
					sair = 2;
				} else{
					printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um SUBMARINO!!");
				}
			}
		} else {
			if(plin == -1 && pcol == -1){
				sair = 1;
			} else{
				printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um SUBMARINO!!");
				getch();
			}
			
		}
	}while(sair != 1 && sair != 2);
	
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_1();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(sair == 2){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_1();
		printf("\nProxima Etapa: CONTRATORPEDEIROS");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Contratorpedeiro_Multijogador_1(){
	nemb = 3;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_1();
		
		printf("\nEmbarcacoes A Posicionar: %d CONTRATORPEDEIROS (T)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 1                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_1();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d CONTRATORPEDEIROS (T)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 8){
					if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin][pcol + 1] == 0){
						for(cont = 0; cont < 2; cont++){
							Tab_Mult_1[plin][pcol] = 2;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 1                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_1();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d CONTRATORPEDEIROS (T)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CONTRATORPEDEIRO: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 8 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin + 1][pcol] == 0){
							for(cont = 0; cont < 2; cont++){
								Tab_Mult_1[plin][pcol] = 2;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CONTRATORPEDEIRO!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_1();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_1();
		printf("\nProxima Etapa: CRUZAZDORES");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Cruzador_Multijogador_1(){
	nemb = 3;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_1();
		
		printf("\nEmbarcacoes A Posicionar: %d CRUZADORES (C)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 1                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_1();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d CRUZADORES (C)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um CRUZADOR: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CRUZADOR: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 7){
					if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin][pcol + 1] == 0 && Tab_Mult_1[plin][pcol + 2] == 0){
						for(cont = 0; cont < 3; cont++){
							Tab_Mult_1[plin][pcol] = 3;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 1                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_1();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d CRUZADORES (C)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um CRUZADOR: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um CRUZADOR: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 7 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin + 1][pcol] == 0 && Tab_Mult_1[plin + 2][pcol] == 0){
							for(cont = 0; cont < 3; cont++){
								Tab_Mult_1[plin][pcol] = 3;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um CRUZADOR!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_1();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_1();
		printf("\nProxima Etapa: ENCOURACADOS");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Encouracado_Multijogador_1(){
	nemb = 2;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_1();
		
		printf("\nEmbarcacoes A Posicionar: %d ENCOURACADOS (E)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 1                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_1();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d ENCOURACADOS (E)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um ENCOURACADO: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um ENCOURACADO: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 6){
					if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin][pcol + 1] == 0 && Tab_Mult_1[plin][pcol + 2] == 0 && Tab_Mult_1[plin][pcol + 3] == 0){
						for(cont = 0; cont < 4; cont++){
							Tab_Mult_1[plin][pcol] = 4;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 1                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_1();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d ENCOURACADOS (E)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um ENCOURACADO: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um ENCOURACADO: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 6 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin + 1][pcol] == 0 && Tab_Mult_1[plin + 2][pcol] == 0 && Tab_Mult_1[plin + 3][pcol] == 0){
							for(cont = 0; cont < 4; cont++){
								Tab_Mult_1[plin][pcol] = 4;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um ENCOURACADO!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_1();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_1();
		printf("\nProxima Etapa: PORTA_AVIOES");
		printf("\nAperte Qualquer Tecla Para Continuar: ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Pos_Porta_Avioes_Multijogador_1(){
	nemb = 1;
	do{
		system("cls");
		sair = 0;
		
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		
		Imprime_Preenche_Multijogador_1();
		
		printf("\nEmbarcacoes A Posicionar: %d PORTA_AVIOES (P)\n", nemb);
		
		printf("\n 1: HORIZONTAL");
		printf("\n 2: VERTICAL");
		printf("\n-1: ENCERRAR");
		printf("\n\nEscolha Uma Das Opcoes Acima: ");
		scanf("%d", &posicao);
		
		if(posicao == 1){
			do{
				system("cls");
				sair = 0;
				
				printf("+===============================================+\n");
				printf("|               MODO MULTIJOGADOR               |\n");
				printf("+===============================================+\n");
				printf("|                   JOGADOR 1                   |\n");
				printf("+===============================================+\n");
				printf("|           POSICIONANDO  EMBARCACOES           |\n");
				printf("+===============================================+\n");
				
				Imprime_Preenche_Multijogador_1();
				
				printf("\nPosicionando na <HORIZONTAL>");
				printf("\nEmbarcacoes A Posicionar: %d PORTA_AVIOES (P)", nemb);
				printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
				printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um PORTA_AVIOES: ");
				scanf("%d", &plin);
				printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um PORTA_AVIOES: ");
				scanf("%d", &pcol);
				
				if(plin >= 0 && plin <= 9 && pcol >= 0 && pcol <= 5){
					if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin][pcol + 1] == 0 && Tab_Mult_1[plin][pcol + 2] == 0 && Tab_Mult_1[plin][pcol + 3] == 0 && Tab_Mult_1[plin][pcol + 4] == 0){
						for(cont = 0; cont < 5; cont++){
							Tab_Mult_1[plin][pcol] = 5;
							pcol = pcol + 1;
						}
						nemb = nemb - 1;
						sair = 2;
					} else{
						printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!\n");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				} else{
					if(plin == -1 && pcol == -1){
						sair = 1;
					} else{
						printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!");
						printf("\nAperte Qualquer Tecla Para Continuar: ");
						getch();
					}
				}
			}while(sair != 1 && sair != 2);
		} else{
			if(posicao == 2){
				do{
					system("cls");
					sair = 0;
					
					printf("+===============================================+\n");
					printf("|               MODO MULTIJOGADOR               |\n");
					printf("+===============================================+\n");
					printf("|                   JOGADOR 1                   |\n");
					printf("+===============================================+\n");
					printf("|           POSICIONANDO  EMBARCACOES           |\n");
					printf("+===============================================+\n");
					
					Imprime_Preenche_Multijogador_1();
					
					printf("\nPosicionando na <VERTICAL>");
					printf("\nEmbarcacoes A Posicionar: %d PORTA_AVIOES (P)", nemb);
					printf("\nDigite -1 Para LINHA E COLUNA A Qualquer Momento Para ENCERRAR!!\n");
					printf("\nJOGADOR 1: Digite Um Valor Para A LINHA Que Deseja Incluir Um PORTA_AVIOES: ");
					scanf("%d", &plin);
					printf("\nJOGADOR 1: Digite Um Valor Para A COLUNA Que Deseja Incluir Um PORTA_AVIOES: ");
					scanf("%d", &pcol);
					
					if(plin >= 0 && plin <= 5 && pcol >= 0 && pcol <= 9){
						if(Tab_Mult_1[plin][pcol] == 0 && Tab_Mult_1[plin + 1][pcol] == 0 && Tab_Mult_1[plin + 2][pcol] == 0 && Tab_Mult_1[plin + 3][pcol] == 0 && Tab_Mult_1[plin + 4][pcol] == 0){
							for(cont = 0; cont < 5; cont++){
								Tab_Mult_1[plin][pcol] = 5;
								plin = plin + 1;
							}
							nemb = nemb - 1;
							sair = 2;
						} else{
							printf("\nPOSICAO INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!\n");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					} else{
						if(plin == -1 && pcol == -1){
							sair = 1;
						} else{
							printf("\nENTRADA INVALIDA: Escolha Outra Posicao Para Incluir Um PORTA_AVIOES!!");
							printf("\nAperte Qualquer Tecla Para Continuar: ");
							getch();
						}
					}
				}while(sair != 1 && sair != 2);
			} else{
				if(posicao == -1){
					sair = 1;
				} else{
					printf("\nEntrada Invalida!!");
					printf("\nAperte Qualquer Tecla Para Continuar: ");
					getch();
				}
			}
		}
		
	}while(nemb != 0 && sair != 1);
			
	if(sair == 1){
		do{
			system("cls");
			printf("+=========================================+\n");
			printf("|              VOCE ENCERROU              |\n");
			printf("+=========================================+\n");
			
			Imprime_Preenche_Multijogador_1();
			
			printf("\n\nDigite 0 Para Voltar Ao Menu: ");
			scanf("%d", &op);
			
			if(op != 0){
				printf("\nEntrada Invalida!!");
				printf("\n\nAperte Qualquer Tecla Para Continuar: ");
				getch();
			}
		}while(op != 0);
	}
	
	if(nemb == 0){
		system("cls");
		printf("+===============================================+\n");
		printf("|               MODO MULTIJOGADOR               |\n");
		printf("+===============================================+\n");
		printf("|                   JOGADOR 1                   |\n");
		printf("+===============================================+\n");
		printf("|           POSICIONANDO  EMBARCACOES           |\n");
		printf("+===============================================+\n");
		Imprime_Preenche_Multijogador_1();
		printf("\nAgora Sera A Vez do JOGADOR 2 Preencher O Seu Tabuleiro!!");
		printf("\nAperte Qualquer Tecla Para Passa Para A Proxima Tela!! ");
		getch();
	}
}

//*******************************************************************************************************************************************************//

void Imprime_Multijogador_1(){
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ", col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Mult_1[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Mult_1[lin][col] == 1){
					printf(" - ");
					} else {
						if (Tab_Mult_1[lin][col] == 2){
						printf(" - ");
						} else {
							if (Tab_Mult_1[lin][col] == 3){
							printf(" - ");
							} else {
								if (Tab_Mult_1[lin][col] == 4){
								printf(" - ");
								} else {
									if (Tab_Mult_1[lin][col] == 5){
									printf(" - ");
									} else {
										if (Tab_Mult_1[lin][col] == -1){
										printf(" ~ ");
										} else {
											if (Tab_Mult_1[lin][col] == 10){
											printf(" S ");
											} else {
												if (Tab_Mult_1[lin][col] == 20){
												printf(" T ");
												} else {
													if (Tab_Mult_1[lin][col] == 30){
													printf(" C ");
													} else {
														if (Tab_Mult_1[lin][col] == 40){
														printf(" E ");
														} else {
															if (Tab_Mult_1[lin][col] == 50){
															printf(" P ");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

void Imprime_Multijogador_1_Resultado(){
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ",col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Mult_1[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Mult_1[lin][col] == 1){
					printf(" S ");
					} else {
						if (Tab_Mult_1[lin][col] == 2){
						printf(" T ");
						} else {
							if (Tab_Mult_1[lin][col] == 3){
							printf(" C ");
							} else {
								if (Tab_Mult_1[lin][col] == 4){
								printf(" E ");
								} else {
									if (Tab_Mult_1[lin][col] == 5){
									printf(" P ");
									} else {
										if (Tab_Mult_1[lin][col] == -1){
										printf(" ~ ");
										} else {
											if (Tab_Mult_1[lin][col] == 10){
											printf(" S ");
											} else {
												if (Tab_Mult_1[lin][col] == 20){
												printf(" T ");
												} else {
													if (Tab_Mult_1[lin][col] == 30){
													printf(" C ");
													} else {
														if (Tab_Mult_1[lin][col] == 40){
														printf(" E ");
														} else {
															if (Tab_Mult_1[lin][col] == 50){
															printf(" P ");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

void Imprime_Multijogador_2(){
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ", col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Mult_2[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Mult_2[lin][col] == 1){
					printf(" - ");
					} else {
						if (Tab_Mult_2[lin][col] == 2){
						printf(" - ");
						} else {
							if (Tab_Mult_2[lin][col] == 3){
							printf(" - ");
							} else {
								if (Tab_Mult_2[lin][col] == 4){
								printf(" - ");
								} else {
									if (Tab_Mult_2[lin][col] == 5){
									printf(" - ");
									} else {
										if (Tab_Mult_2[lin][col] == -1){
										printf(" ~ ");
										} else {
											if (Tab_Mult_2[lin][col] == 10){
											printf(" S ");
											} else {
												if (Tab_Mult_2[lin][col] == 20){
												printf(" T ");
												} else {
													if (Tab_Mult_2[lin][col] == 30){
													printf(" C ");
													} else {
														if (Tab_Mult_2[lin][col] == 40){
														printf(" E ");
														} else {
															if (Tab_Mult_2[lin][col] == 50){
															printf(" P ");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}

void Imprime_Multijogador_2_Resultado(){
	printf("\n\t");
	for(col = 0; col < 10; col++){
		printf(" %d ",col);
	}
	printf("\n\n");
	for(lin = 0; lin < 10; lin++){
		printf("     %d  ", lin);
		for(col = 0; col < 10; col++){
			if (Tab_Mult_2[lin][col] == 0){
				printf(" - ");
				} else{
					if (Tab_Mult_2[lin][col] == 1){
					printf(" S ");
					} else {
						if (Tab_Mult_2[lin][col] == 2){
						printf(" T ");
						} else {
							if (Tab_Mult_2[lin][col] == 3){
							printf(" C ");
							} else {
								if (Tab_Mult_2[lin][col] == 4){
								printf(" E ");
								} else {
									if (Tab_Mult_2[lin][col] == 5){
									printf(" P ");
									} else {
										if (Tab_Mult_2[lin][col] == -1){
										printf(" ~ ");
										} else {
											if (Tab_Mult_2[lin][col] == 10){
											printf(" S ");
											} else {
												if (Tab_Mult_2[lin][col] == 20){
												printf(" T ");
												} else {
													if (Tab_Mult_2[lin][col] == 30){
													printf(" C ");
													} else {
														if (Tab_Mult_2[lin][col] == 40){
														printf(" E ");
														} else {
															if (Tab_Mult_2[lin][col] == 50){
															printf(" P ");
															} else {
																printf("  #  ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	printf("\n");
	}
}
