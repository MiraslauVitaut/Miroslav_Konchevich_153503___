#include <iostream>

int main()
{

    int str, columns;

    std::cout << "Enter a number of rows of the matrix:" << std::endl;
    while (true) {
        std::cin >> str;
        if (std::cin.fail() || std::cin.peek() != '\n' || str < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }
    std::cout << "Enter a number of columns of the matrix:" << std::endl;
    while (true) {
        std::cin >> columns;
        if (std::cin.fail() || std::cin.peek() != '\n' || columns < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }


    double** a = new double* [str];

    for (int i = 0; i < str; i++)
    {
        a[i] = new double[columns];

    }

    for (int j = 0; j < str; j++)
    {
        for (int i = 0; i < columns; i++)
        {

            std::cout << "Enter the element of row number  " << j + 1 << " and of column number  " << i + 1 << " :" << std::endl;
            while (true) {
                std::cin >> a[j][i];
                if (std::cin.fail() || std::cin.peek() != '\n') {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "incorrect data, try again" << std::endl;
                }
                else break;
            }


        }
    }

    std::cout << std::endl;

    for (int j = 0; j < str; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            std::cout << a[j][i] << "\t";


        }
        std::cout << std::endl;
    }

    double** b = new double* [str];

    for (int i = 0; i < str; i++)
    {
        b[i] = new double[columns];

    }


    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            if ((i + 1) < str && j + 1 < columns && (i - 1) < 0 && (j - 1) < 0)
            {
                /// i+1 j+1
                b[i][j] = double((a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1])) / 3.;


            }
            else if ((i + 1) < str && (j - 1) >= 0 && (i - 1) < 0 && (j + 1) >= columns)
            {
                /// i + 1 j - 1
                b[i][j] = double((a[i + 1][j] + a[i][j - 1] + a[i + 1][j - 1])) / 3.;

            }
            else if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) >= str && (j + 1) >= columns)
            {
                /// i - 1 j - 1
                b[i][j] = double((a[i - 1][j] + a[i][j - 1] + a[i - 1][j - 1])) / 3.;

            }
            else if ((i - 1) >= 0 && (j + 1) < columns && (i + 1) >= str && (j - 1) < 0)
            {
                /// i - 1 j + 1
                b[i][j] = double((a[i - 1][j] + a[i][j + 1] + a[i - 1][j + 1])) / 3.;

            }
            else if ((i - 1) >= 0 && (i + 1) < str && (j + 1) < columns && (j - 1) < 0)
            {
                ///i - 1 i + 1 j + 1
                b[i][j] = double((a[i - 1][j] + a[i][j + 1] + a[i + 1][j] + a[i - 1][j + 1] + a[i + 1][j + 1])) / 5.;
            }
            else if ((i - 1) >= 0 && (j - 1) >= 0 && (j + 1) < columns && (i + 1) >= str)
            {
                /// i - 1  j - 1  j + 1
                b[i][j] = double((a[i - 1][j] + a[i][j + 1] + a[i][j - 1] + a[i - 1][j - 1] + a[i - 1][j + 1])) / 5.;
            }
            else if ((i - 1) >= 0 && (i + 1) < str && (j - 1) >= 0 && (j + 1) >= columns)
            {
                /// i - 1  i + 1  j - 1
                b[i][j] = double((a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i - 1][j - 1] + a[i + 1][j + 1])) / 5.;
            }
            else if ((i + 1) < str && (j - 1) >= 0 && (j + 1) < columns && (i - 1) < 0)
            {
                /// i + 1  j - 1  j + 1
                b[i][j] = double((a[i + 1][j] + a[i][j + 1] + a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j + 1])) / 5.;
            }
            else if ((i + 1) < str && (j - 1) >= 0 && (j + 1) < columns && (i - 1) >= 0)
            {
                b[i][j] = double((a[i - 1][j] + a[i][j + 1] + a[i][j - 1] + a[i + 1][j] + a[i - 1][j + 1] + a[i - 1][j - 1] + a[i + 1][j - 1] + a[i + 1][j + 1])) / 8.;

            }
        }

    }
    std::cout << std::endl;


    for (int j = 0; j < str; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            std::cout << b[j][i] << "\t";


        }
        std::cout << std::endl;
    }


    for (int i = 0; i < str; i++)
    {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

}
