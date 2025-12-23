public class Main {
    public static void main(String[] args){
        Tramwaj t = new Tramwaj("Opel", "Ab1321q", 2024, 14, 2, 69);
        Samochod s = new Samochod("Mercedes", "JD4221", 2020, 123, 500, "Czerwony");
        Pojazd p = new Pojazd();
        System.out.println(t);
        System.out.println(s);
        System.out.println(p);
    }
}
