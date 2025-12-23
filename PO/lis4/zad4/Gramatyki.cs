/*
* Maksymilian Kochan
* lista 4: zad4
* dotnet run
*/

using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

public class Rule
{
    public char Nieterminal;
    public string wynik;

    public Rule(char a, string b)
    {
        Nieterminal = a;
        wynik = b;
    }
}
public class Grammar
{
    public char Start;
    public List<Rule> Produkcje;

    public Grammar(char a, List<Rule> b)
    {
        Start = a;
        Produkcje = b;
    }
public string reverse(string s)
    {
        string wyn = "";
        int pom = s.Length;
        for (int i = pom - 1; i >= 0; i--)
        {
            wyn += s[i];
        }
        return wyn;
    }
  
    public string GenerateWord()
    {
        string wyn = "";
        Random rng = new Random();
        Stack<char> stos = new Stack<char>();
        stos.Push(Start);

        while (stos.Count > 0)
        {
            char sym = stos.Pop();
            if (Produkcje.Any(zas => zas.Nieterminal == sym))
            {
                var zasady = Produkcje.FindAll(zas => zas.Nieterminal == sym);
                Rule produkcja = zasady.ElementAt(rng.Next(zasady.Count));
                string pom = reverse(produkcja.wynik);
                foreach (char znak in pom)
                {
                    stos.Push(znak);
                }
            }
            else
            {
                wyn += sym;
            }
        }
        return wyn;
    }
}
class Program
{

    public static void Main()
    {
        List<Rule> zasady = new List<Rule>();
        zasady.Add(new Rule('S', "aSb"));
        zasady.Add(new Rule('S', "ccS"));
        zasady.Add(new Rule('S', "d"));
        Grammar gram = new Grammar('S', zasady);
        string s = gram.GenerateWord();
        Console.WriteLine(s);

    }
}