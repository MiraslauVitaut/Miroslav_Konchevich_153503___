//
// Created by Miroslav Konchevich on 27.12.21.
//

#include "MyLib.h"
#include <iostream>

int** Create(int N, int M)
{
    int** A;/// Создаем матрицу введенной размерности
    A = new int *[N]; /// через массив указателей
    for (int i = 0; i < M; i++)
    {
        A[i] = new int [N];
    }
    return A;
}

/// Заполнение массива
void Initialize(int** A, int N, int M)
{
    for(int i = 0; i < N; i++ )
    {
        for(int j = 0;  j < M;  j++ )
        {
            std::cout << "[" << i << "," << j << "] = ";
            std::cin >> A[i][j];
        }
    }
}

/// Заполнение A
void InitializeA(int** A, int** B, int** C, int N, int M)
{
    for(int i = 0; i < N; i++ )
    {
        for(int j = 0;  j < M;  j++ )
        {
            A[i][j] = abs(B[i][j])>abs(C[i][j]) ? B[i][j] : C[i][j];
        }
    }
}

/// печать массива
void Print(int** A, int N, int M)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cout << A[i][j] << "     ";
        }
        std::cout << std::endl;
    }
}

/// Удаление массива
void Clear(int** A, int N)
{
    for ( int i = 0; i < N; i++ )
    {
        delete [] A[i];
    }
    delete [] A; /// Освобождение памяти
}