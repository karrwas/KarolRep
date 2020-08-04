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
public class Ksiazka {
    String tytul;
    int ilosc_stron;
    double cena;
    
    Ksiazka(String tytul, int ilosc_stron, double cena){
        this.tytul = tytul;
        this.ilosc_stron = ilosc_stron;
        this.cena = cena;
    }
    
    Ksiazka(String tytul){
        this.tytul = tytul;
        this.ilosc_stron = 44;
        this.cena = 24.50;
    }
    
    public void opis(){
        System.out.println("Ksiazka "+tytul+" ma "+ilosc_stron+" stron i kosztuje "+cena);
    }
}
