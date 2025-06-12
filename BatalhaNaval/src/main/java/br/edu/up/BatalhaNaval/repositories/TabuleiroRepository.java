package br.edu.up.BatalhaNaval.repositories;

import br.edu.up.BatalhaNaval.models.Tabuleiro;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class TabuleiroRepository {
    private static final String CAMINHO = "tabuleiros.txt";

    /**
     * Lista todos os tabuleiros cadastrados.
     */
    public static List<Tabuleiro> listarTodos() {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(CAMINHO))) {
            return (List<Tabuleiro>) in.readObject();
        } catch (Exception e) {
            return new ArrayList<>();
        }
    }

    /**
     * Salva um novo tabuleiro ao arquivo.
     */
    public static void salvarTodos(List<Tabuleiro> tabuleiros) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(CAMINHO))) {
            out.writeObject(tabuleiros);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Lista todos os tabuleiros de um dono específico.
     * @param dono - Refere-se ao nome do dono qual os tabuleiros devem ser retornados.
     */
    public static List<Tabuleiro> listarPorUsuario(String dono) {
        List<Tabuleiro> todos = listarTodos();
        List<Tabuleiro> meus = new ArrayList<>();
        for (Tabuleiro t : todos) {
            if (t.getDono().equals(dono)) meus.add(t);
        }
        return meus;
    }
}
