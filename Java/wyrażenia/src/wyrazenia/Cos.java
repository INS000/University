package wyrazenia;

public class Cos extends Funkcje1arg {
    public Cos(Wyrazenia argument) {
        super(argument);
    }

    @Override
    public double oblicz() {
        return Math.cos(getArgument().oblicz());
    }

    @Override
    public String toString() {
        return "cos(" + getArgument() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Cos)) return false;
        if (this == obj) return true;
        return getArgument().equals(((Cos) obj).getArgument());
    }
}
