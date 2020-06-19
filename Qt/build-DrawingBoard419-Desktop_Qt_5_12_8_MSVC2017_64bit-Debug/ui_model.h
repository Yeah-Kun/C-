/********************************************************************************
** Form generated from reading UI file 'model.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_H
#define UI_MODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_model
{
public:
    QTextBrowser *textBrowser;
    QCheckBox *isEditModel;
    QPushButton *saveModel;
    QPushButton *loadModel;
    QPushButton *cleanbtn;
    QPushButton *setCenter;
    QPushButton *selectImg;

    void setupUi(QWidget *model)
    {
        if (model->objectName().isEmpty())
            model->setObjectName(QString::fromUtf8("model"));
        model->resize(1316, 766);
        textBrowser = new QTextBrowser(model);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(1050, 30, 211, 121));
        isEditModel = new QCheckBox(model);
        isEditModel->setObjectName(QString::fromUtf8("isEditModel"));
        isEditModel->setGeometry(QRect(1110, 170, 91, 41));
        saveModel = new QPushButton(model);
        saveModel->setObjectName(QString::fromUtf8("saveModel"));
        saveModel->setGeometry(QRect(1090, 460, 141, 51));
        loadModel = new QPushButton(model);
        loadModel->setObjectName(QString::fromUtf8("loadModel"));
        loadModel->setGeometry(QRect(1090, 520, 141, 51));
        cleanbtn = new QPushButton(model);
        cleanbtn->setObjectName(QString::fromUtf8("cleanbtn"));
        cleanbtn->setGeometry(QRect(220, 630, 331, 51));
        setCenter = new QPushButton(model);
        setCenter->setObjectName(QString::fromUtf8("setCenter"));
        setCenter->setGeometry(QRect(1110, 220, 93, 61));
        selectImg = new QPushButton(model);
        selectImg->setObjectName(QString::fromUtf8("selectImg"));
        selectImg->setGeometry(QRect(1110, 310, 93, 41));

        retranslateUi(model);

        QMetaObject::connectSlotsByName(model);
    } // setupUi

    void retranslateUi(QWidget *model)
    {
        model->setWindowTitle(QApplication::translate("model", "Form", nullptr));
        textBrowser->setHtml(QApplication::translate("model", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\275\277\347\224\250\350\257\264\346\230\216\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; vertical-align:middle;\">1. \345\215\225\345\207\273\357\274\232\351\200\211\344\270\255\347\202\271 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205"
                        "\351\273\221'; vertical-align:middle;\">2. \345\217\214\345\207\273\345\217\263\351\224\256\357\274\232\345\242\236\345\212\240\351\241\266\347\202\271 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; vertical-align:middle;\">3. \351\225\277\346\214\211\345\267\246\351\224\256\357\274\232\346\213\226\345\212\250\347\202\271 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; vertical-align:middle;\">4. \345\217\214\345\207\273\345\267\246\351\224\256\357\274\232\345\210\240\351\231\244\351\241\266\347\202\271</span></p></body></html>", nullptr));
        isEditModel->setText(QApplication::translate("model", "\347\274\226\350\276\221\346\250\241\345\236\213", nullptr));
        saveModel->setText(QApplication::translate("model", "\344\277\235\345\255\230\346\250\241\345\236\213", nullptr));
        loadModel->setText(QApplication::translate("model", "\345\212\240\350\275\275\346\250\241\345\236\213", nullptr));
        cleanbtn->setText(QApplication::translate("model", "\346\270\205\347\251\272\347\224\273\346\235\277", nullptr));
        setCenter->setText(QApplication::translate("model", "\350\256\276\347\275\256\344\270\255\345\277\203", nullptr));
        selectImg->setText(QApplication::translate("model", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class model: public Ui_model {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_H
