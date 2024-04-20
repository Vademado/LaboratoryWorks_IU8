/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(749, 170);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Dialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 0, 1, 2);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217:", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "3) \320\222 \320\277\320\276\320\273\320\265 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202. \320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203\"", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "1) \320\222 \320\277\320\276\320\273\320\265 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260 \"\320\237\321\203\321\202\321\214 \320\272 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\216\" \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 \320\267\320\260\320\277\321\203\321\211\320\265\320\275\320\275\320\276\320\271 \321\201\321\202\320\276\321\200\320\276\320\275\320\275\320\265\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213. ", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "2) \320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
