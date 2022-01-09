
#include <iostream>
#ifndef TEST_2_MAIN_H
#define TEST_2_MAIN_H

int Change(std::string number)
{
    bool isNegative = false;
    long int b;

    std::string number2;


        long int a = atol(number.c_str());

        if(a < 0)
        {
            isNegative = true;
        }

        if(isNegative)
        {
            a *= -1;
        }

        number = "";
        b = a;

        while(a != 1)
        {
            a/=2;
            number += std::to_string(b - (a * 2));
            b = a;
        }

        number += '1';

        for(int i = number.length() - 1 ; i >= 0 ; i--)
        {
            number2 += number[i];
        }

        number = number2;

        if(isNegative)
        {

            long int x;

            x = atol(number.c_str());

            x *= -1;

            number = std::to_string(x);
        }

        return atoi(number.c_str());






}

char * ConvertToDop(std::string number, bool isNegative)
{


    int bit = 8;
    std::string number2;

    if(isNegative)
    {
        long  int x;

        x = atol(number.c_str());

        x *= -1;

        number = std::to_string(x);
    }



        while(true)
        {
            if (number.length() >= bit)
            {
                bit*=2;
            }
            else
            {
                break;
            }
        }



        isNegative ? number2 += '1' : number2 += '0';


        for (int i = 0; i < bit - number.length() - 1; i++)
        {
            number2 += '0';
        }

        number = number2 + number;




    if(!isNegative)
    {
        char * arr = new char [number.length()];
        for (int i = 0; i < number.length(); i++)
        {
            arr[i] = number[i];
        }

        return arr;
    }

    else
    {
        for(int i = 1 ; i < number.length(); i++)
        {
            if (number[i] == '0')
            {
                number[i] = '1';
            }
            else
            {
                number[i] = '0';
            }
        }

        for (int i = number.length() - 1; i >=0 ; i--)
        {
            if(number[i] == '1')
            {
                number[i] = '0';
            }
            else
            {
                number[i] = '1';
                break;
            }
        }

        char * arr = new char [number.length()];
        for (int i = 0; i < number.length(); i++)
        {
            arr[i] = number[i];
        }

        return arr;

    }

}

char * ConvertFromDopToPr(std::string number  , bool  isNegative)
{
    if(isNegative)
    {
        for (int i = number.length() - 1; i >= 0; i--)
        {
            if (number[i] != '1')
            {
                number[i] = '1';
            }
            else
            {
                number[i] = '0';
                break;
            }

        }

        for(int i = 1; i < number.length(); i++)
        {
            if (number[i] == '0')
            {
                number[i] = '1';
            }
            else
            {
                number[i] = '0';
            }
        }

        char * arr = new char [number.length()];
        for (int i = 0; i < number.length(); i++)
        {
            arr[i] = number[i];
        }

        return arr;

    }
    else
    {
        char * arr = new char [number.length()];
        for (int i = 0; i < number.length(); i++)
        {
            arr[i] = number[i];
        }

        return arr;
    }
}


#endif //TEST_2_MAIN_H
