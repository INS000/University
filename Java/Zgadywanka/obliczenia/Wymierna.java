package obliczenia;

public class Wymierna implements Comparable<Wymierna> {
    private final int licznik;
    private final int mianownik;

    public Wymierna() {
        this(0, 1);
    }

    public Wymierna(int licznik) {
        this(licznik, 1);
    }

    public Wymierna(int licznik, int mianownik) {
        if (mianownik == 0) {
            throw new IllegalArgumentException("Mianownik nie moze byc zerem.");
        }

        int gcd = gcd(Math.abs(licznik), Math.abs(mianownik));
        if(mianownik < 0) {
            gcd = -gcd;
        }

        this.licznik = licznik / gcd;

        if(licznik == 0) {
            this.mianownik = 1;
        }
        else {
            this.mianownik = mianownik / gcd;
        }

    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public int getLicznik() {
        return licznik;
    }

    public int getMianownik() {
        return mianownik;
    }

    @Override
    public String toString() {
        if (mianownik == 1) {
            return Integer.toString(licznik);
        }
        return licznik + "/" + mianownik;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Wymierna)) return false;
        Wymierna other = (Wymierna) obj;
        return this.licznik == other.licznik && this.mianownik == other.mianownik;
    }

    @Override
    public int compareTo(Wymierna other) {
        return Long.compare((long)this.licznik * other.mianownik, (long)other.licznik * this.mianownik);
    }

    public static Wymierna dodaj(Wymierna a, Wymierna b) {
        int newLicznik = a.licznik * b.mianownik + b.licznik * a.mianownik;
        int newMianownik = a.mianownik * b.mianownik;
        return new Wymierna(newLicznik, newMianownik);
    }

    public static Wymierna odejmij(Wymierna a, Wymierna b) {
        int newLicznik = a.licznik * b.mianownik - b.licznik * a.mianownik;
        int newMianownik = a.mianownik * b.mianownik;
        return new Wymierna(newLicznik, newMianownik);
    }

    public static Wymierna pomnoz(Wymierna a, Wymierna b) {
        int newLicznik = a.licznik * b.licznik;
        int newMianownik = a.mianownik * b.mianownik;
        return new Wymierna(newLicznik, newMianownik);
    }

    public static Wymierna podziel(Wymierna a, Wymierna b) {
        if (b.licznik == 0) {
            throw new ArithmeticException("Nie mozna dzielic przez zero.");
        }
        int newLicznik = a.licznik * b.mianownik;
        int newMianownik = a.mianownik * b.licznik;
        return new Wymierna(newLicznik, newMianownik);
    }

}
