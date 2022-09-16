using System;
using System.Collections.Generic;
using System.Linq;
using System.Drawing;
using System.Text;
using System.Threading.Tasks;

namespace DoodleJump.Classes
{
    public class White : Platform
    {
        Image sprite;
       
        public White(PointF pos)
            : base(pos)
        {
            sprite = Properties.Resources.platform_white;
            sizeX = 62;
            sizeY = 12;
            transform = new Transform(pos, new Size(sizeX, sizeY));
            isTouchedByPlayer = false;
        }

      
    }
}
