package wyrazenia;

public class Ln extends Funkcje1arg {
    public Ln(Wyrazenia argument) {
        super(argument);
    }

    @Override
    public double oblicz() {
        return Math.log(getArgument().oblicz());
    }

    @Override
    public String toString() {
        return "ln(" + getArgument() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Ln)) return false;
        if (this == obj) return true;
        return getArgument().equals(((Ln) obj).getArgument());
    }
}
