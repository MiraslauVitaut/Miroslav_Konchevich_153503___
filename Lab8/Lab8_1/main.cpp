#include<iostream>
using namespace std;

// Лабораторная 8, задача 1. Выполнена: Кончевич М.В.

struct Info
{
    string point;
    int value_place;
    int hours;
    int min;
};

Info* AddStruct(Info* Obj, int amount); /// динамическое создание массива структур
void setData(Info* Obj, int amount); /// заполнение элемента маиива
void showData(Info* Obj, int amount); /// печать массива
void findData(Info* Obj, int amount); /// поиск
void sortData(Info* Obj, int amount); /// сортировка массива вставкой по убыванию

int main()
{
    Info* OurInfo; /// первоначальная инициализация массива
    int amount = 0;
    int YesOrNot = 0; ///  продолжить или остановить ввод данных (переменная выбора действия)

    /// хотя бы один введем
    OurInfo = AddStruct(OurInfo, amount); /// выделяем память для 1 структуры
    setData(OurInfo, amount); ///заполняем эту первую структуру
    amount++;

    do
    {
        cout << "Задайте требуемое действие: 0-выход, 1-ввод, 2-сортировка, 3-печать, 4-поиск: ";
        cin >> YesOrNot;

        if (YesOrNot==1) /// ввод
        {
            OurInfo = AddStruct(OurInfo, amount);
            setData(OurInfo, amount);
            amount++;
        }

        if (YesOrNot==2) /// сортировка
        {
            sortData(OurInfo, amount);
            showData(OurInfo, amount);
        }

        if (YesOrNot==3) /// печать
        {
            showData(OurInfo, amount);
        }

        if (YesOrNot==4) /// поиск
        {
            sortData(OurInfo, amount);
            findData(OurInfo, amount);
        }
    }
    while (YesOrNot != 0);

    delete[] OurInfo;
    return 0;
}

Info* AddStruct(Info* Obj, int amount)
{
    if (amount == 0)
    {
        Obj = new Info[amount + 1]; /// выделение памяти для первой структуры
    }
    else
    {
        Info* tempObj = new Info[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; /// копируем во временный объект
        }
        delete [] Obj;

        Obj = tempObj;
    }
    return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(Info* Obj, int amount)
{
    cout << "Пункт назначения: ";
    cin >> Obj[amount].point;
    cout << "Время отправления ЧЧ ММ: ";
    cin>>Obj[amount].hours>>Obj[amount].min;
    cout << "Количество свободных мест: ";
    cin >> Obj[amount].value_place;
    cin.get();
    cout << endl;
}

void showData(Info* Obj, int amount)
{
    cout << "   Пункт назначения  Время отправления  Количество свободных мест" << endl;
    cout << "================================================================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << Obj[i].point << '\t' << Obj[i].hours << ":" << Obj[i].min << '\t' << Obj[i].value_place << endl;
    }
}

void sortData(Info* Obj, int amount)
{
    int i, j, key;
    Info tempObj;

    for (i=0; i<amount-1; i++)
    {
        key=i+1;
        tempObj=Obj[key];
        for (j=i+1; j>0; j--)
        {
            if (tempObj.value_place>Obj[j-1].value_place)
            {
                Obj[j]=Obj[j-1];
                key=j-1;
            }
        }
        Obj[key]=tempObj;
    }
}

void findData(Info* Obj, int amount)
{
    string point;
    cout << "Пункт назначения: ";
    cin >> point;
    cout << "  Пункт назначения  Время отправления  Количество свободных мест" << endl;
    cout << "================================================================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].point==point)
        {
            cout << Obj[i].point << '\t' << Obj[i].hours << ":" << Obj[i].min << '\t' << Obj[i].value_place << endl;
        }
    }
}