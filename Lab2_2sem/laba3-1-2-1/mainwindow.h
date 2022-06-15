#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <doublelist.h>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE







class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOpen_clicked();

    void on_pushButtonShow_clicked();

    void on_pushButtonShowAvegare_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonSort_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonSearch_clicked();

    void on_lineSearch_textChanged(const QString &arg1);

    void on_lineName_textChanged(const QString &arg1);

    void on_lineSurname_textChanged(const QString &arg1);

    void on_linePatronymic_textChanged(const QString &arg1);

    void on_spinMath_valueChanged(int arg1);

    void on_spinPhysics_valueChanged(int arg1);

    void on_spinLanguage_valueChanged(int arg1);

    void on_pushButtonDelete();

private:
    Ui::MainWindow *ui;
    DoubleList *list;
    int numbdel;
    QFile file;
    QString search="";
    bool addPress=true;
    QMessageBox* msg;
};
#endif // MAINWINDOW_H
