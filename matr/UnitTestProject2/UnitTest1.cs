using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using math_wrapper;
using System.Diagnostics;

namespace UnitTestProject2
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void MatrTranspTime()// транспонирование время
        {
            int n = 1000;
            double[][] mas = new double[n][];
            for (int i = 0; i < n; i++)
            {
                mas[i] = new double[n];
                for (int j = 0; j < n; j++)
                {
                    mas[i][j] = 1;
                }
            }

            math_wrapper.MatrFuncs mf1 = new math_wrapper.MatrFuncs();

            double[][] res;
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            s1.Start();
            res = mf1.MatrTranspon(mas, n);
            s1.Stop();
            s2.Start();
            res = mf1.MatrTranspon_NotParal(mas, n);
            s2.Stop();
            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;
            Assert.AreEqual(n1 < n2, true);
        }


        [TestMethod]
        public void MatrXVectTime()
        {
            int n = 1000;
            double[][] mas = new double[n][];
            for (int i = 0; i < n; i++)
            {
                mas[i] = new double[n];
                for (int j = 0; j < n; j++)
                {
                    mas[i][j] = 1;
                }
            }

            double[] vec = new double[n];

            math_wrapper.MatrFuncs mf1 = new math_wrapper.MatrFuncs();

            double[] res;
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            s1.Start();
            res = mf1.MatrXVec(mas, vec, n, n);
            s1.Stop();
            s2.Start();
            res = mf1.MatrXVec_NotParal(mas, vec, n, n);
            s2.Stop();
            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;
            Assert.AreEqual(n1 < n2, true);
        }

        [TestMethod]
        public void MatrXMatrTime()
        {
            int n = 1000;
            double[][] mas = new double[n][];
            for (int i = 0; i < n; i++)
            {
                mas[i] = new double[n];
                for (int j = 0; j < n; j++)
                {
                    mas[i][j] = 1;
                }
            }

            double[][] mas1 = new double[n][];
            for (int i = 0; i < n; i++)
            {
                mas1[i] = new double[n];
                for (int j = 0; j < n; j++)
                {
                    mas1[i][j] = 1;
                }
            }


            math_wrapper.MatrFuncs mf1 = new math_wrapper.MatrFuncs();

            double[][] res;
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            s1.Start();
            res = mf1.MatrXMatr(mas1, mas, n, n, n, n);
            s1.Stop();
            s2.Start();
            res = mf1.MatrXMatr_NotParal(mas1, mas, n, n, n, n);
            s2.Stop();
            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;
            Assert.AreEqual(n1 < n2, true);
        }

        [TestMethod]
        public void SimpsonTime()
        {

            math_wrapper.IntegrFuncs mf1 = new math_wrapper.IntegrFuncs();


            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            s1.Start();
            mf1.Simpson(F, 0, 10, 1000000);
            s1.Stop();
            s2.Start();
            mf1.Simpson_NotParal(F, 0, 10, 1000000);
            s2.Stop();
            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;
            Assert.AreEqual(n1 > n2, true);
        }

        [TestMethod]
        public void Simpson38Time()
        {

            math_wrapper.IntegrFuncs mf1 = new math_wrapper.IntegrFuncs();


            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            s1.Start();
            mf1.Simpson38(F, 0, 10, 1000000);
            s1.Stop();
            s2.Start();
            mf1.Simpson38_NotParal(F, 0, 10, 1000000);
            s2.Stop();
            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;
            Assert.AreEqual(n1 > n2, true);
        }

        [TestMethod]
        public void MonteKarloTime()
        {

            math_wrapper.IntegrFuncs mf1 = new math_wrapper.IntegrFuncs();


            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            s1.Start();
            mf1.MonteKarlo(F, 0, 10, 1000000);
            s1.Stop();
            s2.Start();
            mf1.MonteKarlo_NotParal(F, 0, 10, 1000000);
            s2.Stop();
            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;
            Assert.AreEqual(n1 > n2, true);
        }


        [TestMethod]
        public void Simpson()
        {

            math_wrapper.IntegrFuncs mf1 = new math_wrapper.IntegrFuncs();

            double res = mf1.Simpson(F, 0, 10, 1000000);
            Assert.AreEqual(Math.Round(res, 4), 333.3333);
        }

        [TestMethod]
        public void Simpson38()
        {

            math_wrapper.IntegrFuncs mf1 = new math_wrapper.IntegrFuncs();

            double res = mf1.Simpson38(F, 0, 10, 1000000);
            Assert.AreEqual(Math.Round(res, 4), 333.3333);
        }

        [TestMethod]
        public void MonteKarlo()
        {

            math_wrapper.IntegrFuncs mf1 = new math_wrapper.IntegrFuncs();

            double res = mf1.MonteKarlo(F, 0, 10, 1000000);
            bool flag = false;
            if (res > 332 && res < 334)
            {
                flag = true;
            }
            Assert.IsTrue(flag);
        }

        double F(double x)
        {
            return x * x;
        }


        [TestMethod]
        public void Eiler()
        {
            int count = 3;
            double[] y = new double[count];
            y[0] = 1;
            y[1] = 1;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            unsafe { masF[0] = F_diff1; }
            unsafe { masF[1] = F_diff2; }
            unsafe { masF[2] = F_diff3; }
            DiffFuncs df = new DiffFuncs();

            double[] res = df.Eiler(masF, 0, 1, 100, y, count);

            double[] rres = { 1.19, 1.01, 0.11 };

            string str_res = "", str_rres = "";

            for (int i = 0; i < count; i++)
            {
                str_res += String.Format("{0:0.00}", res[i]) + " ";
                str_rres += String.Format("{0:0.00}", rres[i]) + " ";
            }
        }

        [TestMethod]
        public void RungeKutta2()
        {
            int count = 3;
            double[] y = new double[count];
            y[0] = 1;
            y[1] = 1;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            unsafe { masF[0] = F_diff1; }
            unsafe { masF[1] = F_diff2; }
            unsafe { masF[2] = F_diff3; }
            DiffFuncs df = new DiffFuncs();

            double[] res = df.RungeKutta2(masF, 0, 1, 100, y, count);

            double[] rres = { 1.19, 1.01, 0.11 };

            string str_res = "", str_rres = "";

            for (int i = 0; i < count; i++)
            {
                str_res += String.Format("{0:0.00}", res[i]) + " ";
                str_rres += String.Format("{0:0.00}", rres[i]) + " ";
            }
        }

        [TestMethod]
        public void RungeKutta4()
        {
            int count = 3;
            double[] y = new double[count];
            y[0] = 1;
            y[1] = 1;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            unsafe { masF[0] = F_diff1; }
            unsafe { masF[1] = F_diff2; }
            unsafe { masF[2] = F_diff3; }
            DiffFuncs df = new DiffFuncs();

            double[] res = df.RungeKutta4(masF, 0, 1, 100, y, count);

            double[] rres = { 1.19, 1.01, 0.11 };

            string str_res = "", str_rres = "";

            for (int i = 0; i < count; i++)
            {
                str_res += String.Format("{0:0.00}", res[i]) + " ";
                str_rres += String.Format("{0:0.00}", rres[i]) + " ";
            }
        }


        [TestMethod]
        public void EilerTime()
        {
            int count = 300000;
            double[] y = new double[count];
            y[0] = 1;
            y[1] = 1;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            for (int i = 0; i < count; i++)
            {
                if (i % 3 == 0)
                    unsafe { masF[i] = F_diff1; }
                if (i % 3 == 1)
                    unsafe { masF[i] = F_diff1; }
                if (i % 3 == 2)
                    unsafe { masF[i] = F_diff1; }
            }
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            DiffFuncs df = new DiffFuncs();
            s1.Start();
            double[] res = df.Eiler(masF, 0, 1, 100, y, count);
            s1.Stop();

            s2.Start();
            double[] res_paral = df.Eiler_Paral(masF, 0, 1, 100, y, count);
            s2.Stop();

            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;

            Assert.AreEqual(n1 < n2, true);
        }

        [TestMethod]
        public void RungeKutta2Time()
        {
            int count = 300000;
            double[] y = new double[count];
            y[0] = 1;
            y[1] = 1;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            for (int i = 0; i < count; i++)
            {
                if (i % 3 == 0)
                    unsafe { masF[i] = F_diff1; }
                if (i % 3 == 1)
                    unsafe { masF[i] = F_diff1; }
                if (i % 3 == 2)
                    unsafe { masF[i] = F_diff1; }
            }
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            DiffFuncs df = new DiffFuncs();
            s1.Start();
            double[] res = df.RungeKutta2(masF, 0, 1, 100, y, count);
            s1.Stop();

            s2.Start();
            double[] res_paral = df.RungeKutta2_Paral(masF, 0, 1, 100, y, count);
            s2.Stop();

            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;

            Assert.AreEqual(n1 < n2, true);
        }

        [TestMethod]
        public void RungeKutta4Time()
        {
            int count = 300000;
            double[] y = new double[count];
            y[0] = 1;
            y[1] = 1;
            y[2] = 0;
            DiffFuncs.FDelegate[] masF = new DiffFuncs.FDelegate[count];
            for (int i = 0; i < count; i++)
            {
                if (i % 3 == 0)
                    unsafe { masF[i] = F_diff1; }
                if (i % 3 == 1)
                    unsafe { masF[i] = F_diff1; }
                if (i % 3 == 2)
                    unsafe { masF[i] = F_diff1; }
            }
            Stopwatch s1 = new Stopwatch();
            Stopwatch s2 = new Stopwatch();
            DiffFuncs df = new DiffFuncs();
            s1.Start();
            double[] res = df.RungeKutta4(masF, 0, 1, 100, y, count);
            s1.Stop();

            s2.Start();
            double[] res_paral = df.RungeKutta4_Paral(masF, 0, 1, 100, y, count);
            s2.Stop();

            long n1 = s1.ElapsedMilliseconds;
            long n2 = s2.ElapsedMilliseconds;

            Assert.AreEqual(n1 < n2, true);
        }


        unsafe public double F_diff1(double t, double* x)
        {
            return -(55 + x[2]) * x[0] + 65 * x[1];
        }
        unsafe public double F_diff2(double t, double* x)
        {
            return 0.0785 * (x[0] - x[1]);
        }
        unsafe public double F_diff3(double t, double* x)
        {
            return 0.1 * x[0];
        }
    }
}
