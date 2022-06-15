#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>

#include "stack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isCorrect();
    double getValue(QChar val);
    QString readLine(QString str);
    double getAnswer(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QString infix;
    QString postfix;
    double answer;

};
#endif // MAINWINDOW_H
