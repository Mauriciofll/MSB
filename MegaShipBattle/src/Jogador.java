public class Jogador implements ModeloJogador{
    private Integer pontos = 0;

    public Jogador() {
        frota.add(new PortaAvioes());
        frota.add(new Encouracado());
        frota.add(new Cruzador());
        frota.add(new Submarino());
        frota.add(new Destroyer());
    }

    @Override
    public void posicionar(Tabuleiro tabuleiro) {
        for(Embarcacao e : frota) {
            (new TabuleiroController(tabuleiro, new TabuleiroView())).exibirTabuleiro();
            (new EmbarcacaoController(e, new EmbarcacaoView())).posicionarEmbarcacao(tabuleiro);
        }
    }

    public void atacar(Tabuleiro tabuleiro) {
        try {

        } catch(Exception e) {
            System.out.println("Opção inválida!");
        }
    }

    public Integer getPontos() {
        return pontos;
    }

    public void setPontos(Integer pontos) {
        this.pontos = pontos;
    }
}
