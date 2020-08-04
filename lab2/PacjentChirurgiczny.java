/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;
import java.util.Random;
/**
 *
 * @author karol
 */
 public class PacjentChirurgiczny extends Pacjent{
    int sala;
    int lozko;
    
    public void przyjmij(){
        Random s = new Random();
        sala = s.nextInt(20)+1; //zakres od 1 do 20
        
        Random l = new Random();
        lozko = l.nextInt(5)+1; //zakres od 1 do 5
    }
    
    public void zaplanuj_operacje(){
        System.out.println("Planowanie operacji dla");
        System.out.println("Pesel: " + pesel);
        System.out.println("Nazwisko: " + nazwisko);
        System.out.println("Lekarz przyjmujacy: " + lekarz_przyjmujacy);
        System.out.println("Sala: " + sala + "  Lozko: " + lozko);
        
    }
}
