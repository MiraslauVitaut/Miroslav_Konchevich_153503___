#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(500, 250);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CheckString_clicked()
{

        QVector<QString> openBrackets = {"(", "{", "["};
        QVector<QString> closeBrackets = {")","}", "]"};
        QMap<QString, QString> bracketsPairs {{"(", ")"}, {"{", "}"}, {"[", "]"}};
        QVector<QString> brackets;

        QString text = ui->lineEdit->toPlainText();

        int lineCounter = 1;
        int symbols = 0;
        for (int i = 0; i < text.size(); i++) {
            symbols++;
            if (text[i] == '\n'){
                lineCounter++;
                symbols = 0;
            }

            if (openBrackets.indexOf(text[i]) >= 0)
                brackets.push_back(text[i]);

            if (closeBrackets.indexOf(text[i]) >= 0) {
                if (!brackets.isEmpty() && bracketsPairs.key(text[i]) == brackets.back())
                    brackets.pop_back();
                else {
                    QDialog* window = new QDialog;
                    window->setWindowTitle("Failure");
                    window->setWindowFlags(Qt::Window | Qt::Tool);

                    QGridLayout* statusLay = new QGridLayout;

                    statusLay->addWidget(new QLabel("line: "), 0, 0);
                    QLabel* line = new QLabel;
                    line->setText(QString::number(lineCounter) + ", " + QString::number(symbols));// + ", "
                                 // + QString::number(symbols));
                    statusLay->addWidget(line, 0, 1);

                    window->setFixedSize(100,70);
                    window->setLayout(statusLay);
                    window->show();
                    window->activateWindow();

                    return;
                }
            }

        }

        if (!brackets.isEmpty()) {
            QDialog* window = new QDialog;
            window->setWindowTitle("Failure");
            window->setWindowFlags(Qt::Window | Qt::Tool);

            QGridLayout* statusLay = new QGridLayout;

            statusLay->addWidget(new QLabel("line: "), 0, 0);
            QLabel* line = new QLabel;
            line->setText(QString::number(lineCounter)  + ", "
                          + QString::number(symbols));
            statusLay->addWidget(line, 0, 1);

            window->setFixedSize(100,70);
            window->setLayout(statusLay);
            window->show();
            window->activateWindow();;
            return;
        }

        QDialog* window = new QDialog;
        window->setWindowTitle("Success");
        window->setWindowFlags(Qt::Window | Qt::Tool);

        QGridLayout* statusLay = new QGridLayout;

        statusLay->addWidget(new QLabel("Success: "), 0, 0);

        window->setFixedSize(100,70);
        window->setLayout(statusLay);
        window->show();
        window->activateWindow();;
        return;
}

void MainWindow::LoadFromFile(QFile &file)
{
    if(!file.open(QIODevice::ReadWrite)){
        qWarning()<< "Cannot open File";
        return ;
    }

    QTextStream stream(&file);
    stream.seek(0);


    QString str;
    while(!stream.atEnd()){
        str = stream.readLine();
    }
    file.close();


    ui->lineEdit->setPlainText(str);

}
void MainWindow::on_pushButton_clicked()
{
    QString new_file = "";
    new_file = QFileDialog::getOpenFileName(this, tr("Open"), "C://", "All files(*.txt*)");

    QFile file = new_file;
    LoadFromFile(file);
}

