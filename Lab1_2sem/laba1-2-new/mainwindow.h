#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QPushButton>
#include <QLayout>
#include <QComboBox>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QDebug>
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "hexagon.h"
#include "fivepointedstar.h"
#include "sixpointedstar.h"
#include "eightpointedstar.h"
#include "arbitary.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int chosen_moving=-1;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *time;


    Triangle *triangle=NULL;
    Circle *circle=NULL;
    Rectangle *rectangle=NULL;
    Square *square = NULL;
    Hexagon *hexagon=NULL;
    FivePointedStar *fivepointedstar = NULL;
    SixPointedStar *sixpointedstar = NULL;
    EightPointedStar *eightpointedstar = NULL;
    QGraphicsPolygonItem *canva = NULL;
    QPolygonF *canvaPol;
    bool Canvas=false;
    bool RightClicked;
    bool FirstP=false;
    QPointF FirstPoint;
    QPointF PreviousPoint;

    QPushButton *button_triangle;
    QPushButton *button_circle;
    QPushButton *button_rectangle;
    QPushButton *button_square;
    QPushButton *button_hexagon;
    QPushButton *button_fivepointedstar;
    QPushButton *button_sixpointedstar;
    QPushButton *button_eightpointedstar;

    QPushButton *button_turn_left;
    QPushButton *button_turn_right;
    QPushButton *button_turn_up;
    QPushButton *button_turn_down;

    QPushButton *buttonScalePlus;
    QPushButton *buttonScaleMinus;
    QPushButton *buttonRotateClockwise;
    QPushButton *buttonRotateCounterClockwise;
    QPushButton *button_Canva;

private slots:
    void clicked_button_triangle();
    void clicked_button_triangle_del();
    void clicked_button_circle();
    void clicked_button_circle_del();
    void clicked_button_rectangle();
    void clicked_button_rectangle_del();
    void clicked_button_square();
    void clicked_button_square_del();
    void clicked_button_hexagon();
    void clicked_button_hexagon_del();
    void clicked_button_fivepointedstar();
    void clicked_button_fivepointedstar_del();
    void clicked_button_sixpointedstar();
    void clicked_button_sixpointedstar_del();
    void clicked_button_eightpointedstar();
    void clicked_button_eightpointedstar_del();

    void clicked_button_turn_left();
    void clicked_button_turn_right();
    void clicked_button_turn_up();
    void clicked_button_turn_down();
    void chose_box(int);

    void clicked_button_rotate_clockwise();
    void clicked_button_rotate_counterclockwise();

    void clicked_button_scale_plus();
    void clicked_button_scale_minus();

    void clicked_button_show_info();

    //void mousePressEvent(QMouseEvent *event);
    void on_CanvasButton_clicked();
    void mousePressEvent(QMouseEvent *event);

};
#endif // MAINWINDOW_H
