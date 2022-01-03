#include <iostream>
#include <string>
#include <fstream>

// Лабораторная 8, задача 2. Выполнена: Кончевич М.В.

using namespace std;

struct Info
{
    string fio; ///фио
    int group; ///группа
    double ball; ///средний балл
    double dohod; ///доход
};

Info* AddStruct(Info* Obj, int amount); /// создание динамического массива
void setData(Info* Obj, int amount); /// добавление данных
void showData(Info* Obj, int amount); /// печать массива
void sortData(Info* Obj, int amount); /// сортировка массива
void saveData(Info* Obj, int amount); /// сохранение массива в файл
Info* loadData(Info* Obj, int& amount); /// чтение из файла

static string path = "MyData.txt"; /// имя файла

int main()
{


    Info* OurInfo;
    int amount = 0;
    int YesOrNot = 0; ///  продолжить или остановить ввод данных(переменная выбора)

    // хотя бы один введем

    OurInfo = AddStruct(OurInfo, amount);
    setData(OurInfo, amount);
    amount++;


    do
    {
        cout << "Задайте требуемое действие: 0-выход, 1-ввод, 2-сортировка, 3-печать, 4-сохранить в файл, 5-чтение из файла: ";
        cin >> YesOrNot;

        if (YesOrNot == 1) /// ввод
        {
            OurInfo = AddStruct(OurInfo, amount);
            setData(OurInfo, amount);
            amount++;
        }

        if (YesOrNot == 2) /// сортировка
        {
            sortData(OurInfo, amount);
            showData(OurInfo, amount);
        }

        if (YesOrNot == 3) /// печать
        {
            showData(OurInfo, amount);
        }

        if (YesOrNot == 4) /// сохранить в файл
        {
            saveData(OurInfo, amount);
        }

        if (YesOrNot == 5) /// чтение из файла
        {
            OurInfo = loadData(OurInfo, amount);
            showData(OurInfo, amount);
        }
    } while (YesOrNot != 0);

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
        delete[] Obj;

        Obj = tempObj;
    }
    return Obj;
}


void setData(Info* Obj, int amount)
{
    cout << "ФИО: ";
    cin >> Obj[amount].fio;
    cout << "Группа: ";
    cin >> Obj[amount].group;
    cout << "Средний балл: ";
    cin >> Obj[amount].ball;
    cout << "Доход: ";
    cin >> Obj[amount].dohod;
    cin.get();
    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(Info* Obj, int amount)
{
    cout << "    ФИО          Группа     Средний балл       Доход" << endl;
    cout << "================================================================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << Obj[i].fio << '\t' << Obj[i].group << '\t' << Obj[i].ball << '\t' << Obj[i].dohod << endl;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sortData(Info* Obj, int amount)
{
    Info tempObj;
    //сортировка по доходам по возрастанию
    // Сортировка массива пузырьком
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (Obj[j].dohod > Obj[j + 1].dohod) {
                // меняем элементы местами
                tempObj = Obj[j];
                Obj[j] = Obj[j + 1];
                Obj[j + 1] = tempObj;
            }
        }
    }
    double min_zarplata;
    cout << "Минимальная зарплата: ";
    cin >> min_zarplata;

    //сортировка по уменьшению среднего бала если доход выше 2х мин. зарплат
    bool fl = false;
    while (fl == false)
    {
        fl = true;
        for (int i = 0; i < amount - 1; i++)
        {
            if (Obj[i].dohod > min_zarplata * 2)
            {
                if (Obj[i].ball < Obj[i + 1].ball)
                {
                    tempObj = Obj[i + 1];
                    Obj[i + 1] = Obj[i];
                    Obj[i] = tempObj;
                    fl = false;
                }
            }
        }
    }
}

void saveData(Info* Obj, int amount) {
    ofstream fs;
    fs.open(path);
    fs << amount;
    fs << "\n";
    for (int i = 0; i < amount; i++) {
        fs << Obj[i].fio; fs << "\n";
        fs << Obj[i].group; fs << "\n";
        fs << Obj[i].ball; fs << "\n";
        fs << Obj[i].dohod; fs << "\n";
    }
    cout << "Файл успешно сохранен!" << endl << endl;
}

Info* loadData(Info* Obj, int& amount) {
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open()) {
        cout << "Файл не удалось открыть!" << endl;
        return Obj;
    }
    amount = 0;
    fs >> amount;

    Info* OurInfo = 0;
    for (int i = 0; i < amount; i++)
    {
        OurInfo = AddStruct(OurInfo, i);
        fs >> OurInfo[i].fio;
        fs >> OurInfo[i].group;
        fs >> OurInfo[i].ball;
        fs >> OurInfo[i].dohod;
    };

    delete[] Obj;
    Obj = OurInfo;

    cout << "Файл успешно прочитан!" << endl << endl;

    return Obj;
}

