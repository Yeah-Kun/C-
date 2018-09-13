#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    // 成员变量初始化
    ui->setupUi(this);
    camera=new QCamera;//摄像头
    imageCapture=new QCameraImageCapture(camera);// 图片获取容器
    QTimer *timer = new QTimer(this);
    cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
        ui->cameraMenu->addAction(cameraInfo.description());
    }
    insuranceStatus = false;
    lockStatus = false;
    launchStatus = false;
    //setWindowFlags(Qt::FramelessWindowHint);

    // 建立连接
    connect(timer, SIGNAL(timeout()), this, SLOT(getFrame()));
    connect(ui->menuBar,SIGNAL(triggered(QAction*)),this,SLOT(selectCamrea(QAction*)));
    connect(ui->insuranceBtn, SIGNAL(clicked()), this, SLOT(openInsurance()));
    connect(ui->lockBtn, SIGNAL(clicked()), this, SLOT(openLock()));
    connect(ui->launchBtn, SIGNAL(clicked()), this, SLOT(openLaunch()));
    connect(ui->scram_btn, SIGNAL(clicked()), this, SLOT(openScram()));
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(showScreen(int, QImage)));
    connect(this, SIGNAL(textSend(QString)), this, SLOT(textReceiver(QString)));

    // 开始工作
    timer->start(15);
    camera->start();
}

MainPage::~MainPage()
{
    delete ui;
    delete camera;
}

void MainPage::showScreen(int, QImage image)
{
    ui->screen->image = image;
    ui->screen->imageRect = image.rect();
    ui->screen->update();
}

void MainPage::selectCamrea(QAction *act)
{
    camera->stop();
    disconnect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(showScreen(int, QImage))); // 取消之前的连接
    foreach (const QCameraInfo &cameraInfo, cameras) {
        if(cameraInfo.description() == act->text()){
            camera = new QCamera(cameraInfo);
            camera->start();
            imageCapture= new QCameraImageCapture(camera);
            connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(showScreen(int, QImage)));
            break;
        }
    }
}

void MainPage::getFrame()
{
    if(!camera->error()){
        imageCapture->capture();
    }
    else{
        qDebug() << camera->error();
    }
}

void MainPage::openInsurance()
{

    insuranceStatus = true;
    ui->insuranceBtn->setStyleSheet("QPushButton{"
                                    "background-image:url(:/Resources/button_active.png);"
                                    "border-width: 30px;"
                                    "border-radius: 30px;"
                                    "color:white;"
                                    "}");
    this->textSender("保险打开！");

}

void MainPage::openLock()
{
    if(insuranceStatus){

        lockStatus = true;
        ui->lockBtn->setStyleSheet("QPushButton{"
                                   "background-image:url(:/Resources/button_active.png);"
                                   "border-width: 30px;"
                                   "border-radius: 30px;"
                                   "color:white;"
                                   "}");
    }

}

void MainPage::openLaunch()
{
    if(insuranceStatus && lockStatus){

        launchStatus = true;
        ui->launchBtn->setStyleSheet("QPushButton{"
                                     "background-image:url(:/Resources/button_active.png);"
                                     "border-width: 30px;"
                                     "border-radius: 30px;"
                                     "color:white;"
                                     "}");
    }

}

void MainPage::openScram()
{
    if(launchStatus){
        scramStatus = true;
        ui->scram_btn->setStyleSheet("QPushButton{"
                                     "background-image:url(:/Resources/button_active.png);"
                                     "border-width: 30px;"
                                     "border-radius: 30px;"
                                     "color:white;"
                                     "}");
    }

}

void MainPage::textReceiver(const QString &text)
{
    ui->textBrowser->setText(text);
}

void MainPage::textSender(const QString& text)
{
    QDateTime time = QDateTime::currentDateTime();
    //QString current_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    QString current_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    QString info_text= current_time + ":" + text;
    emit textSend(info_text);
}


// http://wd3600.com/html/part/index18_2.html
