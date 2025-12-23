public class Consumer extends Thread{
    private boolean exit;
    Bufor<String>bufor;
    public Consumer(Bufor<String> buf){
        bufor = buf;
    }

    public void run()
    {

        try
        {
            while(!exit) {
                Thread.sleep(1000);
                System.out.println("Zjadlem: " + bufor.pop());
            }
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

    }
    public void stuj()
    {
        exit = true;
    }
}
