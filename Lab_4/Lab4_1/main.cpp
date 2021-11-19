#include<iostream>

void  print (double Myarray[] , const int k) ///Функция вывода массива в консоль
{
    for(int i = 0 ; i < k; i++)
    {
    std::cout << Myarray[i] << "\t";
    }
}

int main()
{
    const int k = 6;
    int  inv = 0;

    double Myarray[k];

    for(int i = 0 ; i < sizeof(Myarray) / sizeof(double) ; i++ )
    {


        std::cout << "Enter element number " << i + 1 << " :" << std::endl; ///Ввод эл-ов массива
        while (true)
        {
            std::cin >> Myarray[i];
            if (std::cin.fail() || std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Incorrect data try again , please!" << std::endl;
            }
            else break;
        }


    }

    for(int j =0 ; j < sizeof(Myarray) / sizeof(double) ; j++)
    {
        if (Myarray[j] > Myarray[j + 1] && (j + 1) < sizeof(Myarray) / sizeof(double))
        {
            inv++;
        }

    }
    std::cout << std::endl;

    print(Myarray , k);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "The number of inversions in the array: " << inv << std::endl;
}

