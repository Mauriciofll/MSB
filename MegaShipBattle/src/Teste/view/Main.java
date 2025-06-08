package Teste.view;

import java.util.Scanner;

import Teste.controller.LoginController;
import Teste.model.Usuario;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LoginController ctrl = new LoginController();
        Usuario logado = new Usuario();

        while (logado == null) {
            System.out.println("1 - Cadastrar\n2 - Entrar");
            int op = sc.nextInt(); sc.nextLine();
            System.out.print("Nome de usuário: ");
            String nome = sc.nextLine();
            System.out.print("Senha: ");
            String senha = sc.nextLine();
            if (op == 1) {
                if (ctrl.cadastrar(nome, senha, false)) System.out.println("Cadastrado!");
                else System.out.println("Esse nome de usuário não está disponível.");
            } else {
                logado = ctrl.logar(nome, senha);
                if (logado == null) System.out.println("Falha no login.");
            }
        }

        boolean sair = false;
        while (!sair) {
            System.out.println("\n1 - Alterar conta\n2 - Apagar conta \n3 - Ranking \n4 - Sair");
            if (ctrl.isAdmin(logado)) {
                System.out.println("5 - Listar usuários \n6 - Editar usuário \n7 - Remover usuário");
            }
            int op = sc.nextInt(); sc.nextLine();
            switch (op) {
                case 1:
                    System.out.print("Novo nome: ");
                    String nn = sc.nextLine();
                    System.out.print("Nova senha: ");
                    String ns = sc.nextLine();
                    if (ctrl.atualizarUsuario(logado, nn, ns)) {
                        System.out.println("Atualizado!");
                        logado = ctrl.logar(nn, ns);
                    } else {
                        System.out.println("Nome já existe.");
                    }
                    break;
                case 2:
                    ctrl.deletarProprioUsuario(logado);
                    System.out.println("Conta apagada.");
                    sair = true;
                    break;
                case 3:
                    System.out.println(ctrl.gerarRanking());
                    break;
                case 4:
                    sair = true;
                    break;
                case 5:
                    if (ctrl.isAdmin(logado)) {
                        for (Usuario u : ctrl.listarTodosUsuarios())
                            System.out.printf("- %s | %s | %d\n", u.getNome(), u.getSenha(), u.getPontuacao());
                    }
                    break;
                case 6:
                    if (ctrl.isAdmin(logado)) {
                        System.out.print("Usuário atual: ");
                        String atual = sc.nextLine();
                        System.out.print("Novo nome: ");
                        String novo = sc.nextLine();
                        System.out.print("Nova senha: ");
                        String ns2 = sc.nextLine();
                        System.out.print("Nova pontuação: ");
                        int pts = sc.nextInt(); sc.nextLine();
                        if (ctrl.adminAtualizarUsuario(atual, novo, ns2, pts)) System.out.println("Editado.");
                        else System.out.println("Erro!");
                    }
                    break;
                case 7:
                    if (ctrl.isAdmin(logado)) {
                        System.out.print("Nome do usuário: ");
                        String nomeDel = sc.nextLine();
                        if (ctrl.adminRemoverUsuario(nomeDel)) System.out.println("Removido.");
                        else System.out.println("Erro!");
                    }
                    break;
            }
        }

        sc.close();

    }
}
