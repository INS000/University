public class Tramwaj extends Pojazd{
    int liczba_pasazerow, liczba_miejsc_niepelnosprawni, ile_wykolejen;
    public Tramwaj(String mar, String re, int rok, int pas, int niep, int wyk){
        super(mar, re, rok);
        liczba_pasazerow = pas;
        liczba_miejsc_niepelnosprawni = niep;
        ile_wykolejen = wyk;
    }

    @Override
    public String toString(){
        return super.toString() + ", Liczba pasazerow: " + liczba_pasazerow + "Liczba miejsc dla niepelnosprawnych: " + liczba_miejsc_niepelnosprawni + ", Liczba wykolejen: " + ile_wykolejen;
    }

    public void wykolejenie(){
        ile_wykolejen++;
    }
}
