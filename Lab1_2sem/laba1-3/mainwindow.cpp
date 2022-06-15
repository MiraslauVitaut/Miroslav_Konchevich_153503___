#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->datesd->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->datesd->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getBirthday_userDateChanged(const QDate &date)
{
    Date birthday = Date(date.year(), date.month(), date.day());
    QDate today = today.currentDate();
    Date td = Date(today.year(), today.month(), today.day());
    ui->number->setText(QString::number(td.DaysTillYourBithday(birthday)));
}

void MainWindow::on_openFile_clicked()
{
    dates.clear();
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
    for(int i =0;!in.atEnd();i++){
        QString line = in.readLine();

        if(line==""||line==" "){
            dates.clear();
            QMessageBox::critical(this,"Error", "Files or data are not correct");
            return;
        }else{
        QDate date = date.fromString(line, "dd.MM.yyyy");
        dates.push_back(Date(date.year(), date.month(), date.day()));
        qDebug()<<date.toString("dd.MM.yyyy");
        if(date.toString()==""||date==QDate::fromString("01.01.0001","dd.MM.yyyy")){
            dates.clear();
            QMessageBox::critical(this,"Error", "Files or data are not correct");
            return;
        }
    }
    }
    file.close();
    ui->datesd->setRowCount(dates.size());
    ui->datesd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i = 0; i < dates.size(); ++i) {
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem((dates[i].IsLeap() ? QString("Yes") : QString("No"))));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
    }
    for (int i = 0; i < dates.size() - 1&&dates.size()!=0; ++i) {
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(dates[i + 1]))));
    }
    qDebug() << dates.size();
}


void MainWindow::on_AddDate_clicked()
{
    QDate d = ui->getDay->date();
    dates.push_back(Date(d.year(), d.month(), d.day()));
    ui->datesd->setRowCount(dates.size());
    for(int i = 0; i < dates.size(); ++i){
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem((dates[i].IsLeap() ? QString("Yes") : QString("No"))));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
    }
    for (int i = 0; i < dates.size() - 1; ++i) {
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(dates[i+1]))));
    }
    QFile file("date.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            return;
    QTextStream out(&file);
    out << dates[dates.size()-1].ToString() << '\n';
}

void MainWindow::on_ChangeDate_clicked()
{
    if(!dates.size()){
        return;
    }
    if (ui->NumDate->text().toInt() > dates.size() || ui->NumDate->text().toInt() <= 0){
        return;
    }
    QDate d = ui->getDay2->date();
    dates[ui->NumDate->text().toInt() - 1] = Date(d.year(), d.month(), d.day());
    ui->datesd->setRowCount(dates.size());
    for(int i = 0; i < dates.size(); ++i){
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem((dates[i].IsLeap() ? QString("Yes") : QString("No"))));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
    }
    for (int i = 0; i < dates.size() - 1; ++i) {
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(dates[i+1]))));
    }
    QFile file("date.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            return;
    QTextStream out(&file);
    out.seek((ui->NumDate->text().toInt() - 1) * 11);
    out << dates[ui->NumDate->text().toInt() - 1].ToString();
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QTextStream out(&file);
    for (int i = 0; i < dates.size(); ++i){
        out << dates[i].ToString() << '\n';
    }
    file.flush();
    file.close();
}
