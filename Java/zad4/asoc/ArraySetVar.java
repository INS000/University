package asoc;

public class ArraySetVar extends SetVar {
    protected Pair[] vars;
    protected int siz;

    public ArraySetVar(int capacity) {
        if (capacity < 0)
            throw new IllegalArgumentException("Pojemnosc musi byc nieujemna");
        this.vars = new Pair[capacity];
        this.siz = 0;
    }

    private int indexOf(String k) {
        for (int i = 0; i < siz; i++) {
            if (vars[i].key.equals(k))
                return i;
        }
        return -1;
    }

    @Override
    public void set(String k, double v) {
        int idx = indexOf(k);
        if (idx >= 0) {
            vars[idx].set(v);
        } else {
            if (siz >= vars.length)
                throw new IllegalStateException("Nie ma miejsca na zmienna: " + k);
            vars[siz++] = new Pair(k, v);
        }
    }

    public void addPair(Pair p) {
        vars[siz++] = p;
    }

    @Override
    public double get(String k) {
        int idx = indexOf(k);
        if (idx < 0)
            throw new java.util.NoSuchElementException("Zmienna " + k + " nie istnieje");
        return vars[idx].get();
    }

    @Override
    public boolean search(String k) {
        return indexOf(k) >= 0;
    }

    @Override
    public String[] names() {
        String[] arr = new String[siz];
        for (int i = 0; i < siz; i++)
            arr[i] = vars[i].key;
        return arr;
    }

    @Override
    public void del(String k) {
        int idx = indexOf(k);
        if (idx < 0) return;
        int move = siz - idx - 1;
        if (move > 0)
            System.arraycopy(vars, idx + 1, vars, idx, move);
        vars[--siz] = null;
    }

    @Override
    public int size() {
        return siz;
    }

    @Override
    public void clear() {
        for (int i = 0; i < siz; i++)
            vars[i] = null;
        siz = 0;
    }

    @Override
    public String toString() {
        return super.defaultToString();
    }

    @Override
    public ArraySetVar clone() {
        try {
            ArraySetVar copy = (ArraySetVar) super.clone();
            copy.vars = this.vars.clone();
            for (int i = 0; i < this.siz; i++) {
                Pair p = this.vars[i];
                copy.vars[i] = p.clone();
            }
            copy.siz = this.siz;
            return copy;
        } catch (CloneNotSupportedException e) {
            throw new AssertionError(e);
        }
    }

}
