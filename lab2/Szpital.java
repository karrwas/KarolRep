/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;
import java.util.Scanner;
/**
 *
 * @author karol
 */
public class Szpital {
    int pojemnosc = 30;
    Pacjent pacjenci[] = new Pacjent[pojemnosc];
    
    Scanner klawiatura = new Scanner(System.in);
    
    public void dodaj_pacjenta(String pesel, String nazwisko, String lekarz_przyjmujacy){
        
        if(Pacjent.ilosc_pacjentow >= pojemnosc) return;
        
        System.out.println("Podaj typ pacjenta (Chirurgiczny / Przychodni): ");
        String typ = klawiatura.nextLine();
        System.out.println("-------------------------------------------");
        
        try {
            Class C = Class.forName(typ);
            Object p = C.newInstance();  
                       
            Pacjent pacjent = (Pacjent) p; //obiekt jest co najmniej typu Pacjent --UPCASTING
                        
            pacjent.nazwisko = nazwisko;
            pacjent.lekarz_przyjmujacy = lekarz_przyjmujacy;
            pacjent.pesel = pesel;
            
            pacjent.przyjmij();
            
            pacjenci[Pacjent.ilosc_pacjentow] = pacjent;
            Pacjent.ilosc_pacjentow++;
            
            procedura_operacji(pacjent);
            
        } catch (Exception ex) {
            System.out.println("Brak danej klasy.." + ex);
        }      
    }
    
    public void procedura_operacji(Object pacjent){
        if(pacjent instanceof PacjentChirurgiczny){
          ((PacjentChirurgiczny)pacjent).zaplanuj_operacje(); //DOWNCASTING
        }    
        else{
            System.out.println("Pacjent jest na NFZ z przychodni");
        }
    }
}
