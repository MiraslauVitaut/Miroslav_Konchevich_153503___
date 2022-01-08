// Лабораторная 5, задача 3. Выполнена: Кончевич М.В.
#include <iostream>



double** Create(int n); /// создание массива
void Initialize(double** A, int n); /// инициализация массива
void Print(double** A, int n); /// печать массива
void Clear(double** A, int n); /// удаление массива

void checkZero(double** A, int n); /// проверка на 0-значение
void reverse(double** A, double**B, int n); /// реверс массива

/// Создание
double** Create(int N)
{
    double** A;/// Создаем матрицу введенной размерности
    A = new double *[N]; /// через массив указателей
    for (int i = 0; i < N; i++) {
        A[i] = new double [N];
    }
    return A;
}

/// Заполнение
void Initialize(double** A, int N)
{
    for(int i = 0; i < N; i++ )
    {
        for(int j = 0;  j < N;  j++ )
        {
            std::cout << "Введите A[" << i << "," << j << "] = ";
            std::cin >> A[i][j];
        }
    }
}

/// печать массива
void Print(double** A, int N)
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << A[i][j] << "     ";
        }
        std:: cout << std::endl;
    }
}

/// Удаление массива
void Clear(double** A, int N)
{
    for ( int i = 0; i < N; i++ )
    {
        delete [] A[i];
    }
    delete [] A; /// Освобождение памяти
}

/// проверка на 0-значение
void checkZero(double** A, int N)
{
    bool isZero = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (A[i][j]==0.) {
                isZero = false;
                std::cout << "A[" << i << "," << j << "] = " << A[i][j] << std::endl;
            }
        }
    }
    if (!isZero) std::cout << "Нулевых элементов в массиве нет!" << std::endl;
    std::cout << "********************" << std::endl;
}

/// реверс массива
void reverse(double** A, double**B, int N)
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            B[j][i] = A[i][j];
        }
    }
}

int main()
{
    int n = 0;
    std::cout << " Введите размер матрицы N" << std::endl;
    
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

    std::cout << "Матрица A" << std::endl;
    double **A;
    A = Create(n); /// создание
    Initialize(A, n); /// заполнение
    Print(A, n); /// печать
    std::cout << "********************" << std:: endl;

    /// проверка на 0-значение
    checkZero(A, n);

    std::cout << "Матрица B (реверсная)" << std::endl;
    double **B;
    B = Create(n); /// создание
    reverse(A, B, n); /// заполнение
    Print(B, n); /// печать
    std::cout << "********************" << std::endl;

    Clear(A, n); /// очистка
    Clear(B, n); /// очистка

    return 0;
}
