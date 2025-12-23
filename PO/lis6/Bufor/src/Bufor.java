/*
 * Maksymilian Kochan
 * lista 6: zad3
 * jdk 20
 * InetelliJ
 */
import java.util.ArrayList;

public class Bufor<T> {
    ArrayList<T> buffer;
    int capacity;
    public Bufor(int cap){
        capacity = cap;
        buffer = new ArrayList<>(capacity);
    }

    public synchronized void push(T elem) throws InterruptedException {
        while (buffer.size() == capacity)
            wait();
        buffer.add(elem);
        notifyAll();
    }

    public synchronized T pop() throws InterruptedException {
        while(buffer.isEmpty())
            wait();
        notify();
        return buffer.remove(0);
    }
}
