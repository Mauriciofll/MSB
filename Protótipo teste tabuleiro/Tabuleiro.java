public class Tabuleiro {
    private char[][] tabuleiro;
    private int linhas;
    private int colunas;

    // Construtor que define o tamanho do tabuleiro
    public Tabuleiro(int linhas, int colunas) {
        this.linhas = linhas;
        this.colunas = colunas;
        this.tabuleiro = new char[linhas][colunas];
        inicializarTabuleiro();
    }

    // Inicializa o tabuleiro com '-'
    private void inicializarTabuleiro() {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                tabuleiro[i][j] = '-';
            }
        }
    }

    // Exibe o tabuleiro no console
    public void exibir() {
        System.out.println("\nTabuleiro:");
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                System.out.print(tabuleiro[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Marca uma posição no tabuleiro com um caractere (ex: 'X')
    public boolean marcarPosicao(int linha, int coluna, char simbolo) {
        if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
            System.out.println("Posição inválida!");
            return false;
        }
        if (tabuleiro[linha][coluna] != '-') {
            System.out.println("Essa posição já está ocupada!");
            return false;
        }

        tabuleiro[linha][coluna] = simbolo;
        return true;
    }

    // Método principal para testar a classe

}
