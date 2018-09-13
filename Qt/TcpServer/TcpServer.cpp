#include "TcpServer.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TCP Server");
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
