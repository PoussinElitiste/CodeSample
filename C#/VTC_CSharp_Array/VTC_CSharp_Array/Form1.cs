using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace VTC_CSharp_Array
{
    public partial class Form1 : Form
    {
        private int[] values; // array
        private int value;
        private ArrayList collections = new ArrayList(); // !pas de type
        private List<int> liste = new List<int>();
        private SortedList<string, int> map = new SortedList<string, int>(4);
        private Stack<int> pile = new Stack<int>(); 
        private Queue<int> file = new Queue<int>();

        private string message;

        public Form1()
        {
            InitializeComponent();
            values = new int[7]{0,1,2,3,4,5,6};
            map.Add("test1", 32);
            map.Add("test2", 22);
            map.Add("test3", 45);
        }

        private void Show_Click(object sender, EventArgs e)
        {
            message = "Array content :\n" ;
            for(int i=0; i<values.Length; ++i)
            {
                message += (" " + Convert.ToString(values[i]));
            }

            MessageBox.Show(message);

            message = "Untyped  content :\n";

            if (collections.Count > 0)
            {
                //for(int i = 0; i<collections.Count; ++i)
                foreach(int msg in collections)
                {
                    //message += (" " + Convert.ToString(collections[i]));
                    message += (" " + msg);
                }
            }

            MessageBox.Show(message);

            message = "sorted list content :\n";

            foreach (KeyValuePair<string, int> data in map)
            {
                message += (" " + data.Key + " " + data.Value + "\n");
            }

            message += "count : " + Convert.ToString(map.Count) + "\t";
            message += "capacity : " + Convert.ToString(map.Capacity);

            MessageBox.Show(message);

        }

        private void add_Click(object sender, EventArgs e)
        {
            try
            {
                value = Convert.ToInt32(textBox1.Text);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            collections.Add(value);
            textBox1.Clear();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            DateTime dt = new DateTime(2010, 07, 19);
            MessageBox.Show(Convert.ToString(dt));
        }
    }
}