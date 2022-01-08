// Лабораторная 5, задача 1. Выполнена: Кончевич М.В.
#include <iostream>
#include "MyLib.h"


int main()
{
    int n = 0;
    std::cout << " Введите размер матриц N :" << std::endl;

    ///Check
    while (true)
    {

    std::cin >> n;

    if (std::cin.fail() || std::cin.peek() != '\n' || n <= 1)
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Ah Shit, Here We Go Again." << std::endl;
    }
    else break;
  }


    std::cout << std::endl;

    std::cout << "Матрица B:" << std::endl;
    int **B;
    B = Create(n, n); /// создание
    Initialize(B, n, n); /// заполнение
    Print(B, n, n); /// печать

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Матрица C:" << std::endl;
    int **C;
    C = Create(n, n); /// создание
    Initialize(C, n, n); /// заполнение
    Print(C, n, n); /// печать

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Матрица A:" << std::endl;
    int **A;
    A = Create(n, n); /// создание
    InitializeA(A, B, C, n, n); /// заполнение
    Print(A, n, n); /// печать

    std::cout << std::endl;
    std::cout << std::endl;

    Clear(A, n); /// очистка
    Clear(B, n); /// очистка
    Clear(C, n); /// очистка

    return 0;
}
