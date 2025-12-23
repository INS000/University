package rozgrywka.wyjatki;

public class MyException extends Exception {
    public MyException(String msg) { super(msg); }
    public MyException(String msg, Throwable cause) { super(msg, cause); }
}
