package Teste.repository;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

import Teste.model.Usuario;

public class UsuarioRepository {
    private static final String CAMINHO = "usuarios.txt";

    public static List<Usuario> carregarUsuarios() {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(CAMINHO))) {
            return (List<Usuario>) in.readObject();
        } catch (Exception e) {
            return new ArrayList<>();
        }
    }

    public static void salvarUsuarios(List<Usuario> usuarios) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(CAMINHO))) {
            out.writeObject(usuarios);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
