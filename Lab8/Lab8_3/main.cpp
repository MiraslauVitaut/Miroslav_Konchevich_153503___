#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Лабораторная 8, задача 3. Выполнена: Кончевич М.В.

/*
Задача 1.3
*/

class Student
{
    string fio;
    int group;
    double ball;
    double dohod;
public:
    void fillData();
    void showData();
    string getFio();
    int getGroup();
    double getBall();
    double getDohod();
    void setFio(string fio);
    void setGroup(int group);
    void setBall(double ball);
    void setDohod(double dohod);
};

void Student::fillData() // заполнение класса
{
    cout << "ФИО: ";
    cin >> fio;
    cout << "Группа: ";
    cin >> group;
    cout << "Средний балл: ";
    cin >> ball;
    cout << "Доход: ";
    cin >> dohod;
    cin.get();
    cout << endl;
}
void Student::showData() // печать класса
{
    cout << fio << '\t' << group << '\t' << ball << '\t' << dohod << endl;
}

string Student::getFio() { return fio; }  // возвращает ФИО
int Student::getGroup() { return group; }  // возвращает номер группы
double Student::getBall() { return ball; }  // возвращает балл
double Student::getDohod() { return dohod; }  // возвращает доход
void Student::setFio(string f) { fio=f; };
void Student::setGroup(int g) { group=g; };
void Student::setBall(double b) { ball=b; };
void Student::setDohod(double d) { dohod=d; };

Student* Add(Student* Obj, int amount); // создание динамического массива
void setData(Student* Obj, int amount); // добавление данных
void showData(Student* Obj, int amount); // печать массива
void sortData(Student* Obj, int amount); // сортировка массива
void saveData(Student* Obj, int amount); // сохранение массива в файл
Student* loadData(Student* Obj, int& amount); // чтение из файла

static string path = "MyData.txt"; // имя файла

int main()
{



    Student* OurInfo;
    int amount = 0;
    int YesOrNot = 0; //  продолжить или остановить ввод данных

    // хотя бы один введем
    OurInfo = Add(OurInfo, amount);
    setData(OurInfo, amount);
    amount++;

    do
    {
        cout << "Задайте требуемое действие: 0-выход, 1-ввод, 2-сортировка, 3-печать, 4-запись в файл, 5-чтение из файла: ";
        cin >> YesOrNot;

        if (YesOrNot == 1) // ввод
        {
            OurInfo = Add(OurInfo, amount);
            setData(OurInfo, amount);
            amount++;
        }

        if (YesOrNot == 2) // сортировка
        {
            sortData(OurInfo, amount);
        }

        if (YesOrNot == 3) // печать
        {
            showData(OurInfo, amount);
        }

        if (YesOrNot == 4) // сохранить в файл
        {
            saveData(OurInfo, amount);
        }

        if (YesOrNot == 5) // чтение из файла
        {
            OurInfo = loadData(OurInfo, amount);
            showData(OurInfo, amount);
        }
    } while (YesOrNot != 0);

    delete[] OurInfo;
    return 0;
}

Student* Add(Student* Obj, int amount)
{
    if (amount == 0)
    {
        Obj = new Student[amount + 1]; // выделение памяти для первой структуры
    }
    else
    {
        Student* tempObj = new Student[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete[] Obj;

        Obj = tempObj;
    }
    return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(Student* Obj, int amount)
{
    Obj[amount].fillData();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(Student* Obj, int amount)
{
    cout << "    ФИО          Группа     Средний балл       Доход" << endl;
    cout << "================================================================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        Obj[i].showData();
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sortData(Student* Obj, int amount)
{
    Student tempObj;
    //сортировка по доходам по возрастанию
    // Сортировка массива пузырьком
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (Obj[j].getDohod() > Obj[j + 1].getDohod()) {
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
    for (int i = 0; i < amount; i++) {
        if (Obj[i].getDohod() < min_zarplata * 2)
        {
            Obj[i].showData();
        }
    }
}

void saveData(Student* Obj, int amount) {
    ofstream fs;
    fs.open(path);
    fs << amount;
    fs << "\n";
    for (int i = 0; i < amount; i++) {
        fs << Obj[i].getFio(); fs << "\n";
        fs << Obj[i].getGroup(); fs << "\n";
        fs << Obj[i].getBall(); fs << "\n";
        fs << Obj[i].getDohod(); fs << "\n";
    }
    cout << "Файл успешно сохранен!" << endl << endl;
}

Student* loadData(Student* Obj, int& amount) {
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "Файл не удалось открыть!" << endl;
        return Obj;
    }
    amount = 0;
    fs >> amount;

    Student* OurInfo = 0;
    string fio;
    int group;
    double ball;
    double dohod;
    for (int i = 0; i < amount; i++)
    {
        OurInfo = Add(OurInfo, i);
        fs >> fio; OurInfo[i].setFio(fio);
        fs >> group; OurInfo[i].setGroup(group);
        fs >> ball; OurInfo[i].setBall(ball);
        fs >> dohod; OurInfo[i].setDohod(dohod);
    };

    delete[] Obj;
    Obj = OurInfo;

    cout << "Файл успешно прочитан!" << endl << endl;

    return Obj;
}


