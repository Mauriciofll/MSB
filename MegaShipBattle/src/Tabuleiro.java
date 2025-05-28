public class Tabuleiro {
//=====================================================================================================================
//ATTRIBUTES
//=====================================================================================================================
    private String nome;
    private int tamanho;
    private String[][] matriz;
//=====================================================================================================================
//GETTERS & SETTERS
//=====================================================================================================================

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(Integer tamanho) {
        this.tamanho = tamanho;
    }

    public String getMatriz(int x, int y) {
        return matriz[x][y];
    }

    public void setMatriz(int x, int y, String valor) {
        matriz[x][y] = valor;
    }

    //=====================================================================================================================
//CONSTRUCTORS
//=====================================================================================================================
    public Tabuleiro(String nome, int tamanho) {
        this.nome = nome;
        this.tamanho = tamanho;
        int colunas = tamanho;
        int linhas = tamanho;
        this.matriz = new String[colunas][linhas];
    }
//=====================================================================================================================
//METHODS
//=====================================================================================================================
    public void preencheTabuleiro() { // Preenche todo o tabuleiro com o valor 0
        for (int x = 0; x < this.tamanho; x++) {
        }
        for (int y = 0; y < this.tamanho; y++) {
            for (int x = 0; x < this.tamanho; x++) {
                matriz[x][y] = "~";
            }
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    public void imprimeTabuleiro() { // Imprime todo o tabuleiro
        System.out.print("\t");
        for (int x = 0; x < this.tamanho; x++) {
            System.out.print("[" + x + "]\t");
        }
        for (int y = 0; y < this.tamanho; y++) {
            System.out.println("");
            System.out.print("[" + y + "]\t");
            for (int x = 0; x < this.tamanho; x++) {
                System.out.print(" " + matriz[x][y] + " \t");
            }
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    public void imprimeTabuleiro() {
//        System.out.print("\t");
//        for (int x = 0; x < this.tamanho; x++) {
//            System.out.print("[" + x + "]\t");
//        }
//        int y = 0;
//        for (Integer[] linha : this.matriz) {
//            System.out.println();
//            System.out.print("[" + y + "]\t");
//            int x = 0;
//            for (Integer valor : linha) {
//                this.matriz[y][x] = 0; // atribui valor usando índices
//                System.out.print("|" + this.matriz[y][x] + "|\t");
//                x++;
//            }
//            y++;
//        }
//    }

}