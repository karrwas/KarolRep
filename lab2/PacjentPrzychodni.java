/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

/**
 *
 * @author karol
 */
public class PacjentPrzychodni extends Pacjent {
    
    public void przyjmij(){
        
        System.out.println("Pacjent: " + nazwisko + " musi czekac...");
        /*
        Moze robic to co funkcja z Chirurgicznego i pilnowac,
        zeby pacjenci nie dostali tego samego lozka w tej samej sali, ale zostalo malo czasu
        */                     
    }
}
