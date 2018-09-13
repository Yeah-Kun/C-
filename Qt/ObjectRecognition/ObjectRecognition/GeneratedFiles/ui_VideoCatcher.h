/********************************************************************************
** Form generated from reading UI file 'VideoCatcher.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOCATCHER_H
#define UI_VIDEOCATCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoCatcher
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *selectLabel;
    QComboBox *selectCamera;
    QPushButton *openCamera;
    QPushButton *startVideo;
    QPushButton *stopVideo;
    QPushButton *closeCamera;

    void setupUi(QWidget *VideoCatcher)
    {
        if (VideoCatcher->objectName().isEmpty())
            VideoCatcher->setObjectName(QStringLiteral("VideoCatcher"));
        VideoCatcher->resize(1601, 776);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoCatcher->sizePolicy().hasHeightForWidth());
        VideoCatcher->setSizePolicy(sizePolicy);
        horizontalLayoutWidget_2 = new QWidget(VideoCatcher);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(200, 0, 1391, 641));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        selectLabel = new QLabel(VideoCatcher);
        selectLabel->setObjectName(QStringLiteral("selectLabel"));
        selectLabel->setGeometry(QRect(20, 10, 91, 31));
        selectCamera = new QComboBox(VideoCatcher);
        selectCamera->addItem(QString());
        selectCamera->addItem(QString());
        selectCamera->setObjectName(QStringLiteral("selectCamera"));
        selectCamera->setGeometry(QRect(40, 40, 111, 31));
        openCamera = new QPushButton(VideoCatcher);
        openCamera->setObjectName(QStringLiteral("openCamera"));
        openCamera->setGeometry(QRect(50, 120, 93, 28));
        startVideo = new QPushButton(VideoCatcher);
        startVideo->setObjectName(QStringLiteral("startVideo"));
        startVideo->setGeometry(QRect(40, 350, 121, 28));
        stopVideo = new QPushButton(VideoCatcher);
        stopVideo->setObjectName(QStringLiteral("stopVideo"));
        stopVideo->setGeometry(QRect(40, 400, 121, 31));
        closeCamera = new QPushButton(VideoCatcher);
        closeCamera->setObjectName(QStringLiteral("closeCamera"));
        closeCamera->setGeometry(QRect(50, 170, 93, 28));

        retranslateUi(VideoCatcher);

        QMetaObject::connectSlotsByName(VideoCatcher);
    } // setupUi

    void retranslateUi(QWidget *VideoCatcher)
    {
        VideoCatcher->setWindowTitle(QApplication::translate("VideoCatcher", "\350\247\206\351\242\221\345\275\225\345\210\266", nullptr));
        label->setText(QString());
        selectLabel->setText(QApplication::translate("VideoCatcher", "\351\200\211\346\213\251\346\221\204\345\203\217\345\244\264\357\274\232", nullptr));
        selectCamera->setItemText(0, QApplication::translate("VideoCatcher", "\350\207\252\345\270\246\346\221\204\345\203\217\345\244\264", nullptr));
        selectCamera->setItemText(1, QApplication::translate("VideoCatcher", "\345\244\226\346\216\245\346\221\204\345\203\217\345\244\264", nullptr));

        openCamera->setText(QApplication::translate("VideoCatcher", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        startVideo->setText(QApplication::translate("VideoCatcher", "\345\274\200\345\247\213\345\275\225\345\203\217", nullptr));
        stopVideo->setText(QApplication::translate("VideoCatcher", "\345\201\234\346\255\242\345\275\225\345\203\217", nullptr));
        closeCamera->setText(QApplication::translate("VideoCatcher", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoCatcher: public Ui_VideoCatcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOCATCHER_H
