/********************************************************************************
** Form generated from reading UI file 'ObjectCatcher.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTCATCHER_H
#define UI_OBJECTCATCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectCatcher
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_13;
    QSlider *minHueSlider;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QSlider *maxHueSlider;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QSlider *minSatSlider;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QSlider *maxSatSlider;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_17;
    QSlider *minValSlider;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QSlider *maxValSlider;
    QHBoxLayout *horizontalLayout;
    QLabel *OrigFrame;
    QLabel *RecoFrame;

    void setupUi(QWidget *ObjectCatcher)
    {
        if (ObjectCatcher->objectName().isEmpty())
            ObjectCatcher->setObjectName(QStringLiteral("ObjectCatcher"));
        ObjectCatcher->resize(1200, 630);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ObjectCatcher->sizePolicy().hasHeightForWidth());
        ObjectCatcher->setSizePolicy(sizePolicy);
        ObjectCatcher->setMinimumSize(QSize(1200, 630));
        horizontalLayout_2 = new QHBoxLayout(ObjectCatcher);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_13 = new QLabel(ObjectCatcher);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_9->addWidget(label_13);

        minHueSlider = new QSlider(ObjectCatcher);
        minHueSlider->setObjectName(QStringLiteral("minHueSlider"));
        minHueSlider->setMaximum(255);
        minHueSlider->setOrientation(Qt::Horizontal);
        minHueSlider->setTickPosition(QSlider::TicksAbove);
        minHueSlider->setTickInterval(256);

        horizontalLayout_9->addWidget(minHueSlider);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_12 = new QLabel(ObjectCatcher);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_10->addWidget(label_12);

        maxHueSlider = new QSlider(ObjectCatcher);
        maxHueSlider->setObjectName(QStringLiteral("maxHueSlider"));
        maxHueSlider->setMaximum(255);
        maxHueSlider->setValue(255);
        maxHueSlider->setSliderPosition(255);
        maxHueSlider->setOrientation(Qt::Horizontal);
        maxHueSlider->setInvertedAppearance(false);
        maxHueSlider->setInvertedControls(false);
        maxHueSlider->setTickPosition(QSlider::TicksAbove);
        maxHueSlider->setTickInterval(255);

        horizontalLayout_10->addWidget(maxHueSlider);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout_14->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_15 = new QLabel(ObjectCatcher);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_11->addWidget(label_15);

        minSatSlider = new QSlider(ObjectCatcher);
        minSatSlider->setObjectName(QStringLiteral("minSatSlider"));
        minSatSlider->setMaximum(255);
        minSatSlider->setOrientation(Qt::Horizontal);
        minSatSlider->setTickPosition(QSlider::TicksAbove);
        minSatSlider->setTickInterval(256);

        horizontalLayout_11->addWidget(minSatSlider);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_14 = new QLabel(ObjectCatcher);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_8->addWidget(label_14);

        maxSatSlider = new QSlider(ObjectCatcher);
        maxSatSlider->setObjectName(QStringLiteral("maxSatSlider"));
        maxSatSlider->setMaximum(256);
        maxSatSlider->setValue(255);
        maxSatSlider->setOrientation(Qt::Horizontal);
        maxSatSlider->setTickPosition(QSlider::TicksAbove);
        maxSatSlider->setTickInterval(256);

        horizontalLayout_8->addWidget(maxSatSlider);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_14->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_17 = new QLabel(ObjectCatcher);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_13->addWidget(label_17);

        minValSlider = new QSlider(ObjectCatcher);
        minValSlider->setObjectName(QStringLiteral("minValSlider"));
        minValSlider->setMaximum(255);
        minValSlider->setOrientation(Qt::Horizontal);
        minValSlider->setTickPosition(QSlider::TicksAbove);
        minValSlider->setTickInterval(256);

        horizontalLayout_13->addWidget(minValSlider);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_16 = new QLabel(ObjectCatcher);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_12->addWidget(label_16);

        maxValSlider = new QSlider(ObjectCatcher);
        maxValSlider->setObjectName(QStringLiteral("maxValSlider"));
        maxValSlider->setMaximum(255);
        maxValSlider->setPageStep(10);
        maxValSlider->setValue(255);
        maxValSlider->setOrientation(Qt::Horizontal);
        maxValSlider->setTickPosition(QSlider::TicksAbove);
        maxValSlider->setTickInterval(256);

        horizontalLayout_12->addWidget(maxValSlider);


        verticalLayout_3->addLayout(horizontalLayout_12);


        horizontalLayout_14->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        OrigFrame = new QLabel(ObjectCatcher);
        OrigFrame->setObjectName(QStringLiteral("OrigFrame"));

        horizontalLayout->addWidget(OrigFrame);

        RecoFrame = new QLabel(ObjectCatcher);
        RecoFrame->setObjectName(QStringLiteral("RecoFrame"));

        horizontalLayout->addWidget(RecoFrame);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 5);

        horizontalLayout_2->addLayout(verticalLayout_4);


        retranslateUi(ObjectCatcher);

        QMetaObject::connectSlotsByName(ObjectCatcher);
    } // setupUi

    void retranslateUi(QWidget *ObjectCatcher)
    {
        ObjectCatcher->setWindowTitle(QApplication::translate("ObjectCatcher", "\347\233\256\346\240\207\350\257\206\345\210\253", nullptr));
        label_13->setText(QApplication::translate("ObjectCatcher", "\346\234\200\345\260\217\350\211\262\350\260\203\357\274\232", nullptr));
        label_12->setText(QApplication::translate("ObjectCatcher", "\346\234\200\345\244\247\350\211\262\350\260\203\357\274\232", nullptr));
        label_15->setText(QApplication::translate("ObjectCatcher", "\346\234\200\345\260\217\351\245\261\345\222\214\345\272\246\357\274\232", nullptr));
        label_14->setText(QApplication::translate("ObjectCatcher", "\346\234\200\345\244\247\351\245\261\345\222\214\345\272\246\357\274\232", nullptr));
        label_17->setText(QApplication::translate("ObjectCatcher", "\346\234\200\345\260\217\344\272\256\345\272\246\357\274\232", nullptr));
        label_16->setText(QApplication::translate("ObjectCatcher", "\346\234\200\345\244\247\344\272\256\345\272\246\357\274\232", nullptr));
        OrigFrame->setText(QApplication::translate("ObjectCatcher", "\346\240\241\345\207\206\345\233\276", nullptr));
        RecoFrame->setText(QApplication::translate("ObjectCatcher", "\350\257\206\345\210\253\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ObjectCatcher: public Ui_ObjectCatcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTCATCHER_H
