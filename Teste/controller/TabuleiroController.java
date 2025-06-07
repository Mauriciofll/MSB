package controller;

import java.util.List;

import model.Tabuleiro;
import repository.TabuleiroRepository;

public class TabuleiroController {
    public void criarTabuleiro(String nome, int x, int y, String dono) {
        List<Tabuleiro> lista = TabuleiroRepository.listarTodos();
        lista.add(new Tabuleiro(nome, x, y, dono));
        TabuleiroRepository.salvarTodos(lista);
    }
}
