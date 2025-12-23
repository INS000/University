import obliczenia.Wymierna;
import rozgrywka.Gra;
import rozgrywka.wyjatki.*;

import java.util.Scanner;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.logging.*;


public class Zgadywanka {
    private static final Logger LOGGER = Logger.getLogger("rozgrywka");

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("logging.properties")) {
            LogManager.getLogManager().readConfiguration(fis);
        } catch (IOException e) {
            System.err.println("Nie udało się wczytać logging.properties: " + e.getMessage());
        }

        LOGGER.info("Uruchomiono program Zgadywanka");
        Scanner sc = new Scanner(System.in);
        System.out.print("Podaj swoje imię: ");
        String imie = sc.nextLine().trim();
        LOGGER.info("Gracz: " + imie);

        Gra gra = new Gra();

        int zakres = 0;
        while (true) {
            try {
                System.out.print("Podaj zakres Z (liczba całkowita 5..20): ");
                String line = sc.nextLine().trim();
                zakres = Integer.parseInt(line);
                gra.start(zakres);
                LOGGER.info("Rozpoczęto grę z zakresem Z=" + zakres + ". Maksymalna liczba prób=" + gra.getMaksIloscProb());
                break;
            } catch (NumberFormatException ex) {
                System.out.println("Proszę podać liczbę całkowitą.");
                LOGGER.warning("Błędny format zakresu: nie liczba");
            } catch (IllegalArgumentException ex) {
                System.out.println("Niepoprawny zakres: " + ex.getMessage());
                LOGGER.warning("Niepoprawny zakres: " + ex.getMessage());
            }
        }

        System.out.println("Zgadnij wylosowaną liczbę wymierną a/b z przedziału (0,1). Format: a/b");
        System.out.println("Możesz się poddać wpisując 'poddaj'.");

        while (!gra.isKoniec()) {
            System.out.printf("Pozostało prób: %d. Podaj swój typ: ", gra.pozostaleProby());
            String input = sc.nextLine().trim();
            if (input.equalsIgnoreCase("poddaj")) {
                gra.poddaj();
                LOGGER.info(imie + " poddał się.");
                break;
            }
            try {
                Wymierna guess = parseInputToWymierna(input);
                // sprawdzenia: czy 0 < a < b <= zakres
                if (!(guess.getLicznik() > 0 && guess.getLicznik() < guess.getMianownik())) {
                    throw new OutOfRangeException("Ułamek musi być w (0,1).");
                }
                if (guess.getMianownik() > gra.getZakres()) {
                    throw new OutOfRangeException("Mianownik przekracza zakres Z=" + gra.getZakres());
                }
                LOGGER.info(imie + " próbuje: " + guess);
                int res = gra.zgaduj(guess);
                if (res == 0) {
                    System.out.println("Zgadłeś! Brawo!");
                    LOGGER.info(imie + " wygrał.");
                    break;
                } else if (res < 0) {
                    System.out.println("Za mało.");
                    LOGGER.fine("Odpowiedź: za mało");
                } else {
                    System.out.println("Za dużo.");
                    LOGGER.fine("Odpowiedź: za dużo");
                }

            } catch (InvalidFormatException e) {
                System.out.println("Błędny format: " + e.getMessage());
                LOGGER.warning("Błędny format wejścia: " + input);
            } catch (OutOfRangeException e) {
                System.out.println("Błąd: " + e.getMessage());
                LOGGER.warning("Błąd walidacji: " + e.getMessage());
            } catch (IllegalStateException e) {
                System.out.println("Gra zakończona.");
                LOGGER.warning("Wywołanie zgaduj po zakończeniu gry");
                break;
            } catch (Exception e) {
                System.out.println("Wystąpił błąd: " + e.getMessage());
                LOGGER.log(Level.SEVERE, "Nieoczekiwany błąd", e);
                break;
            }
        }

        if (gra.isOdgadniete()) {
            System.out.println("Koniec gry: Wygrałeś!");
        } else {
            System.out.println("Koniec gry: nie udało się odgadnąć. Komputer wygrywa.");
            System.out.println("Wylosowana liczba to: " + gra.getLiczba());
            LOGGER.info("Koniec gry: gracz przegrał / poddał się.");
        }

        LOGGER.info("Zakończono program Zgadywanka");
        LOGGER.info("=========================================");
        sc.close();
    }

    private static Wymierna parseInputToWymierna(String s) throws InvalidFormatException {
        if (s == null || s.isEmpty()) throw new InvalidFormatException("Pusty ciąg");
        s = s.trim();
        try {
            if (s.contains("/")) {
                String[] parts = s.split("/");
                if (parts.length != 2) throw new InvalidFormatException("Format powinien być a/b");
                int a = Integer.parseInt(parts[0].trim());
                int b = Integer.parseInt(parts[1].trim());
                return new Wymierna(a, b);
            } else {
                int a = Integer.parseInt(s);
                return new Wymierna(a, 1);
            }
        } catch (NumberFormatException ex) {
            throw new InvalidFormatException("Niepoprawne liczby w ułamku");
        } catch (IllegalArgumentException ex) {
            throw new InvalidFormatException("Błąd przy tworzeniu ułamka: " + ex.getMessage());
        }
    }
}
