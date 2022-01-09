
#ifndef TEST_1_MAIN_H
#define TEST_1_MAIN_H

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

int * Search(std::string str)
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




    int * arr = new int [3];

    arr[0] = max;
    arr[1] = letters;
    arr[2] = pos;

    return arr;

}

#endif //TEST_1_MAIN_H
