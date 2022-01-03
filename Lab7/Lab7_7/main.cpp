#include <iostream>

// Лабораторная 7, задача 7. Выполнена: Кончевич М.В.

int main()
{

int n;
std::cout << "Введите число: " << std::endl;
std::cin >> n;

for(int i = 3 ; i<=n; i+=3)
{
    if(i == n)
    {
        std::cout << "3 is true" << std::endl;
        break;
    }
}

for(int i = 23; i<n; i+=23)
{
    if(i == n)
    {
        std::cout << "23 is true" << std::endl;
        break;
    }
}

for(int i = 107 ; i < n ; i+=107)
{
    if (i == n)
    {
        std::cout << "107 is true" << std::endl;
        break;
    }
}

}
