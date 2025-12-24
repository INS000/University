import java.util.*;

public class zad1 {
    private static String[] rzymskie = {"M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    private static int[] arabskie = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    // private static String[] patroni = {"Małpa", "Kurczak", "Pies", "Świnia", "Szczur", "Bawół", "Tygrys", "Królik", "Smok", "Wąż", "Koń", "Koza"};

    private static String printRoman(int number) {

        if(number <= 0 || number >= 4000) {
            throw new IllegalArgumentException("rok" + number + " spoza zakresu");
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < arabskie.length; i++) {
            while (number >= arabskie[i]) {
                result.append(rzymskie[i]);
                number -= arabskie[i];
            }
        }
        return result.toString();
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.err.print("Jak sie nazywasz? ");
        String name = scanner.nextLine();
        System.out.println("Cześć, " + name + "!");
        System.err.print("W ktorym roku sie urodziles? ");
        int birthYear = scanner.nextInt();
        System.out.println("Twój rok urodzenia w systemie rzymskim to: " + printRoman(birthYear));
        int patron = (birthYear % 12);
        String patronName =

        switch (patron) {
            case 0 -> "Małpa";
            case 1 -> "Kurczak";
            case 2 -> "Pies";
            case 3 -> "Świnia";
            case 4 -> "Szczur";
            case 5 -> "Bawół";
            case 6 -> "Tygrys";
            case 7 -> "Królik";
            case 8 -> "Smok";
            case 9 -> "Wąż";
            case 10 -> "Koń";
            case 11 -> "Koza";
            default -> "Hahaha";
        };
        System.out.println("Twoim chińskim patronem jest " + patronName);
        scanner.close();
    }
}
