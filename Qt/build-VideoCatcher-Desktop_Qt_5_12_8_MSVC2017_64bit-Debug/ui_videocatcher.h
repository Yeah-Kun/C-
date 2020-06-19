/********************************************************************************
** Form generated from reading UI file 'videocatcher.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOCATCHER_H
#define UI_VIDEOCATCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoCatcher
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VideoCatcher)
    {
        if (VideoCatcher->objectName().isEmpty())
            VideoCatcher->setObjectName(QString::fromUtf8("VideoCatcher"));
        VideoCatcher->resize(400, 300);
        menuBar = new QMenuBar(VideoCatcher);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        VideoCatcher->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VideoCatcher);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VideoCatcher->addToolBar(mainToolBar);
        centralWidget = new QWidget(VideoCatcher);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        VideoCatcher->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(VideoCatcher);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VideoCatcher->setStatusBar(statusBar);

        retranslateUi(VideoCatcher);

        QMetaObject::connectSlotsByName(VideoCatcher);
    } // setupUi

    void retranslateUi(QMainWindow *VideoCatcher)
    {
        VideoCatcher->setWindowTitle(QApplication::translate("VideoCatcher", "VideoCatcher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoCatcher: public Ui_VideoCatcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOCATCHER_H
