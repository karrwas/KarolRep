/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1;

/**
 *
 * @author karol
 */
import java.util.*;

public class Ksiegarnia {
    String adres;
   // Typy typ;
    String typ;
    double[] miesieczny_przychod;
    
    Scanner klawiatura = new Scanner(System.in);  
    
    Ksiegarnia(){
   
    }
    
    void max_przychod( ){
        double max = miesieczny_przychod[0];
            for(int i=0; i < miesieczny_przychod.length ; i++){
                
                if(miesieczny_przychod[i] > max) max = miesieczny_przychod[i];
            }        
        System.out.println("Maksymalny przychod: " + max);
    }
    
    void suma_przychodu(int n){
        double suma = 0;
        
        for(int i = miesieczny_przychod.length; i > miesieczny_przychod.length - n; i--){
            suma += miesieczny_przychod[i-1];
        }        
        System.out.println("Przychod z " + n + " ostatnich miesiecy: " + suma);
    }
    
    public void dodaj_ksiazka(boolean x){
        
        System.out.println("Podaj tytul: ");
        String tytul = klawiatura.nextLine(); 
           
        if(x == false) {       
            Ksiazka nowa = new Ksiazka(tytul); 
            nowa.opis();                                   //wystarczy tytul, reszte robi konstruktor
        }           
        else{
            System.out.println("Dopisz ilosc stron i cene"); //dopisac jesli konstruktor tego nie zrobil
            int strony = klawiatura.nextInt();
            double cena = klawiatura.nextDouble();
            
            Ksiazka nowa1 = new Ksiazka(tytul, strony, cena);
            nowa1.opis();
        }
    }
}
