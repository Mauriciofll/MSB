public class EmbarcacaoController {
    private Embarcacao embarcacao;
    private EmbarcacaoView view;

    public EmbarcacaoController(Embarcacao embarcacao, EmbarcacaoView view) {
        this.embarcacao = embarcacao;
        this.view = view;
    }

    public void posicionarEmbarcacao(Tabuleiro tabuleiro) {
        boolean sucesso = false;

        do {
            int orientacao = view.solicitarOrientacao(embarcacao.getNome(), embarcacao.getSlots());
            if (orientacao != 1 && orientacao != 2) {
                view.exibirMensagemErro("Orientação inválida.");
                continue;
            }

            int x = view.solicitarCoordenada("X");
            int y = view.solicitarCoordenada("Y");

            sucesso = embarcacao.posicionar(tabuleiro, x, y, orientacao);

            if (!sucesso) {
                view.exibirMensagemErro("Espaço ocupado ou posição inválida. Tente novamente.");
            }
        } while (!sucesso);

        view.exibirMensagem("Embarcação posicionada com sucesso!");
    }
}
