// Лабораторная 5, задача 2. Выполнена: Кончевич М.В.
#include <iostream>


int* Create(int N); /// создание массива
void Initialize(int* A, int N); /// инициализация массива X и Y
void Print(int* A, int N); /// печать массива
void Clear(int* A); /// удаление массива

/// Создание
int* Create(int N)
{
    int* A;/// Создаем матрицу введенной размерности
    A = new int[N]; /// через массив указателей
    return A;
}

/// Заполнение
void Initialize(int* A, int N)
{
    for(int i = 0; i < N; i++ )
    {
        std::cout << "Введите A[" << i << "] = ";
        std::cin >> A[i];
    }
}

/// печать массива
void Print(int* A, int N)
{
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << "     ";
    }
    std::cout << std::endl;
}

/// Удаление массива
void Clear(int* A)
{
    delete [] A; /// Освобождение памяти
}

/// Анализ массива
bool check_array(int* A, int first, int last)
{
    if(first == last)
    {
        return A[first]<=first*first;
    }
    int mid = first + (last - first)/2;
    return check_array(A, first, mid) || check_array(A, mid + 1, last);
}

int main()
{
    int n = 0;
    std::cout << " Введите размер массива N " << std::endl;
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

    std::cout << "Массив A" << std:: endl;
    int *A;
    A = Create(n); /// создание
    Initialize(A, n); /// заполнение
    Print(A, n); /// печать
    std::cout << "********************" << std::endl;

    std::cout << "Проверка массива A: условие A[i] ≤ i^2 - " << (check_array(A, 0, n-1)==true? "выполняется" : "не выполняется") << std::endl;

    Clear(A); /// очистка

    return 0;
}
