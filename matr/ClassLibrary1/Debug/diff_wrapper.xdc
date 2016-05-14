<?xml version="1.0"?><doc>
<members>
<member name="M:math_wrapper.DiffFuncs.Eiler(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="15">
<summary>
Решение системы дифференциальных уравнений методом Эйлера.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="a">Начальное значение интервала.</param>
<param name="b">Конечное значение интервала.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta2(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="40">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="a">Начальное значение интервала.</param>
<param name="b">Конечное значение интервала.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta4(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="65">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="a">Начальное значение интервала.</param>
<param name="b">Конечное значение интервала.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.Eiler_Paral(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="95">
<summary>
Решение системы дифференциальных уравнений методом Эйлера. Параллельная реализация.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="a">Начальное значение интервала.</param>
<param name="b">Конечное значение интервала.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta2_Paral(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="120">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка. Параллельная реализация.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="a">Начальное значение интервала.</param>
<param name="b">Конечное значение интервала.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta4_Paral(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="145">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка. Параллельная реализация.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="a">Начальное значение интервала.</param>
<param name="b">Конечное значение интервала.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.Eiler(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="180">
<summary>
Решение системы дифференциальных уравнений методом Эйлера.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="tau">Шаг по времени.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta2(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="204">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="tau">Шаг по времени.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta4(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="228">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="tau">Шаг по времени.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.Eiler_Paral(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="257">
<summary>
Решение системы дифференциальных уравнений методом Эйлера. Параллельная реализация.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="tau">Шаг по времени.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta2_Paral(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="281">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка. Параллельная реализация.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="tau">Шаг по времени.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
<member name="M:math_wrapper.DiffFuncs.RungeKutta4_Paral(math_wrapper.DiffFuncs.FDelegate[],System.Double,System.Int32,System.Double[],System.Int32)" decl="false" source="c:\users\12345\documents\visual studio 2012\projects\matr\classlibrary1\diff_wrapper.cpp" line="305">
<summary>
Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка. Параллельная реализация.
</summary>
<param name="fdelegate">Массив указателей на функции.</param>
<param name="tau">Шаг по времени.</param>
<param name="N">Количество шагов.</param>
<param name="arr_y">Массив с начальными значениями.</param>
<param name="count">Количество уравнений.</param>
<returns>Массив с найденными значениями.</returns>
</member>
</members>
</doc>