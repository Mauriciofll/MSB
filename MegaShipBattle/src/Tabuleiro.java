public class Tabuleiro {
//=====================================================================================================================
//ATTRIBUTES
//=====================================================================================================================
    private String nome;
    private Integer tamanho;
    private Integer[][] matriz;
//=====================================================================================================================
//GETTERS & SETTERS
//=====================================================================================================================

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer getTamanho() {
        return tamanho;
    }

    public void setTamanho(Integer tamanho) {
        this.tamanho = tamanho;
    }

    public Integer[][] getMatriz() {
        return matriz;
    }

    public void setMatriz(Integer[][] matriz) {
        this.matriz = matriz;
    }

    //=====================================================================================================================
//CONSTRUCTORS
//=====================================================================================================================
    public Tabuleiro(String nome, Integer tamanho) {
        this.nome = nome;
        this.tamanho = tamanho;
        Integer colunas = tamanho;
        Integer linhas = tamanho;
        this.matriz = new Integer[colunas][linhas];
    }
//=====================================================================================================================
//METHODS
//=====================================================================================================================
    public void preencheTabuleiro() { // Preenche todo o tabuleiro com o valor 0
        for (Integer x = 0; x < this.tamanho; x++) {
        }
        for (Integer y = 0; y < this.tamanho; y++) {
            for (Integer x = 0; x < this.tamanho; x++) {
                matriz[x][y] = 0;
            }
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    public void imprimeTabuleiro() { // Imprime todo o tabuleiro
        System.out.print("\t");
        for (Integer x = 0; x < this.tamanho; x++) {
            System.out.print("[" + x + "]\t");
        }
        for (Integer y = 0; y < this.tamanho; y++) {
            System.out.println("");
            System.out.print("[" + y + "]\t");
            for (Integer x = 0; x < this.tamanho; x++) {
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