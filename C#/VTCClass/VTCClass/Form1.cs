using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace VTCClass
{
    public partial class Form1 : Form
    {
        private String buttonText_;
        private int buttonValue_;

        public Form1()
        {
            InitializeComponent();
            buttonText_ = button1.Text;
            buttonValue_ = 0;
        }

        /* Yo */
        // Hello world demo
        
        private void MessageText(String text)
        {
            MessageBox.Show(text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBox1.Text == "")
                    throw new Exception("Enter a value");
                if ((Convert.ToInt16(textBox1.Text)<1) || Convert.ToInt16(textBox1.Text)>100)
                {
                    throw new Exception("Enter a value between 1 and 100");
                }
                buttonValue_ = Convert.ToInt16(textBox1.Text) * 10;
                button1.Text = buttonValue_.ToString("P2");
            }
            catch (Exception ex)
            {
                MessageText("error occur" + "\n\n" + ex.Message);
            }
            
        }

        private void button1_enter(object sender, EventArgs e)
        {
            button1.Text = buttonValue_.ToString("P2");
        }

        private void button1_leave(object sender, EventArgs e)
        {
            button1.Text = buttonText_;
        }
    }
}