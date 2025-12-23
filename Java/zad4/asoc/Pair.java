package asoc;

public class Pair implements Cloneable {
    public final String key;
    private double value;

    public Pair(String key, double value) {
         if (key == null)
            throw new IllegalArgumentException("Klucz nie moze byc nullem");
        if (key.isEmpty())
            throw new IllegalArgumentException("Klucz nie moze byc pusty");
        if (!key.matches("[a-z]+"))
            throw new IllegalArgumentException("Klucz musi zawierac tylko male litery a-z");
        this.key = key;
        this.value = value;
    }

    public double get() {
        return value;
    }

    public void set(double v) {
        this.value = v;
    }

    @Override
    public String toString() {
        return key + "=" + value;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Pair)) return false;
        Pair p = (Pair) o;
        return this.key.equals(p.key);
    }

    @Override
    public Pair clone() {
        try {
            return new Pair(this.key, this.value);
        } catch (Exception e) {
            throw new AssertionError(e);
        }
    }
}
