using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LAB5KW
{
    public partial class Form1 : Form
    {
        ksztalt ksztalt;
        Rectangle rec;

        private Graphics g;
        private Pen pioro;

        public int xp, yp, width, height;
        bool drawing;
        public Form1()
        {
            InitializeComponent();
            g = panel1.CreateGraphics();
            pioro = new Pen(Color.Black);
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawEllipse(pioro, rec);
            ksztalt = new ksztalt(textBox1.Text, width/2, height/2, height, width); //wspolrzedne to srodek okregu czyli szer/wys podzielone przez 2
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            
            if ( drawing != true) return;

            height = e.Y - yp;
            width = e.X - xp;

            rec = new Rectangle(xp, yp, width, height);

            g.DrawEllipse(pioro, rec);
            label1.Text = Convert.ToString("X: " + e.X + " Y: " + e.Y + " Nazwa: " + ksztalt.nazwa); //wyswietlany jest punkt ktory "ciągnie" myszka
            Refresh();
        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            if (e.NewValue > e.OldValue)
            {
                rec.Y = rec.Y + 2;
            }

            else if (e.NewValue < e.OldValue)
            {
                rec.Y = rec.Y - 2;
            }
            label1.Text = Convert.ToString("X: " + rec.X + " Y: " + rec.Y + " Nazwa: " + ksztalt.nazwa);//wyswietlany jest punkt startowy
            Refresh();
        }

        private void hScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            if (e.NewValue > e.OldValue)
            {
                rec.X = rec.X + 2;
            }

            else if (e.NewValue < e.OldValue)
            {
                rec.X = rec.X - 2;
            }

            label1.Text = Convert.ToString("X: " + rec.X + " Y: " + rec.Y + " Nazwa: " + ksztalt.nazwa);
            Refresh();
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            drawing = false;          
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            drawing = true;
            xp = e.X;
            yp = e.Y;
        }
    }
}
