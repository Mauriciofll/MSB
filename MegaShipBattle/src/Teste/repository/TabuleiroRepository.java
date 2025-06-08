package Teste.repository;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

import Teste.model.Tabuleiro;

public class TabuleiroRepository {
    private static final String CAMINHO = "tabuleiros.txt";

    public static List<Tabuleiro> listarTodos() {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(CAMINHO))) {
            return (List<Tabuleiro>) in.readObject();
        } catch (Exception e) {
            return new ArrayList<>();
        }
    }

    public static void salvarTodos(List<Tabuleiro> tabuleiros) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(CAMINHO))) {
            out.writeObject(tabuleiros);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static List<Tabuleiro> listarPorUsuario(String dono) {
        List<Tabuleiro> todos = listarTodos();
        List<Tabuleiro> meus = new ArrayList<>();
        for (Tabuleiro t : todos) {
            if (t.getDono().equals(dono)) meus.add(t);
        }
        return meus;
    }
}
