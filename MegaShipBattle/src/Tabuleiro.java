public class Tabuleiro {
    private String nome;
    private Integer tamanho;
    private Integer[][] matriz;

    public Tabuleiro(String nome, Integer tamanho) {
        this.nome = nome;
        this.tamanho = tamanho;
        Integer colunas = tamanho;
        Integer linhas = tamanho;
        this.matriz = new Integer[colunas][linhas];
    }

    public Integer getTamanho() {
        return tamanho;
    }

    public void setTamanho(Integer tamanho) {
        this.tamanho = tamanho;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer[][] getMatriz() {
        return matriz;
    }

    public void setMatriz(Integer[][] matriz) {
        this.matriz = matriz;
    }

    public void preencheTabuleiro() {
        System.out.print("   ");
        for (Integer x = 0; x < this.tamanho; x++) {

            System.out.print(" " + x + " ");
        }
        for (Integer y = 0; y < this.tamanho; y++) {
            System.out.println("");
            System.out.print(" " + y + " ");
            for (Integer x = 0; x < this.tamanho; x++) {
                matriz[x][y] = 9;
                System.out.print(" " + matriz[x][y] + " ");
            }
        }
    }

    public void imprimeTabuleiro() {
        System.out.print("   ");
        for (int x = 0; x < this.tamanho; x++) {
            System.out.print(" " + x + " ");
        }

        int y = 0;
        for (Integer[] linha : this.matriz) {
            System.out.println();
            System.out.print(" " + y + " ");

            int x = 0;
            for (Integer valor : linha) {
                this.matriz[y][x] = 9; // atribui valor usando índices
                System.out.print(" " + this.matriz[y][x] + " ");
                x++;
            }
            y++;
        }
    }

}