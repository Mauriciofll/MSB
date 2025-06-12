package br.edu.up.BatalhaNaval.views;
import java.util.Scanner;

public class EmbarcacaoView {
    private Scanner scanner = new Scanner(System.in);

    /**
     * Imprime ao jogador para escolher a orientação da embarcação.
     * @param nome - Diz o nome da embarcação ao jogador.
     * @param tamanho - Diz o tamanho da embarcação ao jogador.
     * @return - Retorna o valor escolhido referente a orientação.
     */
    public int solicitarOrientacao(String nome, int tamanho) {
        System.out.println("\n1 = Horizontal | 2 = Vertical");
        System.out.println("Escolha a orientacao do " + nome + " (Tamanho " + tamanho + "): ");
        return scanner.nextInt();
    }

    /**
     * Solicita ao jogador a posição desejada.
     * @param coordenada - Refere-se ao eixo o qual o usuário deve digitar o valor.
     * @return
     */
    public int solicitarCoordenada(String coordenada) {
        System.out.print("Digite a posição " + coordenada + ": ");
        return scanner.nextInt();
    }

    /*
    Ambos métodos de mensagem servem para imprimir mensagens relevantes ao jogador.
     */
    public void exibirMensagemErro(String msg) {
        System.out.println("Erro: " + msg);
    }

    public void exibirMensagem(String msg) {
        System.out.println(msg);
    }
}
