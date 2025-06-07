package model;

import java.io.Serializable;

public class Tabuleiro implements Serializable {
    private String nome;
    private int x;
    private int y;
    private int pontuacao;
    private String dono;

    public Tabuleiro(String nome, int x, int y, String dono) {
        this.nome = nome;
        this.x = x;
        this.y = y;
        this.dono = dono;
        this.pontuacao = 0;
    }

    public String getNome() { return nome; }
    public int getX() { return x; }
    public int getY() { return y; }
    public int getPontuacao() { return pontuacao; }
    public void setPontuacao(int pontuacao) { this.pontuacao = pontuacao; }
    public String getDono() { return dono; }

    @Override
    public String toString() {
        return String.format("%s (%dx%d) - Pontuação: %d - Dono: %s", nome, x, y, pontuacao, dono);
    }
}
