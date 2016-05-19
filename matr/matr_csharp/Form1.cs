using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using math_wrapper;
using System.Diagnostics;

namespace matr_csharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            panel2.Visible = false;
            panel3.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MatrFuncs mf = new MatrFuncs();
            if (radioButton1.Checked == true)
            {
                double[] mas = new double[12];
                double[] vec = new double[3];
                
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        mas[i * 3 + j] = j + 1;
                        vec[j] = 4;
                    }                    
                }
                double[] res = mf.MatrXVec(mas, vec, 4, 3);
                for (int i = 0; i < 3; i++)
                {
                    richTextBox1.Text += res[i] + Environment.NewLine;
                }
                //double[][] mas = new double[4][];
                //for (int i = 0; i < 4; i++)
                //{
                //    mas[i] = new double[3];
                //}
                //mas[0][0] = Convert.ToInt32(textBox1.Text);
                //mas[0][1] = Convert.ToInt32(textBox5.Text);
                //mas[0][2] = Convert.ToInt32(textBox9.Text);
                //mas[1][0] = Convert.ToInt32(textBox2.Text);
                //mas[1][1] = Convert.ToInt32(textBox6.Text);
                //mas[1][2] = Convert.ToInt32(textBox10.Text);
                //mas[2][0] = Convert.ToInt32(textBox3.Text);
                //mas[2][1] = Convert.ToInt32(textBox7.Text);
                //mas[2][2] = Convert.ToInt32(textBox11.Text);
                //mas[3][0] = Convert.ToInt32(textBox4.Text);
                //mas[3][1] = Convert.ToInt32(textBox8.Text);
                //mas[3][2] = Convert.ToInt32(textBox12.Text);
                //double[] vec = new double[4];
                //vec[0] = Convert.ToInt32(textBox13.Text);
                //vec[1] = Convert.ToInt32(textBox14.Text);
                //vec[2] = Convert.ToInt32(textBox15.Text);
                //vec[3] = Convert.ToInt32(textBox16.Text);
                //double[] res;
                //unsafe
                //{
                //    res = mf.MatrXVec(mas, vec, 4, 3);
                //}
                //for (int i = 0; i < 4; i++)
                //{
                //    richTextBox1.Text += res[i] + Environment.NewLine;
                //}
            }
            if (radioButton2.Checked == true)
            {
                double[] mas = new double[16];
                for (int i = 0; i < 16; i++)
                {
                    mas[i] = i;
                }
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        richTextBox2.Text += mas[i * 4 + j] + "   ";
                    }
                    richTextBox2.Text += Environment.NewLine;
                }
                richTextBox2.Text += Environment.NewLine;
                double[] res = mf.MatrTranspon(mas, 4);
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        richTextBox2.Text += res[i * 4 + j] + "   ";
                    }
                    richTextBox2.Text += Environment.NewLine;
                }
                //double[][] mas = new double[4][];
                //for (int i = 0; i < 4; i++)
                //{
                //    mas[i] = new double[4];
                //}
                //mas[0][0] = Convert.ToInt32(textBox17.Text);
                //mas[0][1] = Convert.ToInt32(textBox21.Text);
                //mas[0][2] = Convert.ToInt32(textBox22.Text);
                //mas[0][3] = Convert.ToInt32(textBox23.Text);
                //mas[1][0] = Convert.ToInt32(textBox18.Text);
                //mas[1][1] = Convert.ToInt32(textBox24.Text);
                //mas[1][2] = Convert.ToInt32(textBox25.Text);
                //mas[1][3] = Convert.ToInt32(textBox26.Text);
                //mas[2][0] = Convert.ToInt32(textBox19.Text);
                //mas[2][1] = Convert.ToInt32(textBox27.Text);
                //mas[2][2] = Convert.ToInt32(textBox28.Text);
                //mas[2][3] = Convert.ToInt32(textBox31.Text);
                //mas[3][0] = Convert.ToInt32(textBox20.Text);
                //mas[3][1] = Convert.ToInt32(textBox29.Text);
                //mas[3][2] = Convert.ToInt32(textBox30.Text);
                //mas[3][3] = Convert.ToInt32(textBox32.Text);
                //double[][] res;
                //unsafe
                //{
                //    res = mf.MatrTranspon(mas, 4);
                //}
                //for (int i = 0; i < 4; i++)
                //{
                //    for (int j = 0; j < 4; j++)
                //    {
                //        richTextBox2.Text += res[i][j] + "   ";
                //    }
                //    richTextBox2.Text += Environment.NewLine;
                //}
            }

            if (radioButton3.Checked == true)
            {
                double[] mas = new double[16];
                double[] mas1 = new double[16];
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        mas[i * 4 + j] = i + 1;
                        mas1[i * 4 + j] = j + 1;
                    }
                }
                double[] res = mf.MatrXMatr(mas1, mas, 4, 4, 4, 4);
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        richTextBox3.Text += res[i * 4 + j] + "   ";
                    }
                    richTextBox3.Text += Environment.NewLine;
                }
                //double[][] mas = new double[4][];
                //for (int i = 0; i < 4; i++)
                //{
                //    mas[i] = new double[4];
                //}
                //mas[0][0] = Convert.ToInt32(textBox64.Text);
                //mas[0][1] = Convert.ToInt32(textBox60.Text);
                //mas[0][2] = Convert.ToInt32(textBox56.Text);
                //mas[0][3] = Convert.ToInt32(textBox52.Text);
                //mas[1][0] = Convert.ToInt32(textBox63.Text);
                //mas[1][1] = Convert.ToInt32(textBox59.Text);
                //mas[1][2] = Convert.ToInt32(textBox55.Text);
                //mas[1][3] = Convert.ToInt32(textBox51.Text);
                //mas[2][0] = Convert.ToInt32(textBox62.Text);
                //mas[2][1] = Convert.ToInt32(textBox58.Text);
                //mas[2][2] = Convert.ToInt32(textBox54.Text);
                //mas[2][3] = Convert.ToInt32(textBox50.Text);
                //mas[3][0] = Convert.ToInt32(textBox61.Text);
                //mas[3][1] = Convert.ToInt32(textBox57.Text);
                //mas[3][2] = Convert.ToInt32(textBox53.Text);
                //mas[3][3] = Convert.ToInt32(textBox49.Text);

                //double[][] mas1 = new double[4][];
                //for (int i = 0; i < 4; i++)
                //{
                //    mas1[i] = new double[4];
                //}
                //mas1[0][0] = Convert.ToInt32(textBox33.Text);
                //mas1[0][1] = Convert.ToInt32(textBox37.Text);
                //mas1[0][2] = Convert.ToInt32(textBox41.Text);
                //mas1[0][3] = Convert.ToInt32(textBox45.Text);
                //mas1[1][0] = Convert.ToInt32(textBox34.Text);
                //mas1[1][1] = Convert.ToInt32(textBox38.Text);
                //mas1[1][2] = Convert.ToInt32(textBox42.Text);
                //mas1[1][3] = Convert.ToInt32(textBox46.Text);
                //mas1[2][0] = Convert.ToInt32(textBox35.Text);
                //mas1[2][1] = Convert.ToInt32(textBox39.Text);
                //mas1[2][2] = Convert.ToInt32(textBox43.Text);
                //mas1[2][3] = Convert.ToInt32(textBox47.Text);
                //mas1[3][0] = Convert.ToInt32(textBox36.Text);
                //mas1[3][1] = Convert.ToInt32(textBox40.Text);
                //mas1[3][2] = Convert.ToInt32(textBox44.Text);
                //mas1[3][3] = Convert.ToInt32(textBox48.Text);

                //double[][] res;
                //unsafe
                //{
                //    res = mf.MatrXMatr(mas1, mas, 4, 4, 4, 4);
                //}
                //for (int i = 0; i < 4; i++)
                //{
                //    for (int j = 0; j < 4; j++)
                //    {
                //        richTextBox3.Text += res[i][j] + "   ";
                //    }
                //    richTextBox3.Text += Environment.NewLine;
                //}
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            panel1.Visible = false;
            panel2.Visible = true;
            panel3.Visible = false;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            panel1.Visible = true;
            panel2.Visible = false;
            panel3.Visible = false;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            panel1.Visible = false;
            panel2.Visible = false;
            panel3.Visible = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //int n = 100;
            //double[][] mas = new double[n][];
            //for (int i = 0; i < n; i++)
            //{
            //    mas[i] = new double[n];
            //    for (int j = 0; j < n; j++)
            //    {
            //        mas[i][j] = 1;
            //    }
            //}
            //double[][] mas1 = new double[n][];
            //for (int i = 0; i < n; i++)
            //{
            //    mas1[i] = new double[n];
            //    for (int j = 0; j < n; j++)
            //    {
            //        mas1[i][j] = 2;
            //    }
            //}
            //MatrFuncs mf = new MatrFuncs();
            //double[][] res;
            //Stopwatch s = new Stopwatch();
            //s.Start();
            //res = mf.MatrXMatr(mas1, mas, n, n, n, n);
            //s.Stop();

            double[][] mas = new double[3][];
            for (int i = 0; i < 3; i++)
            {
                mas[i] = new double[3];
            }
            mas[0][0] = Convert.ToInt32(1.5);
            mas[0][1] = Convert.ToInt32(1.2);
            mas[0][2] = Convert.ToInt32(3.3);
            mas[1][0] = Convert.ToInt32(1.5);
            mas[1][1] = Convert.ToInt32(1.2);
            mas[1][2] = Convert.ToInt32(3.3);
            mas[2][0] = Convert.ToInt32(1.5);
            mas[2][1] = Convert.ToInt32(1.2);
            mas[2][2] = Convert.ToInt32(3.3);
            double[] vec = new double[3];
            vec[0] = Convert.ToInt32(4.1);
            vec[1] = Convert.ToInt32(5.7);
            vec[2] = Convert.ToInt32(5.7);
            double[] result = new double[3];
            result[0] = Convert.ToInt32(31.8);
            result[1] = Convert.ToInt32(31.8);
            result[2] = Convert.ToInt32(31.8);

            double[] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();
            {
                res = mf.MatrXVec(mas, vec, 3, 3);
            }

            string str = "";
            for (int i = 0; i < 3; i++)
            {
                str += String.Format("{0:0.00}", res[i]) + "   ";
            }

            string str1 = "";
            for (int i = 0; i < 3; i++)
            {
                str1 += String.Format("{0:0.00}", result[i]) + "   ";
            }
        }

        private void btn_Simp_Click(object sender, EventArgs e)
        {
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            IntegrFuncs intF = new IntegrFuncs();
            s1.Start();
            lbl_res.Text = intF.Simpson_NotParal(F, Convert.ToDouble(tbx_a.Text), Convert.ToDouble(tbx_b.Text), Convert.ToInt32(tbx_N.Text)).ToString();
            s1.Stop();

            s2.Start();
            lbl_res_paral.Text = intF.Simpson(F, Convert.ToDouble(tbx_a.Text), Convert.ToDouble(tbx_b.Text), Convert.ToInt32(tbx_N.Text)).ToString();
            s2.Stop();

            lbl_time.Text = s1.ElapsedMilliseconds.ToString();
            lbl_time_paral.Text = s2.ElapsedMilliseconds.ToString();
        }
        
        private void btn_Simp38_Click(object sender, EventArgs e)
        {
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            IntegrFuncs intF = new IntegrFuncs();
            s1.Start();
            lbl_res.Text = intF.Simpson38_NotParal(F, Convert.ToDouble(tbx_a.Text), Convert.ToDouble(tbx_b.Text), Convert.ToInt32(tbx_N.Text)).ToString();
            s1.Stop();

            s2.Start();
            lbl_res_paral.Text = intF.Simpson38(F, Convert.ToDouble(tbx_a.Text), Convert.ToDouble(tbx_b.Text), Convert.ToInt32(tbx_N.Text)).ToString();
            s2.Stop();

            lbl_time.Text = s1.ElapsedMilliseconds.ToString();
            lbl_time_paral.Text = s2.ElapsedMilliseconds.ToString();
        }

        private void btn_MK_Click(object sender, EventArgs e)
        {
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            IntegrFuncs intF = new IntegrFuncs();
            s1.Start();
            lbl_res.Text = intF.MonteKarlo_NotParal(F, Convert.ToDouble(tbx_a.Text), Convert.ToDouble(tbx_b.Text), Convert.ToInt32(tbx_N.Text)).ToString();
            s1.Stop();

            s2.Start();
            lbl_res_paral.Text = intF.MonteKarlo(F, Convert.ToDouble(tbx_a.Text), Convert.ToDouble(tbx_b.Text), Convert.ToInt32(tbx_N.Text)).ToString();
            s2.Stop();

            lbl_time.Text = s1.ElapsedMilliseconds.ToString();
            lbl_time_paral.Text = s2.ElapsedMilliseconds.ToString();
        }

        public double F(double x)
        {
            return x * x;
        }
        //unsafe public delegate double FDelegate(double x, double* y);
        private void btn_eiler_Click(object sender, EventArgs e)
        {
            int count = 3;
            double[] y = new double[count];
            y[0] = 10;
            y[1] = 10;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            //for (int i = 0; i < count; i++)
            //{
            //    unsafe { masF[i] = F_diff; }
            //}
            unsafe { masF[0] = F_diff1; }
            unsafe { masF[1] = F_diff2; }
            unsafe { masF[2] = F_diff3; }
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            DiffFuncs df = new DiffFuncs();
            s1.Start();
            double[] res = df.Eiler(masF, Convert.ToDouble(tbx_a_diff.Text), Convert.ToDouble(tbx_b_diff.Text), Convert.ToInt32(tbx_N_diff.Text), y, count);
            s1.Stop();
            lbl_diff_time.Text = s1.ElapsedMilliseconds.ToString();
            dgv_diff.Rows.Clear();
            dgv_diff.Columns.Clear();
            dgv_diff.Columns.Add("", "");
            dgv_diff.Rows.Add(1);
            for (int i = 0; i < count; i++)
            {
                dgv_diff.Columns.Add(i.ToString(), i.ToString());
                dgv_diff.Rows[0].Cells[i + 1].Value = res[i];
            }
            dgv_diff.Columns.RemoveAt(0);

            s2.Start();
            double[] res_paral = df.Eiler_Paral(masF, Convert.ToDouble(tbx_a_diff.Text), Convert.ToDouble(tbx_b_diff.Text), Convert.ToInt32(tbx_N_diff.Text), y, count);
            s2.Stop();
            lbl_diff_time_paral.Text = s2.ElapsedMilliseconds.ToString();
            dgv_diff_paral.Rows.Clear();
            dgv_diff_paral.Columns.Clear();
            dgv_diff_paral.Columns.Add("", "");
            dgv_diff_paral.Rows.Add(1);
            for (int i = 0; i < count; i++)
            {
                dgv_diff_paral.Columns.Add(i.ToString(), i.ToString());
                dgv_diff_paral.Rows[0].Cells[i + 1].Value = res[i];
            }
            dgv_diff_paral.Columns.RemoveAt(0);
        }

        unsafe public double F_diff(double t, double* x)
        {
            return t + x[0];
        }

        unsafe public double F_diff1(double t, double* x)
        {
            return -(55+x[2])*x[0]+65*x[1];
        }
        unsafe public double F_diff2(double t, double* x)
        {
            return 0.0785*(x[0]-x[1]);
        }
        unsafe public double F_diff3(double t, double* x)
        {
            return 0.1*x[0];
        }

        private void btn_rk2_Click(object sender, EventArgs e)
        {
            int count = 3;
            double[] y = new double[count];
            y[0] = 10;
            y[1] = 10;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            //for (int i = 0; i < count; i++)
            //{
            //    unsafe { masF[i] = F_diff; }
            //}
            unsafe { masF[0] = F_diff1; }
            unsafe { masF[1] = F_diff2; }
            unsafe { masF[2] = F_diff3; }
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            DiffFuncs df = new DiffFuncs();
            s1.Start();
            double[] res = df.RungeKutta2(masF, Convert.ToDouble(tbx_a_diff.Text), Convert.ToDouble(tbx_b_diff.Text), Convert.ToInt32(tbx_N_diff.Text), y, count);
            s1.Stop();
            lbl_diff_time.Text = s1.ElapsedMilliseconds.ToString();
            dgv_diff.Rows.Clear();
            dgv_diff.Columns.Clear();
            dgv_diff.Columns.Add("", "");
            dgv_diff.Rows.Add(1);
            for (int i = 0; i < count; i++)
            {
                dgv_diff.Columns.Add(i.ToString(), i.ToString());
                dgv_diff.Rows[0].Cells[i + 1].Value = res[i];
            }
            dgv_diff.Columns.RemoveAt(0);

            s2.Start();
            double[] res_paral = df.RungeKutta2_Paral(masF, Convert.ToDouble(tbx_a_diff.Text), Convert.ToDouble(tbx_b_diff.Text), Convert.ToInt32(tbx_N_diff.Text), y, count);
            s2.Stop();
            lbl_diff_time_paral.Text = s2.ElapsedMilliseconds.ToString();
            dgv_diff_paral.Rows.Clear();
            dgv_diff_paral.Columns.Clear();
            dgv_diff_paral.Columns.Add("", "");
            dgv_diff_paral.Rows.Add(1);
            for (int i = 0; i < count; i++)
            {
                dgv_diff_paral.Columns.Add(i.ToString(), i.ToString());
                dgv_diff_paral.Rows[0].Cells[i + 1].Value = res[i];
            }
            dgv_diff_paral.Columns.RemoveAt(0);
        }

        private void btn_rk4_Click(object sender, EventArgs e)
        {
            int count = 3;
            double[] y = new double[count];
            y[0] = 10;
            y[1] = 10;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            //for (int i = 0; i < count; i++)
            //{
            //    unsafe { masF[i] = F_diff; }
            //}
            unsafe { masF[0] = F_diff1; }
            unsafe { masF[1] = F_diff2; }
            unsafe { masF[2] = F_diff3; }
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            DiffFuncs df = new DiffFuncs();
            s1.Start();
            double[] res = df.RungeKutta4(masF, Convert.ToDouble(tbx_a_diff.Text), Convert.ToDouble(tbx_b_diff.Text), Convert.ToInt32(tbx_N_diff.Text), y, count);
            s1.Stop();
            lbl_diff_time.Text = s1.ElapsedMilliseconds.ToString();
            dgv_diff.Rows.Clear();
            dgv_diff.Columns.Clear();
            dgv_diff.Columns.Add("", "");
            dgv_diff.Rows.Add(1);
            for (int i = 0; i < count; i++)
            {
                dgv_diff.Columns.Add(i.ToString(), i.ToString());
                dgv_diff.Rows[0].Cells[i + 1].Value = res[i];
            }
            dgv_diff.Columns.RemoveAt(0);

            s2.Start();
            double[] res_paral = df.RungeKutta4_Paral(masF, Convert.ToDouble(tbx_a_diff.Text), Convert.ToDouble(tbx_b_diff.Text), Convert.ToInt32(tbx_N_diff.Text), y, count);
            s2.Stop();
            lbl_diff_time_paral.Text = s2.ElapsedMilliseconds.ToString();
            dgv_diff_paral.Rows.Clear();
            dgv_diff_paral.Columns.Clear();
            dgv_diff_paral.Columns.Add("", "");
            dgv_diff_paral.Rows.Add(1);
            for (int i = 0; i < count; i++)
            {
                dgv_diff_paral.Columns.Add(i.ToString(), i.ToString());
                dgv_diff_paral.Rows[0].Cells[i + 1].Value = res[i];
            }
            dgv_diff_paral.Columns.RemoveAt(0);
        }
    }
}
