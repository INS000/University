package wyrazenia;

public class Pot extends Funkcje2arg {
    public Pot(Wyrazenia podstawa, Wyrazenia wykladnik) {
        super(podstawa, wykladnik);
    }

    @Override
    public double oblicz() {
        double podstawaWartosc = this.getArgument().oblicz();
        double wykladnikWartosc = this.getArgument2().oblicz();
        return Math.pow(podstawaWartosc, wykladnikWartosc);
    }

    @Override
    public String toString() {
        return "(" + getArgument() + ")^(" + getArgument2() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Pot)) return false;
        if (this == obj) return true;
        return getArgument().equals(((Pot) obj).getArgument()) &&
               getArgument2().equals(((Pot) obj).getArgument2());
    }

}
