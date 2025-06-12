package br.edu.up.BatalhaNaval.views;


import br.edu.up.BatalhaNaval.controllers.TabuleiroController;
import br.edu.up.BatalhaNaval.models.Jogador;
import br.edu.up.BatalhaNaval.models.Tabuleiro;

import java.util.Scanner;

public class MenuJogador {
    public void intro() {
        Scanner scanner = new Scanner(System.in);
        int opcao = 0;
        do {
            try {
                System.out.println("O que gostaria de jogar?\n1 - Multijogador \n2 - Sair");
                opcao = scanner.nextInt();
                if(opcao == 1) {
                    multijogador();
                } else if (opcao == 2) {
                    System.exit(0);
                } else {
                    System.out.println("Opção inválida!");
                }
            } catch (Exception e) {
                System.out.println("Opção inválida!");
            }
        } while (opcao != 1 && opcao != 2);
    }

    public void multijogador() throws InterruptedException {
        Tabuleiro tabuleiro1 = new Tabuleiro("Padrão1", 10);
        TabuleiroView tabuleiroView1 = new TabuleiroView();
        TabuleiroController tabuleiroController1 = new TabuleiroController(tabuleiro1, tabuleiroView1);
        Tabuleiro tabuleiro2 = new Tabuleiro("Padrão2", 10);
        TabuleiroView tabuleiroView2 = new TabuleiroView();
        TabuleiroController tabuleiroController2 = new TabuleiroController(tabuleiro2, tabuleiroView2);
        Jogador jogador1 = new Jogador();
        Jogador jogador2 = new Jogador();
        System.out.println("\nJogador 1: Posicione suas embarcações.");
        jogador1.posicionar(tabuleiro1, tabuleiroController1, tabuleiroView1);
        Thread.sleep(500);
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        System.out.println("\nJogador 2: Posicione suas embarcações.");
        jogador2.posicionar(tabuleiro2, tabuleiroController2, tabuleiroView2);
        Thread.sleep(500);
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        do {
            System.out.println("Jogador 1: Ataque uma posição.");
            jogador1.atacar(tabuleiro2, tabuleiroController2, tabuleiroView2);
            Thread.sleep(500);
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            System.out.println("Jogador 2: Posicione suas embarcações.");
            jogador2.atacar(tabuleiro1, tabuleiroController1, tabuleiroView1);
            Thread.sleep(500);
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        } while(jogador1.getPontos() < 19 && jogador2.getPontos() < 19);
        if(jogador1.getPontos() < 19) {
            System.out.println("Jogador 1 é o vencedor!");
        } else if (jogador2.getPontos() < 19) {
            System.out.println("Jogador 2 é o vencedor!");
        }
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        intro();
    }
}
