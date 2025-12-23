package wyrazenia;

public class Przeciwnosc extends Operacja1arg {
    public Przeciwnosc(Wyrazenia argument) {
        super(argument);
    }

    @Override
    public double oblicz() {
        return -getArgument().oblicz();
    }

    @Override
    public String toString() {
        return "~(" + getArgument() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Przeciwnosc)) return false;
        if (this == obj) return true;
        Przeciwnosc other = (Przeciwnosc) obj;
        return getArgument().equals(other.getArgument());
    }

}
