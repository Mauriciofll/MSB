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
        do {
            Scanner scanner = new Scanner(System.in);
            try {
                System.out.println("\n\n1 = Horizontal | 2 = Vertical\nEscolha a orientacao do " + nome +
                        " (Tamanho " + slots + "):");
                orientacao = scanner.nextInt();
                if(orientacao != 1 && orientacao!= 2) {
                    System.out.print("Valor inválido! Por favor insira um valor válido!");
                    continue;
                }
            } catch(Exception e) {
                System.out.print("Valor inválido! Por favor insira um valor válido!");
                continue;
            }
            int posicaoX;
            try {
                System.out.println("Posicao X da embarcacao: ");
                posicaoX = scanner.nextInt();
            } catch (Exception e) {
                System.out.print("Valor inválido! Por favor insira um valor válido!");
                continue;
            }
            int posicaoY;
            try {
                System.out.println("Posicao Y da embarcacao: ");
                posicaoY = scanner.nextInt();
            } catch (Exception e) {
                System.out.println("Valor inválido! Por favor insira um valor válido!");
                continue;
            }
            boolean validacao = true;
            if (orientacao == 1) {
                for (int i = 0; i < slots; i++) {
                    if(tabuleiro.getMatriz(posicaoX + i, posicaoY) != "~") {
                        System.out.println("Espaço ocupado! Por favor selecione um espaço livre!");
                        validacao = false;
                        break;
                    }
                    tabuleiro.setMatriz(posicaoX + i, posicaoY, categoria);
                }
            } else if (orientacao == 2) {
                for (int i = 0; i < slots; i++) {
                    if(tabuleiro.getMatriz(posicaoX, posicaoY + i) != "~") {
                        System.out.println("Espaço ocupado! Por favor selecione um espaço livre!");
                        validacao = false;
                        break;
                    }
                    tabuleiro.setMatriz(posicaoX, posicaoY + i, categoria);
                }
            }
            if(validacao) {
                break;
            }
        } while (true);
    }
}