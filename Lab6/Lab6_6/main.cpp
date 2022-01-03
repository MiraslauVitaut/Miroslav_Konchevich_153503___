#include <iostream>

// Лабораторная 6, задача 6. Выполнена: Кончевич М.В.

long double Fact(int N) /// функция вычисления факториала
{
    if (N == 1)
    {
        return 1;
    }
    else
    {
        return N * Fact(N - 1);
    }
}

int main()
{
    std::string str;


    long long  p = 1, x = 0;

    std::cout  << "Enter the word:" << std::endl;
    getline(std::cin, str);

    sort(str.begin(), str.end()); ///сортировка по алфавиту

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == str[i+1])
        {
            x++; ///считаем число повторений
        }
        else
        {
            x++;
            p *= Fact(x);
            x = 0;
        }
    }
    std::cout << Fact(str.size()) / p << std::endl;
    return 0;
}

