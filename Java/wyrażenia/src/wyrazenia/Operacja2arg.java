package wyrazenia;

public class Operacja2arg extends Operacja1arg {
    public Operacja2arg(Wyrazenia argument, Wyrazenia argument2) {
        super(argument);
        this.argument2 = argument2;
    }

    private final Wyrazenia argument2;

    public Wyrazenia getArgument2() {
        return argument2;
    }

    @Override
    public double oblicz() {
        return 0;
    }

    @Override
    public String toString() {
        return "Operacja2arg(" + getArgument() + ", " + argument2 + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Operacja2arg)) return false;
        if (this == obj) return true;
        Operacja2arg other = (Operacja2arg) obj;
        return getArgument().equals(other.getArgument()) && argument2.equals(other.argument2);
    }


}
