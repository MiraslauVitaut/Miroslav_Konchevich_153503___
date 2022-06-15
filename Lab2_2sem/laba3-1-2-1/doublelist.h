#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <QString>
#include <vector>
#include <QDebug>
#include <algorithm>

struct Node
{
    QString surname;
    QString name;
    QString patronymic;
    int math;
    int physics;
    int language;
    double average;

    int index,next,prev;

    Node(QString _surname,QString _name,QString _patronymic,int _math,int _physics,int _language):
        surname(_surname),name(_name),patronymic(_patronymic),math(_math),physics(_physics),
        language(_language),average((_math+_physics+_language)/3.0),index(-1),next(-1),prev(-1){}
};

class DoubleList
{
private:
    int head, tail;
    int count;
    int sizearr;
    double averageMarks;
    std::vector<Node> arr_list;
public:
    DoubleList():head(-1),tail(-1),count(0),sizearr(0){}
    bool is_empty(){return head == -1;}
    bool isErr();
    void push_back(QString _name,QString _surname,QString _patronymic,int _math,int _physics,int _language);
    QString print();
    QString printinfile();
    QString printAverage();
    QString print_search(QString _surname);
    void remove_first();
    void remove_last();
    void remove(int _index);
    void setLastName(QString _name);
    void setLastSurname(QString _surname);
    void setLastPatronymic(QString _patronymic);
    void setLastMath(int _math);
    void setLastPhysics(int _physics);
    void setLastLanguage(int _language);
    double getAverageMarks();
    void qSort();
    Node getLast();
    std::vector<Node> arraySurname(QString _surname);
};

#endif // DOUBLELIST_H
