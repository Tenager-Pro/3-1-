using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DoodleJump
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.Height = 616;//Высота окна
            this.Width = 352;//ширина окна
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 newForm = new Form1(this);
            
            this.Hide();
            newForm.ShowDialog();
            this.Close();
        }

        
    }
}
