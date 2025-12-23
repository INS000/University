using System;

namespace Hotel{
    class Personel
    {
        public string Imie;
        public string Nazwisko;
        public int Identyfikator;
        public string Stanowisko;

        public Personel(string im, string naz, int id, string stan)
        {
            Imie = im;
            Nazwisko = naz;
            Identyfikator = id;
            Stanowisko = stan;
        }

        private string full_name()
        {
            return Imie + ' ' + Nazwisko;
        }

        public void print()
        {
            Console.WriteLine(Identyfikator + " " + full_name() + " " + Stanowisko);
        }
    }

    class Klient
    {
        public string Imie;
        public string Nazwisko;
        public string NumerTelefonu;
        public string AdresEmail;

        public Klient(string im, string naz, string tel, string email)
        {
            Imie = im;
            Nazwisko = naz;
            NumerTelefonu = tel;
            AdresEmail = email;
        }
    }

    class Pokoj
    {
        public int NumerPokoju;
        public int Pojemnosc;
        public int Cena;

        public Pokoj(int nr, int poj, int cen)
        {
            NumerPokoju = nr;
            Pojemnosc = poj;
            Cena = cen;
        }
    }

    class Rezerwacja
    {
        public Klient Klient;
        public Pokoj Pokoj;
        public DateTime Przyjazd;
        public DateTime Wyjazd;

        public Rezerwacja(Klient kl, Pokoj pok, DateTime przyj, DateTime wyj){
            Klient = kl;
            Pokoj = pok;
            Przyjazd = przyj;
            Wyjazd = wyj;
        }
    }

    class Hotel
    {
        public List<Pokoj> pokoje;
        public List<Rezerwacja> rezerwacje;
        public List<Personel> pracownicy;

        public Hotel()
        {
            pokoje = new List<Pokoj>();
            rezerwacje = new List<Rezerwacja>();
            pracownicy = new List<Personel>();
        }

        public void DodajPokoj(Pokoj pokoj)
        {
            pokoje.Add(pokoj);
        }

        public void UsunPokoj(int nr)
        {
            foreach (Pokoj pokoj in pokoje)
            {
                if(pokoj.NumerPokoju == nr)
                {
                    pokoje.Remove(pokoj);
                    return;
                }
            }
            Console.WriteLine("Nie ma takiego pokoju.");
        }

        public void DodajPracownika(Personel prac)
        {
            pracownicy.Add(prac);
        }

        public void UsunPracownika(int id)
        {
            foreach (Personel pracownik in pracownicy)
            {
                if(pracownik.Identyfikator == id)
                {
                    pracownicy.Remove(pracownik);
                    return;
                }
            }
            Console.WriteLine();
            Console.WriteLine("Nie ma pracownika o podanym numerze identyfikacyjnym.");
        }

        public bool SprawdzDostepnoscPokoju(Pokoj pokoj, DateTime przyjazd, DateTime odjazd)
        {
            foreach (Rezerwacja rezerwacja in rezerwacje)
            {
                if (rezerwacja.Pokoj == pokoj && odjazd > rezerwacja.Przyjazd && przyjazd < rezerwacja.Wyjazd)
                {
                    return false;
                }
            }
            return true;
        }

        public List<Pokoj> WyszukajDostepnePokoje(int typ, DateTime przyjazd, DateTime wyjazd)
        {
            List<Pokoj> dostepnePokoje = new List<Pokoj>();
            foreach (Pokoj pokoj in pokoje)
            {
                if (pokoj.Pojemnosc == typ && SprawdzDostepnoscPokoju(pokoj, przyjazd, wyjazd))
                {
                    dostepnePokoje.Add(pokoj);
                }
            }
            return dostepnePokoje;
        }

        public void ZarezerwujPokoj(Rezerwacja rezerwacja)
        {
            rezerwacje.Add(rezerwacja);
        }


    }

    class SystemObslugiHotelu
    {
        private Hotel hotel;

        public SystemObslugiHotelu()
        {
            hotel = new Hotel();
        }

        public void Uruchom()
        {
            bool zakonczony = false;

            while (!zakonczony)
            {
                Console.WriteLine("Co chcesz zrobic?");
                Console.WriteLine("1. Dodac pokoj");
                Console.WriteLine("2. Usunac pokoj");
                Console.WriteLine("3. Wyszukac dostepne pokoje");
                Console.WriteLine("4. Zarezerwowac pokoj");
                Console.WriteLine("5. Dodac pracownika");
                Console.WriteLine("6. Usunac pracownika");
                Console.WriteLine("7. Wyswietlic liste pracownikow");
                Console.WriteLine("8. Wyjsc");
                Console.WriteLine();
                Console.Write("Wybierz opcję: ");
                string opcja = Console.ReadLine();
                Console.WriteLine();

                switch (opcja)
                {
                    case "1":
                        DodajPokoj();
                        break;
                    case "2":
                        UsunPokoj();
                        break;
                    case "3":
                        WyszukajDostepnePokoje();
                        break;
                    case "4":
                        ZarezerwujPokoj();
                        break;
                    case "5":
                        DodajPracownika();
                        break;
                    case "6":
                        UsunPracownika();
                        break;
                    case "7":
                        WyswietlListePracownikow();
                        break;
                    case "8":
                        zakonczony = true;
                        break;

                    default:
                        Console.WriteLine("Nieprawidłowa opcja. Wybierz opcję ponownie.");
                        Console.WriteLine();
                        break;
                }
            }

        }

        private void DodajPokoj()
        {
            Console.Write("Podaj numer pokoju: ");
            int numerPokoju = Convert.ToInt32(Console.ReadLine());
            Console.Write("Podaj ilu osobowy jest pokoj: ");
            int pojemnosc = Convert.ToInt32(Console.ReadLine());
            Console.Write("Podaj cene pokoju: ");
            int cena = Convert.ToInt32(Console.ReadLine());
            Pokoj test = hotel.pokoje.Find(p => p.NumerPokoju == numerPokoju);
            Console.WriteLine();
            if(test != null)
            {
                Console.WriteLine("Pokoj o podanym numerze juz istnieje.");
                Console.WriteLine();
                return;
            }

            Pokoj pokoj = new Pokoj(numerPokoju, pojemnosc, cena);

            hotel.DodajPokoj(pokoj);

            Console.WriteLine("Pokoj zostal dodany.");
            Console.WriteLine();
        }

        private void UsunPokoj()
        {
            Console.Write("Podaj numer pokoju do usunięcia: ");
            int numerPokoju = Convert.ToInt32(Console.ReadLine());

            hotel.UsunPokoj(numerPokoju);

            Console.WriteLine();
        }

        private void DodajPracownika()
        {
            Console.Write("Podaj numer identyfikacyjny: ");
            int id = Convert.ToInt32(Console.ReadLine());
            Console.Write("Podaj imie pracownika: ");
            string imie = Console.ReadLine();
            Console.Write("Podaj nazwisko pracownika: ");
            string nazwisko = Console.ReadLine();
            Console.Write("Podaj stanowisko pracownika: ");
            string stanowisko = Console.ReadLine();
            Personel test = hotel.pracownicy.Find(p => p.Identyfikator == id);
            if(test != null)
            {
                Console.WriteLine();
                Console.WriteLine("Pracownik o podanym numerze identyfikacyjnym nie istnieje.");
                Console.WriteLine();
                return;
            }

            Personel prac = new Personel(imie, nazwisko, id, stanowisko);
            hotel.DodajPracownika(prac);
            Console.WriteLine();
            Console.WriteLine("Pracownik zostal dodany.");
            Console.WriteLine();
        }

        private void UsunPracownika()
        {
            Console.Write("Podaj numer identyfikacyjny pracownika do usunięcia: ");
            int id = Convert.ToInt32(Console.ReadLine());

            hotel.UsunPracownika(id);

            Console.WriteLine();
        }

        private void WyswietlListePracownikow()
        {
            Console.WriteLine("Lista pracownikow:");
            foreach (Personel prac in hotel.pracownicy)
            {
                prac.print();
            }
            Console.WriteLine();
        }

        private void WyszukajDostepnePokoje()
        {
            Console.Write("Podaj ilo osobowego pokoju szukasz: ");
            int poj = Convert.ToInt32(Console.ReadLine());
            Console.Write("Podaj datę rozpoczęcia rezerwacji (RRRR-MM-DD): ");
            DateTime dataRozpoczecia = Convert.ToDateTime(Console.ReadLine());
            Console.Write("Podaj datę zakończenia rezerwacji (RRRR-MM-DD): ");
            DateTime dataZakonczenia = Convert.ToDateTime(Console.ReadLine());
            Console.WriteLine();
            List<Pokoj> dostepnePokoje = hotel.WyszukajDostepnePokoje(poj, dataRozpoczecia, dataZakonczenia);
            if(dostepnePokoje.Count() == 0)
            {
                Console.WriteLine("Nie ma dostepnych pokoi o podanych parametrach.");
                Console.WriteLine();
                return;
            }
            if(dataRozpoczecia > dataZakonczenia)
            {
                Console.WriteLine("Podano zly zakres czasu.");
                Console.WriteLine();
                return;
            }
            Console.WriteLine("Dostępne pokoje:");
            foreach (Pokoj pokoj in dostepnePokoje)
            {
                Console.WriteLine("Numer pokoju: " + pokoj.NumerPokoju);
                Console.WriteLine("Ilosc osob: " + pokoj.Pojemnosc);
                Console.WriteLine("Cena: " + pokoj.Cena);
                Console.WriteLine();
            }
        }

        private void ZarezerwujPokoj()
        {
            string im, naz, tel, email;
            Console.Write("Podaj imie klienta: ");
            im = Console.ReadLine();
            Console.Write("Podaj nazwisko klienta: ");
            naz = Console.ReadLine();
            Console.Write("Podaj numer telefonu klienta: ");
            tel = Console.ReadLine();
            Console.Write("Podaj adres email klienta: ");
            email = Console.ReadLine();
            int nrpokoju;
            Console.Write("Podaj numer pokoju: ");
            nrpokoju = Convert.ToInt32(Console.ReadLine());
            Console.Write("Podaj datę rozpoczęcia rezerwacji (RRRR-MM-DD): ");
            DateTime dataRozpoczecia = Convert.ToDateTime(Console.ReadLine());
            Console.Write("Podaj datę zakończenia rezerwacji (RRRR-MM-DD): ");
            DateTime dataZakonczenia = Convert.ToDateTime(Console.ReadLine());

            Pokoj pokoj = hotel.pokoje.Find(p => p.NumerPokoju == nrpokoju);

            if(pokoj == null)
            {
                Console.WriteLine();
                Console.WriteLine("Pokój o podanym numerze nie istnieje.");
                Console.WriteLine();
            }
            else if(!(hotel.SprawdzDostepnoscPokoju(pokoj, dataRozpoczecia, dataZakonczenia)))
            {
                Console.WriteLine();
                Console.WriteLine("Pokój jest zajety w podanym teminie.");
                Console.WriteLine();
            }
            else
            {
                Klient klient = new Klient(im, naz, tel, email);
                Rezerwacja rez = new Rezerwacja(klient, pokoj, dataRozpoczecia, dataZakonczenia);
                hotel.ZarezerwujPokoj(rez);
                Console.WriteLine();
                Console.WriteLine("Zarezerwowano wybrany pokoj.");
                Console.WriteLine();
            }
        }

        class Start
        {
            static void Main(string[] args)
            {
                SystemObslugiHotelu systemObslugiHotelu = new SystemObslugiHotelu();
                systemObslugiHotelu.Uruchom();
            }
        }
    }


}
