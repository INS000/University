package rozgrywka;

import obliczenia.Wymierna;

public class Gra {
    private int zakres;
    private Wymierna liczba;
    private int maksIloscProb;
    private int licznikProb;
    private boolean aktywna;
    private boolean odgadniete;

    public Gra() {
        this.aktywna = false;
        this.odgadniete = false;
        this.licznikProb = 0;
    }

    public void start(int z) {
        if (z < 5 || z > 20) throw new IllegalArgumentException("Zakres z musi być w [5,20]");
        zakres = z;

        int licz = (int) (Math.random() * zakres) + 1;
        int mian = (int) (Math.random() * zakres) + 1;

        liczba = new Wymierna(licz, mian);

        maksIloscProb = (int) Math.ceil(3 * Math.log(z));
        if (maksIloscProb < 1) maksIloscProb = 1;
        licznikProb = 0;
        aktywna = true;
        odgadniete = false;

        assert liczba.getLicznik() < liczba.getMianownik() : "Oczekiwano licznik < mianownik (ułamek < 1).";
    }

    public Wymierna getLiczba() {
        return liczba;
    }

    public int getZakres() {
        return zakres;
    }

    public int getMaksIloscProb() {
        return maksIloscProb;
    }

    public int getLicznikProb() {
        return licznikProb;
    }

    public boolean isAktywna() {
        return aktywna && !isKoniec();
    }

    public boolean isOdgadniete() {
        return odgadniete;
    }

    public boolean isKoniec() {
        return odgadniete || licznikProb >= maksIloscProb || !aktywna;
    }

    public int zgaduj(Wymierna guess) {
        if (!aktywna) throw new IllegalStateException("Gra nie jest aktywna");
        if (isKoniec()) throw new IllegalStateException("Gra już się zakończyła");
        licznikProb++;
        int cmp = guess.compareTo(liczba);
        if (cmp == 0) {
            odgadniete = true;
            aktywna = false;
            return 0;
        } else if (cmp < 0) {
            if (licznikProb >= maksIloscProb) aktywna = false;
            return -1;
        } else {
            if (licznikProb >= maksIloscProb) aktywna = false;
            return 1;
        }
    }

    public void poddaj() {
        aktywna = false;
    }

    public int pozostaleProby() {
        return maksIloscProb - licznikProb;
    }
}
