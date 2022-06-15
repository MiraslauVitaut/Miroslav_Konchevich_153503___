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
#include <vector>
#include <QMessageBox>
#include "receipts.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showText();

private slots:
    void on_buttton_openFile_clicked();

    void on_button_add_clicked();

    void on_lineType_textChanged(const QString &arg1);

    void on_dataAcc_dateTimeChanged(const QDateTime &dateTime);

    void on_BoxRec_activated(int index);

    void on_dataEx_dateTimeChanged(const QDateTime &dateTime);

    void on_lineBrand_textChanged(const QString &arg1);

    void on_button_save_clicked();

    void on_lineReady_textChanged(const QString &arg1);

    void on_button_delete_clicked();

    void on_button_close_clicked();

    void on_button_notComplInTime_clicked();

    void on_button_sort_clicked();

    void on_button_ready_clicked();

    void on_BoxRecSearch_activated(int index);

    void on_lineSearch_textChanged(const QString &arg1);

    void on_dateSearch_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::MainWindow *ui;
    QFile file;
    QVector <Receipts> list;
    int boxrec=-1;
    int boxrecsearch = -1;
};
#endif // MAINWINDOW_H
