package asoc;

public class PairProb extends Pair {
    public PairProb(String key, double value) {
        super(key, value);
         if (Double.isNaN(value) || value < 0.0 || value > 1.0)
            throw new IllegalArgumentException("Prawdopodobienstwo musi byc z przedzialu [0, 1]");
    }

    @Override
    public void set(double v) {
        if (Double.isNaN(v) || v < 0.0 || v > 1.0)
            throw new IllegalArgumentException("Prawdopodobienstwo musi byc z przedzialu [0, 1]");
        super.set(v);
    }

    @Override
    public PairProb clone() {
        return new PairProb(this.key, this.get());
    }

    @Override
    public String toString() {
        return key + "=P(" + get() + ")";
    }
}
