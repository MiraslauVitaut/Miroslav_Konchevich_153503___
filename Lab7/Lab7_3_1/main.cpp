// Лабораторная 7, задача 3. Выполнена: Кончевич М.В.

#include <iostream>


char* inputNum()
{

    char* num = new char[16];
    num[0] = '0';

    int len = 0;

    num[len] = std::getchar();

    if (num[len] != '1' && num[len] != '0' && num[len] != '-' && num[len] != '+')
    {
        std::cout << "Неверно введены данные!";
        num[0] = 'r';
        return num;
    }

    if (num[len] == '-')
    {
        num[len] = '1';
        ++len;
    }
    else if (num[len] == '+')
    {
        num[len] = '0';
        ++len;
    }
    else
    {
        ++len;
        num[len] = num[0];
        num[0] = '0';
        ++len;
    }

    while (std::cin.peek() != '\n')
    {
        num[len] = std::getchar();
        if (num[len] != '1' && num[len] != '0')
        {
            std::cout << "Неверно введены данные!";
            num[0] = 'r';
            return num;
        }

        ++len;
    }

    int b;
    int g = 15;

    if (len != 16)
    {
        len -= 2;
        b = len + 1;

        for (int a = 0; a < len + 1; ++a)
        {
            num[g] = num[b];
            --b;
            --g;
        }

        for (; g > 0; --g)
        {
            num[g] = '0';
        }
    }

    std::cin.ignore(32324, '\n');

    num[16] = '\0';

    return num;
}

char* twoCompl(char* num)
{
    int len = 0;
    int k = 15;

    while (num[len + 1] != '\0') ++len;

    if (len > 15)
    {
        std::cout << " Неверно введены данные   ";
        num[0] = 'r';
        return num;
    }

    if (len != 15)
    {
        while (len > 0)
        {
            num[k] = num[len];
            --len;
            --k;
        }

        while (k > 0)
        {
            num[k] = '0';
            --k;
        }
    }

    if (num[0] == '1')
    {
        for (int i = 1; i < 16; ++i)
        {
            if (num[i] == '0')
            {
                num[i] = '1';
            }
            else
            {
                num[i] = '0';
            }
        }

        bool dop = false;
        bool mega = true;

        for (int i = 15; i > 0; --i)
        {
            if (num[i] == '0')
            {
                if (dop == true)
                {
                    num[i] = '1';
                    break;
                }
                else if (mega)
                {
                    num[i] = '1';
                    break;
                }
            }
            else if (mega)
            {
                num[i] = '0';
                dop = true;
                mega = false;
            }
            else if (dop)
            {
                num[i] = '0';
            }
        }
    }

    return num;
}

char* sum(char* num1, char* num2)
{
    bool v1;
    bool v2 = false;

    for (int i = 15; i > -1; --i)
    {
        v1 = false;

        if (v2)
        {
            if (num1[i] == '1' && num2[i] == '1')
            {
                v1 = true;
            }
            else if ((num1[i] == '1' && num2[i] == '0') || (num1[i] == '0' && num2[i] == '1'))
            {
                v1 = false;
            }
            else if (num1[i] == '0' && num2[i] == '0') {
                v1 = true;
                v2 = false;
            }
        }
        else
        {
            if (num1[i] == '1' && num2[i] == '1')
            {
                v1 = false;
                v2 = true;
            }
            else if ((num1[i] == '1' && num2[i] == '0') || (num1[i] == '0' && num2[i] == '1'))
            {
                v1 = true;
            }
            else if (num1[i] == '0' && num2[i] == '0')
            {
                v1 = false;
            }
        }

        if (v1)
        {
            num1[i] = '1';
        }
        else
        {
            num1[i] = '0';
        }
    }

    return num1;
}

char* est(char* num)
{
    if (num[0] == '0')
    {
        for (int i = 0; i < 15; ++i)
        {
            num[i] = num[i + 1];
        }

        num[15] = '\0';

        int len = 14;

        while (true)
        {
            for (int i = 0; i < len; ++i)
            {
                num[i] = num[i + 1];
            }

            num[len] = '\0';

            --len;

            if (num[0] == '1' || len == 0) break;
        }
    }
    else
    {
        num = sum(num, (char*)("1111111111111111"));
        num[0] = '-';

        int len = 15;

        for (int i = 1; i < len + 1; ++i)
        {
            if (num[i] == '0')
            {
                num[i] = '1';
            }
            else
            {
                num[i] = '0';
            }
        }

        while (true)
        {
            for (int i = 1; i < len; ++i)
            {
                num[i] = num[i + 1];
            }

            num[len] = '\0';

            --len;

            if (num[1] == '1' || len == 1)
                break;
        }
    }

    return num;
}

int main()
{


    char* num1;
    char* num2;
    char* sums;

   std::cout << "Введите первое число:" << std::endl;

    num1 = inputNum();

    num1 = twoCompl(num1);

    if (num1[0] != 'r')
    {
        std::cout << "Введите второе число: " << std::endl;

        num2 = inputNum();

        num2 = twoCompl(num2);

        if (num2[0] != 'r')
        {

            sums = sum(num1, num2);

            std::cout << "Результат суммы:" << sums;

            std::cout << std::endl;

            std::cout << "Сумма , это число: " << est(sums);
        }



    }


    return 0;
}






