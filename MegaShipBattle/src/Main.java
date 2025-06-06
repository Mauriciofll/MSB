public class Main {
    public static void main(String[] args) {
        Menu menu = new Menu();
        menu.intro();

        // Criando o tabuleiro e associando à View e Controller
        Tabuleiro tabuleiro = new Tabuleiro("Jogador 1", 10);
        TabuleiroView tabuleiroView = new TabuleiroView();
        TabuleiroController tabuleiroController = new TabuleiroController(tabuleiro, tabuleiroView);

        // Inicializando e exibindo o tabuleiro
        tabuleiroController.inicializarTabuleiro();
        tabuleiroController.exibirTabuleiro();

        // Criando uma embarcação (exemplo: Submarino de 3 slots)
        Submarino submarino = new Submarino();  // Subclasse de Embarcacao
        Cruzador cruzador = new Cruzador();
        Destroyer destroyer = new Destroyer();
        PortaAvioes portaAvioes = new PortaAvioes();
        Encouracado encouracado = new Encouracado();
        EmbarcacaoView embarcacaoView = new EmbarcacaoView();
        EmbarcacaoController submarinoController = new EmbarcacaoController(submarino, embarcacaoView);
        EmbarcacaoController cruzadorController = new EmbarcacaoController(cruzador, embarcacaoView);
        EmbarcacaoController destroyerController = new EmbarcacaoController(destroyer, embarcacaoView);
        EmbarcacaoController portaAvioesController = new EmbarcacaoController(portaAvioes, embarcacaoView);
        EmbarcacaoController encouracadoController = new EmbarcacaoController(encouracado, embarcacaoView);

        // Posicionando a embarcação
        submarinoController.posicionarEmbarcacao(tabuleiro);
        tabuleiroController.exibirTabuleiro();
        cruzadorController.posicionarEmbarcacao(tabuleiro);
        tabuleiroController.exibirTabuleiro();
        destroyerController.posicionarEmbarcacao(tabuleiro);
        tabuleiroController.exibirTabuleiro();
        portaAvioesController.posicionarEmbarcacao(tabuleiro);
        tabuleiroController.exibirTabuleiro();
        encouracadoController.posicionarEmbarcacao(tabuleiro);
        tabuleiroController.exibirTabuleiro();
    }
}
