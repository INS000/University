package wyrazenia;

public class Stala extends Wyrazenia {
    private final double wartosc;
    private final String nazwa;

    public Stala(String nazwa, double wartosc) {
        this.nazwa = nazwa;
        this.wartosc = wartosc;
    }

    @Override
    public String toString() {
        return nazwa;
    }

    @Override
    public double oblicz() {
        return wartosc;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Stala)) return false;
        if (this == obj) return true;
        return this.wartosc == ((Stala) obj).wartosc && this.nazwa.equals(((Stala) obj).nazwa);
    }

    public static final Stala Pi = new Stala("Pi", Math.PI);
    public static final Stala E = new Stala("e", Math.E);
}


