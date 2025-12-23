public class Pojazd {
    String marka, rejestracja;
    int rok_prod;
    public Pojazd(){
        marka = "";
        rejestracja = "";
        rok_prod = 0;
    }
    public Pojazd(String mar, String re, int rok){
        marka = mar;
        rejestracja = re;
        rok_prod = rok;
    }

    @Override
    public String toString(){
        return "Marka: " + marka + ", Rejestracja: " + rejestracja + ", Rok produkcji: " + rok_prod;
    }
}

