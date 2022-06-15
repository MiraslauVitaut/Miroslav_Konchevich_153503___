#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include "doublelistabitura.h"
#include <QMessageBox>


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

    void on_pushButtonAdd_clicked();

    void on_lineName_textChanged(const QString &arg1);

    void on_lineSurname_textChanged(const QString &arg1);

    void on_linePatronymic_textChanged(const QString &arg1);

    void on_spinMath_valueChanged(int arg1);

    void on_spinPhysics_valueChanged(int arg1);

    void on_spinLanguage_valueChanged(int arg1);

    void on_pushButtonShowAvegare_clicked();

    void on_lineSearch_textChanged(const QString &arg1);

    void on_pushButtonSearch_clicked();

    void on_pushButtonDelete();

    void on_pushButtonSave_clicked();

    void on_pushButtonSort_clicked();

private:
    Ui::MainWindow *ui;
    QFile file;
    listAbitura *list;
    bool addPress=true;
    QString search="";
    QMessageBox* msg;
    NodeAbitura *numbdel;
};
#endif // MAINWINDOW_H
