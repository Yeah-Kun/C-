#include "model.h"
#include "ui_model.h"

model::model(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::model)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("设计模式"));
    image = QImage(800,600,QImage::Format_RGB32); // 设置画布大小
    bgColor = qRgb(255,255,255);
    QPen pen; // 设置画笔
    ptcounter = 0; // 模型模式，点数初始化，从0开始
    image.fill(bgColor);
    mode = 0; // 初始模式设为0
    timer=new QTimer(this);
    FocusPoint = QPoint(0,0); // 设置焦点初始坐标
    FocusIndex = -1; // 设置焦点初始索引值
    isWrite = true; // 模型初始设为可画
    imgpath = ""; // 初始化图片路径
    connect(timer, SIGNAL(timeout()), this, SLOT(mouseClickEvent()));
    connect(ui->isEditModel,SIGNAL(stateChanged(int)), this,SLOT(EditMode())); // 改变编辑状态
    connect(ui->cleanbtn,SIGNAL(clicked()), this, SLOT(cleanDrawBoard()));
    connect(ui->setCenter, SIGNAL(clicked()), this, SLOT(setCenterMode()));
    connect(ui->saveModel, SIGNAL(clicked()), this, SLOT(saveModel()));
    connect(ui->loadModel, SIGNAL(clicked()), this, SLOT(loadModel()));
    connect(ui->selectImg, SIGNAL(clicked()), this, SLOT(selectImg()));

}


model::~model()
{
    delete ui;
}

void model::paintEvent(QPaintEvent *)
// 绘图事件，将image上的内容绘制出来
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true); //设置反走样,不然绘制出来的线条会出现锯齿
    p.drawImage(0,0,image);
}

void model::mousePressEvent(QMouseEvent *e)
// 鼠标按下事件，记录按下的坐标
{
    if(e->x() <= 800 && e->y() <= 600){
        timer->start(200); // 计时开始
        beginPoint = e->pos();
        endPoint = e->pos();
    }
}

void model::mouseMoveEvent(QMouseEvent *e)
// 鼠标移动事件，记录移动并且画image
{
    if(mode == 0){

    }
    else if(mode == 1){ // 编辑模式
        if(FocusPoint != QPoint(0,0) && (abs(e->x() - FocusPoint.x()) + abs(e->y() - FocusPoint.y()) < 50)){
            QPoint *data = pt.data();
            data[FocusIndex] = e->pos();
            FocusPoint = e->pos();
            rewriteModel(image);
        }
    }
}

void model::mouseReleaseEvent(QMouseEvent *e)
{
    // 描图
    if(mode == 0 && isWrite){
        if(e->button() == Qt::LeftButton){
            pt.append(beginPoint);
            writeModel(image, ptcounter-1, ptcounter);
            ptcounter++;
        }
        else if(e->button() == Qt::RightButton)
        {
            writeModel(image);
        }
    }
    // 编辑模型
    else if (mode == 1){
        setFocusPoint(e);
        rewriteModel(image);
    }
    // 设置模型中心点
    else if (mode == 2){
        setCenter(e);
    }
}

void model::writeModel(QImage &drawboard)
// 右击连接模型首尾两点
{
    QPainter p(&drawboard); // 设置画布
    pen.setWidth(1);
    pen.setColor("black");
    p.setPen(pen); // 在画布上放笔
    p.drawLine(pt.value(0), pt.value(ptcounter-1));
    update();
    for(auto i=0; i< ptcounter; i++)
        qDebug() << pt.value(i);
    isWrite = false;
}


void model::writeModel(QImage &drawboard, int begin, int end)
// 画模型，begin：首点，end：尾点
{
    QPainter p(&drawboard); // 设置画布
    pen.setWidth(1);
    pen.setColor("black");
    p.setPen(pen); // 在画布上放笔
    if(ptcounter == 0){
        p.drawEllipse(beginPoint, 3,3); // 画圆
    }
    else{
        p.drawEllipse(pt.value(end), 3,3);
        p.drawLine(pt.value(begin),pt.value(end)); //两点之间划线
    }
    update();

}

void model::addPoint(QMouseEvent *e)
{
    int i, index = -1; // 序数
    int x, y; // 当前鼠标x，y值
    int A, B, C; // 直线到点方程系数
    int topLX, topLY, downRX, downRY;
    double d = 100, d1, d2;
    QPoint Point, Point2; // 最短临近点
    QPoint tempPoint, tempPoint2; // 临时点
    x = e->x();
    y = e->y();

    for(i = 1;i<=ptcounter;i++){
        if(i!=ptcounter){
            tempPoint = pt.value(i);
            tempPoint2 = pt.value(i-1);
        }
        else{
            tempPoint = pt.value(0);
            tempPoint2 = pt.value(ptcounter-1);
        }

        A = tempPoint.y() - tempPoint2.y();
        B = tempPoint2.x() - tempPoint.x();
        C = tempPoint.x()*tempPoint2.y() - tempPoint2.x()*tempPoint.y();
        d1 = abs(A*x + B*y + C);
        d2 = sqrt(A*A + B*B);
        // 判断
        if (tempPoint.x() < tempPoint2.x()){
            topLX = tempPoint.x();
            downRX = tempPoint2.x();
        }
        else{
            topLX = tempPoint2.x();
            downRX = tempPoint.x();
        }
        if (tempPoint.y() < tempPoint2.y()){
            topLY = tempPoint.y();
            downRY = tempPoint2.y();
        }
        else{
            topLY = tempPoint2.y();
            downRY = tempPoint.y();
        }
        if((d1/d2) < d && (topLX < x && x < downRX && topLY < y && y < downRY)
                ){
            d = d1 / d2;
            Point = tempPoint;
            Point2 = tempPoint2;
            index = i;
        }
    }

    if(d < 10 && index != -1){
        qDebug() << index;
        pt.insert(index, e->pos());
        ptcounter++;
    }
    rewriteModel(image);
}

void model::delPoint(QMouseEvent *e)
// 删除模型的点
{
    int i = 0, x, y;
    QPoint temp;
    x = e->x();
    y = e->y();
    for(;i<ptcounter;i++){
        temp = pt.value(i);
        if((x-temp.x())*(x-temp.x()) + (y-temp.y())*(y-temp.y()) < 100){
            pt.remove(i);
            ptcounter--;
            break;
        }
    }
    rewriteModel(image); // 重画
}

void model::rewriteModel(QImage &drawboard)
// 重画整个画板
{
    if(imgpath == ""){
        image.fill(bgColor); // 洗白画板
    }
    else{
        image.load(imgpath);
        update();
    }
    int i = 0;
    QPainter p(&drawboard); // 设置画布
    pen.setWidth(2);
    pen.setColor("red");
    p.setPen(pen); // 在画布上放笔
    if(FocusPoint != QPoint(0,0)){
        p.drawEllipse(FocusPoint, 4,4);
    }
    pen.setColor("black");
    pen.setWidth(1);
    p.setPen(pen); // 在画布上放笔
    for(;i<ptcounter;i++){
        if(i == 0){
            p.drawEllipse(pt.value(i), 3,3); // 画圆
        }
        else{
            p.drawEllipse(pt.value(i), 3,3);
            p.drawLine(pt.value(i-1),pt.value(i)); //两点之间划线
        }
    }
    p.drawLine(pt.value(0),pt.value(ptcounter-1));
    update();

}

void model::setCenter(QMouseEvent *e)
{
    int i;
    int x,y;
    int tempx, tempy;
    x = e->x();
    y = e->y();
    for(i=0;i<ptcounter;i++){
        tempx = pt.value(i).x();
        tempy = pt.value(i).y();
        newpt.append(QPoint(x-tempx,y-tempy));
        qDebug() << QPoint(x-tempx,y-tempy);
    }
}

void model::setFocusPoint(QMouseEvent *e)
// 选择焦点
{
    int i;
    int x, y;
    int tempx, tempy;
    x = e->x();
    y = e->y();
    for(i=0; i<ptcounter; i++){
        tempx = pt.value(i).x();
        tempy = pt.value(i).y();
        if((x-tempx)*(x-tempx) + (y-tempy)*(y-tempy) < 20){
            FocusPoint = pt.value(i);
            FocusIndex = i;
            break;
        }
    }

}

void model::saveModel()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("保存模型"),
                                                "./",
                                                "Text(*.txt)");
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QDataStream  in(&file);
    for(int i=0; i<ptcounter; i++){
        in << pt.value(i);
    }
    file.close();
    qDebug() << filename;
}

void model::loadModel()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                "./",
                                                "",
                                                "Text(*.txt);;"
                                                "Images (*.png *.xpm *.jpg)");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        qDebug() << "文件打开失败";
    else{
        pt.clear();
        ptcounter = 0;
        QDataStream in(&file);
        while (!in.atEnd()) {
            QPoint p;
            in >> p;
            pt.append(p);
            ptcounter++;
        }
        rewriteModel(image);
    }
}

void model::selectImg()
{
    imgpath = QFileDialog::getOpenFileName(this,
                                                "./",
                                                "",
                                                "Images (*.png *.xpm *.jpg)");
    qDebug() << imgpath;
    if (imgpath == "")
        qDebug() << imgpath;
    else{
//        stuffimg = QImage();
//        stuffimg.load(filename);
//        brush = QBrush(stuffimg); // 建立画刷
//        QPainter p(&image); // 设置画布
//        p.setBrush(brush); // 设置画刷
//        patpath = QPainterPath();

//        QPolygonF f = QPolygonF(pt);
//        patpath.addPolygon(f); // 将多边形放到绘画路径里面去
//        p.drawPath(patpath);
        image = QImage();
        image.load(imgpath);
        update();
    }

}

void model::setCenterMode()
// 设置模型中心点
{
    mode = 2;
}

void model::mouseDoubleClickEvent(QMouseEvent  *e)
// 双击事件
{
    timer->stop();
    if(mode == 1){
        if(e->button()==Qt::LeftButton){
            delPoint(e);
        }

        else if(e->button()==Qt::RightButton){
            addPoint(e);
        }

    }
}


void model::mouseClickEvent()
// 单击事件
{

}

void model::EditMode()
{
    mode = 1;
}

void model::cleanDrawBoard()
{
    image.fill(bgColor); // 洗白画板
    update();
    pt.clear(); // 清空Vector所有元素
    ptcounter = 0;
    FocusPoint = QPoint(0,0);
    FocusIndex = -1; // 设置焦点初始索引值
    isWrite = true;
}
