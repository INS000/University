import java.util.*;

public class zad1 {
    private static String[] rzymskie = {"M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    private static int[] arabskie = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    private static String[] patroni = {"Małpa", "Kurczak", "Pies", "Świnia", "Szczur", "Bawół", "Tygrys", "Królik", "Smok", "Wąż", "Koń", "Koza"};

    private static void printRoman(int number) {

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
        System.out.println("Twój rok urodzenia w systemie rzymskim to: " + result.toString());
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.err.print("Jak sie nazywasz? ");
        String name = scanner.nextLine();
        System.out.println("Cześć, " + name + "!");
        System.err.print("W ktorym roku sie urodziles? ");
        int birthYear = scanner.nextInt();
        printRoman(birthYear);
        int patron = (birthYear % 12);
        String patronName;

        switch (patron) {
            case 0:
                patronName = "Małpa";
                break;
            case 1:
                patronName = "Kurczak";
                break;
            case 2:
                patronName = "Pies";
                break;
            case 3:
                patronName = "Świnia";
                break;
            case 4:
                patronName = "Szczur";
                break;
            case 5:
                patronName = "Bawół";
                break;
            case 6:
                patronName = "Tygrys";
                break;
            case 7:
                patronName = "Królik";
                break;
            case 8:
                patronName = "Smok";
                break;
            case 9:
                patronName = "Wąż";
                break;
            case 10:
                patronName = "Koń";
                break;
            case 11:
                patronName = "Koza";
                break;
            default:
                patronName = "Hahaha";
        }
        System.out.println("Twoim chińskim patronem jest " + patronName);
        scanner.close();
    }
}
