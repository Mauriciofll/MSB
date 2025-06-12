package br.edu.up.BatalhaNaval.models;

import java.io.Serializable;

public class Tabuleiro implements Serializable {
    private int largura;
    private int altura;
    private String dono;

    public Tabuleiro(String nome, int largura, int altura, String dono) {
        this.nome = nome;
        this.largura = largura;
        this.altura = altura;
        this.dono = dono;
        this.pontuacao = 0;
        this.matriz = new String[altura][largura];
        this.matrizEscondida = new String[altura][largura];
        preencheTabuleiro();
    }

    //Construtor vazio declarado para instâncias onde não se sabe os atributos na declaração do objeto.
    public Tabuleiro() {

    }

    private int pontuacao;

    public int getPontuacao() { return pontuacao; }
    public void setPontuacao(int pontuacao) { this.pontuacao = pontuacao; }

    private String nome;
    private int tamanho;
    private String[][] matriz;
    private String[][] matrizEscondida;

    //Construtor para declarações de objeto com somente atributos nome e tamanho geral.
    public Tabuleiro(String nome, int tamanho) {
        this.nome = nome;
        this.tamanho = tamanho;
        this.matriz = new String[tamanho][tamanho];
        this.matrizEscondida = new String[tamanho][tamanho];
        preencheTabuleiro(); // já inicia o tabuleiro preenchido
    }

    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public int getTamanho() { return tamanho; }
    public void setTamanho(int tamanho) { this.tamanho = tamanho; }

    public String getMatriz(int x, int y) { return matriz[x][y]; }

    public void setMatriz(int x, int y, String valor) { matriz[x][y] = valor; }

    //Método serve para revelar o que há na Matriz real, substituindo gradualmente os valores da matriz escondida.
    public void setMatrizEscondida(int x, int y) {
        matrizEscondida[x][y] = matriz[x][y];
    }

    public boolean isCelulaLivre(int x, int y) {
        return dentroDosLimites(x, y) && matriz[x][y].equals("~");
    }

    public boolean dentroDosLimites(int x, int y) {
        return x >= 0 && y >= 0 && x < tamanho && y < tamanho;
    }

    public void preencheTabuleiro() {
        for (int y = 0; y < this.tamanho; y++) {
            for (int x = 0; x < this.tamanho; x++) {
                matriz[x][y] = "~";
            }
        }
        //Matriz escondida é preenchida de "X" para mostrar espaços ainda não atingidos.
        for (int y = 0; y < this.tamanho; y++) {
            for (int x = 0; x < this.tamanho; x++) {
                matrizEscondida[x][y] = "X";
            }
        }
    }

    public String[][] getMatrizCompleta() {
        return matriz;
    }

    public String[][] getMatrizEscondida() { return matrizEscondida; }

    public String getMatrizEscondidaValor(int x, int y) {
        return matrizEscondida[x][y];
    }

    public String getDono() {
        return dono;
    }

    public void setDono(String dono) {
        this.dono = dono;
    }

    @Override
    public String toString() {
        return "Tabuleiro: " + nome +
        " | Dimensões: " + largura + "x" + altura +
        " | Dono: " + dono;
    }
}