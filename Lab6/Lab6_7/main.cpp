#include <iostream>
#include <string>

// Лабораторная 6, задача 7. Выполнена: Кончевич М.В.

bool CheckEqual(std::string str1) /// функция проверки наличия палиндрома в строке
{
    for (int i = 0; i < str1.length() ; i++)
    {
        if(str1[i] != str1[0] )
        {
            return false;
        }
    }
    return true;
}

bool CheckForPal(std::string str1) ///функция проверки строки на палиндром
{
    for (int i = 0; i < str1.length() / 2; i++)
    {
        if(str1[i] != str1[str1 . length() - i - 1]) /// проверяем элементы с начала и с конца
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string str1;
    std::cout << "Enter the string: " << std::endl;
    std::cin >> str1;

    if (CheckEqual(str1)) ///если палиндрома не существует
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    if(CheckForPal(str1)) ///если строка - палиндром
    {
        if(str1[0] < str1[1])
        {
            str1 = str1.substr(0 , str1.length() - 1);
            std::cout << str1.length() << std::endl;
        }

        else
        {
            str1 = str1.substr(1, str1.length());
            std::cout << str1.length() << std::endl;
        }
    }
    else
    {
        std::cout << str1.length() << std::endl;
    }

}
