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
abstract class Pacjent {
    String pesel;         //mogło by być private
    String nazwisko;    //mogło by być private
    String lekarz_przyjmujacy;  //mogło by być private RODO itd
    static int ilosc_pacjentow;
    
    public static void wypisz(){       
        ilosc_pacjentow--;
    }
    
    public abstract void przyjmij();        //deklaracja metody
    
}
