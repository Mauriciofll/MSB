package br.edu.up.BatalhaNaval.controllers;

import br.edu.up.BatalhaNaval.models.Tabuleiro;
import br.edu.up.BatalhaNaval.repositories.TabuleiroRepository;
import br.edu.up.BatalhaNaval.views.TabuleiroView;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.Serializable;
import java.util.List;

public class TabuleiroController implements Serializable{
    private Tabuleiro tabuleiro;
    private TabuleiroView view;

    private static final Logger logger = LogManager.getLogger(TabuleiroController.class);

    public TabuleiroController(Tabuleiro tabuleiro, TabuleiroView view) {
        this.tabuleiro = tabuleiro;
        this.view = view;
    }

    /**
     * Método para criar tabuleiros personalizados.
     * @param nome - Refere-se ao nome do tabuleiro.
     * @param x - Refere-se a altura do tabuleiro.
     * @param y - Refere-se a largura do tabuleiro.
     * @param dono - Refere-se ao usuário dono do tabuleiro.
     */
    public void criarTabuleiro(String nome, int x, int y, String dono) {
        logger.info("Iniciando metodo de criacao de tabuleiro");
        List<Tabuleiro> lista = TabuleiroRepository.listarTodos();
        lista.add(new Tabuleiro(nome, x, y, dono));
        TabuleiroRepository.salvarTodos(lista);
        logger.info("Finalizando metodo de criacao de tabuleiro");
    }

    public void inicializarTabuleiro() {
        tabuleiro.preencheTabuleiro();
        view.exibirMensagem("Tabuleiro '" + tabuleiro.getNome() + "' inicializado.");
    }

    public void exibirTabuleiro() {
        view.exibirTabuleiro(tabuleiro);
    }

    public void exibirTabuleiroEscondido() { view.exibirTabuleiroEscondido(tabuleiro);
    }

    public boolean atualizarCelula(int x, int y, String valor) {
        if (tabuleiro.dentroDosLimites(x, y) && tabuleiro.isCelulaLivre(x, y)) {
            tabuleiro.setMatriz(x, y, valor);
            return true;
        } else {
            view.exibirMensagem("Posição inválida ou já ocupada!");
            return false;
        }
    }

    public boolean atualizarCelulaEscondida(int x, int y) {
        if (tabuleiro.dentroDosLimites(x, y) && tabuleiro.isCelulaLivre(x, y)) {
            tabuleiro.setMatrizEscondida(x, y);
            return true;
        } else {
            view.exibirMensagem("Posição inválida ou já ocupada!");
            return false;
        }
    }

    
}
