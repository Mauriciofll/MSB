package br.edu.up.BatalhaNaval.controllers;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import model.Embarcacao;
import model.Tabuleiro;
import view.EmbarcacaoView;

import java.io.IOException;

public class EmbarcacaoController {
    private static final Logger logger = LogManager.getLogger(EmbarcacaoController.class);
    private Embarcacao embarcacao;
    private EmbarcacaoView view;

    public EmbarcacaoController(Embarcacao embarcacao, EmbarcacaoView view) {
        logger.info("Iniciando a execução do método EmbarcacaoController");
        this.embarcacao = embarcacao;
        this.view = view;
    }

    public void posicionarEmbarcacao(Tabuleiro tabuleiro) {
        boolean sucesso = false;
        logger.info("Iniciando o posicionamento de embarcacoes");
        do {
            logger.debug("Solicitacao de entrada de valores");
            int orientacao = view.solicitarOrientacao(embarcacao.getNome(), embarcacao.getSlots());
            logger.debug("Validacao da entrada de dados");
            if (orientacao != 1 && orientacao != 2) {
                view.exibirMensagemErro("Orientação inválida.");
                continue;
            }
            logger.debug("Atribuicao das entradas de valor");
            int x = view.solicitarCoordenada("X");
            int y = view.solicitarCoordenada("Y");

            sucesso = embarcacao.posicionar(tabuleiro, x, y, orientacao);

            if (!sucesso) {
                view.exibirMensagemErro("Espaço ocupado ou posição inválida. Tente novamente.");
            }
        } while (!sucesso);
        logger.info("Finalizando o posicionamento de embarcacao");
        view.exibirMensagem("Embarcação posicionada com sucesso!");
    }
}
