package br.edu.up.BatalhaNaval.models;

import java.io.Serializable;

import br.edu.up.BatalhaNaval.controllers.TabuleiroController;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Usuario implements Serializable {
    private static final Logger logger = LogManager.getLogger(TabuleiroController.class);
    private String nome;
    private String senha;
    private boolean admin;

    public Usuario(String nome, String senha, boolean admin) {
        this.nome = nome;
        this.senha = senha;
        this.admin = admin;
    }

    public Usuario() {

    }

    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public String getSenha() { return senha; }
    public void setSenha(String senha) { this.senha = senha; }

    public boolean isAdmin() { return admin; }
}
