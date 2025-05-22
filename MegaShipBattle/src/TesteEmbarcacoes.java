public class TesteEmbarcacoes {
    public static void main(String[] args) {
        Tabuleiro tabuleiro = new Tabuleiro("padrao", 10);
        tabuleiro.preencheTabuleiro();
        tabuleiro.imprimeTabuleiro();
        Embarcacao torpedeiro = new Embarcacao("dallas", "T", 2);
        Embarcacao submarino = new Embarcacao("Teste","S", 1);
        torpedeiro.posicionaEmbarcacao(tabuleiro);
        tabuleiro.imprimeTabuleiro();
    }
}
