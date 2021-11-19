#include <iostream>
#include<cmath>


int main() {
    srand( time(0) );
    int  N , d1 = 0 ,d2 = 0 ,d3 = 0 ,d4 = 0 , maxd , maxindx = 1;

    std::cout << "Введите размерность 3-х мерного массива!" << std::endl;
    while (true) {
        std::cin >> N;
        if (std::cin.fail() || std::cin.peek() != '\n' || N < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }


    int ***arr = new int **[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int *[N];

    }

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++)
        {
            arr[i][j] = new int[N];
        }

    }

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            for (int z = 0; z < N; z++)
            {
                arr[i][j][z] = rand() % 1000 + 1;
                std::cout << arr[i][j][z] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;


    }

    std::cout << std::endl;

    for(int i = 0; i < N ; i++)
    {

    d1 += arr[i][i][i];
    d2 += arr[i][i][N - i - 1];
    d3 += arr[N - i - 1][i][i];
    d4 += arr[N - i - 1][i][N - i - 1];

    }

    std::cout << d1 << "\t" << d2 << "\t" << d3 << "\t" << d4 << "\t" << std::endl;

    maxd = d1;

   if(maxd < d2)
   {
       maxd = d2;
       maxindx = 2;
   }

   if(maxd < d3)
   {
       maxd = d3;
       maxindx = 3;
   }

  if(maxd < d4)
  {
      maxd = d4;
      maxindx = 4;
  }



  std::cout << std::endl;
  std::cout << "Диагональ с наибольшей суммой чисел находится под номером " << maxindx << " и сумма чисел диагонали равна: "  << maxd << std::endl;

  for(int i = 0 ; i < N ; i++)
  {

      for(int j = 0 ; j < N; j++)
      {
          delete[] arr[i][j];
      }

      delete[] arr[i];

  }

  delete[] arr;

}
