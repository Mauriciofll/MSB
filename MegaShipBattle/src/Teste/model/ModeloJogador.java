package model;
import java.util.ArrayList;
import java.util.List;

import controller.TabuleiroController;
import view.TabuleiroView;

public interface ModeloJogador {
    List<Embarcacao> frota = new ArrayList<>();

    void posicionar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView);

    void atacar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView);
}
