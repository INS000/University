package figury;

public class Prosta {
    public final double a;
    public final double b;
    public final double c;

    public Prosta(double a, double b, double c) {
        if (a == 0 && b == 0) {
            throw new IllegalArgumentException("Współczynniki a i b nie mogą być jednocześnie zerowe.");
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public String toString() {
        return String.format("prosta(%.2f x + %.2f y + %.2f = 0)", a, b, c);
    }

    public static Prosta przesun(Prosta prosta, Wektor wektor) {
        double newC = prosta.c - (prosta.a * wektor.dx + prosta.b * wektor.dy);
        return new Prosta(prosta.a, prosta.b, newC);
    }

    public static boolean saRownolegle(Prosta p1, Prosta p2) {
        return Math.abs((p1.a * p2.b) - (p2.a * p1.b)) < 1e-9;
    }

    public static boolean saProstopadle(Prosta p1, Prosta p2) {
        return Math.abs(p1.a * p2.a + p1.b * p2.b) < 1e-9;
    }

    public static Punkt punktPrzeciecia(Prosta p1, Prosta p2) {
        if (saRownolegle(p1, p2)) {
            throw new IllegalArgumentException("Proste są równoległe i nie mają punktu przecięcia.");
        }
        double wyznacznik = p1.a * p2.b - p2.a * p1.b;
        double x = (p1.c * (-p2.b) - p2.c * (-p1.b)) / wyznacznik;
        double y = (p2.c * (-p1.a) - p1.c * (-p2.a)) / wyznacznik;
        return new Punkt(x, y);
    }

}


