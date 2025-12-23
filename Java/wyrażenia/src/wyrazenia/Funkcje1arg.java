package wyrazenia;

public class Funkcje1arg extends Wyrazenia {
    private final Wyrazenia argument;

    public Funkcje1arg(Wyrazenia argument) {
        this.argument = argument;
    }

    Wyrazenia getArgument() {
        return argument;
    }

    // Placeholder
    @Override
    public double oblicz() {
        return 0;
    }

    @Override
    public String toString() {
        return "Funkcje1arg(" + argument + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Funkcje1arg)) return false;
        if (this == obj) return true;
        return this.argument.equals(((Funkcje1arg) obj).argument);
    }
}
