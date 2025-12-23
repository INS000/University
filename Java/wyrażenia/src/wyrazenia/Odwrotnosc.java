package wyrazenia;

public class Odwrotnosc extends Operacja1arg {
    public Odwrotnosc(Wyrazenia argument) {
        super(argument);
    }

    @Override
    public double oblicz() {
        return 1.0 / getArgument().oblicz();
    }

    @Override
    public String toString() {
        return "!(" + getArgument() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Odwrotnosc)) return false;
        if (this == obj) return true;
        Odwrotnosc other = (Odwrotnosc) obj;
        return getArgument().equals(other.getArgument());
    }

}
