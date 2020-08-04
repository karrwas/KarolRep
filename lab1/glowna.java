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
public class glowna {
    
    public enum Typy{jezykowa, techniczna, katolicka};
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int n = 2; //2 ostatnie miesiace
        double[] przychod = {123, 645.9, 89}; //bardzo slabo przedzie
        Ksiegarnia ksiegarnia = new Ksiegarnia();
        
        ksiegarnia.adres = "Warszawska";
       // ksiegarnia.typ = Typy.jezykowa;        nie wiem czemu nie dziala, w ksiegarni zmieniam na Typy typ i nic;
        ksiegarnia.miesieczny_przychod = przychod;
        
        ksiegarnia.max_przychod();
        ksiegarnia.suma_przychodu(n);

        ksiegarnia.dodaj_ksiazka(false);  //tutaj boolean wybiera jeden konstruktor
        ksiegarnia.dodaj_ksiazka(true); //tutaj drugi konstruktor
    }
    
}
