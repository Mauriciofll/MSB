package br.edu.up.BatalhaNaval.models;

import br.edu.up.BatalhaNaval.controllers.EmbarcacaoController;
import br.edu.up.BatalhaNaval.controllers.TabuleiroController;
import br.edu.up.BatalhaNaval.interfaces.ModeloJogador;
import br.edu.up.BatalhaNaval.views.EmbarcacaoView;
import br.edu.up.BatalhaNaval.views.TabuleiroView;


import java.util.Scanner;

public class Jogador implements ModeloJogador {
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
        for(int i  = 0; i < 5; i++) {
            EmbarcacaoView embarcacaoView = new EmbarcacaoView();
            EmbarcacaoController embarcacaoController = new EmbarcacaoController(frota.get(i), embarcacaoView);

            tabuleiroController.exibirTabuleiro();
            embarcacaoController.posicionarEmbarcacao(tabuleiro);
        }
    }

    @Override
    public int atacar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView) {
        int sair = 0;
        do {
            try {
                tabuleiroController.exibirTabuleiroEscondido();
                Scanner scanner = new Scanner(System.in);
                System.out.println("Por favor insira a posição X do ataque: ");
                int posicaoX = scanner.nextInt();
                if(posicaoX > tabuleiro.getTamanho() || posicaoX < -1) {
                    System.out.println("Opção inválida!");
                }
                System.out.println("Por favor insira a posição Y do ataque: ");
                int posicaoY = scanner.nextInt();
                if(posicaoY > tabuleiro.getTamanho() || posicaoY < -1) {
                    System.out.println("Posição inválida!");
                }
                if (posicaoX != -1 && posicaoY != -1) {
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
                    }
                } else {
                    sair = 1;
                }
            } catch (Exception e) {
                System.out.println("Opção inválida!");
            }
        } while(sair != 1);
        if (sair == 1) {
            return 1;
        }
        return 0;
    }

    public Integer getPontos() {
        return pontos;
    }

    public void setPontos(Integer pontos) {
        this.pontos = pontos;
    }
}
