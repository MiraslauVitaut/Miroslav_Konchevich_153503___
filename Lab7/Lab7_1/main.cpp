// Лабораторная 7, задача 1. Выполнена: Кончевич М.В.
#include <iostream>
#include <cmath>

void CheckForDouble(std::string str , bool * isDouble)
{
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '.' || (str[i] == 'e' && str[i + 1] == '-'))
        {
            *isDouble = true;
            break;
        }
    }
}

int Convert(std::string str , int * arr , bool isDouble , int length , bool isNegative)
{
    if(!isDouble)
    {
        long int b;
        std::string rezult;
        std::string rezultdop;
        long int ch = std::atoi(str.c_str()); /// переводим строку в число

        if(isNegative) /// если отрицательное число то меняем знак на +
        {
            ch*=-1;
        }

        for (int i = 0; i < length; i++)
        {
            arr[i] =ch % 10 ; /// разбиваем число на массив
            ch/=10;
        }


        ch = 0; ///переменной где хранилось число присваиваем 0

        for(int j = length - 1 ; j>=0; j--) ///переводим число в десятичную систему
        {
            ch += arr[j] * pow(14 , j);

        }

        std::cout << ch << std::endl; ///выводим на экран число в десятичной системе



        while(true) ///перевод числа в троичную систему счисления
        {
            if(ch == 1 || ch == 2)
            {
                rezult += std::to_string(ch);
                break;
            }
            else
            {
                b = ch;
                ch /= 3;
                rezult += std::to_string(b - (ch * 3));
            }
        }

        for(int i = rezult.length() - 1 ; i >= 0; i--) /// в доп строку записываем основную строку прочитанную с конца
        {
            rezultdop += rezult[i];
        }

        rezult = rezultdop; /// основной строке присваиваем значение доп строки

        if(isNegative) ///если число отрицательное
        {
            return -1*(atoi(rezult.c_str()));
        }
        else
        {
            return atoi(rezult.c_str());
        }

    }
    else
    {

    }

}


int main()
{
    bool isDouble = false;
    bool isNegative = false;

    std::string str;
    int length;

    std::cout << "Enter the number:" << std::endl;
    std::cin >> str;

    if(atoi(str.c_str()) < 0)
    {
        isNegative = true;
    }

    CheckForDouble(str, &isDouble);

    isDouble ? length = str.length() - 1 : length = str.length();

    int *arr = new int[length]; /// массив на который будем

    std::cout << "The number" << std::endl;
    std::cout << Convert(str , arr , isDouble , length , isNegative) << std::endl;
}

