using System.Diagnostics;

namespace Gjenkjenn
{
    public partial class Form1 : Form
    {
        private Image? img;

        public Form1()
        {
            InitializeComponent();
        }



        private void imageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                ofd.Title = "Select an image to circle in";
                ofd.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif|All Files|*.*";
                ofd.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures);
                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    var fn = ofd.FileName;
                    this.img = Image.FromFile(fn);
                    var bn = Path.GetFileName(fn);
                    imageToolStripMenuItem.Text = bn;
                    if (img is System.Drawing.Bitmap bmp)
                    {
                        Debug.WriteLine("got a bitmap");
                        pictureBox1.Image = bmp;
                        var ft = new FirstTest();
                        var modified = ft.transfer(bmp);
                        pictureBox2.Image = modified;
                    }
                    else
                    {
                        imageToolStripMenuItem.Text = "not a valid image";
                    }
                }
            }

        }

        private void gjenkjennToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                ofd.Title = "Select an image to detect from";
                ofd.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif|All Files|*.*";
                ofd.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures);
                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    var fn = ofd.FileName;
                    this.img = Image.FromFile(fn);
                    var bn = Path.GetFileName(fn);
                    gjenkjennToolStripMenuItem.Text = bn;
                    if (img is System.Drawing.Bitmap bmp)
                    {
                        Debug.WriteLine("got a bitmap");
                        pictureBox1.Image = bmp;
                        Task.Run(() =>
                        {
                            var dtf = new DetectFromImage();
                            dtf.DetectAndAnnotate(bmp);
                            pictureBox2.BeginInvoke(() =>
                            {

                            });
                        });
                        //var ft = new FirstTest();
                        //var modified = ft.transfer(bmp);
                        //pictureBox2.Image = modified;
                    }
                    else
                    {
                        gjenkjennToolStripMenuItem.Text = "not a valid image";
                    }
                }
            }

        }
    }
}
