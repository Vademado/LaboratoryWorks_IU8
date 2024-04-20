/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *MainWindow_2;
    QGridLayout *gridLayout;
    QPushButton *pushButtonCompleteTask;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QTextEdit *textEditInputText;
    QPushButton *pushButtonSelectApplication;
    QComboBox *comboBoxProgramPath;
    QLabel *labelProgramPath;
    QLabel *labelFilePath;
    QPushButton *pushButtonSelectFile;
    QLineEdit *lineEditFilePath;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow_2 = new QWidget(MainWindow);
        MainWindow_2->setObjectName("MainWindow_2");
        gridLayout = new QGridLayout(MainWindow_2);
        gridLayout->setObjectName("gridLayout");
        pushButtonCompleteTask = new QPushButton(MainWindow_2);
        pushButtonCompleteTask->setObjectName("pushButtonCompleteTask");
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        pushButtonCompleteTask->setFont(font);

        gridLayout->addWidget(pushButtonCompleteTask, 3, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 4);

        pushButton = new QPushButton(MainWindow_2);
        pushButton->setObjectName("pushButton");
        QFont font1;
        font1.setBold(true);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 6, 3, 1, 1);

        textEditInputText = new QTextEdit(MainWindow_2);
        textEditInputText->setObjectName("textEditInputText");

        gridLayout->addWidget(textEditInputText, 0, 0, 1, 4);

        pushButtonSelectApplication = new QPushButton(MainWindow_2);
        pushButtonSelectApplication->setObjectName("pushButtonSelectApplication");
        pushButtonSelectApplication->setFont(font);

        gridLayout->addWidget(pushButtonSelectApplication, 1, 3, 1, 1);

        comboBoxProgramPath = new QComboBox(MainWindow_2);
        comboBoxProgramPath->setObjectName("comboBoxProgramPath");

        gridLayout->addWidget(comboBoxProgramPath, 1, 1, 1, 2);

        labelProgramPath = new QLabel(MainWindow_2);
        labelProgramPath->setObjectName("labelProgramPath");
        labelProgramPath->setMinimumSize(QSize(141, 16));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setItalic(false);
        labelProgramPath->setFont(font2);

        gridLayout->addWidget(labelProgramPath, 1, 0, 1, 1);

        labelFilePath = new QLabel(MainWindow_2);
        labelFilePath->setObjectName("labelFilePath");
        labelFilePath->setFont(font1);

        gridLayout->addWidget(labelFilePath, 2, 0, 1, 1);

        pushButtonSelectFile = new QPushButton(MainWindow_2);
        pushButtonSelectFile->setObjectName("pushButtonSelectFile");
        pushButtonSelectFile->setFont(font1);

        gridLayout->addWidget(pushButtonSelectFile, 2, 3, 1, 1);

        lineEditFilePath = new QLineEdit(MainWindow_2);
        lineEditFilePath->setObjectName("lineEditFilePath");

        gridLayout->addWidget(lineEditFilePath, 2, 1, 1, 1);

        MainWindow->setCentralWidget(MainWindow_2);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonCompleteTask->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        pushButtonSelectApplication->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        labelProgramPath->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\216:", nullptr));
        labelFilePath->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:", nullptr));
        pushButtonSelectFile->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
