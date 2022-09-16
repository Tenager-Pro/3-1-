using System;
using System.Collections.Generic;
using System.Linq;
using System.Drawing;
using System.Text;
using System.Threading.Tasks;

namespace DoodleJump.Classes
{
    public class Blue:Platform
    {
        Image sprite;

        public Blue(PointF pos)
            : base(pos)
        {
            sprite = Properties.Resources.platform_blue;
            sizeX = 62;
            sizeY = 12;
            transform = new Transform(pos, new Size(sizeX, sizeY));
            isTouchedByPlayer = false;
        }
    }
}
