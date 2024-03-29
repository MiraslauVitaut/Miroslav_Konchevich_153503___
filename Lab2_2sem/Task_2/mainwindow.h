#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void LoadFromFile(QFile &file);

private slots:
    void on_CheckString_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMap <QString, QString> Bracket_List = {
        {"(", ")"},
        {"[", "]"},
        {"{", "}"},
    };
};
#endif // MAINWINDOW_H
