#include <iostream>

// Лабораторная 7, задача 9. Выполнена: Кончевич М.В.

int main()
{

    int number = 0; ///(в троичной системе счисления)

    int numb;

    std::cout << "Введите число: " << std::endl;
    std::cin >> numb;

    if(numb<3)
    {
        std::cout << numb;
    }

    else
    {

        if (numb % 3 == 0)
        {
            numb--;
            int k = 1;

            while (numb / 3 != 0)
            {
                number += (numb % 3) * k;

                if (numb / 3 > 3)
                {
                    k *= 10;
                }
                else
                {
                    number += (numb / 3) * k * 10;
                }

                numb /= 3;
            }
            number++;
        }

        else
        {
            int k = 1;

            while (numb / 3 != 0)
            {
                number += (numb % 3) * k;
                if (numb / 3 > 3)
                {
                    k *= 10;
                }
                else
                {
                    number += (numb / 3) * k * 10;
                }
                numb /= 3;
            }
        }
        std::cout << number;
    }
}
