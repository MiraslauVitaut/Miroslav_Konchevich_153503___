// Лабораторная 5, дополнительная задача. Выполнена: Кончевич М.В.
#include <iostream>
#include <cmath>

int F(int n, int r, int k)
{
    if (n==0 && r==0)
    {
        return 1;
    }
    if (n>0 && r>=0 && r<n*(k-1)+1)
    {
        int f = 0;
        for (int i=0; i<=k-1; i++)
        {
            f += F(n-1, r-i, k);
        }
        return f;
    };
    return 0;
}

int X(int k, int n, int t)
{
    int m = pow(10, t);
    int summ = 0;
    for (int i=0; i<=n*(k-1); i++)
    {
        std::cout << "i = " << i << std::endl;
        summ += F(n, i, k);
    }
    return summ%m;

}

int main()
{
    int k, n, t=-1;

    while (k!=0 && n!=0 && t!=0)
    {
        std::cin >> k >> n >> t;
        std:: cout << std::endl;

        std:: cout << X(k, n, t) << std::endl;
    }

    return 0;
}
