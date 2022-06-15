#include "doublelist.h"



double DoubleList::getAverageMarks()
{
    double res =0;

    if(is_empty())
        return res;

    int p = head;
    while (p!=-1) {
        res +=arr_list[p].average;
        p = arr_list[p].next;
    }
    res/=count;
    averageMarks=res;

    return averageMarks;
}

bool compare(const Node& a, const Node& b)
{
    return a.average>b.average;

}
void DoubleList::qSort()
{
    std::vector<Node> temp_arr;
    int p = head;
    while (p!=-1) {
        temp_arr.push_back(arr_list[p]);
        p = arr_list[p].next;
    }
    std::sort(temp_arr.begin(), temp_arr.end(), compare);
    sizearr = temp_arr.size();
    head = 0;
    tail = sizearr-1;
    if(temp_arr.size()==1){
        temp_arr[head].prev=-1;
        temp_arr[head].next=-1;
        temp_arr[head].index=0;
    }else{
    temp_arr[head].prev=-1;
    temp_arr[head].next=1;
    temp_arr[head].index=0;
    }
    for(int i =1;i<sizearr;i++){
        temp_arr[i].prev=i-1;
        temp_arr[i].index=i;
        if(i==sizearr-1) temp_arr[i].next=-1;
        else temp_arr[i].next = i+1;
    }
    arr_list = temp_arr;
}

Node DoubleList::getLast()
{
    return arr_list[tail];
}

std::vector<Node> DoubleList::arraySurname(QString _surname)
{
    int p = head;
    int numb = 0;
    while (p!=-1) {
        if(arr_list[p].surname ==_surname){
        numb++;
        }
        p = arr_list[p].next;
    }
    std::vector<Node> array;
    p = head;
    for(int i=0;i<numb&&p!=-1;){
        if(arr_list[p].surname==_surname){
            array.push_back(arr_list[p]);
            i++;
        }
        p = arr_list[p].next;
    }
    return array;
}

bool DoubleList::isErr()
{
    return (arr_list[tail].name == ""||arr_list[tail].surname ==""||arr_list[tail].patronymic=="");
}

void DoubleList::push_back(QString _surname, QString _name, QString _patronymic, int _math, int _physics, int _language)
{
    Node p(_surname,_name,_patronymic,_math,_physics,_language);
    arr_list.push_back(p);

    if (is_empty()) {
        count = 1;
        sizearr = 1;
        head = 0;
        tail = 0;
        arr_list[arr_list.size()-1].index = sizearr-1;
        averageMarks = p.average;
        return;
    }

    count++;
    sizearr++;
    arr_list[tail].next = count-1;
    arr_list[arr_list.size()-1].prev=tail;
    tail= count-1;
    arr_list[arr_list.size()-1].index = sizearr-1;
    averageMarks=(averageMarks+p.average)/2.0;
}

QString DoubleList::print()
{
    QString textInfo="";
    if(is_empty())
        return textInfo;

    int p = head;
    while(p!=-1){
        textInfo+=(arr_list[p].surname+" "+arr_list[p].name+" "+arr_list[p].patronymic+"  Математика: "+QString::number(arr_list[p].math)+"  Физика: "+QString::number(arr_list[p].physics)+"  Язык: "+QString::number(arr_list[p].language)+"\n");
        qDebug()<<arr_list[p].index;
        p = arr_list[p].next;
    }
    return textInfo;
}

QString DoubleList::printinfile()
{
    QString textInfo="";
    if(is_empty())
        return textInfo;

    int p = head;
    while (p!=-1) {
        textInfo+=(arr_list[p].surname+" "+arr_list[p].name+" "+arr_list[p].patronymic+" "+QString::number(arr_list[p].math)+" "+QString::number(arr_list[p].physics)+" "+QString::number(arr_list[p].language)+"\n");
        p = arr_list[p].next;
    }
    return textInfo;
}

QString DoubleList::printAverage()
{
    QString textInfo="";

    if(is_empty())
        return textInfo;

    int p = head;
    while (p!=-1) {
        if(arr_list[p].average>averageMarks){
            textInfo+=(arr_list[p].surname+" "+arr_list[p].name+" "+arr_list[p].patronymic+"  Математика: "+QString::number(arr_list[p].math)+"  Физика: "+QString::number(arr_list[p].physics)+"  Язык: "+QString::number(arr_list[p].language)+"\n");
        }
        p = arr_list[p].next;
    }
    return textInfo;
}

QString DoubleList::print_search(QString _surname)
{
    QString textInfo="";
    if(is_empty())
        return textInfo;

    int p = head;
    while (p!=-1) {
        if(arr_list[p].surname==_surname){
            textInfo+=(arr_list[p].surname+" "+arr_list[p].name+" "+arr_list[p].patronymic+"  Математика: "+QString::number(arr_list[p].math)+"  Физика: "+QString::number(arr_list[p].physics)+"  Язык: "+QString::number(arr_list[p].language)+"\n");
        }
        p = arr_list[p].next;
    }
    return textInfo;
}

void DoubleList::remove_first()
{
    if (is_empty()) return;

    head = arr_list[head].next;
    arr_list[head].prev=-1;
    count--;
}

void DoubleList::remove_last()
{
    if (is_empty()) return;

            if (head == tail) {
                remove_first();
                count--;
                return;
            }
            int p = head;
            while (arr_list[p].next != tail) p = arr_list[p].next;
            arr_list[p].next = -1;
            tail = p;
            count--;
}

void DoubleList::remove(int _index)
{
    if (is_empty()) return;
            if (head == _index) {
                remove_first();
                return;
            }
            else if (tail == _index) {
                remove_last();
                return;
            }
            int slow = head;
            int fast = arr_list[head].next;
            while (fast && fast != _index) {
                fast = arr_list[fast].next;
                slow = arr_list[slow].next;
            }

            arr_list[slow].next = arr_list[fast].next;
            count--;
}

void DoubleList::setLastName(QString _name)
{
    arr_list[tail].name = _name;
}

void DoubleList::setLastSurname(QString _surname)
{
    arr_list[tail].surname = _surname;
}

void DoubleList::setLastPatronymic(QString _patronymic)
{
    arr_list[tail].patronymic = _patronymic;
}

void DoubleList::setLastMath(int _math)
{
    arr_list[tail].math = _math;
    arr_list[tail].average = (arr_list[tail].math+arr_list[tail].physics+arr_list[tail].language)/3.0;
}

void DoubleList::setLastPhysics(int _physics)
{
    arr_list[tail].physics = _physics;
    arr_list[tail].average = (arr_list[tail].math+arr_list[tail].physics+arr_list[tail].language)/3.0;
}

void DoubleList::setLastLanguage(int _language)
{
    arr_list[tail].language = _language;
    arr_list[tail].average = (arr_list[tail].math+arr_list[tail].physics+arr_list[tail].language)/3.0;
}
