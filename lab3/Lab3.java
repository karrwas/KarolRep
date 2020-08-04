/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;

/**
 *
 * @author karol
 */
class Okno extends JFrame{
    Okno(String nazwa){
    super(nazwa);
    setSize(600,600);
    setLayout(new BorderLayout()); //FlowLayout sprawiał duże problemy, wiec zrobilem BorderLayout
    setResizable(false);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
}

class Ekran extends Canvas{
    public static Color color;
    
    ArrayList<Point> points = new ArrayList<Point>(); //zawiera punkty "docelowe"
    ArrayList<String> znaczki = new ArrayList<String>();
    
    private int x = 100 ,y = 100 , x2, y2, dx, dy; //zmienne odpowiedzialne za poruszanie sie
    private Font f;
    
    Ekran(){
        super();
        f = new Font("Times New Roman", Font.BOLD, 10);
        setFont(f);

        addKeyListener(new KeyAdapter(){    //klasa anonimowa wewnętrzna
            @Override       
            public void keyPressed(KeyEvent ke){
                znaczki.add(String.valueOf((char)ke.getKeyCode()));
               
                if(ke.getKeyCode() == KeyEvent.VK_LEFT){
                System.out.println("Lewa strzalka"); //konsola wypisuje jaki klawisz wcisnieto
                dx = -20;                
                }
                else if(ke.getKeyCode() == KeyEvent.VK_RIGHT){
                System.out.println("Prawa strzalka");
                dx = 20;                
                }
                else if(ke.getKeyCode() == KeyEvent.VK_DOWN){
                System.out.println("Dolna strzalka");
                dy = 20;                  
                }
                else if(ke.getKeyCode() == KeyEvent.VK_UP){
                System.out.println("Gorna strzalka");
                dy = -20;                  
                }
                else{
                    System.out.println("Zly przycisk");
                    System.out.println(String.valueOf((char)ke.getKeyCode()));
                }

                x2 = x + dx;
                y2 = y + dy;
                points.add(new Point(x2,y2)); //zbiera punkty "docelowe"
                
                repaint();
            }
        });
    }
    
    @Override
    public void paint(Graphics G){       
        
        Graphics2D G2 = (Graphics2D) G;
        G2.setColor(color);
       
        int i = 0;
	String pozycja; //wyswietla wcisniety znak na linii
        
		for(Point p:points) //rysowanie linii
		{
			pozycja = znaczki.get(i);
				
			x2=(int)p.getX();
			y2=(int)p.getY();
			G2.drawString(pozycja, x2, y2);
                        G2.drawLine(x,y,x2,y2);
                               
                        x = x2;
                        y = y2;
                        dx = 0;
                        dy = 0;                              				
                    i++;	
		 }
    }
}

public class Lab3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Okno okno = new Okno("Okienko");
        Ekran ekran = new Ekran();
        ekran.setBackground(Color.LIGHT_GRAY);
        
        JPanel p1 = new JPanel();   //kolory
        JPanel p2 = new JPanel(); //rysowanie
        
        p1.add(new JLabel("Kolory"));
        JCheckBox kolor1 = new JCheckBox("Czerwony");
        JCheckBox kolor2 = new JCheckBox("Czarny" , true);
       
        p1.add(kolor1);
        p1.add(kolor2);
        
        okno.add(ekran);
        p2.add(new JLabel("Rysowanie"));
     
        okno.add(p1, BorderLayout.WEST);
        okno.add(p2, BorderLayout.EAST);
        
        okno.setVisible(true);
        
        kolor1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                if(kolor1.isSelected()){
                    Ekran.color = Color.RED;
                    kolor2.setSelected(false);
                }
            }
        });
     
        kolor2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                if(kolor2.isSelected()){
                    Ekran.color = Color.BLACK;
                    kolor1.setSelected(false);
                }
            }
        });
               
    }
    }
    

