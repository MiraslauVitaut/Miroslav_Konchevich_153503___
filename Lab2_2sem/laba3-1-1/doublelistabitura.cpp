#include "doublelistabitura.h"



double listAbitura::getAverageMarks() const
{
    return averageMarks;
}

NodeAbitura *listAbitura::getHead() const
{
    return head;
}

NodeAbitura *listAbitura::getTail() const
{
    return tail;
}

listAbitura::listAbitura()
{
    head=NULL;
    tail=NULL;
    count = 0;
}

listAbitura::~listAbitura()
{
    while (head != NULL) {
        NodeAbitura *next = head->next;
        delete head;
        head = next;
      }
}

void listAbitura::push_back(QString _surname, QString _name, QString _patronymic, int _math, int _physics, int _language)
{
    NodeAbitura* p = new NodeAbitura(_surname,_name,_patronymic,_math,_physics,_language);

    if (is_empty()) {
        count = 1;
        head = p;
        tail = p;
        p->average = (_math+_physics+_language)/3.0;
        averageMarks = (_math+_language+_physics)/3.0;
        return;
    }

    tail->next = p;
    p->prev=tail;
    tail= p;
    count++;
    p->average = (_math+_physics+_language)/3.0;
    averageMarks=(averageMarks+(_math+_physics+_language)/3.0)/2.0;
}

QString listAbitura::print()
{
    QString textInfo="";
    if(is_empty())
        return textInfo;

    NodeAbitura* p = head;
    while (p) {
        textInfo+=(p->getSurname()+" "+p->getName()+" "+p->getPatronymic()+"  Математика: "+QString::number(p->getMath())+"  Физика: "+QString::number(p->getPhysics())+"  Язык: "+QString::number(p->getLanguage())+"\n");
        p = p->next;
    }
    return textInfo;
}

QString listAbitura::printAverage()
{
    QString textInfo="";

    if(is_empty())
        return textInfo;
    calculateAverage();
    NodeAbitura* p = head;
    while (p) {
        if((p->getLanguage()+p->getMath()+p->getPhysics())/3.0>averageMarks){
        textInfo+=(p->getSurname()+" "+p->getName()+" "+p->getPatronymic()+"  Математика: "+QString::number(p->getMath())+"  Физика: "+QString::number(p->getPhysics())+"  Язык: "+QString::number(p->getLanguage())+"\n");
        }
        p = p->next;
    }
    return textInfo;
}

NodeAbitura *listAbitura::findSurname(const QString &surname)
{
    NodeAbitura* p = head;
    while (p && p->getSurname() != surname) p=p->next;
    return (p && p->getSurname() == surname) ? p : NULL;
}

void listAbitura::remove(const NodeAbitura* p)
{
    if (is_empty()) return;
            if (head == p) {
                remove_first();
                return;
            }
            else if (tail == p) {
                remove_last();
                return;
            }
            NodeAbitura* slow = head;
            NodeAbitura* fast = head->next;
            while (fast && fast != p) {
                fast = fast->next;
                slow = slow->next;
            }

            slow->next = fast->next;
            count--;
            delete fast;
}

double listAbitura::calculateAverage()
{
    double res =0;
    if(is_empty())
        return res;

    NodeAbitura* p = head;
    while (p) {
        res +=p->getLanguage()+p->getMath()+p->getPhysics();
        p = p->next;
    }
    res/=count*3.0;
    averageMarks=res;
    return res;
}

NodeAbitura* listAbitura::getLast()
{
    return tail;
}

void listAbitura::remove_first()
{
    if (is_empty()) return;
            NodeAbitura* p = head;
            head = p->next;
            delete p;
            count--;
}

void listAbitura::remove_last()
{
    if (is_empty()) return;
            if (head == tail) {
                remove_first();
                count--;
                return;
            }
            NodeAbitura* p = head;
            while (p->next != tail) p = p->next;
            p->next = NULL;
            delete tail;
            tail = p;
            count--;
}

QString listAbitura::print_search(QString _surname)
{
    QString textInfo="";
    if(is_empty())
        return textInfo;

    NodeAbitura* p = head;
    while (p) {
        if(p->getSurname()==_surname){
        textInfo+=(p->getSurname()+" "+p->getName()+" "+p->getPatronymic()+"  Математика: "+QString::number(p->getMath())+"  Физика: "+QString::number(p->getPhysics())+"  Язык: "+QString::number(p->getLanguage())+"\n");
        }
        p = p->next;
    }
    return textInfo;
}

NodeAbitura **listAbitura::arraySurname(QString _surname)
{
    NodeAbitura* p = head;
    int numb = 0;
    while (p) {
        if(p->getSurname()==_surname){
        numb++;
        }
        p = p->next;
    }
    NodeAbitura** array = new NodeAbitura*[numb];
    p = head;
    for(int i=0;i<numb&&p;){
        if(p->getSurname()==_surname){
            array[i]=p;
            i++;
        }
        p = p->next;
    }
    return array;
}

QString listAbitura::printinfile()
{
    QString textInfo="";
    if(is_empty())
        return textInfo;

    NodeAbitura* p = head;
    while (p) {
        textInfo+=(p->getSurname()+" "+p->getName()+" "+p->getPatronymic()+" "+QString::number(p->getMath())+" "+QString::number(p->getPhysics())+" "+QString::number(p->getLanguage())+"\n");
        p = p->next;
    }
    return textInfo;
}

const QString &NodeAbitura::getSurname() const
{
    return surname;
}

void NodeAbitura::setSurname(const QString &newSurname)
{
    surname = newSurname;
}

const QString &NodeAbitura::getPatronymic() const
{
    return patronymic;
}

void NodeAbitura::setPatronymic(const QString &newPatronymic)
{
    patronymic = newPatronymic;
}

int NodeAbitura::getMath() const
{
    return math;
}

void NodeAbitura::setMath(int newMath)
{
    this->average = (newMath+physics+language)/3.0;
    math = newMath;
}

int NodeAbitura::getPhysics() const
{
    return physics;
}

void NodeAbitura::setPhysics(int newPhysics)
{
    this->average = (math+newPhysics+language)/3.0;
    physics = newPhysics;
}

int NodeAbitura::getLanguage() const
{
    return language;
}

void NodeAbitura::setLanguage(int newLanguage)
{
    this->average = (math+physics+newLanguage)/3.0;
    language = newLanguage;
}

const QString &NodeAbitura::getName() const
{
    return name;
}

void NodeAbitura::setName(const QString &newName)
{
    name = newName;
}

NodeAbitura* listAbitura::partition(NodeAbitura *left, NodeAbitura *right)
{
    NodeAbitura *pivot = right;
    NodeAbitura *i = left->prev;
    for (NodeAbitura *ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->average >= pivot->average)
        {
            i = (i == NULL ? left : i->next);
            double temp = i->average;
            i->average = ptr->average;
            ptr->average = temp;

            int tempm = i->getMath();
            i->setMath(ptr->getMath());
            ptr->setMath(tempm);

            tempm = i->getLanguage();
            i->setLanguage(ptr->getLanguage());
            ptr->setLanguage(tempm);

            tempm = i->getPhysics();
            i->setPhysics(ptr->getPhysics());
            ptr->setPhysics(tempm);

            QString temps = i->getName();
            i->setName(ptr->getName());
            ptr->setName(temps);

            temps = i->getPatronymic();
            i->setPatronymic(ptr->getPatronymic());
            ptr->setPatronymic(temps);

            temps = i->getSurname();
            i->setSurname(ptr->getSurname());
            ptr->setSurname(temps);
        }
    }
    i = (i == NULL ? left : i->next);
    double temp = i->average;
    i->average = pivot->average;
    pivot->average = temp;

    int tempm = i->getMath();
    i->setMath(pivot->getMath());
    pivot->setMath(tempm);

    tempm = i->getLanguage();
    i->setLanguage(pivot->getLanguage());
    pivot->setLanguage(tempm);

    tempm = i->getPhysics();
    i->setPhysics(pivot->getPhysics());
    pivot->setPhysics(tempm);

    QString temps = i->getName();
    i->setName(pivot->getName());
    pivot->setName(temps);

    temps = i->getPatronymic();
    i->setPatronymic(pivot->getPatronymic());
    pivot->setPatronymic(temps);

    temps = i->getSurname();
    i->setSurname(pivot->getSurname());
    pivot->setSurname(temps);
    return i;
}
void listAbitura::QuickSort(NodeAbitura *left, NodeAbitura *right)
{
    if (right != NULL && left != right && left != right->next)
    {
        NodeAbitura *p = partition(left, right);
        QuickSort(left, p->prev);
        QuickSort(p->next, right);
    }
}
