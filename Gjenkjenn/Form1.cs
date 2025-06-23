using System.Diagnostics;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace Gjenkjenn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        private void imageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                ofd.Title = "Select an image to detect";
                ofd.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif|All Files|*.*";
                ofd.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures);
                if(ofd.ShowDialog() == DialogResult.OK)
                {
                    var fn=ofd.FileName;
                    var img = Image.FromFile(fn);
                    var bn=Path.GetFileName(fn);
                    imageToolStripMenuItem.Text =bn;
                    if (img is System.Drawing.Bitmap bmp)
                    {
                        Debug.WriteLine("got a bitmap");
                        pictureBox1.Image = bmp;
                        var ft = new FirstTest();
                        ft.transfer(bmp);
                    }
                }
            }
            
        }
    }
}
