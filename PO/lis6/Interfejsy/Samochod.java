public class Samochod extends Pojazd{
    int moc_silnika, pojemnosc_bagaznika;
    String kolor;
    public Samochod(String mar, String re, int rok, int moc, int poj, String kol){
        super(mar, re, rok);
        kolor = kol;
        moc_silnika = moc;
        pojemnosc_bagaznika = poj;
    }

    @Override
    public String toString(){
        return super.toString() + ", Moc silnika: " + moc_silnika + "Pojemnosc bagaznika: " + pojemnosc_bagaznika + ", Kolor: " + kolor;
    }
}
