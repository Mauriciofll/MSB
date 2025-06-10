package br.edu.up.BatalhaNaval.controllers;

import br.edu.up.BatalhaNaval.models.Tabuleiro;
import br.edu.up.BatalhaNaval.repositories.TabuleiroRepository;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.List;

public class TabuleiroController {
    private static final Logger logger = LogManager.getLogger(TabuleiroController.class);
    public void criarTabuleiro(String nome, int x, int y, String dono) {
        logger.info("Iniciando metodo de criacao de tabuleiro");
        List<Tabuleiro> lista = TabuleiroRepository.listarTodos();
        lista.add(new Tabuleiro(nome, x, y, dono));
        TabuleiroRepository.salvarTodos(lista);
        logger.info("Finalizando metodo de criacao de tabuleiro");
    }


    
}
