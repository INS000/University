/*
 * Maksymilian Kochan
 * lista 6: zad1
 * jdk 20
 * InetelliJ
 */
import java.io.ObjectOutputStream;
import java.io.*;



public class Main {
    public static void main(String[] args) throws InterruptedException {
        Bufor<String>bufor = new Bufor<String>(12);
        bufor.push("a");
        bufor.push("d");
        bufor.push("c");
        bufor.push("h");
        String filename = "plik.ser";

        try
        {
            FileOutputStream file = new FileOutputStream(filename);
            ObjectOutputStream out = new ObjectOutputStream(file);
            out.writeObject(bufor);
            out.close();
            file.close();
            System.out.println("Zapisano do plik");
        }
        catch(IOException ex)
        {
            System.out.println("Blad w zapisie");
        }


        Bufor<String> obj = null;

        try
        {
            FileInputStream file = new FileInputStream(filename);
            ObjectInputStream in = new ObjectInputStream(file);
            obj = (Bufor<String>) in.readObject();
            in.close();
            file.close();
            System.out.println("Wczytane z pliku");
        }
        catch(IOException ex)
        {
            System.out.println("Blad przy wczytywaniu");
        }
        catch(ClassNotFoundException ex)
        {
            System.out.println("Blad przy wczytywaniu");
        }

        while (!obj.buffer.isEmpty()){
            System.out.println(obj.pop());
        }





    }
}