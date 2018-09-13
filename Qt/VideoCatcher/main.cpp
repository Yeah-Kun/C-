#include "videocatcher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VideoCatcher w;
    w.show();

    return a.exec();
}
