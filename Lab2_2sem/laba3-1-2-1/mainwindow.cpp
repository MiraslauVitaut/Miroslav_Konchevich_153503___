#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineName->setDisabled(true);
    ui->linePatronymic->setDisabled(true);
    ui->lineSurname->setDisabled(true);
    ui->spinLanguage->setDisabled(true);
    ui->spinMath->setDisabled(true);
    ui->spinPhysics->setDisabled(true);
    ui->pushButtonAdd->setDisabled(true);
    ui->pushButtonShow->setDisabled(true);
    ui->pushButtonSave->setDisabled(true);
    ui->pushButtonShowAvegare->setDisabled(true);
    ui->pushButtonSearch->setDisabled(true);
    ui->lineSearch->setDisabled(true);
    ui->pushButtonSort->setDisabled(true);

    QPushButton *ok;
    msg = new QMessageBox;
    msg->setIcon(QMessageBox::Information);
    msg->setWindowTitle("Abitur finded");
    msg->setText("Abiturient finded but he wasn't on the exam");
    msg->setInformativeText("Delete him?");
    ok = msg->addButton("Delete", QMessageBox::AcceptRole);
    msg->addButton("Cancel", QMessageBox::RejectRole);
    connect(ok,SIGNAL(clicked()),this,SLOT(on_pushButtonDelete()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonOpen_clicked()
{
    file.setFileName(QFileDialog::getOpenFileName(this, tr("Open txt"), "//", tr("txt files (*.txt)")));

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
                return;

    if(file.isOpen()) qDebug() << "File is open";
    else  qDebug() << "File nono open";

    bool error=false;
    QTextStream in(&file);
    list = new DoubleList();
    for(int i =0;!in.atEnd();i++){
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if(fields.size()!=6){
            error = true;
            break;
        }
        if(fields[3].toInt()>10||fields[3].toInt()<0||fields[4].toInt()>10||fields[4].toInt()<0||fields[5].toInt()>10||fields[5].toInt()<0){
            error = true;
            break;
        }
        list->push_back(fields[0],fields[1],fields[2],fields[3].toInt(),fields[4].toInt(),fields[5].toInt());
    }
    if(error){
        delete list;
        QMessageBox::critical(this,"Error", "Files or data are not correct");
        file.close();
    }else{
        ui->pushButtonAdd->setDisabled(false);
        ui->pushButtonShow->setDisabled(false);
        ui->pushButtonSave->setDisabled(false);
        ui->pushButtonOpen->setDisabled(true);
        ui->pushButtonShowAvegare->setDisabled(false);
        ui->pushButtonSearch->setDisabled(false);
        ui->lineSearch->setDisabled(false);
        ui->pushButtonSort->setDisabled(false);
    }
}


void MainWindow::on_pushButtonShow_clicked()
{
    ui->displayInfo->setText(list->print()+"GPA: "+ QString::number(list->getAverageMarks()));
}


void MainWindow::on_pushButtonShowAvegare_clicked()
{
    ui->displayInfo->setText(list->printAverage());
}


void MainWindow::on_pushButtonSave_clicked()
{
    QTextStream out(&file);
    file.resize(0);

    out<<list->printinfile();
}


void MainWindow::on_pushButtonSort_clicked()
{
   if(list->is_empty()) return;
   list->qSort();
}


void MainWindow::on_pushButtonAdd_clicked()
{
    if(addPress){
        list->push_back("","","",0,0,0);
        ui->lineName->setDisabled(false);
        ui->linePatronymic->setDisabled(false);
        ui->lineSurname->setDisabled(false);
        ui->spinLanguage->setDisabled(false);
        ui->spinMath->setDisabled(false);
        ui->spinPhysics->setDisabled(false);
        ui->pushButtonAdd->setDisabled(false);
        ui->pushButtonShow->setDisabled(false);
        ui->pushButtonSave->setDisabled(false);
        ui->pushButtonSearch->setDisabled(true);
        ui->lineSearch->setDisabled(true);
        ui->pushButtonShow->setDisabled(true);
        ui->pushButtonShowAvegare->setDisabled(true);
        ui->pushButtonSort->setDisabled(true);
        ui->pushButtonSave->setDisabled(true);
        ui->lineName->setText("");
        ui->linePatronymic->setText("");
        ui->lineSurname->setText("");
        ui->spinMath->setValue(0);
        ui->spinLanguage->setValue(0);
        ui->spinPhysics->setValue(0);

    addPress = false;
    }else if(list->isErr()){

        QMessageBox::critical(this,"Error", "Data not correct");

    }else{
        ui->lineName->setDisabled(true);
        ui->linePatronymic->setDisabled(true);
        ui->lineSurname->setDisabled(true);
        ui->spinLanguage->setDisabled(true);
        ui->spinMath->setDisabled(true);
        ui->spinPhysics->setDisabled(true);
        ui->pushButtonAdd->setDisabled(false);
        ui->pushButtonShowAvegare->setDisabled(false);
        ui->pushButtonShow->setDisabled(false);
        ui->pushButtonSave->setDisabled(false);
        ui->pushButtonSort->setDisabled(false);
        ui->pushButtonSearch->setDisabled(false);
        ui->lineSearch->setDisabled(false);
        addPress = true;
    }
}


void MainWindow::on_pushButtonSearch_clicked()
{
    std::vector<Node> listSurname = list->arraySurname(search);
    for(size_t i=0;i<listSurname.size();i++){
    Node p = listSurname[i];
    if(p.language==0&&p.math==0&&p.physics==0){
        numbdel = p.index;
        msg->show();
    }
}
    if(listSurname.size()!=0)
    ui->displayInfo->setText(list->print_search(search));
    else
        QMessageBox::information(this,"Messege", "Abiturient not found");
}


void MainWindow::on_lineSearch_textChanged(const QString &arg1)
{
    search = arg1;
}


void MainWindow::on_lineName_textChanged(const QString &arg1)
{
    list->setLastName(arg1);
}


void MainWindow::on_lineSurname_textChanged(const QString &arg1)
{
    list->setLastSurname(arg1);
}


void MainWindow::on_linePatronymic_textChanged(const QString &arg1)
{
    list->setLastPatronymic(arg1);
}


void MainWindow::on_spinMath_valueChanged(int arg1)
{
    list->setLastMath(arg1);
}


void MainWindow::on_spinPhysics_valueChanged(int arg1)
{
    list->setLastPhysics(arg1);
}


void MainWindow::on_spinLanguage_valueChanged(int arg1)
{
    list->setLastLanguage(arg1);
}

void MainWindow::on_pushButtonDelete()
{
    list->remove(numbdel);
}

