/*
 * Maksymilian Kochan
 * lista 6: zad3
 * jdk 20
 * InetelliJ
 */
public class Main {
    public static void main(String[] args) {
        Bufor<String>bufor = new Bufor<String>(12);
        Producer prod = new Producer(bufor);
        Consumer cons = new Consumer(bufor);

        prod.start();
        cons.start();
    }
}