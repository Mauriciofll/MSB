public class TabuleiroController {
    private Tabuleiro tabuleiro;
    private TabuleiroView view;

    public TabuleiroController(Tabuleiro tabuleiro, TabuleiroView view) {
        this.tabuleiro = tabuleiro;
        this.view = view;
    }

    public void inicializarTabuleiro() {
        tabuleiro.preencheTabuleiro();
        view.exibirMensagem("Tabuleiro '" + tabuleiro.getNome() + "' inicializado.");
    }

    public void exibirTabuleiro() {
        view.exibirTabuleiro(tabuleiro);
    }

    public void exibirTabuleiroEscondido() { view.exibirTabuleiroEscondido(tabuleiro);
    }

    public boolean atualizarCelula(int x, int y, String valor) {
        if (tabuleiro.dentroDosLimites(x, y) && tabuleiro.isCelulaLivre(x, y)) {
            tabuleiro.setMatriz(x, y, valor);
            return true;
        } else {
            view.exibirMensagem("Posição inválida ou já ocupada!");
            return false;
        }
    }

    public boolean atualizarCelulaEscondida(int x, int y) {
        if (tabuleiro.dentroDosLimites(x, y) && tabuleiro.isCelulaLivre(x, y)) {
            tabuleiro.setMatrizEscondida(x, y);
            return true;
        } else {
            view.exibirMensagem("Posição inválida ou já ocupada!");
            return false;
        }
    }
}
