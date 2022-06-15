#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    setFixedSize(810,600);

    srand(time(0));
    for (int i = 0; i < 64 ;++i ) {

         tree.push(QPair<int, QString>(i, "Tree"));
    }

//     tree.push(QPair<int, QString>(7, "V AD IM"));
//      tree.push(QPair<int, QString>(3, "V AD IM"));
//       tree.push(QPair<int, QString>(1, "V AD IM"));
//        tree.push(QPair<int, QString>(-5, "V AD IM"));
//        tree.push(QPair<int, QString>(0, "V AD IM"));
//        tree.push(QPair<int, QString>(0, "V AD IM"));
//        tree.push(QPair<int, QString>(0, "V AD IM"));
//        tree.push(QPair<int, QString>(0, "V AD IM"));
//        tree.push(QPair<int, QString>(0, "V AD IM"));
//        tree.push(QPair<int, QString>(0, "V AD IM"));

    tree.prNode();
    tree.bp();
    ui->MainText->setText(tree.print_str());

    ui->RemoveSpinBox->setRange(1,35000);
    ui->SearchSpinBox->setRange(1,35000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_clicked()
{
      srand(time(0));
    tree.push(QPair<int,QString>(16,":D"));
    ui->MainText->clear();
    tree.StrZero();
    ui->MainText->setText(tree.print_str());
}

void MainWindow::on_RemoveButton_clicked()
{
    tree.pop(ui->RemoveSpinBox->value());
    ui->MainText->clear();
    tree.StrZero();
    ui->MainText->setText(tree.print_str());
}

void MainWindow::on_ChildrenButton_clicked()
{
    ui->MainText->clear();
    tree.StrZero();
    ui->MainText->setText(tree.pr_children());
    tree.ChildrenZero();
}

void MainWindow::on_ViewButton_clicked()
{
    ui->MainText->clear();
    tree.StrZero();
    ui->MainText->setText(tree.print_str());
}

void MainWindow::on_SearchButton_clicked()
{

    ui->MainText->clear();
    tree.StrZero();
    ui->MainText->setText(tree.searching(ui->SearchSpinBox->value()));
}

