
#include<iostream>
#include<iomanip>


void print (int n , int**square ) ///Функция вывода массива в консоль
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            std::cout << square[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void clear(int n , int **square) ///Функция освобождения памяти
{
    for(int i = 0 ; i < n ;i++)
    {
       free(square[i]);
    }
    free(square);
}

int main()
{
    int n , newrow , newcol;

    std::cout << "Enter the size of the magic square! " << std::endl;

    while (true)
    {
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n' || n < 2)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Incorrect data , try again , please!" << std::endl;
        }
        else break;
    }


    int** square = (int**) malloc(sizeof(int**) * n);

    for (int i = 0; i < n; ++i)
    {
        square[i] = (int*)malloc(sizeof (int*) * n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            square[i][j] = 0;
        }
    }





    int i = 0;
    int j = n / 2;


    for (int value = 0; value <= n*n; value++)
    {
        square[i][j] = value;
        newrow = (i + 1) % n;
        newcol = (j + 1) % n;
        if (square[newrow][newcol] == 0)
        {
            i = newrow;
            j = newcol;
        }
        else
        {

            i = (i - 1 + n) % n;
        }

    }


    print(n , square);
    clear(n , square);



}
