#include <iostream>

int main() {


    int N;

    std::cout << "Enter the order of the matrix:" << std::endl;


    while (true)
    {
        std::cin >> N;
        if (std::cin.fail() || std::cin.peek() != '\n' || N<=1)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Incorrect data try again , please!" << std::endl;
        }
        else break;
    }

    double **a = new double *[N];

    for (int i = 0; i < N; i++) {
        a[i] = new double[N];

    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {

            std::cout << "Enter element of the row number" << j + 1 << " and of the column number " << i + 1 << " :" << std::endl;
            while (true)
            {
                std::cin >> a[j][i];
                if (std::cin.fail() || std::cin.peek() != '\n')
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Incorrect data try again , please!" << std::endl;
                }
                else break;
            }


        }
    }

    std::cout << std::endl;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            std::cout << a[j][i] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Matrix 2:" << std::endl;

    int **b = new int *[N];

    for (int i = 0; i < N; i++) {
        b[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] > a[i][i]) {
                b[i][j] = 1;
            } else {
                b[i][j] = 0;
            }


        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            std::cout << b[j][i] << "\t";
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < N; i++) {
        delete[] a[i];
        delete[] b[i];

    }

    delete[] a;
    delete[] b;
}

