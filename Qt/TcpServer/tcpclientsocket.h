#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT // 实现信号和槽通信
public:
    TcpClientSocket();


signals:
    void updateClients(QString, int); // 更新客户端数据
    void disconnect(int); // 关闭连接

protected slots:
    void dataReceived(); // 接收数据
    void slotDisconnected(); // 取消连接信号
};

#endif // TCPCLIENTSOCKET_H
