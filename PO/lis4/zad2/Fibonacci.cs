/*
* Maksymilian Kochan
* lista 4: zad2
* dotnet run
*/

using System;
using System.Collections;


namespace Fibstring
{
    public class SlowaFibonacciego : IEnumerable
    {
        private string[] fib;
        private string gen_fib(int a)
        {
            string s = "a", sprev = "b";
            if (a == 1)
                return sprev;
            for (int i = 2; i < a; i++)
            {
                string tmp = s + sprev;
                sprev = s;
                s = tmp;
            }
            return s;
        }

        public SlowaFibonacciego(int n)
        {
            fib = new string[n];
            for (int i = 0; i < n; i++)
            {
                fib[i] = gen_fib(i + 1);
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator)GetEnumerator();
        }

        public IEnumerator GetEnumerator()
        {
            return fib.GetEnumerator();
        }



    }
}
  
    public class Program
    {
        public static void Main()
        {
            SlowaFibonacciego sf = new SlowaFibonacciego(6);
            foreach (string s in sf)
                System.Console.WriteLine(s);
        }
    }
 