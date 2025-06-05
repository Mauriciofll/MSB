package controller;

import java.util.List;

import model.Usuario;
import repository.UsuarioRepository;

public class LoginController {
    private UsuarioRepository UsuarioRepository;

    public LoginController() {
        UsuarioRepository = new UsuarioRepository();
    }

    public boolean cadastrar(String nome, String senha) {
        if (UsuarioRepository.buscarPorNome(nome) != null) return false;
        UsuarioRepository.adicionarUsuario(new Usuario(nome, senha));
        return true;
    }

    public Usuario logar(String nome, String senha) {
        Usuario usuario = UsuarioRepository.buscarPorNome(nome);
        if (usuario != null && usuario.getSenha().equals(senha)) return usuario;
        return null;
    }

    public boolean atualizarUsuario(Usuario atual, String novoNome, String novaSenha) {
        List<Usuario> usuarios = UsuarioRepository.listarUsuarios();
        for (Usuario u : usuarios) {
            if (u.getNome().equals(novoNome) && !u.getNome().equals(atual.getNome())) return false;
        }
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios.get(i).getNome().equals(atual.getNome())) {
                Usuario atualizado = new Usuario(novoNome, novaSenha);
                atualizado.setPontuacao(atual.getPontuacao());
                usuarios.set(i, atualizado);
                UsuarioRepository.salvarUsuarios(usuarios);
                return true;
            }
        }
        return false;
    }

    public boolean deletarProprioUsuario(Usuario usuario) {
        List<Usuario> usuarios = UsuarioRepository.listarUsuarios();
        usuarios.removeIf(u -> u.getNome().equals(usuario.getNome()));
        UsuarioRepository.salvarUsuarios(usuarios);
        return true;
    }

    public boolean adminRemoverUsuario(String nome) {
        List<Usuario> usuarios = UsuarioRepository.listarUsuarios();
        boolean removido = usuarios.removeIf(u -> u.getNome().equals(nome));
        UsuarioRepository.salvarUsuarios(usuarios);
        return removido;
    }

    public boolean adminAtualizarUsuario(String nomeAntigo, String novoNome, String novaSenha, int novaPontuacao) {
        List<Usuario> usuarios = UsuarioRepository.listarUsuarios();
        for (Usuario u : usuarios) {
            if (u.getNome().equals(novoNome) && !u.getNome().equals(nomeAntigo)) return false;
        }
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios.get(i).getNome().equals(nomeAntigo)) {
                Usuario atualizado = new Usuario(novoNome, novaSenha);
                atualizado.setPontuacao(novaPontuacao);
                usuarios.set(i, atualizado);
                UsuarioRepository.salvarUsuarios(usuarios);
                return true;
            }
        }
        return false;
    }

    public List<Usuario> listarTodosUsuarios() {
        return UsuarioRepository.listarUsuarios();
    }

    public String gerarRanking() {
        StringBuilder sb = new StringBuilder();
        List<Usuario> usuarios = UsuarioRepository.listarUsuarios();
        usuarios.sort((u1, u2) -> Integer.compare(u2.getPontuacao(), u1.getPontuacao()));
        sb.append("Ranking de Usuários:\n");
        for (Usuario u : usuarios) {
            sb.append(String.format("- %s: %d pts\n", u.getNome(), u.getPontuacao()));
        }
        return sb.toString();
    }

    public boolean isAdmin(Usuario usuario) {
        return usuario.getNome().equals("Admin");
    }
}
