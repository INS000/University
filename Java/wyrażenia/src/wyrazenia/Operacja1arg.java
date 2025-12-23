package wyrazenia;

public class Operacja1arg extends Wyrazenia {
    private Wyrazenia argument;

    public Operacja1arg(Wyrazenia argument) {
        this.argument = argument;
    }

    public Wyrazenia getArgument() {
        return argument;
    }

    @Override
    public double oblicz() {
        return 0;
    }

    @Override
    public String toString() {
        return "Operacja1arg(" + argument + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Operacja1arg)) return false;
        if (this == obj) return true;
        Operacja1arg other = (Operacja1arg) obj;
        return argument.equals(other.argument);
    }
}
