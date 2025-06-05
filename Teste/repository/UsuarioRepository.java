package repository;

import model.Usuario;
import java.io.*;
import java.util.*;
import java.util.logging.*;

public class UsuarioRepository {
    private static final String ARQUIVO = "usuarios.txt";
    private static final Logger logger = Logger.getLogger(UsuarioRepository.class.getName());

    public UsuarioRepository() {
        configurarLog();
    }

    private void configurarLog() {
        try {
            FileHandler fileHandler = new FileHandler("logs/app.log", true);
            fileHandler.setFormatter(new SimpleFormatter());
            logger.addHandler(fileHandler);
            logger.setUseParentHandlers(false);
        } catch (IOException e) {
            System.out.println("Erro ao configurar log: " + e.getMessage());
        }
    }

    public List<Usuario> listarUsuarios() {
        List<Usuario> usuarios = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(ARQUIVO))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                usuarios.add(Usuario.fromString(linha));
            }
        } catch (IOException e) {
            logger.warning("Erro ao listar usuários: " + e.getMessage());
        }
        return usuarios;
    }

    public void salvarUsuarios(List<Usuario> usuarios) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(ARQUIVO))) {
            for (Usuario u : usuarios) {
                bw.write(u.toString());
                bw.newLine();
            }
            logger.info("Usuários salvos com sucesso.");
        } catch (IOException e) {
            logger.severe("Erro ao salvar usuários: " + e.getMessage());
        }
    }

    public Usuario buscarPorNome(String nome) {
        for (Usuario u : listarUsuarios()) {
            if (u.getNome().equals(nome)) {
                return u;
            }
        }
        return null;
    }

    public void adicionarUsuario(Usuario usuario) {
        List<Usuario> usuarios = listarUsuarios();
        usuarios.add(usuario);
        salvarUsuarios(usuarios);
        logger.info("Usuário cadastrado: " + usuario.getNome());
    }
}
