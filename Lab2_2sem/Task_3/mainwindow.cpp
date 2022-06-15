#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(200, 370);
    setWindowTitle("Polish Write");

    ui->InputExpr->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-e | +-/*()]{255}$")));

    ui->input_A->setRange(-10000, 10000);
    ui->input_B->setRange(-10000, 10000);
    ui->input_C->setRange(-10000, 10000);
    ui->input_D->setRange(-10000, 10000);
    ui->input_E->setRange(-10000, 10000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!isCorrect()){
        QMessageBox::critical(this, "Error", "Incorrect input!");
        return;
    }

    QString ans = readLine(ui->InputExpr->text());
    qDebug() << ans;
    ui->OPZ->setText(ans);
    ui->answer->setText(QString::number(getAnswer(ans)));

}
bool MainWindow::isCorrect() {

    infix = ui->InputExpr->text();
    QString expression = infix;

    if(expression[0] == '+' || expression[0] == '-' || expression[0] == '/' || expression[0] == '*' || expression[0] == ')'){
        return false;
    }

    int bracket = 0;
    for (int i = 0; i < expression.size(); i++)
        if (expression[i] == '(')
            bracket++;
         else if (expression[i] == ')')
            bracket--;

    if (bracket != 0)
        return false;

    if (expression.size() == 0)
        return false;

    for (int i = 0; i < expression.size(); i++) {

        QChar c = expression[i];
        if (!(c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')' ||
              ('a' <= c && c <= 'e')))
            return false;

        if (i + 1 < expression.size()) {
            QChar next = expression[i + 1];
            if (c >= 'a' && c <= 'e' && ((next >= 'a' && next <= 'e') || next == '('))
                return false;
        }
    }

    return true;
}

double MainWindow::getValue(QChar val){
    if(val == 'a')
        return ui->input_A->value();

    if(val == 'b')
        return ui->input_B->value();

    if(val == 'c')
        return ui->input_C->value();

    if(val == 'd')
        return ui->input_D->value();

    if(val == 'e')
        return ui->input_E->value();

    return 0;
}

double MainWindow::getAnswer(QString str){
    NumStack stack;

    for (int i = 0; i < str.length() ; i++ ) {
        if(str[i].isLetter()){
            stack.push(getValue(str[i]));
        }
        else{
            double secondTmp = stack.eraseValue();

            double firstTmp = stack.eraseValue();

            if(str[i] == '+')
                stack.push(firstTmp+secondTmp);
            else if(str[i] == '-')
                stack.push(firstTmp-secondTmp);
            else if(str[i] == '*')
                stack.push(firstTmp*secondTmp);
            else
                stack.push(firstTmp/secondTmp);
        }
    }

    double tmp = stack.answer();

    return tmp;
}

QString MainWindow::readLine(QString str){
    str.remove(' ');

    StrStack stack;
    QString newStr;

    for(int i = 0; i < str.length();i++){

        if(str[i].isLetter()){
            newStr.push_back(str[i]);
        }      
        else{
            if(str[i] == '(' ){
                stack.push(str[i]);
                continue;
            }
            if(str[i] == ')' ){
                newStr.push_back(stack.returnPrev(str[i]));
                continue;
            }

            newStr.push_back(stack.returnPrev(str[i]));
            stack.push(str[i]);
        }
    }

    newStr.push_back(stack.returnLasts());

    return newStr;
}
