
// Лабораторная 7, задача 2. Выполнена: Кончевич М.В.
#include <iostream>

void CheckDouble(std::string number , bool * isDouble)
{
    for (int i = 0; i < number.length(); i++)
    {
        if(number[i] == '.')
        {
           *isDouble = true;
        }
    }
}


std::string Change(std::string number , bool isDouble , bool * isNegative)
{

   long int b;

    std::string number2;

    if(!isDouble)
    {
       long int a = atol(number.c_str());

        if(a < 0)
        {
            *isNegative = true;
        }

        if(*isNegative)
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

        if(*isNegative)
        {

           long int x;

            x = atol(number.c_str());

            x *= -1;

            number = std::to_string(x);
        }

        return number;

    }

    else
    {

    }



}



std::string ConvertToDop(std::string number , bool isDouble , bool  isNegative)
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


if(!isDouble)
{
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


}

if(!isNegative)
{
    return number;
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

    return number;

}

}

std::string ConvertFromDopToPr(std::string number , bool isDouble , bool  isNegative)
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

        return number;
    }
    else
    {
        return number;
    }
}




int main()
{
    int z = 8;
    bool isDouble = false;
    bool isNegative = false;

 std::string number;
 std::cout << "Enter the number" << std::endl;


    while (true)
    {
        std::cin >> number;
        if (std::cin.fail() || std::cin.peek() != '\n' || number == "0")
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "It's null. Sorry , but you are not clever. " << std::endl;
        }
        else break;
    }

    std::cout << "Your number:" << std::endl;
    std::cout << number << std::endl;
 CheckDouble(number,&isDouble);
 std::cout << "The number in 2 system :" << std::endl;
 number = Change(number , isDouble , &isNegative);
 std::cout  << number << std::endl;
 std::cout << "It is a dop code" << std::endl;
   number = ConvertToDop(number , isDouble , isNegative );
    std::cout  << number << std::endl;
    std::cout << "It is a straight code" << std::endl;
    number = ConvertFromDopToPr(number , isDouble , isNegative);
    std::cout  << number << std::endl;





}
