/*
 * Maksymilian Kochan
 * lista 6: zad3
 * jdk 20
 * InetelliJ
 */
public class Consumer extends Thread{
    Bufor<String>bufor;
    public Consumer(Bufor<String> buf){
        bufor = buf;
    }

    public void run()
    {

        try
        {
            while(true) {
                Thread.sleep(1000);
                System.out.println("Zjadlem: " + bufor.pop());
            }
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

    }
}
