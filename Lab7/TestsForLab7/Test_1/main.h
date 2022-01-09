//
// Created by Miroslav Konchevich on 9.01.22.
//

#ifndef TEST_1_MAIN_H
#define TEST_1_MAIN_H

int Convert(std::string str  , bool isNegative)
{
    int *arr = new int[str.length()];

        long int b;
        std::string rezult;
        std::string rezultdop;
        long int ch = std::atoi(str.c_str()); /// переводим строку в число

        if(isNegative) /// если отрицательное число то меняем знак на +
        {
            ch*=-1;
        }

        for (int i = 0; i < str.length(); i++)
        {
            arr[i] =ch % 10 ; /// разбиваем число на массив
            ch/=10;
        }


        ch = 0; ///переменной где хранилось число присваиваем 0

        for(int j = str.length() - 1 ; j>=0; j--) ///переводим число в десятичную систему
        {
            ch += arr[j] * pow(14 , j);

        }



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

#endif //TEST_1_MAIN_H
