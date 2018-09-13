#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived())); // 当数据来的时候，触发readyRead信号，从而接收数据
    connect(this, SIGNAL(disconnect()), this, SLOT(slotDisconnected())); // 断开信号
}

void TcpClientSocket::dataReceived()
{
    while (bytesAvailable() > 0) {
       int length = bytesAvailable();
       char buf[1024];
       read(buf, length);
       QString msg = buf;
       emit updateClients(msg, length); // 向所有成员广播信息
    }
}

void TcpClientSocket::slotDisconnected()
{
    emit disconnect(this->socketDescriptor());
}
