using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Diagnostics;


namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void MatrTransp()
        {
            double[][] mas = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas[i] = new double[4];
            }
            mas[0][0] = (1);
            mas[0][1] = (2);
            mas[0][2] = (3);
            mas[0][3] = (4);
            mas[1][0] = (5);
            mas[1][1] = (6);
            mas[1][2] = (7);
            mas[1][3] = (8);
            mas[2][0] = (9);
            mas[2][1] = (10);
            mas[2][2] = (11);
            mas[2][3] = (12);
            mas[3][0] = (13);
            mas[3][1] = (14);
            mas[3][2] = (15);
            mas[3][3] = (16);

            double[][] mas1 = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas1[i] = new double[4];
            }
            mas1[0][0] = (1);
            mas1[0][1] = (5);
            mas1[0][2] = (9);
            mas1[0][3] = (13);
            mas1[1][0] = (2);
            mas1[1][1] = (6);
            mas1[1][2] = (10);
            mas1[1][3] = (14);
            mas1[2][0] = (3);
            mas1[2][1] = (7);
            mas1[2][2] = (11);
            mas1[2][3] = (15);
            mas1[3][0] = (4);
            mas1[3][1] = (8);
            mas1[3][2] = (12);
            mas1[3][3] = (16);

            double[][] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();
            //unsafe
            {
                res = mf.MatrTranspon(mas, 4);
            }

            string str = "";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    str += res[i][j].ToString() + "   ";
                }
            }

            string str1 = "";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    str1 += mas1[i][j].ToString() + "   ";
                }
            }

            Assert.AreEqual(str, str1);
        }
        
        [TestMethod]
        public void MatrXVect()
        {
            double[][] mas = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas[i] = new double[3];
            }
            mas[0][0] = (1);
            mas[0][1] = (2);
            mas[0][2] = (3);
            mas[1][0] = (1);
            mas[1][1] = (2);
            mas[1][2] = (3);
            mas[2][0] = (1);
            mas[2][1] = (2);
            mas[2][2] = (3);
            mas[3][0] = (1);
            mas[3][1] = (2);
            mas[3][2] = (3);
            double[] vec = new double[4];
            vec[0] = (4);
            vec[1] = (4);
            vec[2] = (4);
            vec[3] = (4);
            double[] result = new double[4];
            result[0] = (24);
            result[1] = (24);
            result[2] = (24);
            result[3] = (24);

            double[] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();
            {
                res = mf.MatrXVec(mas, vec, 4, 3);
            }

            string str = "";
            for (int i = 0; i < 4; i++)
            {
                str += res[i].ToString() + "   ";
            }

            string str1 = "";
            for (int i = 0; i < 4; i++)
            {
                str1 += result[i].ToString() + "   ";
            }

            Assert.AreEqual(str, str1);
        }

        [TestMethod]
        public void MatrXMatr()
        {
            double[][] mas = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas[i] = new double[4];
            }
            mas[0][0] = (1);
            mas[0][1] = (2);
            mas[0][2] = (3);
            mas[0][3] = (4);
            mas[1][0] = (1);
            mas[1][1] = (2);
            mas[1][2] = (3);
            mas[1][3] = (4);
            mas[2][0] = (1);
            mas[2][1] = (2);
            mas[2][2] = (3);
            mas[2][3] = (4);
            mas[3][0] = (1);
            mas[3][1] = (2);
            mas[3][2] = (3);
            mas[3][3] = (4);


            double[][] mas1 = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas1[i] = new double[4];
            }
            mas1[0][0] = (1);
            mas1[0][1] = (1);
            mas1[0][2] = (1);
            mas1[0][3] = (1);
            mas1[1][0] = (2);
            mas1[1][1] = (2);
            mas1[1][2] = (2);
            mas1[1][3] = (2);
            mas1[2][0] = (3);
            mas1[2][1] = (3);
            mas1[2][2] = (3);
            mas1[2][3] = (3);
            mas1[3][0] = (4);
            mas1[3][1] = (4);
            mas1[3][2] = (4);
            mas1[3][3] = (4);

            double[][] result = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                result[i] = new double[4];
            }
            result[0][0] = (30);
            result[0][1] = (30);
            result[0][2] = (30);
            result[0][3] = (30);
            result[1][0] = (30);
            result[1][1] = (30);
            result[1][2] = (30);
            result[1][3] = (30);
            result[2][0] = (30);
            result[2][1] = (30);
            result[2][2] = (30);
            result[2][3] = (30);
            result[3][0] = (30);
            result[3][1] = (30);
            result[3][2] = (30);
            result[3][3] = (30);

            double[][] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();

            res = mf.MatrXMatr(mas, mas1, 4, 4, 4, 4);


            string str = "";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    str += res[i][j].ToString() + "   ";
                }
            }

            string str1 = "";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    str1 += result[i][j].ToString() + "   ";
                }
            }

            Assert.AreEqual(str, str1);
        }

        [TestMethod]
        public void MatrXMatrMinus()
        {
            double[][] mas = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas[i] = new double[4];
            }
            mas[0][0] = (-1);
            mas[0][1] = (-2);
            mas[0][2] = (-3);
            mas[0][3] = (-4);
            mas[1][0] = (-1);
            mas[1][1] = (-2);
            mas[1][2] = (-3);
            mas[1][3] = (-4);
            mas[2][0] = (-1);
            mas[2][1] = (-2);
            mas[2][2] = (-3);
            mas[2][3] = (-4);
            mas[3][0] = (-1);
            mas[3][1] = (-2);
            mas[3][2] = (-3);
            mas[3][3] = (-4);


            double[][] mas1 = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas1[i] = new double[4];
            }
            mas1[0][0] = (-1);
            mas1[0][1] = (-1);
            mas1[0][2] = (-1);
            mas1[0][3] = (-1);
            mas1[1][0] = (-2);
            mas1[1][1] = (-2);
            mas1[1][2] = (-2);
            mas1[1][3] = (-2);
            mas1[2][0] = (-3);
            mas1[2][1] = (-3);
            mas1[2][2] = (-3);
            mas1[2][3] = (-3);
            mas1[3][0] = (-4);
            mas1[3][1] = (-4);
            mas1[3][2] = (-4);
            mas1[3][3] = (-4);

            double[][] result = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                result[i] = new double[4];
            }
            result[0][0] = (30);
            result[0][1] = (30);
            result[0][2] = (30);
            result[0][3] = (30);
            result[1][0] = (30);
            result[1][1] = (30);
            result[1][2] = (30);
            result[1][3] = (30);
            result[2][0] = (30);
            result[2][1] = (30);
            result[2][2] = (30);
            result[2][3] = (30);
            result[3][0] = (30);
            result[3][1] = (30);
            result[3][2] = (30);
            result[3][3] = (30);

            double[][] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();

            res = mf.MatrXMatr(mas, mas1, 4, 4, 4, 4);


            string str = "";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    str += res[i][j].ToString() + "   ";
                }
            }

            string str1 = "";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    str1 += result[i][j].ToString() + "   ";
                }
            }

            Assert.AreEqual(str, str1);
        }

        [TestMethod]
        public void MatrXVectMinus()
        {
            double[][] mas = new double[4][];
            for (int i = 0; i < 4; i++)
            {
                mas[i] = new double[3];
            }
            mas[0][0] = (-1);
            mas[0][1] = (-2);
            mas[0][2] = (-3);
            mas[1][0] = (-1);
            mas[1][1] = (-2);
            mas[1][2] = (-3);
            mas[2][0] = (-1);
            mas[2][1] = (-2);
            mas[2][2] = (-3);
            mas[3][0] = (-1);
            mas[3][1] = (-2);
            mas[3][2] = (-3);
            double[] vec = new double[4];
            vec[0] = (-4);
            vec[1] = (-4);
            vec[2] = (-4);
            vec[3] = (-4);
            double[] result = new double[4];
            result[0] = (24);
            result[1] = (24);
            result[2] = (24);
            result[3] = (24);

            double[] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();
            {
                res = mf.MatrXVec(mas, vec, 4, 3);
            }

            string str = "";
            for (int i = 0; i < 4; i++)
            {
                str += res[i].ToString() + "   ";
            }

            string str1 = "";
            for (int i = 0; i < 4; i++)
            {
                str1 += result[i].ToString() + "   ";
            }

            Assert.AreEqual(str, str1);
        }

        [TestMethod]
        public void MatrXVectDouble()
        {
            double[][] mas = new double[3][];
            for (int i = 0; i < 3; i++)
            {
                mas[i] = new double[3];
            }
            mas[0][0] = Convert.ToDouble(1.5);
            mas[0][1] = Convert.ToDouble(1.2);
            mas[0][2] = Convert.ToDouble(3.3);
            mas[1][0] = Convert.ToDouble(1.5);
            mas[1][1] = Convert.ToDouble(1.2);
            mas[1][2] = Convert.ToDouble(3.3);
            mas[2][0] = Convert.ToDouble(1.5);
            mas[2][1] = Convert.ToDouble(1.2);
            mas[2][2] = Convert.ToDouble(3.3);
            double[] vec = new double[3];
            vec[0] = Convert.ToDouble(4.1);
            vec[1] = Convert.ToDouble(5.7);
            vec[2] = Convert.ToDouble(5.7);
            double[] result = new double[3];
            result[0] = Convert.ToDouble(31.8);
            result[1] = Convert.ToDouble(31.8);
            result[2] = Convert.ToDouble(31.8);

            double[] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();
            {
                res = mf.MatrXVec(mas, vec, 3, 3);
            }

            string str = "";
            for (int i = 0; i < 3; i++)
            {
                str += String.Format("{0:0.00}",res[i]) + "   ";
            }

            string str1 = "";
            for (int i = 0; i < 3; i++)
            {
                str1 += String.Format("{0:0.00}",result[i]) + "   ";
            }

            Assert.AreEqual(str, str1);
        }


        [TestMethod]
        public void MatrXMatrDouble()
        {
            double[][] mas = new double[3][];
            for (int i = 0; i < 3; i++)
            {
                mas[i] = new double[3];
            }
            mas[0][0] = (1.5);
            mas[0][1] = (1.2);
            mas[0][2] = (3.3);
            mas[1][0] = (1.5);
            mas[1][1] = (1.2);
            mas[1][2] = (3.3);
            mas[2][0] = (1.5);
            mas[2][1] = (1.2);
            mas[2][2] = (3.3);


            double[][] mas1 = new double[3][];
            for (int i = 0; i < 3; i++)
            {
                mas1[i] = new double[3];
            }
            mas1[0][0] = (4.1);
            mas1[0][1] = (4.1);
            mas1[0][2] = (4.1);
            mas1[1][0] = (5.7);
            mas1[1][1] = (6.3);
            mas1[1][2] = (8.9);
            mas1[2][0] = (5.7);
            mas1[2][1] = (8.9);
            mas1[2][2] = (6.3);

            double[][] result = new double[3][];
            for (int i = 0; i < 3; i++)
            {
                result[i] = new double[3];
            }
            result[0][0] = (31.8);
            result[0][1] = (43.08);
            result[0][2] = (37.62);
            result[1][0] = (31.8);
            result[1][1] = (43.08);
            result[1][2] = (37.62);
            result[2][0] = (31.8);
            result[2][1] = (43.08);
            result[2][2] = (37.62);

            double[][] res;
            math_wrapper.MatrFuncs mf = new math_wrapper.MatrFuncs();

            res = mf.MatrXMatr(mas, mas1, 3, 3, 3, 3);


            string str = "";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    str += String.Format("{0:0.00}", Math.Round(res[i][j], 2)) + "   ";
                }
            }

            string str1 = "";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    str1 += String.Format("{0:0.00}", result[i][j]) + "   ";
                }
            }

            Assert.AreEqual(str, str1);
        }

    }
}
