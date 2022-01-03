#include <iostream>

// Лабораторная 7, задача 6. Выполнена: Кончевич М.В.

int main()
{
    int t,n,i = 0;

    std::cout << "Введите число наборв:" << std::endl;
    std::cin >> t;

    while (t > 0)
    {
        std::cout << "Введите число для набора " << i <<" :" << std::endl;
        std::cin >> n;
        std::cout << (n + 1) / 10 << '\n';
        t--;
        i++;
    }
}
