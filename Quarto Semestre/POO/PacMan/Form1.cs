using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.LinkLabel;

namespace PACMAN001
{
    
    public partial class Form1 : Form
    {
        string[,] pacman = new string[20, 10];


        string[] tabuleiro = new string[100];
        int lintabuleiro = 9;
        int coltabuleiro = 40;
        int largura = 30;
        int altura = 30;
        int cursorcol = 1;
        int cursorlin = 1;
        char tecla = ' ';
        int tempo = 0;
        int pontos = 0;

        int flagimagempacman = 0;



        public Form1()
        {
            InitializeComponent();

            pbTabuleiro.BackgroundImage = Image.FromFile("abertura.jpg");
            pbTabuleiro.SizeMode = PictureBoxSizeMode.StretchImage;

            pacman[0, 0] = "w";
            pacman[0, 1] = "PMVU001.JPG";
            pacman[0, 2] = "PMVU002.JPG";

            pacman[1, 0] = "s";
            pacman[1, 1] = "PMVD001.JPG";
            pacman[1, 2] = "PMVD002.JPG";

            pacman[2, 0] = "a";
            pacman[2, 1] = "PMHE001.JPG";
            pacman[2, 2] = "PMHE002.JPG";

            pacman[3, 0] = "d";
            pacman[3, 1] = "PMHD001.JPG";
            pacman[3, 2] = "PMHD002.JPG";

            pbTabuleiro.BackgroundImage = Image.FromFile("abertura.jpg");
            pbTabuleiro.SizeMode = PictureBoxSizeMode.StretchImage;

        }

        private void btnSair_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            tempo--;
            lblTempo.Text ="TEMPO:  "+tempo.ToString();
            lblPontos.Text="PONTOS: "+ pontos.ToString();
            txbTeclado.Focus();
            pbTabuleiro.Invalidate();
            //if (tempo == 0)
            {
            //    timer1.Enabled = false;
            //    lblTempo.Text = "TEMPO:  GAME OVER";
            ////    pbTabuleiro.BackgroundImage = Image.FromFile("gameover.jpg");
            //    pbTabuleiro.SizeMode = PictureBoxSizeMode.StretchImage;
            }

            
        }

        private void pbTabuleiro_Paint(object sender, PaintEventArgs e)
        {
            if (timer1.Enabled == true)
            {
                Pen pen = new Pen(Color.Blue, 1);
                SolidBrush bs = new SolidBrush(Color.Blue);
                Pen caminhopen = new Pen(Color.Yellow, 1);
                SolidBrush caminhobs = new SolidBrush(Color.Yellow);
                Pen brancopen = new Pen(Color.White, 1);
                SolidBrush brancobs = new SolidBrush(Color.White);
                for (int lin = 0; lin < lintabuleiro; lin++)
                {
                    for (int col = 0; col < coltabuleiro; col++)
                    {
                        if (tabuleiro[lin][col] == '*')
                        {
                            e.Graphics.DrawRectangle(pen, col * altura, lin * largura, altura, largura);
                            e.Graphics.FillRectangle(bs, col * altura, lin * largura, altura, largura);

                        }
                        if (tabuleiro[lin][col] == '.')
                        {
                            e.Graphics.DrawRectangle(caminhopen, col * altura, lin * largura, altura, largura);
                            e.Graphics.FillRectangle(caminhobs, col * altura, lin * largura, altura, largura);

                        }
                        if (tabuleiro[lin][col] == ' ')
                        {
                            e.Graphics.DrawRectangle(brancopen, col * altura, lin * largura, altura, largura);
                            e.Graphics.FillRectangle(brancobs, col * altura, lin * largura, altura, largura);

                        }
                    }
                }

                //DESENHGAR CURSOR
                //Pen cursorpen = new Pen(Color.Green, 1);
                //SolidBrush cursorbs = new SolidBrush(Color.Green);
                //e.Graphics.DrawRectangle(cursorpen, cursorcol * altura, cursorlin * largura, altura, largura);
                //e.Graphics.FillRectangle(cursorbs, cursorcol * altura, cursorlin * largura, altura, largura);

                //Carregar as Imagem em função da tecla digitada

                //DESENHAR PACMAN
                int dir = 0;
                switch (tecla)
                {
                    case 'w':
                        dir = 0;
                        break;
                    case 's':
                        dir = 1;
                        break;
                    case 'a':
                        dir = 2;
                        break;
                    case 'd':
                        dir = 3;
                        break;
                }

                pbPACMAN.Location = new Point(cursorcol * largura + largura / 2 + 2, cursorlin * altura + altura / 2 + 2);

                pbPACMAN.BackgroundImage = Image.FromFile(pacman[dir, flagimagempacman + 1]);
                flagimagempacman = Math.Abs(flagimagempacman - 1);

            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {

        }

        private void txbTeclado_TextChanged(object sender, EventArgs e)
        {

        }

        private void txbTeclado_KeyPress(object sender, KeyPressEventArgs e)
        {
            tecla = e.KeyChar;
            if (e.KeyChar == 'w')
            {
                if ((tabuleiro[cursorlin - 1][cursorcol] == '.')||(tabuleiro[cursorlin - 1][cursorcol] == ' '))
                {
                    cursorlin--;
                    if (tabuleiro[cursorlin][cursorcol] == '.')
                    {
                        pontos++;
                    }
                    var sb = new StringBuilder(tabuleiro[cursorlin]);
                    sb[cursorcol] = ' ';
                    tabuleiro[cursorlin]=sb.ToString();
                }
            }
            if (e.KeyChar == 's')
            {
                if ((tabuleiro[cursorlin + 1][cursorcol] == '.')|| (tabuleiro[cursorlin + 1][cursorcol] == ' '))
                {
                    cursorlin++;
                    if (tabuleiro[cursorlin][cursorcol] == '.')
                    {
                        pontos++;
                    }
                    var sb = new StringBuilder(tabuleiro[cursorlin]);
                    sb[cursorcol] = ' ';
                    tabuleiro[cursorlin] = sb.ToString();  
                }
            }
            if (e.KeyChar == 'a')
            {
                if ((tabuleiro[cursorlin][cursorcol-1] == '.') || (tabuleiro[cursorlin][cursorcol-1] == ' '))
                {
                    cursorcol--;
                    if (tabuleiro[cursorlin][cursorcol] == '.')
                    {
                        pontos++;
                    }
                    var sb = new StringBuilder(tabuleiro[cursorlin]);
                    sb[cursorcol] = ' ';
                    tabuleiro[cursorlin] = sb.ToString();
                    
                }
            }
            if (e.KeyChar == 'd')
            {
                if ((tabuleiro[cursorlin][cursorcol + 1] == '.')|| (tabuleiro[cursorlin][cursorcol+1] == ' '))
                {
                    cursorcol++;
                    if (tabuleiro[cursorlin][cursorcol] == '.')
                    {
                        pontos++;
                    }
                    var sb = new StringBuilder(tabuleiro[cursorlin]);
                    sb[cursorcol] = ' ';
                    tabuleiro[cursorlin] = sb.ToString();
                }
            }
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {

        }

        private void btnInicializar_Click(object sender, EventArgs e)
        {
            tabuleiro[0] = "****************************************";
            tabuleiro[1] = "*......................................*";
            tabuleiro[2] = "*.*.******.****.****.***.******.***.**.*";
            tabuleiro[3] = "*.*.******.****.****.***.******.***.**.*";
            tabuleiro[4] = "*.*.******.****.****.***.******.***.**.*";
            tabuleiro[5] = "*......................................*";
            tabuleiro[6] = "*.****.***.*******.****.********.***.***";
            tabuleiro[7] = "*......***.........****..............***";
            tabuleiro[8] = "****************************************";
            timer1.Enabled = true;
            timer1.Interval = 200;
            pbTabuleiro.Invalidate();
            tempo = vsbNivel.Value/10; 
            pontos = 0;
        }

        private void pbTabuleiro_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
