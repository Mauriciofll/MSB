package model;

public class Usuario {
    private String nome;
    private String senha;
    private int pontuacao;

    public Usuario(String nome, String senha) {
        this.nome = nome;
        this.senha = senha;
        this.pontuacao = 0;
    }

    public String getNome() {
        return nome;
    }

    public String getSenha() {
        return senha;
    }

    public int getPontuacao() {
        return pontuacao;
    }

    public void setPontuacao(int pontuacao) {
        this.pontuacao = pontuacao;
    }

    @Override
    public String toString() {
        return nome + ";" + senha + ";" + pontuacao;
    }

    public static Usuario fromString(String linha) {
        String[] partes = linha.split(";");
        Usuario u = new Usuario(partes[0], partes[1]);
        u.setPontuacao(Integer.parseInt(partes[2]));
        return u;
    }
}
