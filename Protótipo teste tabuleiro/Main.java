import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicita o tamanho do tabuleiro ao usuário
        System.out.print("Digite o número de linhas: ");
        int linhas = scanner.nextInt();

        System.out.print("Digite o número de colunas: ");
        int colunas = scanner.nextInt();

        Tabuleiro jogo = new Tabuleiro(linhas, colunas);

        boolean continuar = true;
        while (continuar) {
            jogo.exibir();

            System.out.print("Digite a linha (0 a " + (linhas - 1) + "): ");
            int linha = scanner.nextInt();

            System.out.print("Digite a coluna (0 a " + (colunas - 1) + "): ");
            int coluna = scanner.nextInt();

            System.out.print("Digite o símbolo para marcar: ");
            char simbolo = scanner.next().charAt(0);

            jogo.marcarPosicao(linha, coluna, simbolo);

            System.out.print("Deseja continuar? (s/n): ");
            char resp = scanner.next().toLowerCase().charAt(0);
            continuar = (resp == 's');
        }

        System.out.println("Programa encerrado.");
        scanner.close();
    }
}