package br.edu.up.BatalhaNaval.views;


import br.edu.up.BatalhaNaval.controllers.LoginController;
import br.edu.up.BatalhaNaval.controllers.TabuleiroController;
import br.edu.up.BatalhaNaval.models.Jogador;
import br.edu.up.BatalhaNaval.models.Tabuleiro;
import br.edu.up.BatalhaNaval.repositories.UsuarioRepository;

import java.util.Scanner;

public class MenuJogador {
    /**
     * Menu inicial ao Jogador.
     */
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

    /**
     * Modo multijogador local.
     * @throws InterruptedException - É utilizado para o comando thread.sleep.
     */
    public void multijogador() throws InterruptedException {
        int sair = 0;
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
        //Thread.sleep(500) é usado para que haja um momento onde o jogador possa ver o que ocoreu antes de acabar seu turno.
        Thread.sleep(500);
        //Sequências de \n são utilizadas na ausência de console.clear().
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        System.out.println("\nJogador 2: Posicione suas embarcações.");
        jogador2.posicionar(tabuleiro2, tabuleiroController2, tabuleiroView2);
        Thread.sleep(500);
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        do {
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            System.out.println("Jogador 1: Ataque uma posição.");
            if(jogador1.atacar(tabuleiro2, tabuleiroController2, tabuleiroView2) == 1) {
                sair = 1;
            }
            Thread.sleep(500);
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            System.out.println("Jogador 2: Posicione suas embarcações.");
            if(jogador2.atacar(tabuleiro1, tabuleiroController1, tabuleiroView1) == 1) {
                sair = 1;
            }
            Thread.sleep(500);
        } while(jogador1.getPontos() < 19 && jogador2.getPontos() < 19 && sair != 1);
        if(jogador1.getPontos() < 19) {
            System.out.println("Jogador 1 é o vencedor!");
        } else if (jogador2.getPontos() < 19) {
            System.out.println("Jogador 2 é o vencedor!");
        } else if (sair == 1) {
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            intro();
        } else{
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            intro();
        }
    }
}
