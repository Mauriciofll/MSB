package br.edu.up.BatalhaNaval.models;

import controller.TabuleiroController;
import view.TabuleiroView;

import java.util.ArrayList;
import java.util.List;

public interface ModeloJogador {
    List<Embarcacao> frota = new ArrayList<>();

    void posicionar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView);

    void atacar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView);
}
