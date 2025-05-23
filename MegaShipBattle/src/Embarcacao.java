import java.util.Scanner;

public abstract class Embarcacao {
//=====================================================================================================================
//ATTRIBUTES
//=====================================================================================================================
    String nome;
    String categoria;
    int slots; // slots = tamanho
    int orientacao;
//=====================================================================================================================
//CONSTRUCTORS
//=====================================================================================================================
    Embarcacao(String nome, String categoria, int slots) {
        this.nome = nome;
        this.categoria = categoria;
        this.slots = slots;
    }
//=====================================================================================================================
//METHODS
//=====================================================================================================================
    public void posicionaEmbarcacao(Tabuleiro tabuleiro) {
        System.out.println("\n\n1 = Horizontal | 2 = Vertical\nEscolha a orientacao do " + nome +
                " (Tamanho " + slots + "):");
        Scanner scanner = new Scanner(System.in);
        orientacao = scanner.nextInt();
        System.out.println("Posicao X da embarcacao: ");
        int posicaoX = scanner.nextInt();
        System.out.println("Posicao Y da embarcacao: ");
        int posicaoY = scanner.nextInt();
        if(orientacao == 1) {
            for (int i = 0; i < slots; i++) {
                tabuleiro.setMatriz(posicaoX + i, posicaoY, categoria);
            }
        } else if (orientacao == 2) {
            for(int i = 0; i < slots; i++) {
                tabuleiro.setMatriz(posicaoX, posicaoY + i, categoria);
            }
        }
    }
}