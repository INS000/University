package wyrazenia;

public class Exp extends Funkcje1arg {
    public Exp(Wyrazenia argument) {
        super(argument);
    }

    @Override
    public double oblicz() {
        return Math.exp(getArgument().oblicz());
    }

    @Override
    public String toString() {
        return "e^(" + getArgument() + ")";
    }


    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Exp)) return false;
        if (this == obj) return true;
        return getArgument().equals(((Exp) obj).getArgument());
    }
}
