#include <iostream>
#include <string>

// Лабораторная 6, задача 1. Выполнена: Кончевич М.В.

void Search(std::string str)
{

    int max = 0; /// номер максимального по длинне слова
    int letters = 0;  /// кол-во буков(макс слова)
    int j = 0; /// счетчик каждого слова для нахождения кол-ва буков
    int countspaces = 0; /// число пробелов
    int indx = 0; /// номер каждого слова

    int pos = 0; /// позиция слова в строке

    for (int i = 0; i < str.length(); i++)
    {


        if(str[i] == ' ')  /// проверка значения элемента на пробел
        {

            countspaces++; /// кол-во пробелов++
            indx++; /// номер слова++


            if(letters  <= j) /// нахождение максимального по длинне слова
            {
                max = indx; /// присваиваем его номер в строке
                letters = j; /// присваиваем значение счетчика буков в переменную

                if (countspaces > 1) ///высчитываем позицию слова в строке
                {
                    pos = (i - letters) + 1;
                }
                else
                {
                    pos = i - letters;
                }

            }


            j = 0; ///обнуляем кол-во буков слова для перехода к следующему

        }
        else
        {
            j++; ///считываем кол-во буков каждого слова
        }



    }





    std::cout << "The max string with number: " << max << std::endl;
    std::cout << "Include " << letters << " letters" << std::endl;
    std::cout << "The number of position in string is : " << pos << std::endl;

}



int main()
{



    std::string str;
    std::cout << "Enter the string: " << std::endl;


    while (true)
    {

        getline(std::cin , str);

        if (str.length() > 80)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Incorrect data!" << std::endl;
        }
        else break;
    }



    str += ' ';



    std::cout << str << std::endl;

    std::cout << std::endl;

    Search(str);






}

