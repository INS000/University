package wyrazenia;

public class Dodaj extends Operacja2arg {
    public Dodaj(Wyrazenia argument, Wyrazenia argument2) {
        super(argument, argument2);
    }

    @Override
    public double oblicz() {
        return getArgument().oblicz() + getArgument2().oblicz();
    }

    @Override
    public String toString() {
        return "(" + getArgument() + " + " + getArgument2() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Dodaj)) return false;
        if (this == obj) return true;
        Dodaj other = (Dodaj) obj;
        return getArgument().equals(other.getArgument()) && getArgument2().equals(other.getArgument2());
    }

}
