#include <iostream>
#include <string>
#include <math.h>

// Лабораторная 6, задача 5. Выполнена: Кончевич М.В.

void InputData(std::string * str1 , std::string * str2 , int * L , int * m) /// функция ввода данных
{

std::cout << "Enter the first string (it can be a prefiks): " << std::endl;
std::cin >> *str1;
std::cout << "Enter the second string (it can be a sufiks): " << std::endl;
std::cin >> *str2;

std::cout << "Enter the length of the string:" << std::endl; /// длинна искомой строки
std::cin >> *L;

std::cout << "Enter m:" << std::endl; /// число , на которое делим в конце
std::cin >> *m;


}

int Search (int L , int  count , std::string str1 , std::string str2) /// функция поиска всевозможных комбинаций с данным префиксом и суффиксом
{
    int amount = L - (str1.length() + str2.length());

    if(amount <= 0)
    {
        return count; /// возвращаем 0 если комбинаций нет (либо в слове только префикс и суффикс , либо длинна слова меньше чем преффикс и суффикс)
    }
    else
    {
        count = pow(26 , amount); /// (26 - кол-во буков в латинском алфавите)
    }

    return  count;
}


int main()
{

int  L ,  m , count = 0;
std::string  str1;
std::string  str2;

InputData(&str1 , &str2 , &L , &m);
int rez = (Search(L , count , str1 , str2) % m) * 2;

std::cout << "Rezult is: " << rez <<  std::endl;



}
