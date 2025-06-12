package br.edu.up.BatalhaNaval.models;

import br.edu.up.BatalhaNaval.controllers.TabuleiroController;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public abstract class Embarcacao {
    private static final Logger logger = LogManager.getLogger(TabuleiroController.class);
    private String nome;
    private String categoria;
    private int slots;
    private int orientacao;

    /**
     * Construtor base para a embarcação.
     * Classes que extendem a classe abstrata usam de valores predeterminados no construtor, baseados em seus atributos.
     * @param nome
     * @param categoria
     * @param slots
     */
    public Embarcacao(String nome, String categoria, int slots) {
        logger.info("Iniciando a execução do contrutor 'Embarcacao'.");
        this.nome = nome;
        this.categoria = categoria;
        this.slots = slots;
        logger.info("Finalizando a execução do contrutor 'Embarcacao'.");
    }

    /**
     * Método próprio para posiconar embarcações no tabuleiro
     * @param tabuleiro - Define o tabuleiro onde a embarcação será posicionada.
     * @param posicaoX - Define a posição no eixo X para o posicionamento.
     * @param posicaoY - Define a posição no eixo y para o posicionamento.
     * @param orientacao - Define a orientação da embarcação, podendo ser horizontal ou vertical.
     * @return - Retorna uma validação boolean dependendo do estado da operação.
     */
    public boolean posicionar(Tabuleiro tabuleiro, int posicaoX, int posicaoY, int orientacao) {
        logger.info("Iniciando execução do método 'Posicionar' para alocar uma embarcação.");
        this.orientacao = orientacao;
        boolean validacao = true;

        if (orientacao == 1) { // Horizontal
            logger.debug("Validação de posicionamento na HORIZONTAL iniciada.");
            for (int i = 0; i < slots; i++) {
                if (!tabuleiro.isCelulaLivre(posicaoX + i, posicaoY)) {
                    validacao = false;
                    break;
                }
            }
            logger.debug("Validação de posicionamento na HORIZONTAL finalizada.");
            if (validacao) {
                logger.debug("Iniciando o posicionamento na HORIZONTAL.");
                for (int i = 0; i < slots; i++) {
                    tabuleiro.setMatriz(posicaoX + i, posicaoY, categoria);
                }
                logger.debug("Finalizado o posicionamento na HORIZONTAL.");
            }
        } else if (orientacao == 2) { // Vertical
            logger.debug("Validação de posicionamento na VERTICAL iniciada.");
            for (int i = 0; i < slots; i++) {
                if (!tabuleiro.isCelulaLivre(posicaoX, posicaoY + i)) {
                    validacao = false;
                    break;
                }
            }
            logger.debug("Validação de posicionamento na VERTICAL finalizada.");
            if (validacao) {
                logger.debug("Iniciando o posicionamento na VERTICAL.");
                for (int i = 0; i < slots; i++) {
                    tabuleiro.setMatriz(posicaoX, posicaoY + i, categoria);
                }
                logger.debug("Finalizado o posicionamento na VERTICAL.");
            }
        }
        logger.info("Finalizando a execução do método 'Posicionar' para alocar uma embarcação.");
        return validacao;
    }

    // Getters
    public String getNome() { return nome; }
    public String getCategoria() { return categoria; }
    public int getSlots() { return slots; }
}