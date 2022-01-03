#include <iostream>

// Лабораторная 6, задача 3. Выполнена: Кончевич М.В.

void Search(char * arr , std::string str)
{
    int k = 0; /// переменная для занесения использующихся символов в массив
    bool isUnic = true; /// переменная для проверки уникальности символа
    bool itsnot = false; /// переменная для проверки элемента на букву

    for (int i = 0; str[i] != '\0' ; i++)
    {

        for (int j = 0; j < str.length(); j++)
        {
            if (str[i] == arr[j]) /// проверка уникальности элемента
            {
                isUnic = false;
                break;
            }
            else if(str[i] == ',' || str[i] == '.' || str[i] == ' ') /// проверка на букву
            {
                itsnot = true;
                break;
            }
        }

                if(isUnic && !itsnot) /// выполнение всех условий
                {
                    arr[k] = str[i];
                    k++;

                }

        itsnot = false; /// возвращаем исходное значение
        isUnic = true;





    }


}


int main()
{


    std::string str;
    std::cout << "Enter the string: " << std::endl;
    getline(std::cin, str);

    char * arr = new char [str.length()];

    Search(arr , str);
    std::cout << str << std::endl;

    std::cout << std::endl;

    std::cout << "Symbols , that are used in string are:" << std::endl;

    std::cout << arr << std::endl;

    delete [] arr;


}
