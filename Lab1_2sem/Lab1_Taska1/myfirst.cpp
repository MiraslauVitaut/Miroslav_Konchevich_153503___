#include "myfirst.h"
#include<QFrame>
#include <QLabel>
#include<QMouseEvent>
#include<QPixmap>


MyFirstBallon::MyFirstBallon(QWidget *parent)
    : QGraphicsView(parent)

{



   scene = new QGraphicsScene(0,0,1000,800,this);
   scene->addRect(scene->sceneRect());
   QPixmap background("/Users/miroslavkonchevich/Desktop/MyLaba/Lab1_Taska1/Nebo.jpeg"); /// создание фонового изображения через Pixmap
   scene->setBackgroundBrush(background.scaled(1200,850,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
   setScene(scene);



    fly_ballon_time = new QTimer(this); /// Приведение шарика в движение через таймер
    fly_ballon_time->start(1000 / 100);
    connect(fly_ballon_time , SIGNAL(timeout()) , this , SLOT(MyTimer()));
    connect(scene, SIGNAL(doubleClicked(const QModelIndex& )), this, SLOT(OnDc(const QModelIndex&)));

   ballon = new QGraphicsEllipseItem(0,340,100,100); //// Создание шарика
   ballon->setBrush(Qt::blue);

   blick = new QGraphicsEllipseItem(20,360,30,40); /// Создание блика на шарике
   blick -> setBrush(Qt::white);

   QPolygon stick;
   stick << QPoint(45,440) << QPoint(45 , 540) << QPoint(49,540) << QPoint(49 ,440); /// Создание веревки на которой держится шарик

   steek = new QGraphicsPolygonItem();
   steek -> setPolygon(stick);
   steek->setBrush(Qt::black);


   scene->addItem(ballon);    /// Добавление на сцену
   scene->addItem(steek);
   scene->addItem(blick);



}


void MyFirstBallon::mouseDoubleClickEvent(QMouseEvent * e) /// Функция взрыва шарика (по двойному щелчку правой кнопки мыши)
{
    if (e->button() == Qt::RightButton)
        {
        scene->removeItem(ballon);
        scene->removeItem(steek);
        scene ->removeItem(blick);
        }
}

void MyFirstBallon::MyTimer() /// Движение шарика через таймер
{
static int i = 0 , j = -330 , k = 900, x = 0 , y = 250 , t = 580;
i++;
i++;
j++;
ballon ->setPos(i, j);
steek -> setPos(i, j);
blick -> setPos(i,j);

if(i >= (900))
{
  ballon -> setPos(900, j);
  steek -> setPos(900, j);
  blick -> setPos(900, j);
  j++;
}
if(j >= 250)
{
    ballon -> setPos(k, 250);
    steek -> setPos(k, 250);
    blick -> setPos(k, 250);
    k--;
    k--;
}
if(k<= 0)
{
    ballon -> setPos(x, y);
    steek -> setPos(x, y);
    blick -> setPos(x, y);
    y--;
    y--;
    x++;
    x++;
}

if(y <= -330)
{

    ballon -> setPos(t,-330);
    steek -> setPos(t,-330);
    blick -> setPos(t, -330);
    t--;
    t--;

}

if(t<=0)
{
        i = 0;
        j = -330;
        k = 900;
        x = 0;
        y = 250;
        t = 550;

}




}





MyFirstBallon::~MyFirstBallon()
{
}

Graphic_Scene::Graphic_Scene(QWidget * parent)
    :QWidget(parent)
{

    myScene = new QHBoxLayout(this);
    myballon = new MyFirstBallon;
    myScene -> addWidget(myballon);
    setLayout(myScene);
}

Graphic_Scene::~Graphic_Scene()
{
}

