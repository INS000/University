package figury;

public class Trojkat {
    private Punkt p1;
    private Punkt p2;
    private Punkt p3;

    public Trojkat(Punkt p1, Punkt p2, Punkt p3) {
        if(p1 == null || p2 == null || p3 == null) {
            throw new IllegalArgumentException("Punkty nie mogą być null.");
        }
        if(p1.equals(p2) || p1.equals(p3) || p2.equals(p3)) {
            throw new IllegalArgumentException("Punkty nie mogą być identyczne.");
        }
        double area = 0.5 * Math.abs(
                p1.getX() * (p2.getY() - p3.getY()) +
                p2.getX() * (p3.getY() - p1.getY()) +
                p3.getX() * (p1.getY() - p2.getY())
        );
        if(area < 1e-9) {
            throw new IllegalArgumentException("Punkty nie mogą być współliniowe.");
        }

        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public Punkt getP1() {
        return p1;
    }

    public Punkt getP2() {
        return p2;
    }

    public Punkt getP3() {
        return p3;
    }

    public void setP1(Punkt p1) {
        this.p1 = p1;
    }

    public void setP2(Punkt p2) {
        this.p2 = p2;
    }

    public void setP3(Punkt p3) {
        this.p3 = p3;
    }

    @Override
    public String toString() {
        return String.format("trojkat{p1 = %s, p2 = %s, p3 = %s}", p1, p2, p3);
    }

    public double pole() {
        return 0.5 * Math.abs(
                p1.getX() * (p2.getY() - p3.getY()) +
                p2.getX() * (p3.getY() - p1.getY()) +
                p3.getX() * (p1.getY() - p2.getY())
        );
    }

    public void przesun(Wektor wektor) {
        p1.przesun(wektor);
        p2.przesun(wektor);
        p3.przesun(wektor);
    }

    public void obroc(Punkt srodek, double kat) {
        p1.obroc(srodek, kat);
        p2.obroc(srodek, kat);
        p3.obroc(srodek, kat);
    }

    public void odbij(Prosta prosta) {
        p1.odbij(prosta);
        p2.odbij(prosta);
        p3.odbij(prosta);
    }
}
