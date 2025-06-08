import java.util.Scanner;

public class Menu {
    public void intro() {
        Scanner scanner = new Scanner(System.in);
        int opcao = 0;
        do {
            try {
                System.out.println("Boas vindas ao MSB! O que gostaria de jogar?\n1 - Multijogador \n2 - Sair");
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

    public void multijogador() {
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
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        System.out.println("\nJogador 2: Posicione suas embarcações.");
        jogador2.posicionar(tabuleiro2, tabuleiroController2, tabuleiroView2);
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        System.out.println("\nJogador 1: Ataque uma posição.");


    }
}
