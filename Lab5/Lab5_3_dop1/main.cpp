// Лабораторная 5, задача 3. Выполнена: Кончевич М.В.
#include <iostream>

int** Create(int n, int m); /// создание массива
void Initialize(int** A, int n, int m); /// инициализация массива
void Print(int** A, int n, int m); /// печать массива
void Clear(int** A, int n); /// удаление массива

int lengthDiagonal(int** A, int n, int m); /// размер диагонального массива
void InitializeB(int** A, int* B, int N, int M); /// создание массива диагонального четного

/// Создание
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

/// Заполнение
void Initialize(int** A, int N, int M)
{
    for(int i = 0; i < N; i++ )
    {
        for(int j = 0;  j < M;  j++ )
        {
            std::cout << "Введите элемент [" << i << "," << j << "] = ";
            std::cin >> A[i][j];
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
        std:: cout << std::endl;
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

/// размер диагонального массива
int lengthDiagonal(int** A, int N, int M)
{
    int size = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (i==j && A[i][j]%2==0)
                size++;
        }
    }
    return size;
}

/// Заполнение B
void InitializeB(int** A, int* B, int N, int M)
{
    int k = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (i==j && A[i][j]%2==0)
            {
                B[k] = A[i][j];
                k++;
            }
        }
    }
}

int main()
{
    int n(0), m(0);
    std::cout << " Введите размер матриц NxM " << std::endl;
    std::cin >> n >> m;
    std::cout << std::endl;

    std:: cout << "Матрица A" << std::endl;
    int **A;
    A = Create(n, m); /// создание
    Initialize(A, n, m); /// заполнение
    Print(A, n, m); /// печать
    std::cout << "********************" << std::endl;

    int size = lengthDiagonal(A, n, m);
    if (size==0)
    {
        std::cout << "На диагонали матрицы нет четных элементов";
    }
    else
    {
        std::cout << "Матрица B" << std::endl;
        int* B = new int[size]; /// создание
        InitializeB(A, B, n, m); /// заполнение
        for(int i = 0; i < size; i++)
        {
            std::cout << B[i] << "     ";
        }
        std::cout << std::endl << "********************" << std::endl;
        delete [] B; /// очистка
    }

    Clear(A, n); /// очистка

    return 0;
}
