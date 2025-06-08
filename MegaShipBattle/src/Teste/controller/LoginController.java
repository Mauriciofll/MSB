package Teste.controller;

import java.util.List;

import Teste.model.Usuario;
import Teste.repository.UsuarioRepository;

public class LoginController {
    private Usuario usuarioLogado;
    private UsuarioRepository usuarioRepository;

    public LoginController(UsuarioRepository usuarioRepository) {
        this.usuarioRepository = usuarioRepository;
    }

    public boolean logar(String nome, String senha) {
        List<Usuario> usuarios = UsuarioRepository.carregarUsuarios();
        for (Usuario u : usuarios) {
            if (u.getNome().equals(nome) && u.getSenha().equals(senha)) {
                usuarioLogado = u;
                return true;
            }
        }
        return false;
    }

    public boolean cadastrar(String nome, String senha, boolean admin) {
        List<Usuario> usuarios = UsuarioRepository.carregarUsuarios();
        for (Usuario u : usuarios) {
            if (u.getNome().equals(nome)) return false;
        }
        usuarios.add(new Usuario(nome, senha, admin));
        UsuarioRepository.salvarUsuarios(usuarios);
        return true;
    }

    public Usuario getUsuarioLogado() {
        return usuarioLogado;
    }

    public void deslogar() {
        usuarioLogado = null;
    }
}
