#ifndef MYFIRST_H
#define MYFIRST_H

#include <QMainWindow>
#include <QWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QTimer>
#include<QHBoxLayout>
#include<QDebug>
#include<QPainter>
#include<QGraphicsEllipseItem>
#include<QGraphicsRectItem>
#include<QGraphicsPolygonItem>
#include<QPushButton>
#include<QSplashScreen>

QT_BEGIN_NAMESPACE
namespace Ui { class MyFirstBallon; }
QT_END_NAMESPACE

class MyFirstBallon :  public QGraphicsView
{
    Q_OBJECT

private:

    QGraphicsScene * scene;
    QGraphicsEllipseItem *ballon;
    QGraphicsEllipseItem *blick;

    QPushButton *boom_button;
    QGraphicsPolygonItem * steek;
    QTimer * fly_ballon_time;
    QGraphicsSceneMouseEvent * click;
    void mousedoubleclick ( QMouseEvent*);

private slots:

    void MyTimer();

protected slots:
    void mouseDoubleClickEvent(QMouseEvent * e);

public:

    MyFirstBallon(QWidget *parent = nullptr);
    ~MyFirstBallon();
};

class Graphic_Scene: public QWidget
{
    Q_OBJECT

public:
    Graphic_Scene(QWidget * parent = nullptr);
    ~Graphic_Scene();

private:
    QHBoxLayout * myScene;
    MyFirstBallon * myballon;


};

#endif // MYFIRST_H
