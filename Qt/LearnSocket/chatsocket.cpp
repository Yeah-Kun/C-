#include "chatsocket.h"
#include "ui_chatsocket.h"

ChatSocket::ChatSocket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatSocket)
{
    ui->setupUi(this);
}

ChatSocket::~ChatSocket()
{
    delete ui;
}
