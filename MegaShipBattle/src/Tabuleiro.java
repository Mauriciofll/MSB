public class Tabuleiro {
    //=================================================================================================================
    // Atributos
    //=================================================================================================================
    private String nome;
    private int tamanho;
    private String[][] matriz;

    //=================================================================================================================
    // Construtor
    //=================================================================================================================
    public Tabuleiro(String nome, int tamanho) {
        this.nome = nome;
        this.tamanho = tamanho;
        this.matriz = new String[tamanho][tamanho];
        preencheTabuleiro(); // já inicia o tabuleiro preenchido
    }

    //=================================================================================================================
    // Getters e Setters
    //=================================================================================================================
    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public int getTamanho() { return tamanho; }
    public void setTamanho(int tamanho) { this.tamanho = tamanho; }

    public String getMatriz(int x, int y) { return matriz[x][y]; }

    public void setMatriz(int x, int y, String valor) { matriz[x][y] = valor; }

    public boolean isCelulaLivre(int x, int y) {
        return dentroDosLimites(x, y) && matriz[x][y].equals("~");
    }

    public boolean dentroDosLimites(int x, int y) {
        return x >= 0 && y >= 0 && x < tamanho && y < tamanho;
    }

    //=================================================================================================================
    // Métodos
    //=================================================================================================================
    public void preencheTabuleiro() {
        for (int y = 0; y < this.tamanho; y++) {
            for (int x = 0; x < this.tamanho; x++) {
                matriz[x][y] = "~";
            }
        }
    }

    public String[][] getMatrizCompleta() {
        return matriz;
    }
}