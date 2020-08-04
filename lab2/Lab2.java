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
public class Lab2 {

    public static void oblicz_koszt(Object tab[]){ //"przebiegając" się po całej tablicy można zrobić sumę kosztów
        double koszt_leczenia = 0;                 //tutaj liczone są koszty leczenia w zależności od typu pacjenta
        
        for(int i=Pacjent.ilosc_pacjentow-1; i < Pacjent.ilosc_pacjentow; i++){ //na pewno da się to jakoś inteligentniej zapisać
            if(tab[i] instanceof PacjentChirurgiczny){
                koszt_leczenia += 2000;
            }
            if(tab[i] instanceof PacjentPrzychodni){
                koszt_leczenia += 1000;
            }
        }
        System.out.println("Koszty leczenia: " + koszt_leczenia + " PLN");
        System.out.println("-------------------------------------------");
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Szpital szpital = new Szpital();
        
        szpital.dodaj_pacjenta("959595959", "Chory", "Urolog");
        oblicz_koszt(szpital.pacjenci); 
        
        szpital.dodaj_pacjenta("232323232", "Bogaty", "Neurolog");       
        oblicz_koszt(szpital.pacjenci);  
        
        System.out.println(szpital.pacjenci[0].nazwisko + " To pierwszy pacjent"); 
    }
    
}
