package figury;

public class Odcinek {
    private Punkt p1;
    private Punkt p2;

    public Odcinek(Punkt p1, Punkt p2) {
        if(p1 == null || p2 == null) {
            throw new IllegalArgumentException("Punkty nie mogą być null.");
        }
        if(p1.getX() == p2.getX() && p1.getY() == p2.getY()) {
            throw new IllegalArgumentException("Punkty nie mogą być identyczne.");
        }
        this.p1 = p1;
        this.p2 = p2;
    }

    public Punkt getP1() {
        return p1;
    }

    public Punkt getP2() {
        return p2;
    }

    public void setP1(Punkt p1) {
        this.p1 = p1;
    }

    public void setP2(Punkt p2) {
        this.p2 = p2;
    }

    @Override
    public String toString() {
        return String.format("odcinek[%s, %s]", p1, p2);
    }

    public double dlugosc() {
        return p1.odleglosc(p2);
    }

    public void przesun(Wektor wektor) {
        p1.przesun(wektor);
        p2.przesun(wektor);
    }

    public void obroc(Punkt srodek, double kat) {
        p1.obroc(srodek, kat);
        p2.obroc(srodek, kat);
    }

    public void odbij(Prosta prosta) {
        p1.odbij(prosta);
        p2.odbij(prosta);
    }

}
