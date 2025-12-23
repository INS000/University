package wyrazenia;

public abstract class Wyrazenia implements Obliczalny {
    public static double suma(Wyrazenia... wyrażenia) {
        double suma = 0;
        for (Wyrazenia wyrażenie : wyrażenia) {
            suma += wyrażenie.oblicz();
        }
        return suma;
    }

    public static double iloczyn(Wyrazenia... wyrażenia) {
        double iloczyn = 1;
        for (Wyrazenia wyrażenie : wyrażenia) {
            iloczyn *= wyrażenie.oblicz();
        }
        return iloczyn;
    }
}
