
#include <iostream>



void print(char** A, int n, int m)///Функция вывода массива в консоль
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << " " << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void clear(char** A, int N) ///Функция освобождения памяти
{
    for (int i = 0; i < N; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}


int countsMines(char** B, int i, int j)///Функция подсчета мин
{
    int count = 0;

    i += 1;
    j += 1;

    if (B[i][j] == '*') count++;
    if (B[i][j - 1] == '*') count++;
    if (B[i][j + 1] == '*') count++;
    if (B[i - 1][j] == '*') count++;
    if (B[i + 1][j] == '*') count++;
    if (B[i - 1][j - 1] == '*') count++;
    if (B[i - 1][j + 1] == '*') count++;
    if (B[i + 1][j - 1] == '*') count++;
    if (B[i + 1][j + 1] == '*') count++;

    return count;
}

int main()
{
    int n(0), m(0);
    std::cout << " Введите кол-во строк на игровом поле" << std::endl;

    while (true) {
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n' || n < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }
    std::cout << " Введите кол-во столбцов на игровом поле" << std::endl;
    while (true) {
        std::cin >> m;
        if (std::cin.fail() || std::cin.peek() != '\n' || m < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }

    std::cout << std::endl;


    char** A = new char* [n];

    for (int i = 0; i < n; i++) {
        A[i] = new char[m];
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "Введите ячейку [" << i << "," << j << "]"; ///выводим подсказку
            while (true) {
                std::cin >> A[i][j];
                if (std::cin.fail() || std::cin.peek() != '\n') {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "incorrect data, tre again" << std::endl;
                }
                else break;
            }

        }
    }

    /// вывод заполненного массива
    std::cout << "" << std::endl;
    std::cout << "Игровое поле игры 'сапер'" << std::endl;
    print(A, n, m);
    std::cout << "" << std::endl;

    /// сформируем вспомогательный массив (+2 строки + 2 столбца), чтобы по нему искать соседей
    char** B;
    B = new char* [n + 2]; /// через массив указателей
    for (int i = 0; i < n + 2; i++) {
        B[i] = new char[m + 2];
    }

    /// заполним первоначально пустыми клетками '.'
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            B[i][j] = '.';
        }
    }

    /// само игровое поле возьмем из основного массива (бомбы + пустые клетки)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[i + 1][j + 1] = A[i][j];
        }
    }

    std::cout << "" << std::endl;
    std::cout << "Вспомогательное игровое поле игры 'сапер'" << std::endl;
    print(B, n + 2, m + 2);
    std::cout << "" << std::endl;


    int** C;
    C = new int* [n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[m];
    }

    /// теперь будем искать бомбы в соседних ячейках вспомогательного массива
    ///(без первой и последней строки и певого и последнего столбца)
    /// итого всегда у нас будет 8 соседних ячеек + сама ячейка
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = countsMines(B, i, j);
        }
    }

    std::cout << "" << std::endl;
    std::cout << "Количество мин на игровом поле в соседних ячейках игры 'сапер'" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << " " << C[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "" << std::endl;


    clear(A, n);
    clear(B, n);
    for (int i = 0; i < n; i++)
    {
        delete[] C[i];
    }
    delete[] C;
}