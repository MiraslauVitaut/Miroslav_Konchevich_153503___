#include <iostream>
#include <string>

// Лабораторная 6, задача 2. Выполнена: Кончевич М.В.

#define max 100 /// макимальный размер массива с запасом
using namespace std;

string strings[max];

/// длина строки
int len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

/// заполняем массив строк
void split (string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int main()
{
    string str;
    cout << "Введите строку: " << endl;
    getline(cin , str);
    char seperator = ' '; /// разделитель
    split(str, seperator); /// заполняем массив строк
    /// длина реального массива (так как изначально задали с запасом)
    int lenArr = 0;
    for (int i = 0; i < max; i++)
    {
        if (strings[i] != "")
        {
            lenArr++;
            cout << "\n i : " << i << " " << strings[i]; /// распечатаем для примера список отдельных слов
        }
    }
    cout << "\n*****************" << endl;

    /// пошли обрабатывать массив строк
    string stringsTmp[lenArr]; /// вспомогательный массив
    for (int i = 0; i < lenArr; i++)
    {
        int l = strings[i].length(); /// длина слова в массиве
        char last = strings[i][l-1]; /// последняя буква слова

        for (int j=0; j < lenArr; j++)
        {
            if (j==i) continue; /// само слово пропускаем
            char first = strings[j][0]; /// первая буква слова
            if (last == first)
            {
                cout << strings[i] << " " << strings[j];
            }
        }
    }

    return 0;
}
