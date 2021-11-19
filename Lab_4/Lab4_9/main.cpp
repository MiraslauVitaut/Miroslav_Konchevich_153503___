#include <iostream>
#include<stdlib.h>


int main() {
   int N = 0 , m = 0 , k = 0;
   std::cout << "Введите размер матриц:" <<  std::endl;

    while (true) {
        std::cin >> N;
        if (std::cin.fail() || std::cin.peek() != '\n' || N < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, tre again" << std::endl;
        }
        else break;
    }


   int** arr1 = (int**) malloc (sizeof(int*) * N);

   for(int i =0 ; i < N ; i++)
   {
       arr1[i] = (int*)malloc(sizeof(int) * N);

   }

    std::cout << "Матрица 1:" << std::endl;
   for(int  i = 0; i < N ; i++)
   {
       for(int j = 0 ; j < N ; j++)
       {
           arr1[i][j] = rand() % 1000 + 1;
            std::cout << arr1[i][j] << "\t";
       }
       std::cout << std::endl;
   }

   std::cout << std::endl;

   int** arr2 = (int**) malloc(sizeof(int*) * N);

    for(int j = 0 ; j < N ; j++)
    {
        arr2[j] = (int*)malloc(sizeof(int) * N);

    }

    std::cout << "Матрица 2:" << std::endl;
    for(int  i = 0; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            arr2[i][j] = rand() % 1000 + 1;
            std::cout << arr2[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int **arr3 = (int**)malloc(sizeof(int*) * N);

    for(int i = 0  ; i < N ; i++)
    {
        arr3[i] = (int*) malloc(sizeof (int) * N);
    }


    for(int  i = 0 ; i < N ; i++)
    {
        for(int k = 0 ; k < N ; k++)
        {
            for (int j = 0; j < N; j++)
            {
            arr3[i][k] += arr1[i][j] * arr2[j][k];
            }
        }

    }

    std::cout << std::endl;
    std::cout << "Полученная матрица:" << std::endl;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {
            std::cout << arr3[i][j] << "\t";
        }
        std::cout << std::endl;

    }

    for(int i = 0 ; i < N ; i++)
    {
        free(arr1[i]);
        free(arr2[i]);
        free(arr3[i]);
    }

    free(arr1);
    free(arr2);
    free(arr3);

}
