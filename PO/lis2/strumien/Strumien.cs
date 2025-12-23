/*
* Maksymilian Kochan
* lista 2: zad1
* dotnet run
*/

class IntStream
{
    public int a;
    protected int storage;
    public IntStream(int liczba = 0){
        this.a = liczba - 1;
        this.storage = this.a;
    }

    public virtual int next()
    {
        this.a += 1;
        return this.a;
    }

    public virtual bool eos()
    {
        if(this.a == int.MaxValue)
            return true;
        return false;
    }

    public void restart()
    {
        this.a = this.storage;
    }
}

class PrimeStream:IntStream
{
    public bool is_prime(int a)
    {
        for(int i = 2; i * i <= a; i++){
            if(a % i == 0)
                return false;
        }
        return true;
    }

    public PrimeStream(int liczba = 2){
        this.a = liczba - 1;
        this.storage = this.a;
    }

    //dziedziczymy eos bo max int jest liczba pierwszy (ósma liczba Mersenne’a)
    public override int next()
    {
        this.a += 1;
        while(!is_prime(this.a))
            this.a += 1;
        return this.a;
    }
}

class RandomStream:IntStream
{
    Random rnd = new Random();

    public override int next()
    {
        this.a = rnd.Next();
        return this.a;
    }

    public override bool eos()
    {
        return false;
    }

}

class RandomWordStream
{
    string s = "";
    RandomStream rng = new RandomStream();
    PrimeStream len = new PrimeStream();
    int act_len = 0;

    private void add_rand_char()
    {
        int pom = (int)'z' - (int)'a' + 1;
        char c =(char) (this.rng.next() % pom + (int)'a');
        this.act_len += 1;
        this.s += c;
    }

    public RandomWordStream()
    {
        add_rand_char();
    }


    public string next()
    {
        len.next();
        add_rand_char();
        int tmp = this.act_len;
        for(int i = tmp; i < this.len.a; i++){
            add_rand_char();
        }
        return this.s;
    }

    public bool eos()
    {
        if(this.act_len == int.MaxValue)
            return true;
        return false;
    }

    public string restart()
    {
        this.s = "";
        this.act_len = 0;
        len.restart();
        add_rand_char();
        return this.s;
    }
}

class Start
{
    public static void Main()
    {
        RandomStream slowo = new RandomStream();
        for(int i = 0; i < 3; i++){
            Console.WriteLine(slowo.next());
        }
        slowo.restart();
        for(int i = 0; i < 3; i++){
            Console.WriteLine(slowo.next());
        }
    }
}

