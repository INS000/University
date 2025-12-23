import java.util.Random;

public class Producer extends Thread{
    private boolean exit;
    Bufor<String>bufor;
    public Producer(Bufor<String> buf){
        bufor = buf;
    }

    public String make(){
        Random rng = new Random();
        int max_len = rng.nextInt(7);
        StringBuilder pom = new StringBuilder();
        for(int i = 0; i < max_len; i++){
            pom.append((char)(rng.nextInt(26)+'A'));
        }
        return pom.toString();
    }

    public void run()
    {
        while(!exit) {
            try
            {
                Thread.sleep(300);
                String slowo = make();
                bufor.push(slowo);
                System.out.println("Wyprodukowalem: " + slowo);

            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
    public void stuj()
    {
        exit = true;
    }
}
