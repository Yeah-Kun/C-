#include "chatsocket.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatSocket w;
    w.show();

    return a.exec();
}
