package wyrazenia;

public class Funkcje2arg extends Funkcje1arg {
    private final Wyrazenia argument2;

    public Funkcje2arg(Wyrazenia argument1, Wyrazenia argument2) {
        super(argument1);
        this.argument2 = argument2;
    }

    public Wyrazenia getArgument2() {
        return argument2;
    }

    // Placeholder
    @Override
    public double oblicz() {
        return 0;
    }

    @Override
    public String toString() {
        return "Funkcje2arg(" + getArgument() + ", " + argument2 + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Funkcje2arg)) return false;
        if (this == obj) return true;
        Funkcje2arg other = (Funkcje2arg) obj;
        return getArgument().equals(other.getArgument()) && argument2.equals(other.argument2);
    }
}
