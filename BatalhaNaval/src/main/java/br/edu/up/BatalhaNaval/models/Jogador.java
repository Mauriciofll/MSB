package br.edu.up.BatalhaNaval.models;

import br.edu.up.BatalhaNaval.controllers.EmbarcacaoController;
import br.edu.up.BatalhaNaval.controllers.TabuleiroController;
import br.edu.up.BatalhaNaval.interfaces.ModeloJogador;
import br.edu.up.BatalhaNaval.views.EmbarcacaoView;
import br.edu.up.BatalhaNaval.views.TabuleiroView;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.Scanner;

public class Jogador implements ModeloJogador {
    private static final Logger logger = LogManager.getLogger(TabuleiroController.class);
    private Integer pontos = 0;

    /**
     * Jogador usa um construtor vazio que adiciona as embarcações relevantes à frota.
     */
    public Jogador() {
        frota.add(new PortaAvioes());
        frota.add(new Encouracado());
        frota.add(new Cruzador());
        frota.add(new Submarino());
        frota.add(new Destroyer());
    }

    /**
     * Método usa parâmetros da classe Tabuleiro para posiconamento de embarcações.
     * @param tabuleiro - Refere-se ao tabuleiro em si.
     * @param tabuleiroController - Refere-se a classe que utiliza dos dois outros parâmetros para manusear as operações.
     * @param tabuleiroView - Refere-se a classe contendo os atributos e métodos relevantes ao que o usuário irá ver no console.
     */
    @Override
    public void posicionar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView) {
        logger.info("Iniciando método de posicionamento de embarcações.");
        for(int i  = 0; i < 5; i++) {
            EmbarcacaoView embarcacaoView = new EmbarcacaoView();
            EmbarcacaoController embarcacaoController = new EmbarcacaoController(frota.get(i), embarcacaoView);

            tabuleiroController.exibirTabuleiro();
            embarcacaoController.posicionarEmbarcacao(tabuleiro);
        }
        logger.info("Finalizado o método de posicionamento de embarcações.");
    }

    /**
     * Método usas parâmetros da classe Tabuleiro para atacar.
     * @param tabuleiro - Usa a matrizEscondida do tabuleiro para ser atacada.
     * @param tabuleiroController - Gerencia os métodos e atributos relevantes da classe Tabuleiro.
     * @param tabuleiroView - Exibe a matrizEscondida ao Jogador e revela espaços já atacados.
     * @return
     */
    @Override
    public void atacar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView) {
        logger.info("Iniciando método de ataque.");
        int sair = 0;
        do {
            try {
                tabuleiroController.exibirTabuleiroEscondido();
                Scanner scanner = new Scanner(System.in);
                System.out.println("Por favor insira a posição X do ataque (Ou -1 para encerrar): ");
                int posicaoX = scanner.nextInt();
                if(posicaoX > tabuleiro.getTamanho() || posicaoX < -1) {
                    System.out.println("Opção inválida!");
                    continue;
                } else if (posicaoX == -1) {
                    System.exit(0);
                }
                System.out.println("Por favor insira a posição Y do ataque (Ou -1 para encerrar): ");
                int posicaoY = scanner.nextInt();
                if(posicaoY > tabuleiro.getTamanho() || posicaoY < -1) {
                    System.out.println("Posição inválida!");
                } else if (posicaoY == -1) {
                    System.exit(0);
                }
                if(tabuleiro.getMatrizEscondidaValor(posicaoX, posicaoY) == "X") {
                    if (tabuleiro.getMatriz(posicaoX, posicaoY) != "~") {
                        System.out.println("\nAlvo atingido!");
                        tabuleiro.setMatrizEscondida(posicaoX, posicaoY);
                        pontos += 1;
                        break;
                    } else {
                        System.out.println("\nNenhum alvo atingido!");
                        tabuleiro.setMatrizEscondida(posicaoX, posicaoY);
                        break;
                    }
                } else {
                    System.out.println("Posição já atingida!");
                    continue;
                }
            } catch (Exception e) {
                System.out.println("Opção inválida!");
            }
        } while(true);
        logger.info("Finalizando o método de ataque.");
    }

    public Integer getPontos() {
        return pontos;
    }

    public void setPontos(Integer pontos) {
        this.pontos = pontos;
    }
}
