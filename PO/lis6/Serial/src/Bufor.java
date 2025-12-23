import java.io.Serializable;
import java.util.ArrayList;

public class Bufor<T> implements Serializable {
    ArrayList<T> buffer;
    int capacity;
    public Bufor(int cap){
        capacity = cap;
        buffer = new ArrayList<T>(capacity);
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
