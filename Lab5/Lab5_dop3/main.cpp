#include <iostream>
// Лабораторная 5, дополнительная задача. Выполнена: Кончевич М.В.

/// Наибольший нечетный делитель натурального числа n найдем, если разделим это число на 2 до тех пор, пока не получим нечетное число.
int NND(int n)
{
    if (n%2==1)
    {
        return n;
    }
    return NND(n/2);
}

int main()
{
    int n;

    std::cout << "Задайте число N = ";
    std::cin >> n;
    std::cout << std::endl;

    int summ = 0, nnd;
    for (int i=1; i<=n; i++)
    {
        nnd = NND(i);
        summ += nnd;
        std::cout << "Число = " << i << "; ННД = " << nnd << std::endl;
    }
    std::cout << "********************" << std::endl;
    std::cout << "Сумма ННД = " << summ << std::endl;

    return 0;
}

