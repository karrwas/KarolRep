using System;
using System.Collections;
using System.Collections.Generic;

namespace lab4
{
    public enum Jezyki { Angielski, Polski, Niemiecki};
    
    public abstract class Matura
    {
        public string nazwisko;
        public string przedmiot;
        public double ocena;
        public Matura()
        {
           
        }
        public Matura(Jezyki jezyk)
        {
            this.przedmiot = Convert.ToString(jezyk);
        }

        public Hashtable oceny = new Hashtable();

        public abstract void OpiszZadanie();
    }

    public class MaturaZMatematyki : Matura
    {
        public MaturaZMatematyki():base()
        {
            base.przedmiot = "Matematyka";
        }

        public override void OpiszZadanie()
        {
            Console.WriteLine("Zadanko z matematyczki <3");
        }
    }

    public class MaturaZJezyka : Matura
    {
        
        public MaturaZJezyka( Jezyki jezyk):base( jezyk)
        {
            base.przedmiot = Convert.ToString(jezyk);
        }

        public override void OpiszZadanie()
        {
            Console.WriteLine("Zadanko z jezyka obcego");
        }
    }
    class Program
    {
        delegate void del(string nazwisko);
        public static List<Matura> wyniki = new List<Matura>();
        static void Main(string[] args)
        {                     
            MaturaZMatematyki matma = new MaturaZMatematyki();  
            MaturaZJezyka jezyk1 = new MaturaZJezyka(Jezyki.Angielski);
            MaturaZJezyka jezyk2 = new MaturaZJezyka(Jezyki.Niemiecki);

            wyniki.Add(matma);
            wyniki.Add(jezyk1);
            wyniki.Add(jezyk2);

            wyniki[0].oceny.Add("Kowalski", 5);
            wyniki[1].oceny.Add("Kowalski", 6);
            wyniki[2].oceny.Add("Kowalski", 4);
                       
            wyniki[0].oceny.Add("Wasik", 1);
            wyniki[1].oceny.Add("Wasik", 2);
            wyniki[2].oceny.Add("Wasik", 3);
                       
            wyniki[0].oceny.Add("Nowak", 4);
            wyniki[1].oceny.Add("Nowak", 4);
            wyniki[2].oceny.Add("Nowak", 6);

            Console.Write("Kogo chcesz sprawdzic/policzyc?: ");
            string nazwisko = Console.ReadLine();
            Console.Write("Wpisz (sprawdz) lub (oblicz): ");
            string wybor = Console.ReadLine();

            if(wybor.Equals("sprawdz"))
            {
                del d = new del(SprawdzUcznia);
                d(nazwisko);
            }
            else if(wybor.Equals("oblicz"))
            {
                del d = new del(ObliczSrednia);
                d(nazwisko);
            }

            Console.ReadKey();
        }
        public static void ObliczSrednia(string s)
        {
            int suma = 0;
            int i = 0;
            
            foreach(Matura m in wyniki)
            {
                if(m.oceny.Contains(s))
                {
                    suma = suma + (int)m.oceny[s];
                    i++;
                }
                else
                {
                    Console.WriteLine("Taki uczen nie istnieje");
                }
               
            }
            Console.WriteLine("Srednia " + s + " : "  +((double)suma / i));
        }

        public static void SprawdzUcznia(string s)
        {
            foreach(Matura m in wyniki)
            {
                if((int)m.oceny[s] < 2)
                {
                    Console.WriteLine("Uczen nie zdal " + m.przedmiot);
                }
                else
                {
                    Console.WriteLine("Uczen zdal " + m.przedmiot);
 
                }
            }

        }
    }
}
