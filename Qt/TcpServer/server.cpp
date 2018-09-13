#include "server.h"

Server::Server(QObject *parent, int port)
{
    listen(QHostAddress::Any, port); // 在指定端口对任意地址进行监听
}

void Server::incomingConnection(int socketDescriptor)
// 出现新连接，触发函数
{
    TcpClientSocket* ClientSocket = new TcpClientSocket(this); // 服务器端

    connect(ClientSocket, SIGNAL(updateClients(QString,int)), this, SLOT(updateClients(QString,int)));
    connect(ClientSocket, SIGNAL(disconnect(int)), this, SLOT(slotDisconnected(int)));
    ClientSocket->setSocketDescriptor(socketDescriptor);
    
    ClientList.append(ClientSocket);
}
