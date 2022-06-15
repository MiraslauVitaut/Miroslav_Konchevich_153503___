#ifndef DOUBLELISTABITURA_H
#define DOUBLELISTABITURA_H

#include <QString>
#include <QDebug>


struct NodeAbitura
{
private:
    QString name;
    QString surname;
    QString patronymic;
    int math;
    int physics;
    int language;

public:
    double average;
    NodeAbitura(QString _surname,QString _name,QString _patronymic,int _math,int _physics,int _language):
        name(_name),surname(_surname),patronymic(_patronymic),math(_math),physics(_physics),language(_language),next(NULL),prev(NULL){}

    NodeAbitura *next;
    NodeAbitura *prev;
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);
    int getMath() const;
    void setMath(int newMath);
    int getPhysics() const;
    void setPhysics(int newPhysics);
    int getLanguage() const;
    void setLanguage(int newLanguage);
};


class listAbitura{
private:
    int count=0;
    double averageMarks=0;
    NodeAbitura *head;
    NodeAbitura *tail;
public:
    listAbitura();
    ~listAbitura();
    bool is_empty(){
        return head==NULL;
    }
    void push_back(QString _name,QString _surname,QString _patronymic,int _math,int _physics,int _language);
    QString print();
    QString printAverage();
    NodeAbitura* findSurname(const QString &surname);
    void remove(const NodeAbitura* p);
    double calculateAverage();
    NodeAbitura* getLast();
    void remove_first();
    void remove_last();
    QString print_search(QString _surname);
    NodeAbitura** arraySurname(QString _surname);
    QString printinfile();

    struct NodeAbitura *partition(struct NodeAbitura *left, struct NodeAbitura *right);
    void QuickSort(struct NodeAbitura *left, struct NodeAbitura *right);
    double getAverageMarks() const;
    NodeAbitura *getHead() const;
    NodeAbitura *getTail() const;
};

#endif // DOUBLELISTABITURA_H
