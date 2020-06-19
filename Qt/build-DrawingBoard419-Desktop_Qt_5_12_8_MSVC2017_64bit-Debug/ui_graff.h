/********************************************************************************
** Form generated from reading UI file 'graff.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFF_H
#define UI_GRAFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graff
{
public:
    QLabel *label;
    QPushButton *setColor;
    QPushButton *ButtonClear;

    void setupUi(QWidget *graff)
    {
        if (graff->objectName().isEmpty())
            graff->setObjectName(QString::fromUtf8("graff"));
        graff->resize(1287, 757);
        label = new QLabel(graff);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1030, 440, 72, 41));
        setColor = new QPushButton(graff);
        setColor->setObjectName(QString::fromUtf8("setColor"));
        setColor->setGeometry(QRect(1130, 440, 93, 41));
        ButtonClear = new QPushButton(graff);
        ButtonClear->setObjectName(QString::fromUtf8("ButtonClear"));
        ButtonClear->setGeometry(QRect(1070, 250, 93, 41));

        retranslateUi(graff);

        QMetaObject::connectSlotsByName(graff);
    } // setupUi

    void retranslateUi(QWidget *graff)
    {
        graff->setWindowTitle(QApplication::translate("graff", "Form", nullptr));
        label->setText(QApplication::translate("graff", "\347\224\273\347\254\224\351\242\234\350\211\262\357\274\232", nullptr));
        setColor->setText(QApplication::translate("graff", "\344\277\256\346\224\271", nullptr));
        ButtonClear->setText(QApplication::translate("graff", "\346\270\205\347\251\272\347\224\273\346\235\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graff: public Ui_graff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFF_H
