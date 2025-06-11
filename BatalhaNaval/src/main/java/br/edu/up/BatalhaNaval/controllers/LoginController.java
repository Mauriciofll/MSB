package br.edu.up.BatalhaNaval.controllers;

import br.edu.up.BatalhaNaval.models.Usuario;
import br.edu.up.BatalhaNaval.repositories.UsuarioRepository;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.List;

public class LoginController {
    private static final Logger logger = LogManager.getLogger(LoginController.class);
    private Usuario usuarioLogado;
    private UsuarioRepository usuarioRepository;

    public LoginController(UsuarioRepository usuarioRepository) {
        this.usuarioRepository = usuarioRepository;
    }

    public boolean logar(String nome, String senha) {
        logger.info("Iniciando processo de login");
        List<Usuario> usuarios = UsuarioRepository.carregarUsuarios();
        logger.debug("Realizando comparacao de credenciais");
        for (Usuario u : usuarios) {
            logger.trace("Realizando comparacao de credenciais");
            if (u.getNome().equals(nome) && u.getSenha().equals(senha)) {
                usuarioLogado = u;
                return true;
            }
        }
        logger.debug("Validacao de credenciais realizada");
        logger.info("Finalizando metodo de login");
        return false;

    }

    public boolean cadastrar(String nome, String senha, boolean admin) {
        logger.info("Iniciando cadastro de usuario");
        List<Usuario> usuarios = UsuarioRepository.carregarUsuarios();
        for (Usuario u : usuarios) {
            if (u.getNome().equals(nome)) return false;
        }
        usuarios.add(new Usuario(nome, senha, admin));
        UsuarioRepository.salvarUsuarios(usuarios);
        logger.info("Finalizando cadastro de usuario");
        return true;
    }

    public Usuario getUsuarioLogado() {
        return usuarioLogado;
    }

    public void deslogar() {
        usuarioLogado = null;
    }
}
