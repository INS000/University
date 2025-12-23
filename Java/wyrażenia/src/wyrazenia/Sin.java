package wyrazenia;

public class Sin extends Funkcje1arg {
    public Sin(Wyrazenia argument) {
        super(argument);
    }

    @Override
    public double oblicz() {
        return Math.sin(getArgument().oblicz());
    }

    @Override
    public String toString() {
        return "sin(" + getArgument() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Sin)) return false;
        if (this == obj) return true;
        return getArgument().equals(((Sin) obj).getArgument());
    }
}
