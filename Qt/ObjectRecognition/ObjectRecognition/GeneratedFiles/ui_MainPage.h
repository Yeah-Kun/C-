/********************************************************************************
** Form generated from reading UI file 'MainPage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPageClass
{
public:
    QAction *action_2;
    QAction *action_4;
    QAction *action_5;
    QAction *video;
    QAction *action_6;
    QAction *action_7;
    QAction *color_selector;
    QAction *KCF_selector;
    QAction *action_ROI;
    QAction *tracking;
    QAction *test_VideoProcessor;
    QAction *VideoProcessor;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_5;
    QMenu *menu_3;
    QMenu *menu_6;
    QMenu *menu_4;
    QMenu *menu_7;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *fileDock;
    QWidget *dockWidgetContents;
    QTreeView *treeView;
    QDockWidget *consoleDock;
    QWidget *dockWidgetContents_2;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *MainPageClass)
    {
        if (MainPageClass->objectName().isEmpty())
            MainPageClass->setObjectName(QStringLiteral("MainPageClass"));
        MainPageClass->resize(1578, 852);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainPageClass->sizePolicy().hasHeightForWidth());
        MainPageClass->setSizePolicy(sizePolicy);
        MainPageClass->setIconSize(QSize(32, 32));
        action_2 = new QAction(MainPageClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_4 = new QAction(MainPageClass);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(MainPageClass);
        action_5->setObjectName(QStringLiteral("action_5"));
        video = new QAction(MainPageClass);
        video->setObjectName(QStringLiteral("video"));
        action_6 = new QAction(MainPageClass);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_7 = new QAction(MainPageClass);
        action_7->setObjectName(QStringLiteral("action_7"));
        color_selector = new QAction(MainPageClass);
        color_selector->setObjectName(QStringLiteral("color_selector"));
        KCF_selector = new QAction(MainPageClass);
        KCF_selector->setObjectName(QStringLiteral("KCF_selector"));
        action_ROI = new QAction(MainPageClass);
        action_ROI->setObjectName(QStringLiteral("action_ROI"));
        tracking = new QAction(MainPageClass);
        tracking->setObjectName(QStringLiteral("tracking"));
        test_VideoProcessor = new QAction(MainPageClass);
        test_VideoProcessor->setObjectName(QStringLiteral("test_VideoProcessor"));
        VideoProcessor = new QAction(MainPageClass);
        VideoProcessor->setObjectName(QStringLiteral("VideoProcessor"));
        centralWidget = new QWidget(MainPageClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(11, 11, 1461, 660));
        mdiArea->setMinimumSize(QSize(1200, 660));
        QBrush brush(QColor(160, 160, 160, 255));
        brush.setStyle(Qt::SolidPattern);
        mdiArea->setBackground(brush);
        mdiArea->setActivationOrder(QMdiArea::CreationOrder);
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);
        mdiArea->setTabShape(QTabWidget::Triangular);
        MainPageClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainPageClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1578, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_5 = new QMenu(menu_2);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_6 = new QMenu(menu_3);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_7 = new QMenu(menuBar);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        MainPageClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainPageClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainPageClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainPageClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainPageClass->setStatusBar(statusBar);
        fileDock = new QDockWidget(MainPageClass);
        fileDock->setObjectName(QStringLiteral("fileDock"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        treeView = new QTreeView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(-20, 0, 161, 631));
        treeView->setMinimumSize(QSize(160, 630));
        fileDock->setWidget(dockWidgetContents);
        MainPageClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), fileDock);
        consoleDock = new QDockWidget(MainPageClass);
        consoleDock->setObjectName(QStringLiteral("consoleDock"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        plainTextEdit = new QPlainTextEdit(dockWidgetContents_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(-7, -4, 1581, 121));
        consoleDock->setWidget(dockWidgetContents_2);
        MainPageClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), consoleDock);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_7->menuAction());
        menu->addAction(action_4);
        menu->addAction(action_5);
        menu_2->addAction(menu_5->menuAction());
        menu_5->addAction(action_6);
        menu_5->addAction(action_7);
        menu_3->addAction(video);
        menu_3->addAction(menu_6->menuAction());
        menu_3->addAction(tracking);
        menu_3->addAction(action_2);
        menu_6->addAction(color_selector);
        menu_6->addAction(KCF_selector);
        menu_4->addAction(action_ROI);
        menu_7->addAction(VideoProcessor);

        retranslateUi(MainPageClass);

        QMetaObject::connectSlotsByName(MainPageClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainPageClass)
    {
        MainPageClass->setWindowTitle(QApplication::translate("MainPageClass", "\345\234\260\351\235\242\347\253\231", nullptr));
        action_2->setText(QApplication::translate("MainPageClass", "\347\233\256\346\240\207\346\265\213\350\267\235", nullptr));
        action_4->setText(QApplication::translate("MainPageClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        action_5->setText(QApplication::translate("MainPageClass", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        video->setText(QApplication::translate("MainPageClass", "\350\247\206\351\242\221\345\275\225\345\210\266", nullptr));
#ifndef QT_NO_SHORTCUT
        video->setShortcut(QApplication::translate("MainPageClass", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        action_6->setText(QApplication::translate("MainPageClass", "\345\206\205\347\275\256\346\221\204\345\203\217\345\244\264", nullptr));
        action_7->setText(QApplication::translate("MainPageClass", "\345\244\226\351\203\250\346\221\204\345\203\217\345\244\264", nullptr));
        color_selector->setText(QApplication::translate("MainPageClass", "\351\242\234\350\211\262\350\257\206\345\210\253\345\231\250", nullptr));
        KCF_selector->setText(QApplication::translate("MainPageClass", "KCF\350\257\206\345\210\253\345\231\250", nullptr));
        action_ROI->setText(QApplication::translate("MainPageClass", "\351\200\211\346\213\251ROI", nullptr));
        tracking->setText(QApplication::translate("MainPageClass", "\347\233\256\346\240\207\350\267\237\350\270\252", nullptr));
        test_VideoProcessor->setText(QApplication::translate("MainPageClass", "VideoProcessor", nullptr));
        VideoProcessor->setText(QApplication::translate("MainPageClass", "test_VideoProcessor", nullptr));
        menu->setTitle(QApplication::translate("MainPageClass", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainPageClass", "\350\256\276\347\275\256", nullptr));
        menu_5->setTitle(QApplication::translate("MainPageClass", "\351\200\211\346\213\251\346\221\204\345\203\217\345\244\264", nullptr));
        menu_3->setTitle(QApplication::translate("MainPageClass", "\345\212\237\350\203\275", nullptr));
        menu_6->setTitle(QApplication::translate("MainPageClass", "\347\233\256\346\240\207\350\257\206\345\210\253", nullptr));
        menu_4->setTitle(QApplication::translate("MainPageClass", "\345\267\245\345\205\267", nullptr));
        menu_7->setTitle(QApplication::translate("MainPageClass", "\346\265\213\350\257\225", nullptr));
        fileDock->setWindowTitle(QApplication::translate("MainPageClass", "\346\226\207\344\273\266", nullptr));
        consoleDock->setWindowTitle(QApplication::translate("MainPageClass", "\350\276\223\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPageClass: public Ui_MainPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
