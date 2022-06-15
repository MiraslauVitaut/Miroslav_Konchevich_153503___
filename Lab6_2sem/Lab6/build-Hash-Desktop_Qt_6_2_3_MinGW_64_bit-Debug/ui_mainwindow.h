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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QSpinBox *addSpinBox;
    QPushButton *deleteButton;
    QSpinBox *deleteSpinBox;
    QWidget *widget1;
    QGridLayout *gridLayout_3;
    QPushButton *maxButton;
    QLineEdit *maxLine;
    QSpinBox *fillSpinBox;
    QPushButton *fillButton;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QPushButton *clearButton;
    QLabel *label;
    QLabel *amountLabel;
    QPushButton *findButton;
    QSpinBox *findSpinBox;
    QWidget *widget3;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *findLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(832, 488);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(11, 12, 801, 311));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(16, 336, 214, 67));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(widget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        addSpinBox = new QSpinBox(widget);
        addSpinBox->setObjectName(QString::fromUtf8("addSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addSpinBox->sizePolicy().hasHeightForWidth());
        addSpinBox->setSizePolicy(sizePolicy);
        addSpinBox->setMinimum(-2000000000);
        addSpinBox->setMaximum(2000000000);

        gridLayout->addWidget(addSpinBox, 0, 1, 1, 1);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 1, 0, 1, 1);

        deleteSpinBox = new QSpinBox(widget);
        deleteSpinBox->setObjectName(QString::fromUtf8("deleteSpinBox"));
        sizePolicy.setHeightForWidth(deleteSpinBox->sizePolicy().hasHeightForWidth());
        deleteSpinBox->setSizePolicy(sizePolicy);
        deleteSpinBox->setMinimum(-2000000000);
        deleteSpinBox->setMaximum(2000000000);

        gridLayout->addWidget(deleteSpinBox, 1, 1, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(460, 340, 321, 67));
        gridLayout_3 = new QGridLayout(widget1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        maxButton = new QPushButton(widget1);
        maxButton->setObjectName(QString::fromUtf8("maxButton"));

        gridLayout_3->addWidget(maxButton, 1, 0, 1, 2);

        maxLine = new QLineEdit(widget1);
        maxLine->setObjectName(QString::fromUtf8("maxLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(maxLine->sizePolicy().hasHeightForWidth());
        maxLine->setSizePolicy(sizePolicy1);
        maxLine->setReadOnly(true);

        gridLayout_3->addWidget(maxLine, 1, 2, 1, 1);

        fillSpinBox = new QSpinBox(widget1);
        fillSpinBox->setObjectName(QString::fromUtf8("fillSpinBox"));
        sizePolicy.setHeightForWidth(fillSpinBox->sizePolicy().hasHeightForWidth());
        fillSpinBox->setSizePolicy(sizePolicy);
        fillSpinBox->setMinimum(0);
        fillSpinBox->setMaximum(1000);

        gridLayout_3->addWidget(fillSpinBox, 0, 2, 1, 1);

        fillButton = new QPushButton(widget1);
        fillButton->setObjectName(QString::fromUtf8("fillButton"));

        gridLayout_3->addWidget(fillButton, 0, 0, 1, 2);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(238, 337, 214, 67));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        clearButton = new QPushButton(widget2);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout_2->addWidget(clearButton, 0, 0, 1, 1);

        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        amountLabel = new QLabel(widget2);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));

        gridLayout_2->addWidget(amountLabel, 0, 2, 1, 1);

        findButton = new QPushButton(widget2);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        gridLayout_2->addWidget(findButton, 1, 0, 1, 1);

        findSpinBox = new QSpinBox(widget2);
        findSpinBox->setObjectName(QString::fromUtf8("findSpinBox"));
        sizePolicy.setHeightForWidth(findSpinBox->sizePolicy().hasHeightForWidth());
        findSpinBox->setSizePolicy(sizePolicy);
        findSpinBox->setMinimum(-2000000000);
        findSpinBox->setMaximum(2000000000);

        gridLayout_2->addWidget(findSpinBox, 1, 1, 1, 2);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(240, 410, 81, 22));
        gridLayout_4 = new QGridLayout(widget3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        findLabel = new QLabel(widget3);
        findLabel->setObjectName(QString::fromUtf8("findLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(findLabel->sizePolicy().hasHeightForWidth());
        findLabel->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(findLabel, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 832, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hash", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        maxButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274 (\320\274\320\276\320\271 \320\262\320\260\321\200)", nullptr));
        fillButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262:", nullptr));
        amountLabel->setText(QString());
        findButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "BOOL:", nullptr));
        findLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
