#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button_add->setDisabled(true);
    ui->button_delete->setDisabled(true);
    ui->button_save->setDisabled(true);
    ui->button_close->setDisabled(true);
    ui->button_notComplInTime->setDisabled(true);
    ui->button_sort->setDisabled(true);
    ui->lineType->setDisabled(true);
    ui->lineBrand->setDisabled(true);
    ui->lineReady->setDisabled(true);
    ui->dataAcc->setDisabled(true);
    ui->dataEx->setDisabled(true);
    ui->dateSearch->setDisabled(true);
    ui->lineSearch->setDisabled(true);
    ui->BoxRecSearch->setDisabled(true);
    ui->button_ready->setDisabled(true);
}

void MainWindow::showText()
{
    QString textinfo;
    for(int i =0;i<list.size();i++)
    {
        textinfo+= QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
        ui->displayInfo->setText(textinfo);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttton_openFile_clicked()
{
    file.setFileName(QFileDialog::getOpenFileName(this,
    tr("Open txt"), "//", tr("txt files (*.txt)")));

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
                return;

    if(file.isOpen()) qDebug() << "File is open";
    else  qDebug() << "File nono open";

    bool error=false;
    QTextStream in(&file);
    QString textinfo="";
    for(int i =0;!in.atEnd();i++)
    {
        QString l1,l2,l3,l4,l5;
        list.push_back(Receipts());
        l1 = in.readLine();
        l2 = in.readLine();
        l3 = in.readLine();
        l4 = in.readLine();
        l5 = in.readLine();
        if(l1==""||l2==""||l3==""||l4==""||l5==""||l1==" "||l2==" "||l3==" "||l4==" "||l5==" ")
            error = true;
        else
        {
        list[i].SetInfo(l1,l2,l3,l4,l5);
        list[i].showInfo();
        if(list[i].getAcceptanceDate().toString()==""||list[i].getExecutionDate().toString()=="")
            error=true;
        in.readLine();
        textinfo+= QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
        ui->BoxRec->addItem(QString::number(i+1));
        }
    }
    if(error)
    {
        list.clear();
        ui->BoxRec->clear();
        QMessageBox::critical(this,"Error", "Files or data are not correct");
        file.close();
    }
    else
    {
    ui->buttton_openFile->setDisabled(true);
    ui->button_add->setDisabled(false);
    ui->button_save->setDisabled(false);
    ui->button_close->setDisabled(false);
    ui->button_notComplInTime->setDisabled(false);
    ui->button_sort->setDisabled(false);
    ui->BoxRecSearch->setDisabled(false);
    ui->button_ready->setDisabled(false);
    ui->displayInfo->setText(textinfo);
    }
}


void MainWindow::on_button_add_clicked()
{
    list.push_back(Receipts());
    ui->BoxRec->addItem(QString::number(ui->BoxRec->count()+1));
    showText();
}


void MainWindow::on_lineType_textChanged(const QString &arg1)
{
    if(boxrec!=-1)
    {
        list[boxrec].setType(arg1);
        showText();
    }
}


void MainWindow::on_dataAcc_dateTimeChanged(const QDateTime &dateTime)
{
    if(boxrec!=-1){
        list[boxrec].setAcceptanceDate(dateTime);
        showText();
    }
}

void MainWindow::on_dataEx_dateTimeChanged(const QDateTime &dateTime)
{
    if(boxrec!=-1)
    {
        list[boxrec].setExecutionDate(dateTime);
        showText();
    }
}

void MainWindow::on_lineBrand_textChanged(const QString &arg1)
{
    if(boxrec!=-1)
    {
        list[boxrec].setBrand(arg1);
        showText();
    }
}

void MainWindow::on_BoxRec_activated(int index)
{
    ui->lineType->setDisabled(false);
    ui->lineBrand->setDisabled(false);
    ui->lineReady->setDisabled(false);
    ui->dataAcc->setDisabled(false);
    ui->dataEx->setDisabled(false);
    boxrec = index;
    ui->lineType->setText(list[index].getType());
    ui->lineBrand->setText(list[index].getBrand());
    ui->dataAcc->setDateTime(list[index].getAcceptanceDate());
    ui->dataEx->setDateTime(list[index].getExecutionDate());
    ui->lineReady->setText(list[index].getReady_n_y());
    ui->button_delete->setDisabled(false);
}

void MainWindow::on_button_save_clicked()
{
    QTextStream out(&file);
    file.resize(0);
    for(int i =0;i<list.size();i++){
        out<<list[i].saveInfo()<<"\n";
    }
}


void MainWindow::on_lineReady_textChanged(const QString &arg1)
{
    if(boxrec!=-1){
        list[boxrec].setReady_n_y(arg1);
        showText();
    }
}


void MainWindow::on_button_delete_clicked()
{
    list.erase(list.begin()+boxrec);
    boxrec = -1;
    ui->displayInfo->setText("");
    ui->lineType->setText("");
    ui->lineBrand->setText("");
    ui->dataAcc->setDateTime(QDateTime::fromString("01.01.2000","dd.MM.yyyy"));
    ui->dataEx->setDateTime(QDateTime::fromString("01.01.2000","dd.MM.yyyy"));
    ui->lineReady->setText("");
    ui->BoxRec->clear();
    for(int i=0;i<list.size();i++)
        ui->BoxRec->addItem(QString::number(i+1));
    showText();
    ui->lineType->setDisabled(true);
    ui->lineBrand->setDisabled(true);
    ui->lineReady->setDisabled(true);
    ui->dataAcc->setDisabled(true);
    ui->dataEx->setDisabled(true);
    ui->button_delete->setDisabled(true);
}


void MainWindow::on_button_close_clicked()
{
    file.close();
    list.clear();
    ui->BoxRec->clear();
    ui->button_add->setDisabled(true);
    ui->button_delete->setDisabled(true);
    ui->button_save->setDisabled(true);
    ui->button_close->setDisabled(true);
    ui->buttton_openFile->setDisabled(false);
    ui->button_notComplInTime->setDisabled(true);
    ui->button_sort->setDisabled(true);
    ui->button_ready->setDisabled(true);
    ui->BoxRecSearch->setDisabled(true);
    ui->lineSearch->setDisabled(true);
    ui->dateSearch->setDisabled(true);
    boxrec = -1;
    ui->displayInfo->setText("");
    ui->lineType->setText("");
    ui->lineBrand->setText("");
    ui->dataAcc->setDateTime(QDateTime::fromString("01.01.2000","dd.MM.yyyy"));
    ui->dataEx->setDateTime(QDateTime::fromString("01.01.2000","dd.MM.yyyy"));
    ui->lineReady->setText("");
}


void MainWindow::on_button_notComplInTime_clicked()
{
    QString info="Not comleted on time:\n";
    for(int i=0;i<list.size();i++){
        if(list[i].getReady_n_y()=="Не готово"&&list[i].getExecutionDate()<QDateTime::currentDateTime())
            info+=QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
    }
    ui->displayInfo->setText(info);
}


void MainWindow::on_button_sort_clicked()
{
    for(int i = 1; i < list.size(); ++i)
    {
        for(int r = 0; r < list.size()-i; r++)
        {
            if(list[r].getExecutionDate() < list[r+1].getExecutionDate())
            {
                Receipts temp = list[r];
                list[r] = list[r+1];
                list[r+1] = temp;
            }
        }
    }
    showText();
}

void MainWindow::on_button_ready_clicked()
{
    QString info="Readiness:\n";
    for(int i=0;i<list.size();i++){
            info+=QString::number(i+1) + ". "+list[i].getType()+" "+list[i].getReady_n_y()+"\n";
    }
    ui->displayInfo->setText(info);
}





void MainWindow::on_BoxRecSearch_activated(int index)
{
    boxrecsearch = index;
    if(index<=1){
        ui->lineSearch->setDisabled(false);
        ui->dateSearch->setDisabled(true);
    }else{
        ui->lineSearch->setDisabled(true);
        ui->dateSearch->setDisabled(false);
    }
}


void MainWindow::on_lineSearch_textChanged(const QString &arg1)
{
    QString info="Search:\n";
    if(arg1==""){
        for(int i =0;i<list.size();i++){
            info+= QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
            ui->displayInfo->setText(info);
        }
    }else{
    for(int i=0;i<list.size();i++){
        if(boxrecsearch==0&&list[i].getType()==arg1)
            info+=QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
        else if(boxrecsearch==1&&list[i].getBrand()==arg1)
            info+=QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
    }
    }
    ui->displayInfo->setText(info);
}


void MainWindow::on_dateSearch_dateTimeChanged(const QDateTime &dateTime)
{
    QString info="Search:\n";
    if(dateTime==QDateTime::fromString("01.01.2000","dd.MM.yyyy")){
        for(int i =0;i<list.size();i++){
            info+= QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
            ui->displayInfo->setText(info);
        }
    }else{
        for(int i=0;i<list.size();i++){
            if(boxrecsearch==2&&list[i].getAcceptanceDate()==dateTime)
                info+=QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
            else if(boxrecsearch==3&&list[i].getExecutionDate()==dateTime)
                info+=QString::number(i+1) + ". "+list[i].showInfoDisplay()+"\n";
        }
        }
        ui->displayInfo->setText(info);
}

