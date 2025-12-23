package figury;

public class Punkt {
    private double x;
    private double y;

    public Punkt(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // Gettery
    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    // Settery
    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return String.format("(%.2f, %.2f)", x, y);
    }

    public void przesun(Wektor wektor) {
        this.x += wektor.dx;
        this.y += wektor.dy;
    }

    public void obroc(Punkt srodek, double kat) {
        double cosKat = Math.cos(kat);
        double sinKat = Math.sin(kat);

        double translatedX = this.x - srodek.getX();
        double translatedY = this.y - srodek.getY();

        double rotatedX = translatedX * cosKat - translatedY * sinKat;
        double rotatedY = translatedX * sinKat + translatedY * cosKat;

        this.x = rotatedX + srodek.getX();
        this.y = rotatedY + srodek.getY();
    }

    public void odbij(Prosta prosta) {
        double a = prosta.a;
        double b = prosta.b;
        double c = prosta.c;

        double d = (a * this.x + b * this.y + c) / (a * a + b * b);
        double reflectedX = this.x - 2 * a * d;
        double reflectedY = this.y - 2 * b * d;

        this.x = reflectedX;
        this.y = reflectedY;
    }

    public double odleglosc(Punkt drugiPunkt) {
        double deltaX = this.x - drugiPunkt.getX();
        double deltaY = this.y - drugiPunkt.getY();
        return Math.sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    public double odleglosc(Punkt p1, Punkt p2) {
        double deltaX = p1.getX() - p2.getX();
        double deltaY = p1.getY() - p2.getY();
        return Math.sqrt(deltaX * deltaX + deltaY * deltaY);
    }

}
