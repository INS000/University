using System;
namespace Wektory
{
    public class Wektor{
        private float[] val;
        public Wektor(int wymiar){
            val = new float[wymiar];
        }

        public void set_wek(float[] wspol){
            if(val.Length == wspol.Length)
                val = wspol;
            else
                throw new InvalidOperationException("Rozne dlugosci wektora i tablicy wspolczynnikow");

        }

        public void dodaj(Wektor a)
        {
            int dl = this.val.Length;
            if(dl != a.val.Length)
                throw new InvalidOperationException("Rozne dlugosci wektorow");
            for(int i = 0; i < dl; i++){
                this.val[i] += a.val[i]; 
            }
        }

        public float ilocz_skal(Wektor a){
            int dl = this.val.Length;
            float wyn = 0;
            if(dl != a.val.Length)
                throw new InvalidOperationException("Rozne dlugosci wektorow");
            for(int i = 0; i < dl; i++){
                wyn += this.val[i] + a.val[i];
            }
            return wyn;
        }
        public void mnozenie(float skal)
        {
            int dl = this.val.Length;
            for(int i = 0; i < dl; i++){
                this.val[i] *= skal; 
            }
        }

        public float norma()
        {
            return (float)Math.Sqrt(ilocz_skal(this));
        }
    }



}