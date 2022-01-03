// Лабораторная 4, задача 15. Выполнена: Кончевич М.В.

#include <iostream>
#include <cmath>

int main()
{
    int n = 0;
    std::cout << " Enter the number: " << std::endl;
    std::cin >> n;

    std::cout << std::endl;

    int nn = ceil(sqrt(n)); /// номер углового квадрата
    std::cout << " Number of the square = " << nn << std::endl;

    int col; /// столбец
    int row; /// строка

    int begin = pow((nn-1), 2)+1; /// начальное число квадрата
    int end = pow(nn, 2); ///
    if (n<begin+nn-1) /// последний столбец
    {
        col = nn; ///конечное число квадрата

    }
    else
    {
        ///col = nn*nn-n+1;
        int i=0;
        for (i=end, col=1; i>end-nn; i--, col++)
        {
            if (i==n)
            {
                break;
            }
        }
    }

    if (n>end-nn+1)
    { /// последняя строка
        row = nn;
    }
    else
    {
        int i=0;
        for (i=begin, row=1; i<begin+nn; i++, row++)
        {
            if (i==n)
            {
                break;
            }
        }
    }

    std::cout << "The number " << n << " located in " << row << " row and in " << col << " col.";

    return 0;
}
