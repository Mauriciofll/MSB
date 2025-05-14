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

    public void preencheTabuleiro () {
        for(Integer x = 0; x < this.tamanho; x++){
            for (Integer y = 0; y < this.tamanho; y++) {
                matriz[x][y] = 0;
                System.out.println(matriz[x][y]);
            }
        }
    }

    public void imprimeTabuleiro () {

    }
}
