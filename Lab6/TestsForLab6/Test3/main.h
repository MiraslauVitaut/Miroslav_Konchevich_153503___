

#ifndef TEST3_MAIN_H
#define TEST3_MAIN_H

char * Check()
{

    std::string str;
    std::cout << "Enter the string for getline for checking:" << std::endl;
    getline(std::cin , str);

    if(str.length() <= 80)
    {

        char * str2 = new char [str.length()];

        for (int i = 0; i < str.length(); i++)
        {
            str2[i] = str[i];
        }

        return str2;
    }
    else
    {
        Check();
    }

}

char * Search(std::string str)
{
    char * arr = new char [str.length()];

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

    return arr;

}

#endif //TEST3_MAIN_H
