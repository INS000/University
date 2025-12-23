import figury.*;

/**
 * Program testujący funkcjonalność klas w pakiecie figury.
 * Uruchom i sprawdź wypisy na konsolę.
 */
public class Testy {
    public static void main(String[] args) {
        System.out.println("=== Test klas figury ===");

        // Punkty
        Punkt p1 = new Punkt(0, 0);
        Punkt p2 = new Punkt(3, 0);
        Punkt p11 = new Punkt(0, 0);
        Punkt p22 = new Punkt(3, 0);
        Punkt p3 = new Punkt(0, 4);

        System.out.println("Punkty początkowe:");
        System.out.println("p1 = " + p1);
        System.out.println("p2 = " + p2);
        System.out.println("p3 = " + p3);

        // Odcinek
        Odcinek od = new Odcinek(p1, p2);
        System.out.println("\nOdcinek początkowy: " + od + ", długość = " + od.dlugosc());

        // Trójkąt
        Trojkat t = new Trojkat(p11, p22, p3);
        System.out.println("\nTrójkąt początkowy: " + t + ", pole = " + t.pole());

        // Wektor i Prosta
        Wektor w = new Wektor(1, 2);
        System.out.println("\nWektor przesunięcia: " + w);

        Prosta prosta = new Prosta(1, -1, 0); // x - y = 0 (prosta y = x)
        System.out.println("Prosta: " + prosta);

        // Test przesunięć
        System.out.println("\n-- Test: przesun(w) --");
        od.przesun(w);
        System.out.println("Odcinek po przesunięciu: " + od);
        t.przesun(w);
        System.out.println("Trójkąt po przesunięciu: " + t);

        // Test obrotu: obróć wokół punktu (0,0) o 90 stopni (pi/2)
        System.out.println("\n-- Test: obroc(pivot, kat) --");
        Punkt pivot = new Punkt(0, 0);
        od.obroc(pivot, Math.PI / 2.0);
        System.out.println("Odcinek po obrocie o 90° wokół (0,0): " + od);
        t.obroc(pivot, Math.PI / 2.0);
        System.out.println("Trójkąt po obrocie o 90° wokół (0,0): " + t);

        // Test odbicia względem prostej y = x (x - y = 0)
        System.out.println("\n-- Test: odbij(prosta) --");
        od.odbij(prosta);
        System.out.println("Odcinek po odbiciu względem y=x: " + od);
        t.odbij(prosta);
        System.out.println("Trójkąt po odbiciu względem y=x: " + t);

        // Test klasy Prosta: przesunięcie prostej o wektor, równoległość, prostopadłość, przecięcie
        System.out.println("\n-- Test: Prosta statyczne --");
        Prosta pA = new Prosta(1, -1, 0); // y = x
        Prosta pB = new Prosta(1, 1, -4); // x + y -4 = 0
        System.out.println("pA = " + pA);
        System.out.println("pB = " + pB);
        System.out.println("pA równoległa do pB? " + Prosta.saRownolegle(pA, pB));
        System.out.println("pA prostopadła do pB? " + Prosta.saProstopadle(pA, pB));
        Punkt px = Prosta.punktPrzeciecia(pA, pB);
        System.out.println("Punkt przecięcia pA i pB: " + px);

        Prosta pAshift = Prosta.przesun(pA, new Wektor(2, 3));
        System.out.println("pA przesunięta o (2,3): " + pAshift);

        // Test Wektor.zloz
        Wektor w2 = new Wektor(-1, 1);
        Wektor wsum = Wektor.zloz(w, w2);
        System.out.println("\nSuma wektorów " + w + " + " + w2 + " = " + wsum);

        // Próby konstrukcyjne powodujące wyjątki (obsłużymy je i wypiszemy komunikaty)
        System.out.println("\n-- Test walidacji konstruktorów (oczekiwane wyjątki) --");
        try {
            new Odcinek(new Punkt(1,1), new Punkt(1,1));
        } catch (IllegalArgumentException ex) {
            System.out.println("Oczekiwany błąd (Odcinek): " + ex.getMessage());
        }

        try {
            new Trojkat(new Punkt(0,0), new Punkt(1,1), new Punkt(2,2)); // współliniowe
        } catch (IllegalArgumentException ex) {
            System.out.println("Oczekiwany błąd (Trojkat): " + ex.getMessage());
        }

        System.out.println("\n=== Test zakończony ===");
    }
}
