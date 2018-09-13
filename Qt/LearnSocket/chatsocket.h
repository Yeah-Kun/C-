#ifndef CHATSOCKET_H
#define CHATSOCKET_H

#include <QMainWindow>

namespace Ui {
class ChatSocket;
}

class ChatSocket : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatSocket(QWidget *parent = 0);
    ~ChatSocket();

private:
    Ui::ChatSocket *ui;
};

#endif // CHATSOCKET_H
