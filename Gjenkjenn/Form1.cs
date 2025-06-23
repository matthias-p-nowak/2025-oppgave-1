namespace Gjenkjenn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void testToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var ft = new FirstTest();
            ft.ping();
        }

        private void imageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var img = Image.FromFile(@"C:\temp\car.jpg");
            var ft= new FirstTest();
            ft.transfer(img);
        }
    }
}
