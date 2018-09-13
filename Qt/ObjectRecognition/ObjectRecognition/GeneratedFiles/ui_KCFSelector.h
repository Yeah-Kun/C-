/********************************************************************************
** Form generated from reading UI file 'KCFSelector.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KCFSELECTOR_H
#define UI_KCFSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KCFSelector
{
public:
    QLabel *show_label;
    QPushButton *select_btn;
    QPushButton *load_video_btn;
    QPushButton *output_video_btn;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QRadioButton *camera_radbtn;
    QRadioButton *file_radbtn;

    void setupUi(QWidget *KCFSelector)
    {
        if (KCFSelector->objectName().isEmpty())
            KCFSelector->setObjectName(QStringLiteral("KCFSelector"));
        KCFSelector->resize(1092, 614);
        show_label = new QLabel(KCFSelector);
        show_label->setObjectName(QStringLiteral("show_label"));
        show_label->setGeometry(QRect(0, 30, 641, 571));
        select_btn = new QPushButton(KCFSelector);
        select_btn->setObjectName(QStringLiteral("select_btn"));
        select_btn->setGeometry(QRect(800, 50, 121, 41));
        load_video_btn = new QPushButton(KCFSelector);
        load_video_btn->setObjectName(QStringLiteral("load_video_btn"));
        load_video_btn->setGeometry(QRect(800, 290, 121, 51));
        output_video_btn = new QPushButton(KCFSelector);
        output_video_btn->setObjectName(QStringLiteral("output_video_btn"));
        output_video_btn->setGeometry(QRect(800, 370, 121, 51));
        comboBox = new QComboBox(KCFSelector);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(800, 200, 121, 21));
        groupBox = new QGroupBox(KCFSelector);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(800, 100, 120, 80));
        camera_radbtn = new QRadioButton(groupBox);
        camera_radbtn->setObjectName(QStringLiteral("camera_radbtn"));
        camera_radbtn->setGeometry(QRect(20, 20, 101, 19));
        camera_radbtn->setChecked(true);
        file_radbtn = new QRadioButton(groupBox);
        file_radbtn->setObjectName(QStringLiteral("file_radbtn"));
        file_radbtn->setGeometry(QRect(20, 50, 115, 19));

        retranslateUi(KCFSelector);

        QMetaObject::connectSlotsByName(KCFSelector);
    } // setupUi

    void retranslateUi(QWidget *KCFSelector)
    {
        KCFSelector->setWindowTitle(QApplication::translate("KCFSelector", "KCF\350\257\206\345\210\253\345\231\250", nullptr));
        show_label->setText(QString());
        select_btn->setText(QApplication::translate("KCFSelector", "\351\200\211\346\213\251ROI\345\214\272\345\237\237", nullptr));
        load_video_btn->setText(QApplication::translate("KCFSelector", "\345\212\240\350\275\275\350\247\206\351\242\221", nullptr));
        output_video_btn->setText(QApplication::translate("KCFSelector", "\350\276\223\345\207\272\347\273\223\346\236\234", nullptr));
        comboBox->setItemText(0, QApplication::translate("KCFSelector", "KCF\350\257\206\345\210\253\345\231\250", nullptr));
        comboBox->setItemText(1, QApplication::translate("KCFSelector", "Camshift\350\257\206\345\210\253\345\231\250", nullptr));

        groupBox->setTitle(QApplication::translate("KCFSelector", "\350\247\206\351\242\221\346\265\201", nullptr));
        camera_radbtn->setText(QApplication::translate("KCFSelector", "\346\221\204\345\203\217\345\244\264\350\247\206\351\242\221\346\265\201", nullptr));
        file_radbtn->setText(QApplication::translate("KCFSelector", "\346\226\207\344\273\266\350\247\206\351\242\221\346\265\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KCFSelector: public Ui_KCFSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KCFSELECTOR_H
