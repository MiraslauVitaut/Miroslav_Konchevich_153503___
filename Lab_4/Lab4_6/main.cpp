
#include <iostream>


/// Создание матрицы
int** create(int N, int M)
{
    int **A = new int *[N];

    for (int i = 0; i < N; i++) {
        A[i] = new int [M];
    }
    return A;
}

/// Заполнение рандомное
void initialize(int** A, int N, int M)
{
    srand(time(0));
    for(int i = 0; i < N; i++ )
    {
        for(int j = 0;  j < M;  j++ )
        {
            A[i][j] = rand() % 11 - 5 ;
        }
    }
}

void print(int** A, int N, int M)
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

/// Функция удаления
void clear(int** A, int N)
{
    for ( int i = 0; i < N; i++ )
    {
        delete [] A[i];
    }
    delete [] A; /// Освобождение памяти
}

/// является ли ячейка i,j локальным минимумом
int maxLeftUp(int** B, int i, int j)
{
    /// перейдем на индексы вспомогательного массива
    i +=1;
    j +=1;

    int max = B[i][j]; /// первоначальный МАКС

    if (B[i][j-1] > max) max = B[i][j-1]; /// левая ячейка
    if (B[i-1][j] > max) max = B[i-1][j]; /// верхняя ячейка
    if (B[i-1][j-1] > max) max = B[i-1][j-1]; /// диагональная ячейка лево-верхняя

    return max;
}

int main()
{
    int n(0), m(0);
    std::cout << " Введите кол-во строк в массиве" << std::endl;
    while (true) {
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n' || n < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, tre again" << std::endl;
        }
        else break;
    }

    std::cout << " Введите кол-во столбцов в массиве" << std::endl;
    while (true) {
        std::cin >> m;
        if (std::cin.fail() || std::cin.peek() != '\n' || m < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, tre again" << std::endl;
        }
        else break;
    }
    std::cout << std::endl;

    int **A;
    A = create(n,m); /// создание
    initialize(A, n, m); /// заполнение


    std::cout << "Исходный массив" << std::endl;
    print(A, n, m); /// печать
    std::cout <<  std::endl;

    /// сформируем вспомогательный массив (+2 строки + 2 столбца), чтобы по нему искать соседей
    int **B;
    B = create(n+2,m+2); /// создание

    /// заполним первоначально МИНом из первоначального массива
    int min = A[0][0];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (min>A[i][j])
                min = A[i][j];
        }
    }
    for(int i=0; i<n+2; i++) {
        for(int j=0; j<m+2; j++) {
            B[i][j] = min;
        }
    }

    /// сам массив возьмем из основного массива (кроме певой и последней строк, первого и последнео столбца)
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            B[i+1][j+1] = A[i][j];
        }
    }

    std::cout << "Вспомогательный массив" << std::endl;
    print(B, n+2, m+2);
    std::cout <<  std::endl;

    /// новый массив МАКСов левее/выше
    int **C;
    C = create(n,m); /// создание
    /// заполняем новый массив
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            C[i][j] = maxLeftUp(B, i, j);
        }
    }

    std::cout << "Новый массив лево-верхних МАКСов" << std::endl;
    print(C, n, m);


    clear(A, n); /// очистка
    clear(B, n+2); /// очистка
    clear(C, n); /// очистка

    return 0;
}
