// Лабораторная 5, дополнительная задача. Выполнена: Кончевич М.В.
#include <iostream>

int F(int n)
{

    if (n==0)
    {
        return 0;
    }
    if (n%10>0)
    {
        return n%10;
    }

    return F(n/10);
}

int S(int p, int q)
{
    int summ = 0;
    for (int i=p; i<=q; i++)
    {
        summ += F(i);
    }
    return summ;
}

int main()
{
    int p, q;

    while (p!=-1 && q!=-1)
    {
        std::cin >> p >> q;
        std::cout <<  std::endl;

        std::cout << S(p, q) <<  std::endl;
    }

    return 0;
}
