#include <iostream>

// Лабораторная 6, задача 8. Выполнена: Кончевич М.В.

int t;
std::string str1,str2,S,s1,s2;

bool Check()
{
    for(int i=1; i <= str1.length() ;++i)
    {
        s1 = str1.substr(0,i);
        s2 = str1.substr(0,i-1);
        reverse(s2.begin(),s2.end());

        S = s1 + s2;

        if(S.find(str2)!=S.npos) ///если find не найдет строки str2 в S то
        {
            return true;
        }

    }
    return false;
}

int main()
{


    std::cout << "Введите кол-во наборов:" << std::endl;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        std::cin >> str1 >> str2;

        if (Check())
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }


    }
    return 0;
}
