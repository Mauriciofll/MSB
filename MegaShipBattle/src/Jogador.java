import java.util.Scanner;

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
    public void posicionar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView) {
        for(Embarcacao e : frota) {
            EmbarcacaoView embarcacaoView = new EmbarcacaoView();
            EmbarcacaoController embarcacaoController = new EmbarcacaoController(e, embarcacaoView);

            tabuleiroController.exibirTabuleiro();
            embarcacaoController.posicionarEmbarcacao(tabuleiro);
        }
    }

    public void atacar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView) {
        do {
            try {
                tabuleiroController.exibirTabuleiroEscondido();
                Scanner scanner = new Scanner(System.in);
                System.out.println("Por favor insira a posição X do ataque: ");
                int posicaoX = scanner.nextInt();
                if(posicaoX > tabuleiro.getTamanho() || posicaoX < 0) {
                    System.out.println("Opção inválida!");
                }
                System.out.println("Por favor insira a posição Y do ataque: ");
                int posicaoY = scanner.nextInt();
                if(posicaoY > tabuleiro.getTamanho() || posicaoY < 0) {
                    System.out.println("Posição inválida!");
                }
                if(tabuleiro.getMatriz(posicaoX, posicaoY) != "~") {
                    System.out.println("Alvo atingido!");
                    tabuleiro.setMatrizEscondida(posicaoX, posicaoY);
                } else {
                    System.out.println("Nenhum alvo atingido!");
                }

            } catch (Exception e) {
                System.out.println("Opção inválida!");
            }
        } while(true);
    }

    public Integer getPontos() {
        return pontos;
    }

    public void setPontos(Integer pontos) {
        this.pontos = pontos;
    }
}
