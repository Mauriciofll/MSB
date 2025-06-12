package br.edu.up.BatalhaNaval.repositories;

import br.edu.up.BatalhaNaval.models.Usuario;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class UsuarioRepository {
    private static final String CAMINHO = "usuarios.txt";

    /**
     * Lista os usuários cadastrados.
     */
    @SuppressWarnings("unchecked")
    public static List<Usuario> carregarUsuarios() {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(CAMINHO))) {
            return (List<Usuario>) in.readObject();
        } catch (Exception e) {
            return new ArrayList<>();
        }
    }

    /**
     * Salva um novo usuário.
     */
    public static void salvarUsuarios(List<Usuario> usuarios) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(CAMINHO))) {
            out.writeObject(usuarios);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
