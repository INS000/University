package wyrazenia;

public class Log extends Funkcje2arg {
    public Log(Wyrazenia podstawa, Wyrazenia argument) {
        super(podstawa, argument);
    }

    @Override
    public double oblicz() {
        double podstawaWartosc = this.getArgument().oblicz();
        double argumentWartosc = this.getArgument2().oblicz();
        return Math.log(argumentWartosc) / Math.log(podstawaWartosc);
    }

    @Override
    public String toString() {
        return "log_(" + getArgument() + ")(" + getArgument2() + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Log)) return false;
        if (this == obj) return true;
        return getArgument().equals(((Log) obj).getArgument()) &&
               getArgument2().equals(((Log) obj).getArgument2());
    }
}
