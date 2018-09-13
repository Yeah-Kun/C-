#include "subject.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    subject w;
    w.show();

    return a.exec();
}
