package br.edu.up.BatalhaNaval.interfaces;

import br.edu.up.BatalhaNaval.controllers.TabuleiroController;
import br.edu.up.BatalhaNaval.models.Embarcacao;
import br.edu.up.BatalhaNaval.models.Tabuleiro;
import br.edu.up.BatalhaNaval.views.TabuleiroView;


import java.util.ArrayList;
import java.util.List;

/*
ModeloJogador é implementado como interface pois pode ser utilizado para formação de diferentes classes de
jogador, como um jogador normal controlado por um usuário ou um jogador IA controlado pelo programa.

*/

public interface ModeloJogador {
    List<Embarcacao> frota = new ArrayList<>();

    void posicionar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView);

    int atacar(Tabuleiro tabuleiro, TabuleiroController tabuleiroController, TabuleiroView tabuleiroView);
}
