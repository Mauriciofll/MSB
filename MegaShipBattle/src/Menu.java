import java.util.Scanner;

public class Menu {
    public void intro() {
        Scanner scanner = new Scanner(System.in);
        int opcao = 0;
        do {
            try {
                System.out.println("Boas vindas ao MSB! O que gostaria de jogar?\n1 - Desafio contra computador \n2 - Multijogador");
                opcao = scanner.nextInt();
            } catch (Exception e) {
                System.out.println("Opção inválida!");
            }
        } while (opcao != 1 && opcao != 2);
    }
}
