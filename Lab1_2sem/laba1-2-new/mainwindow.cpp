#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(9,9,1111,601);
    scene->setSceneRect(-551,-296,1111,601);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

///////////////////////////////////////////////////////////////////////////////////////////////////

    button_triangle = new QPushButton("Triangle",ui->graphicsViewButtons); // TRIANGLE ADD
    button_triangle->setGeometry(0,0,100,30);
    connect(button_triangle,SIGNAL(clicked()),this,SLOT(clicked_button_triangle()));

    QPushButton *button_triangle_del = new QPushButton("Del",ui->graphicsViewButtons); // TRINAGLE DELETE
    button_triangle_del->setGeometry(100,0,40,30);
    connect(button_triangle_del,SIGNAL(clicked()),this,SLOT(clicked_button_triangle_del()));

    button_circle = new QPushButton("Circle",ui->graphicsViewButtons);  // CIRCLE ADD
    button_circle->setGeometry(0,31,100,30);
    connect(button_circle,SIGNAL(clicked()),this,SLOT(clicked_button_circle()));

    QPushButton *button_circle_del = new QPushButton("Del",ui->graphicsViewButtons);  // CIRLCE DELETE
    button_circle_del->setGeometry(100,31,40,30);
    connect(button_circle_del,SIGNAL(clicked()),this,SLOT(clicked_button_circle_del()));

    button_rectangle = new QPushButton("Rectangle",ui->graphicsViewButtons);  // RECTANGLE ADD
    button_rectangle->setGeometry(0,62,100,30);
    connect(button_rectangle,SIGNAL(clicked()),this,SLOT(clicked_button_rectangle()));

    QPushButton *button_rectangle_del = new QPushButton("Del",ui->graphicsViewButtons);  // RECTANGLE DELETE
    button_rectangle_del->setGeometry(100,62,40,30);
    connect(button_rectangle_del,SIGNAL(clicked()),this,SLOT(clicked_button_rectangle_del()));

    button_square = new QPushButton("Square",ui->graphicsViewButtons); // SQUARE ADD
    button_square->setGeometry(0,93,100,30);
    connect(button_square,SIGNAL(clicked()),this,SLOT(clicked_button_square()));

    QPushButton *button_square_del = new QPushButton("Del",ui->graphicsViewButtons); // SQUARE DELETE
    button_square_del->setGeometry(100,93,40,30);
    connect(button_square_del,SIGNAL(clicked()),this,SLOT(clicked_button_square_del()));

    button_hexagon = new QPushButton("Hexagon",ui->graphicsViewButtons); // HEXAGON ADD
    button_hexagon->setGeometry(0,124,100,30);
    connect(button_hexagon,SIGNAL(clicked()),this,SLOT(clicked_button_hexagon()));

    QPushButton *button_hexagon_del = new QPushButton("Del",ui->graphicsViewButtons);  // HEXAGON DELETE
    button_hexagon_del->setGeometry(100,124,40,30);
    connect(button_hexagon_del,SIGNAL(clicked()),this,SLOT(clicked_button_hexagon_del()));

    button_fivepointedstar = new QPushButton("Star(5)",ui->graphicsViewButtons);  // STAR(5) ADD
    button_fivepointedstar->setGeometry(0,154,100,30);
    connect(button_fivepointedstar,SIGNAL(clicked()),this,SLOT(clicked_button_fivepointedstar()));

    QPushButton *button_fivepointedstar_del = new QPushButton("Del",ui->graphicsViewButtons); // STAR(5) DELETE
    button_fivepointedstar_del->setGeometry(100,154,40,30);
    connect(button_fivepointedstar_del,SIGNAL(clicked()),this,SLOT(clicked_button_fivepointedstar_del()));

    button_sixpointedstar = new QPushButton("Star(6)",ui->graphicsViewButtons); // STAR(6) ADD
    button_sixpointedstar->setGeometry(0,185,100,30);
    connect(button_sixpointedstar,SIGNAL(clicked()),this,SLOT(clicked_button_sixpointedstar()));

    QPushButton *button_sixpointedstar_del = new QPushButton("Del",ui->graphicsViewButtons); // STAR(6) DELETE
    button_sixpointedstar_del->setGeometry(100,185,40,30);
    connect(button_sixpointedstar_del,SIGNAL(clicked()),this,SLOT(clicked_button_sixpointedstar_del()));

    button_eightpointedstar = new QPushButton("Star(8)",ui->graphicsViewButtons); // STAR(8) ADD
    button_eightpointedstar->setGeometry(0,216,100,30);
    connect(button_eightpointedstar,SIGNAL(clicked()),this,SLOT(clicked_button_eightpointedstar()));

    QPushButton *button_eightpointedstar_del = new QPushButton("Del",ui->graphicsViewButtons); // STAR(8) DELETE
    button_eightpointedstar_del->setGeometry(100,216,40,30);
    connect(button_eightpointedstar_del,SIGNAL(clicked()),this,SLOT(clicked_button_eightpointedstar_del()));

    button_Canva = new QPushButton("Canva",ui->graphicsViewButtons);
    button_Canva->setGeometry(0,247,140,30);
    connect(button_Canva,SIGNAL(clicked()),this,SLOT(on_CanvasButton_clicked()));
///////////////////////////////////////////////////////////////////////////////////////////////////

    QComboBox *chose = new QComboBox(ui->graphicsViewButtons);  // CHOOSING A FIRUGE FOR ACTION
    chose->setGeometry(35,500,70,30);
    chose->addItem("Trinagle");
    chose->addItem("Circle");
    chose->addItem("Rectangle");
    chose->addItem("Square");
    chose->addItem("Hexagon");
    chose->addItem("Star(5)");
    chose->addItem("Star(6)");
    chose->addItem("Star(8)");
    connect(chose,SIGNAL(activated(int)),this,SLOT(chose_box(int)));

    button_turn_left = new QPushButton("🡸",ui->graphicsViewButtons);  // SHIFT LEFT
    button_turn_left->setGeometry(0,500,30,30);
    button_turn_left->setAutoRepeat(true);
    connect(button_turn_left,SIGNAL(pressed()),this,SLOT(clicked_button_turn_left()));

    button_turn_right = new QPushButton("🡺",ui->graphicsViewButtons);  // SHIFT RIGHT
    button_turn_right->setGeometry(110,500,30,30);
    button_turn_right->setAutoRepeat(true);
    connect(button_turn_right,SIGNAL(pressed()),this,SLOT(clicked_button_turn_right()));

    button_turn_up = new QPushButton("🡹",ui->graphicsViewButtons);   // SHIFT UP
    button_turn_up->setGeometry(35,465,70,30);
    button_turn_up->setAutoRepeat(true);
    connect(button_turn_up,SIGNAL(pressed()),this,SLOT(clicked_button_turn_up()));

    button_turn_down = new QPushButton("🡻",ui->graphicsViewButtons);  // SHIFT DOWN
    button_turn_down->setGeometry(35,535,70,30);
    button_turn_down->setAutoRepeat(true);
    connect(button_turn_down,SIGNAL(pressed()),this,SLOT(clicked_button_turn_down()));

///////////////////////////////////////////////////////////////////////////////////////////////////

    QPushButton *button_info = new QPushButton("INFO",ui->graphicsViewButtons);  // SHOW INFO
    button_info->setGeometry(10,575,120,25);
    connect(button_info,SIGNAL(clicked()),this,SLOT(clicked_button_show_info()));

///////////////////////////////////////////////////////////////////////////////////////////////////

    buttonScalePlus = new QPushButton("➕",ui->graphicsViewButtons); // SCALE +
    buttonScalePlus->setGeometry(0,300,64,30);
    buttonScalePlus->setAutoRepeat(true);
    connect(buttonScalePlus,SIGNAL(pressed()),this,SLOT(clicked_button_scale_plus()));

    buttonScaleMinus = new QPushButton("➖",ui->graphicsViewButtons);  //SCALE -
    buttonScaleMinus->setGeometry(76,300,64,30);
    buttonScaleMinus->setAutoRepeat(true);
    connect(buttonScaleMinus,SIGNAL(pressed()),this,SLOT(clicked_button_scale_minus()));

    buttonRotateClockwise = new QPushButton("↻",ui->graphicsViewButtons); // ROTATE CLOCKWISE
    buttonRotateClockwise->setGeometry(0,400,63,30);
    buttonRotateClockwise->setStyleSheet("font-size: 25px");
    buttonRotateClockwise->setAutoRepeat(true);
    connect(buttonRotateClockwise,SIGNAL(pressed()),this,SLOT(clicked_button_rotate_clockwise()));

    buttonRotateCounterClockwise = new QPushButton("↺",ui->graphicsViewButtons); //ROTATE COUNTERCLOCKWISE
    buttonRotateCounterClockwise->setGeometry(76,400,64,30);
    buttonRotateCounterClockwise->setStyleSheet("font-size: 25px");
    buttonRotateCounterClockwise->setAutoRepeat(true);
    connect(buttonRotateCounterClockwise,SIGNAL(pressed()),this,SLOT(clicked_button_rotate_counterclockwise()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::clicked_button_triangle()
{
    if(triangle==NULL){
    double randposx = rand()%200;
    double randposy = rand()%200;
    triangle = new Triangle{0,randposy,randposx,0,2*randposx,randposy};
    triangle->addTriangle(scene);
    }
}

void MainWindow::clicked_button_triangle_del()
{
    if(triangle!=NULL){
    triangle->removeTriangle(scene);
    delete triangle;
    triangle=NULL;
    chosen_moving=-1;
    }
}

void MainWindow::clicked_button_circle()
{
    if(circle==NULL){
    double randR = rand()%300;
    circle = new Circle{0,0,randR,randR};
    circle->addCircle(scene);
    }
}

void MainWindow::clicked_button_circle_del()
{
    if(circle!=NULL){
    circle->removeCirle(scene);
    delete circle;
    circle = NULL;
    chosen_moving=-1;
    }
}

void MainWindow::clicked_button_rectangle()
{
    if(rectangle==NULL){
        double randside1 = rand()%300;
        double randside2 = rand()%200;
        rectangle = new Rectangle{0,0,randside1,randside2};
        rectangle->addRectangle(scene);
    }
}

void MainWindow::clicked_button_rectangle_del()
{
    if(rectangle!=NULL){
        rectangle->removeRectangle(scene);
        delete rectangle;
        rectangle = NULL;
        chosen_moving=-1;
    }
}

void MainWindow::clicked_button_square()
{
    if(square==NULL){
        double randside1 = rand()%300;
        square = new Square{0,0,randside1,randside1};
        square->addRectangle(scene);
    }
}

void MainWindow::clicked_button_square_del()
{
    if(square!=NULL){
        square->removeRectangle(scene);
        delete square;
        square = NULL;
        chosen_moving=-1;
    }
}

void MainWindow::clicked_button_hexagon()
{
    if(hexagon==NULL){
        hexagon = new Hexagon(rand()%200);
        hexagon->addHexagon(scene);
    }
}

void MainWindow::clicked_button_hexagon_del()
{
    if(hexagon!=NULL){
        hexagon->removeHexagon(scene);
        delete hexagon;
        hexagon = NULL;
        chosen_moving=-1;
    }  
}

void MainWindow::clicked_button_fivepointedstar()
{
    if(fivepointedstar==NULL){
        fivepointedstar = new FivePointedStar(40,90);
        fivepointedstar->addStar(scene);
    }
}

void MainWindow::clicked_button_fivepointedstar_del()
{
    if(fivepointedstar!=NULL){
        fivepointedstar->removeStar(scene);
        delete fivepointedstar;
        fivepointedstar = NULL;
        chosen_moving=-1;
    }
}

void MainWindow::clicked_button_sixpointedstar()
{
    if(sixpointedstar==NULL){
        sixpointedstar = new SixPointedStar(40,90);
        sixpointedstar->addStar(scene);
    }
}

void MainWindow::clicked_button_sixpointedstar_del()
{
    if(sixpointedstar!=NULL){
        sixpointedstar->removeStar(scene);
        delete sixpointedstar;
        sixpointedstar = NULL;
        chosen_moving=-1;
    }
}

void MainWindow::clicked_button_eightpointedstar()
{
    if(eightpointedstar==NULL){
        eightpointedstar = new EightPointedStar(40,90);
        eightpointedstar->addStar(scene);
    }
}

void MainWindow::clicked_button_eightpointedstar_del()
{
    if(eightpointedstar!=NULL){
        eightpointedstar->removeStar(scene);
        delete eightpointedstar;
        eightpointedstar = NULL;
        chosen_moving=-1;
    }
}

void MainWindow::clicked_button_turn_left()
{
    switch(chosen_moving){
    case 0:
    triangle->moveTriangle(-10,0);
        break;
    case 1:
    circle->moveCircle(-10,0);
        break;
    case 2:
    rectangle->moveRectangle(-10,0);
        break;
    case 3:
    square->moveRectangle(-10,0);
        break;
    case 4:
    hexagon->moveHexagon(-10,0);
        break;
    case 5:
    fivepointedstar->moveStar(-10,0);
        break;
    case 6:
    sixpointedstar->moveStar(-10,0);
        break;
    case 7:
    eightpointedstar->moveStar(-10,0);
        break;
    }
}

void MainWindow::clicked_button_turn_right()
{
    switch(chosen_moving){
    case 0:
    triangle->moveTriangle(10,0);
        break;
    case 1:
    circle->moveCircle(10,0);
        break;
    case 2:
    rectangle->moveRectangle(10,0);
        break;
    case 3:
    square->moveRectangle(10,0);
        break;
    case 4:
    hexagon->moveHexagon(10,0);
        break;
    case 5:
    fivepointedstar->moveStar(10,0);
        break;
    case 6:
    sixpointedstar->moveStar(10,0);
        break;
    case 7:
    eightpointedstar->moveStar(10,0);
        break;
    }
}

void MainWindow::clicked_button_turn_up()
{
    switch(chosen_moving){
    case 0:
    triangle->moveTriangle(0,-10);
        break;
    case 1:
    circle->moveCircle(0,-10);
        break;
    case 2:
    rectangle->moveRectangle(0,-10);
        break;
    case 3:
    square->moveRectangle(0,-10);
        break;
    case 4:
    hexagon->moveHexagon(0,-10);
        break;
    case 5:
    fivepointedstar->moveStar(0,-10);
        break;
    case 6:
    sixpointedstar->moveStar(0,-10);
        break;
    case 7:
    eightpointedstar->moveStar(0,-10);
        break;
    }
}

void MainWindow::clicked_button_turn_down()
{
    switch(chosen_moving){
    case 0:
    triangle->moveTriangle(0,10);
        break;
    case 1:
    circle->moveCircle(0,10);
        break;
    case 2:
    rectangle->moveRectangle(0,10);
        break;
    case 3:
    square->moveRectangle(0,10);
        break;
    case 4:
    hexagon->moveHexagon(0,10);
        break;
    case 5:
    fivepointedstar->moveStar(0,10);
        break;
    case 6:
    sixpointedstar->moveStar(0,10);
        break;
    case 7:
    eightpointedstar->moveStar(0,10);
        break;
    }
}


void MainWindow::chose_box(int a)
{
    switch(a){
    case 0:
        if(triangle!=NULL)
            chosen_moving = 0;
        else chosen_moving = -1;
        break;
    case 1:
        if(circle!=NULL)
        chosen_moving = 1;
        else chosen_moving = -1;
        break;
    case 2:
        if(rectangle!=NULL)
        chosen_moving = 2;
        else chosen_moving = -1;
        break;
    case 3:
        if(square!=NULL)
        chosen_moving = 3;
        else chosen_moving = -1;
        break;
    case 4:
        if(hexagon!=NULL)
        chosen_moving = 4;
        else chosen_moving = -1;
        break;
    case 5:
        if(fivepointedstar!=NULL)
        chosen_moving =5;
        else chosen_moving = -1;
        break;
    case 6:
        if(sixpointedstar!=NULL)
        chosen_moving = 6;
        else chosen_moving = -1;
        break;
    case 7:
        if(eightpointedstar!=NULL)
        chosen_moving = 7;
        else chosen_moving = -1;
        break;
    }
}

void MainWindow::clicked_button_rotate_clockwise()
{
    switch(chosen_moving){
    case 0:
    triangle->rotateTriangle(5);
        break;
    case 1:
        break;
    case 2:
    rectangle->rotateRect(5);
        break;
    case 3:
    square->rotateRect(5);
        break;
    case 4:
    hexagon->rotateHex(5);
        break;
    case 5:
    fivepointedstar->rotateStar(5);
        break;
    case 6:
    sixpointedstar->rotateStar(5);
        break;
    case 7:
    eightpointedstar->rotateStar(5);
        break;
    }
}

void MainWindow::clicked_button_rotate_counterclockwise()
{
    switch(chosen_moving){
    case 0:
    triangle->rotateTriangle(-5);
        break;
    case 1:
        break;
    case 2:
    rectangle->rotateRect(-5);
        break;
    case 3:
    square->rotateRect(-5);
        break;
    case 4:
    hexagon->rotateHex(-5);
        break;
    case 5:
    fivepointedstar->rotateStar(-5);
        break;
    case 6:
    sixpointedstar->rotateStar(-5);
        break;
    case 7:
    eightpointedstar->rotateStar(-5);
        break;
    }
}

void MainWindow::clicked_button_scale_plus()
{
    switch(chosen_moving){
    case 0:
    triangle->scaleTriangle(0.05);
        break;
    case 1:
    circle->scaleCircle(0.05);
        break;
    case 2:
    rectangle->scaleRect(0.05);
        break;
    case 3:
    square->scaleRect(0.05);
        break;
    case 4:
    hexagon->scaleHex(0.05);
        break;
    case 5:
    fivepointedstar->scaleStar(0.05);
        break;
    case 6:
    sixpointedstar->scaleStar(0.05);
        break;
    case 7:
    eightpointedstar->scaleStar(0.05);
        break;
    }
}

void MainWindow::clicked_button_scale_minus()
{
    switch(chosen_moving){
    case 0:
    triangle->scaleTriangle(-0.01);
        break;
    case 1:
    circle->scaleCircle(-0.01);
        break;
    case 2:
    rectangle->scaleRect(-0.01);
        break;
    case 3:
    square->scaleRect(-0.01);
        break;
    case 4:
    hexagon->scaleHex(-0.01);
        break;
    case 5:
    fivepointedstar->scaleStar(-0.01);
        break;
    case 6:
    sixpointedstar->scaleStar(-0.01);
        break;
    case 7:
    eightpointedstar->scaleStar(-0.01);
        break;
    }
}

void MainWindow::clicked_button_show_info()
{
    QGridLayout* info = new QGridLayout;
    QWidget* window_info = new QWidget;
    window_info->resize(200,0);
    window_info->setWindowTitle("Info");
    QLabel* figure_t = new QLabel();
    QLabel* sq_t = new QLabel();
    QLabel* perimeter_t = new QLabel();

    switch(chosen_moving){
    case 0:
    figure_t->setText("Треугольник");
    sq_t->setNum(triangle->showFigureShape());
    perimeter_t->setNum(triangle->showFigurePerimetr());
        break;
    case 1:
    figure_t->setText("Круг");
    sq_t->setNum(circle->showFigureShape());
    perimeter_t->setNum(circle->showFigurePerimetr());
        break;
    case 2:
    figure_t->setText("Прямоугольник");
    sq_t->setNum(rectangle->showFigureShape());
    perimeter_t->setNum(rectangle->showFigurePerimetr());
        break;
    case 3:
    figure_t->setText("Квадрат");
    sq_t->setNum(square->showFigureShape());
    perimeter_t->setNum(square->showFigurePerimetr());
        break;
    case 4:
    figure_t->setText("Шестиугольник");
    sq_t->setNum(hexagon->showFigureShape());
    perimeter_t->setNum(hexagon->showFigurePerimetr());
        break;
    case 5:
    figure_t->setText("Пятиугольная звезда");
    sq_t->setNum(fivepointedstar->showFigureShape());
    perimeter_t->setNum(fivepointedstar->showFigurePerimetr());
        break;
    case 6:
    figure_t->setText("Шестиугольаная звезда");
    sq_t->setNum(sixpointedstar->showFigureShape());
    perimeter_t->setNum(sixpointedstar->showFigurePerimetr());
        break;
    case 7:
    figure_t->setText("Восьмиугольная звезда");
    sq_t->setNum(eightpointedstar->showFigureShape());
    perimeter_t->setNum(eightpointedstar->showFigurePerimetr());
        break;
}

    info->addWidget(new QLabel("Фигура"),1,0);
    info->addWidget(figure_t,1,1);
    info->addWidget(new QLabel("Площадь"), 2, 0);
    info->addWidget(sq_t,2,1);
    info->addWidget(new QLabel("Периметр"), 3, 0);
    info->addWidget(perimeter_t,3,1);
    window_info->setLayout(info);
    window_info->show();


}



void MainWindow::on_CanvasButton_clicked()
{
    Canvas = !Canvas;
    button_Canva->setDisabled(true);
    RightClicked = false;
    if (!Canvas){
        FirstP = false;
    }

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(Canvas)
    {
        if (event->button() == Qt::LeftButton && !RightClicked){
            if (FirstP){
                scene->addLine(PreviousPoint.x() - 559,PreviousPoint.y() - 306, event->pos().x() - 559, event->pos().y() - 306, QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
            }
            else{
                scene->addEllipse(event->pos().x() - 562,event->pos().y() - 308, 4, 4, QPen(Qt::NoPen), QBrush(Qt::black));
                FirstPoint.rx() = event->pos().x();
                FirstPoint.ry() = event->pos().y();
            }
            FirstP = true;
            PreviousPoint = event->pos();
        }
        if (event->button() == Qt::RightButton){
            RightClicked = true;
            scene->addLine(PreviousPoint.x() - 559,PreviousPoint.y() - 306, FirstPoint.rx() - 559, FirstPoint.ry() - 306, QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
            button_Canva->setDisabled(false);
            Canvas = !Canvas;

            FirstP = false;
        }
    }
    if (event->button() == Qt::MiddleButton){
        on_CanvasButton_clicked();
    }
}




