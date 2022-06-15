/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QTextEdit *InformationText;
    QTextEdit *MainText;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QPushButton *FileButton;
    QPushButton *SaveButton;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QPushButton *VariablesButton;
    QPushButton *FuncButton;
    QPushButton *LocalVarButton;
    QPushButton *ClassesButton;
    QGridLayout *gridLayout_3;
    QPushButton *BranchButton;
    QPushButton *ErrorsButton;
    QPushButton *OperatorButton;
    QPushButton *EditButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(942, 630);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 751, 491));
        gridLayout_6 = new QGridLayout(layoutWidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 1, 1, 1);

        InformationText = new QTextEdit(layoutWidget);
        InformationText->setObjectName(QString::fromUtf8("InformationText"));

        gridLayout->addWidget(InformationText, 0, 1, 1, 1);

        MainText = new QTextEdit(layoutWidget);
        MainText->setObjectName(QString::fromUtf8("MainText"));

        gridLayout->addWidget(MainText, 0, 0, 2, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        FileButton = new QPushButton(layoutWidget);
        FileButton->setObjectName(QString::fromUtf8("FileButton"));

        verticalLayout->addWidget(FileButton);

        SaveButton = new QPushButton(layoutWidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        verticalLayout->addWidget(SaveButton);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        VariablesButton = new QPushButton(layoutWidget);
        VariablesButton->setObjectName(QString::fromUtf8("VariablesButton"));

        gridLayout_2->addWidget(VariablesButton, 0, 0, 1, 1);

        FuncButton = new QPushButton(layoutWidget);
        FuncButton->setObjectName(QString::fromUtf8("FuncButton"));

        gridLayout_2->addWidget(FuncButton, 0, 1, 1, 1);

        LocalVarButton = new QPushButton(layoutWidget);
        LocalVarButton->setObjectName(QString::fromUtf8("LocalVarButton"));

        gridLayout_2->addWidget(LocalVarButton, 1, 0, 1, 1);

        ClassesButton = new QPushButton(layoutWidget);
        ClassesButton->setObjectName(QString::fromUtf8("ClassesButton"));

        gridLayout_2->addWidget(ClassesButton, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        BranchButton = new QPushButton(layoutWidget);
        BranchButton->setObjectName(QString::fromUtf8("BranchButton"));

        gridLayout_3->addWidget(BranchButton, 0, 0, 1, 1);

        ErrorsButton = new QPushButton(layoutWidget);
        ErrorsButton->setObjectName(QString::fromUtf8("ErrorsButton"));

        gridLayout_3->addWidget(ErrorsButton, 0, 1, 1, 1);

        OperatorButton = new QPushButton(layoutWidget);
        OperatorButton->setObjectName(QString::fromUtf8("OperatorButton"));

        gridLayout_3->addWidget(OperatorButton, 1, 0, 1, 1);

        EditButton = new QPushButton(layoutWidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));

        gridLayout_3->addWidget(EditButton, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 942, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Parser", nullptr));
        FileButton->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        SaveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        VariablesButton->setText(QCoreApplication::translate("MainWindow", "Variables", nullptr));
        FuncButton->setText(QCoreApplication::translate("MainWindow", "Functions", nullptr));
        LocalVarButton->setText(QCoreApplication::translate("MainWindow", "LocalVar", nullptr));
        ClassesButton->setText(QCoreApplication::translate("MainWindow", "Classes", nullptr));
        BranchButton->setText(QCoreApplication::translate("MainWindow", "Branching", nullptr));
        ErrorsButton->setText(QCoreApplication::translate("MainWindow", "Errors", nullptr));
        OperatorButton->setText(QCoreApplication::translate("MainWindow", "Operator", nullptr));
        EditButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
