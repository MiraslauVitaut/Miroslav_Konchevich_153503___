#include <iostream>

// Лабораторная 7, задача 8. Выполнена: Кончевич М.В.

int main()
{
std::string s;
int n;

std::cout << "Введите число: " << std::endl;
std::cin >> n ;

if(n>10)
{
n+=2;
}

while(n > 0)
{
    s = char((n % 2) + 48) + s;
    n/=2;
}

std::cout << s << std::endl;

}
