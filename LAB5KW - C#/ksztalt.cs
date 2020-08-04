using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB5KW
{
    public class ksztalt
    {
        public string nazwa;
        public int x, y, height, width;

        public ksztalt(string nazwa, int x, int y, int height, int width)
        {
            this.nazwa = nazwa;
            this.x = x;
            this.y = y;
            this.height = height;
            this.width = width;
        }
    }
}
