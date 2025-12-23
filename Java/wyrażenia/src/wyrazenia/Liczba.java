package wyrazenia;

public class Liczba extends Wyrazenia {
    private final double wartosc;

    public Liczba(double wartosc) {
        this.wartosc = wartosc;
    }

    @Override
    public double oblicz() {
        return wartosc;
    }

    @Override
    public String toString() {
        return Double.toString(wartosc);
    }

   @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Liczba)) return false;
        if (this == obj) return true;
        return this.wartosc == ((Liczba) obj).wartosc;
    }

}
