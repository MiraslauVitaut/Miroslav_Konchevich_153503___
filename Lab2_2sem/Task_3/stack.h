#ifndef StrStack_H
#define StrStack_H
#include<QApplication>

class StrStack
{

public:
    StrStack(){};

    void push(QChar data)
    {
        if(_size == 0)
        {

            _head = new Element(data);
            _size++;

            return;
        }

        auto tmp = _head;
        _head = new Element(data);
        _head->next = tmp;

        _size++;
    };


    QString returnPrev(QChar data)
    {
        if(_size == 0 )
            return "";


        QString str = "";
        while(true){
            if(_size == 0)
            {
                break;
            }
            if( _head->data == '(' && data == ')'){
                this->erase();
                break;
            }
            if(_size != 0 && powerOfElement(_head->data)  >= powerOfElement(data)){

                auto tmp = _head->data;
                this->erase();

                str.push_back(tmp);
            }
            else{
                break;
            }
        }
        return str;
    };

    QString returnLasts(){
        QString str;
        auto tmp = _head;
        for(int i = 0; i < _size; i++){
            if(tmp->data == '(' || tmp->data == ')'){
                tmp = tmp->next;
                continue;
            }
            str.push_back(tmp->data);
            tmp = tmp->next;
        }

        return str;
    };
    void erase(){
        if(_size == 0)
            return;

        auto tmp = _head->next;

        delete _head;
        _head = tmp;

        --_size;
    };


    int powerOfElement(QChar data){
        if(data == '*' || data == '/' )
        {
            return 2;
        }
        else if(data == '+' || data == '-' )
        {
            return 1;
        }
        else if(data == '(' || data == ')')
        {
            return 0;
        }
        return -1;
    };


    ~StrStack(){
        while(_size-- != 0)
            this->erase();
        delete _head;
    };

private:

    class Element
    {
    public:
        Element(QChar data):data(data){};

        Element *next;
        QChar data;
    };

    int _size = 0;
    Element *_head = nullptr;
};


class NumStack
{
public:
    NumStack(){};

    void push(double data){
        if(_size == 0){
            _head = new Element(data);
            _size++;

            return;
        }

        auto tmp = _head;
        _head = new Element(data);
        _head->next = tmp;

        _size++;
    };


    void erase()
    {
        if(_size == 0)
            return;

        auto tmp = _head->next;

        delete _head;
        _head = tmp;

        --_size;
    };


    double answer()
    {
        return _head->data;
    }


    double eraseValue()
    {
        auto tmp = _head->data;
        erase();
        return tmp;
    };

    ~NumStack()
    {
        while(_size-- != 0)
            this->erase();
        delete _head;
    };

private:
    class Element
    {
    public:
        Element(double data):data(data){};

        Element *next;
        double data;
    };

    int _size = 0;
    Element *_head = nullptr;
};

#endif // StrStack_H
