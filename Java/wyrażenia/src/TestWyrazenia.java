import wyrazenia.*;

public class TestWyrazenia {

    public static void main(String[] args) {


        // 1. 7 + 5 * π - 1
        Wyrazenia w1 = new Odejmij(
                new Dodaj(
                    new Liczba(7),
                    new Mnoz(
                        new Liczba(5),
                        Stala.Pi)),
                new Liczba(1)
        );
        System.out.println("Wyrażenie 1: " + w1);
        System.out.println("Wynik: " + w1.oblicz());
        System.out.println("Oczekiwane: " + (7 + 5 * Math.PI - 1));
        System.out.println();

        // 2. ~(2 - x) * e
        Wyrazenia w2 = new Mnoz(
                new Przeciwnosc(
                    new Odejmij(
                        new Liczba(2),
                        new Stala("x", 4))),
                Stala.E
        );
        System.out.println("Wyrażenie 2: " + w2);
        System.out.println("Wynik: " + w2.oblicz());
        System.out.println("Oczekiwane: " + (-(2 - 4) * Math.E));
        System.out.println();

        // 3. (3 * π - 1) / (!x + 5)
        Wyrazenia w3 = new Dziel(
                new Odejmij(
                    new Mnoz(
                        new Liczba(3),
                        Stala.Pi),
                    new Liczba(1)),
                new Dodaj(
                    new Odwrotnosc(new Stala("x", 2)),
                    new Liczba(5))
        );
        System.out.println("Wyrażenie 3: " + w3);
        System.out.println("Wynik: " + w3.oblicz());
        System.out.println("Oczekiwane: " + (((3 * Math.PI) - 1) / ((1.0 / 2) + 5)));
        System.out.println();

        // 4. sin((x + 13) * π / (1 - x))
        Wyrazenia w4 = new Sin(
                new Dziel(
                        new Mnoz(
                            new Dodaj(
                                new Stala("x", 2),
                                new Liczba(13)),
                            Stala.Pi),
                        new Odejmij(
                            new Liczba(1),
                            new Stala("x", 2))
                        )
        );
        System.out.println("Wyrażenie 4: " + w4);
        System.out.println("Wynik: " + w4.oblicz());
        System.out.println("Oczekiwane: " + Math.sin(((2 + 13) * Math.PI) / (1 - 2)));
        System.out.println();

        // 5. exp(5) + x * log(e, x)
        Wyrazenia w5 = new Dodaj(
                new Exp(new Liczba(5)),
                new Mnoz(
                    new Stala("x", 2),
                    new Log(
                        Stala.E,
                        new Stala("x", 2)))
        );
        System.out.println("Wyrażenie 5: " + w5);
        System.out.println("Wynik: " + w5.oblicz());
        System.out.println("Oczekiwane: " + (Math.exp(5) + 2 * (Math.log(2) / Math.log(Math.E))));
        System.out.println();

        // 6. Test metod suma() i iloczyn()
        Wyrazenia a = new Liczba(2);
        Wyrazenia b = new Liczba(3);
        Wyrazenia c = new Liczba(4);
        System.out.println("Suma(2,3,4) = " + Wyrazenia.suma(a, b, c) + " (oczekiwane: 9)");
        System.out.println("Iloczyn(2,3,4) = " + Wyrazenia.iloczyn(a, b, c) + " (oczekiwane: 24)");
        System.out.println();

        // 7. Test equals()
        Wyrazenia w6a = new Dodaj(new Liczba(5), new Stala("x", 2));
        Wyrazenia w6b = new Dodaj(new Liczba(5), new Stala("x", 2));
        Wyrazenia w6c = new Odejmij(new Liczba(5), new Stala("x", 2));

        System.out.println("Equals test 1 (powinno być true): " + w6a.equals(w6b));
        System.out.println("Equals test 2 (powinno być false): " + w6a.equals(w6c));
        System.out.println();
    }
}
