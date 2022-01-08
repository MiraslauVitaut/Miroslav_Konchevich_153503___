// Лабораторная 5, задача 3. Выполнена: Кончевич М.В.
#include <iostream>

int** Create(int n, int m); /// создание массива
void Initialize(int** A, int n, int m); /// инициализация массива
void Print(int** A, int n, int m); /// печать массива
void Clear(int** A, int n); /// удаление массива

int lengthNewArray(int** A, int n, int m); /// размер нового массива
void initializeB(int** A, int* B, int N, int M); /// создание нового массива
double avgArray(int** A, int n, int m); /// среднее арифметическое массива

/// Создание
int** Create(int N, int M)
{
    int** A;/// Создаем матрицу введенной размерности
    A = new int *[N]; /// через массив указателей
    for (int i = 0; i < M; i++) {
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
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << A[i][j] << "     ";
        }
        std::cout << std:: endl;
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
int lengthNewArray(int** A, int N, int M)
{
    int size = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if ((j+1)%2==0 && A[i][j]%2==1)
                size++;
        }
    }
    return size;
}

/// Заполнение B
void initializeB(int** A, int* B, int N, int M)
{
    int k = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if ((j+1)%2==0 && A[i][j]%2==1) {
                B[k] = A[i][j];
                k++;
            }
        }
    }
}

/// среднее арифметическое массива
double avgArray(int** A, int N, int M)
{
    double summ = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            summ += A[i][j];
        }
    }
    return summ / (N+M);
}

int main()
{
    int n = 0, m = 0;
    std::cout << " Введите размер матриц NxM " << std::endl;

    while (true)
    {

    std::cin >> n >> m;

    if (std::cin.fail() || std::cin.peek() != '\n' || n <= 1 || m<=1)
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Ah Shit, Here We Go Again." << std::endl;
    }
    else break;
  }

    std::cout << std::endl;

    std::cout << "Матрица A" << std:: endl;
    int **A;
    A = Create(n, m); /// создание
    Initialize(A, n, m); /// заполнение
    Print(A, n, m); /// печать
    std::cout << "********************" << std::endl;

    std::cout << "Среднее арифметическое массива AVG = " << avgArray(A, n, m) << std::endl;
    std::cout << "********************" << std::endl;

    int size = lengthNewArray(A, n, m);
    if (size==0)
    {
        std::cout << "В четных столбцах нет нечетных значений";
    }
    else
    {
        std::cout << "Матрица B" << std::endl;
        int* B = new int[size]; /// создание
        initializeB(A, B, n, m); /// заполнение
        for(int i = 0; i < size; i++)
        {
            std::cout << B[i] << "     ";
        }
        std:: cout << std::endl << "********************" << std::endl;
        delete [] B; /// очистка
    }

    Clear(A, n); /// очистка

    return 0;
}
