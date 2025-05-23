public class TesteEmbarcacoes {
    public static void main(String[] args) {
        Tabuleiro tabuleiro = new Tabuleiro("padrao", 10);
        tabuleiro.preencheTabuleiro();
        tabuleiro.imprimeTabuleiro();
        PortaAvioes portaAvioes = new PortaAvioes();
        Encouracado encouracado = new Encouracado();
        Cruzador cruzador = new Cruzador();
        Submarino submarino = new Submarino();
        Destroyer destroyer = new Destroyer();

        portaAvioes.posicionaEmbarcacao(tabuleiro);
        tabuleiro.imprimeTabuleiro();
        encouracado.posicionaEmbarcacao(tabuleiro);
        tabuleiro.imprimeTabuleiro();
        cruzador.posicionaEmbarcacao(tabuleiro);
        tabuleiro.imprimeTabuleiro();
        submarino.posicionaEmbarcacao(tabuleiro);
        tabuleiro.imprimeTabuleiro();
        destroyer.posicionaEmbarcacao(tabuleiro);
        tabuleiro.imprimeTabuleiro();

    }
}
