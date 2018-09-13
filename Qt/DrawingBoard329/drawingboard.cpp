#include "drawingboard.h"
#include "ui_drawingboard.h"

DrawingBoard::DrawingBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawingBoard)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Drawing Board"));
    isDrawing = false; // 初始值设为未绘画
    image = QImage(800,600,QImage::Format_RGB32); // 设置画布大小
    bgColor = qRgb(255,255,255);
    QPen pen; // 设置画笔
    mode = 0; // 设置模式，0为乱画模式，1为模型模式
    ptcounter = -1; // 模型模式，点数初始化，从0开始
    //qDebug << "mode:" << mode << ptcounter;
    //QPoint pt[300];
    QVector<QPoint> pt;
    image.fill(bgColor);
    connect(ui->ButtonExit,SIGNAL(clicked()), qApp, SLOT(quit()) ); // 使用信号槽退出
    connect(ui->ButtonClear,SIGNAL(clicked()), this, SLOT(cleanDrawBoard()) ); // 清除画布内容
    connect(ui->ButtonCircle,SIGNAL(clicked()), this, SLOT(timerTask())); // 定时器画圆
    connect(ui->setColor,SIGNAL(clicked()), this, SLOT(setPenColor())); // 设置画笔颜色
    connect(ui->modeComboBox,SIGNAL(activated(int)), this, SLOT(changeMode())); // 改变模式
    connect(ui->fullmodelbtn,SIGNAL(clicked()), this, SLOT(fullModel())); // 填充模型
}

DrawingBoard::~DrawingBoard()
{
    delete ui;
}

void DrawingBoard::paintEvent(QPaintEvent *)
// 绘图事件，将image上的内容绘制出来
{
    QPainter painter(this);
    painter.drawImage(0,0,image);
}

void DrawingBoard::mouseDoubleClickEvent(QMouseEvent *e)
// 双击事件，对底层的mouseEvent进行进一步封装
{
    
}

void DrawingBoard::mousePressEvent(QMouseEvent *e)
// 鼠标按下事件，记录按下的坐标
{
    if(e->button() == Qt::LeftButton)
    {
        beginPoint = e->pos();
        endPoint = e->pos();
        if(mode == 0)
            paint(image);

    }
    else if(e->button() == Qt::RightButton)
    {
        if(mode == 1)
            writeModel(image, ptcounter, 0);
    }
}


void DrawingBoard::mouseMoveEvent(QMouseEvent *e)
// 鼠标移动事件，记录移动并且画image
{
    if(e->buttons() && Qt::LeftButton) // 这里跟press和realse的操作不一样
    {
        endPoint = e->pos();
        if (mode == 0){
            paint(image);
        }
    }
}


void DrawingBoard::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton && mode == 1){
        pt.append(beginPoint);
        ptcounter++;
        writeModel(image, ptcounter, ptcounter-1);
    }
}


void DrawingBoard::paint(QImage &drawboard)
// 核心绘图函数，使用（引用）image作为画板，在它上面画图
{
    // Qt 的绘图系统实际上是，使用QPainter在QPainterDevice上进行绘制
    // QPainter 可以理解成画图的人
    QPainter p(&drawboard);
    pen.setWidth(5);
    p.setPen(pen); // 在画布上放笔
    p.drawLine(beginPoint,endPoint);
    beginPoint = endPoint;
    update();
}

void DrawingBoard::writeModel(QImage &drawboard, int begin, int end)
// 画模型，begin：首点，end：尾点
{
    QPainter p(&drawboard); // 设置画布
    pen.setWidth(3);
    p.setPen(pen); // 在画布上放笔
    if(ptcounter == 0){
        p.drawEllipse(beginPoint, 5,5); // 画圆
    }
    else{
        p.drawEllipse(beginPoint, 5,5);
        p.drawLine(pt.value(begin),pt.value(end));

    }
    update();
    p.end();
}

void DrawingBoard::setPenColor()
// 设置画笔颜色
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue), this);
    // penColorFrame->setPalentte(QPalette(color));
    pen.setColor(color);
    QPixmap p(93, 93);
    p.fill(color);
    ui->setColor->setIcon(QIcon(p));
}

void DrawingBoard::changeMode()
// 改变画图模式
{
    mode = ui->modeComboBox->currentIndex();
}

void DrawingBoard::fullModel()
// 填充模型
// 根据点集，使用image填充模型
{
    qDebug() << "fullmodel";
    int i;
    stuffimg = QImage();
    stuffimg.load(":/model/plane/plane.jpg");
    brush = QBrush(stuffimg); // 建立画刷
    QPainter p(&image); // 设置画布
    p.setBrush(brush); // 设置画刷
    patpath = QPainterPath();

    QPolygonF f = QPolygonF(pt);
    patpath.addPolygon(f); // 将多边形放到绘画路径里面去
    p.drawPath(patpath);

    update();
    qDebug() << "end";
    p.end();
}

void DrawingBoard::cleanDrawBoard()
{
    image.fill(bgColor);
    update();
}

void DrawingBoard::timerTask()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(paintCircle()));
    timer->start(1000);
}

void DrawingBoard::paintCircle()
// 使用计时器画圆
{
    XYpoint = QPoint(300,300);
    QPainter p(&image);
    p.drawEllipse(XYpoint,100,100);
    update();
    while (XYpoint.x()<600) {
        XYpoint.setX(XYpoint.x() + 20);
        XYpoint.setY(XYpoint.y() + 20);
        p.drawEllipse(XYpoint,100,100);
        update();
    }
    timer->stop();
}
