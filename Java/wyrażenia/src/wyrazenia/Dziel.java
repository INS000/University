package wyrazenia;

public class Dziel extends Operacja2arg {
    public Dziel(Wyrazenia argument, Wyrazenia argument2) {
        super(argument, argument2);
        if (argument2.oblicz() == 0) {
            throw new ArithmeticException("Division by zero");
        }
    }

    @Override
    public double oblicz() {
        return getArgument().oblicz() / getArgument2().oblicz();
    }

    @Override
    public String toString() {
        return "(" + getArgument() + " / " + getArgument2() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Dziel)) return false;
        if (this == obj) return true;
        Dziel other = (Dziel) obj;
        return getArgument().equals(other.getArgument()) && getArgument2().equals(other.getArgument2());
    }

}
