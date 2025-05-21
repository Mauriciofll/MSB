import java.util.Scanner;

public class Embarcacao {
//=====================================================================================================================
//ATTRIBUTES
//=====================================================================================================================
    private String nome;
    private String categoria;
    private Integer slots; // slots = tamanho
    private Integer[] posicao;
    private Integer orientacao;
//=====================================================================================================================
//CONSTRUCTORS
//=====================================================================================================================
    public Embarcacao(String nome, String categoria, Integer slots) {
        this.nome = nome;
        this.categoria = categoria;
        this.slots = slots;
    }
//=====================================================================================================================
//METHODS
//=====================================================================================================================
    public void posicionaEmbarcacao() {
        Tabuleiro tabuleiro = new Tabuleiro("padrao", 10);
        tabuleiro.preencheTabuleiro();
        tabuleiro.imprimeTabuleiro();
        System.out.println("\n\n1 = Horizontal | 2 = Vertical\nEscolha a orientacao da embarcacao: ");
        Scanner scanner = new Scanner(System.in);
        orientacao = scanner.nextInt();
        System.out.println("Posicao X da embarcacao: ");
        scanner = new Scanner(System.in);
        posicao[0] = scanner.nextInt();
        System.out.println("Posicao Y da embarcacao: ");
        scanner = new Scanner(System.in);
        posicao[1] = scanner.nextInt();

        //if (orientacao == 1) {

            //Tabuleiro.matriz[posicao[0]][posicao[1]]

        }

    }

