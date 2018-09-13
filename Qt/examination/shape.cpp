#include "shape.h"
#include "ui_shape.h"

shape::shape(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shape)
{
    ui->setupUi(this);
    image = QImage(800,600,QImage::Format_RGB32); // 设置画布大小
    image.fill(Qt::white);
    connect(ui->colorBtn,SIGNAL(clicked()), this, SLOT(getColor()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(clearBoard()));
    connect(ui->picBtn, SIGNAL(clicked()), this, SLOT(loadImage()));
}

shape::~shape()
{
    delete ui;
}

void shape::getColor()
// 获得画笔颜色
{
    qDebug() << "getColor";
    penColor = QColorDialog::getColor(static_cast<int>(Qt::blue), this);
    pen.setColor(penColor);
    QPixmap iconColor(93, 93);
    iconColor.fill(penColor);
    ui->colorBtn->setIcon(QIcon(iconColor));
}

void shape::clearBoard()
{
    image.fill(Qt::white);
    update();
}

void shape::loadImage()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                "./",
                                                "",
                                                "Images (*.png *.xpm *.jpg)");
    QImage* img = new QImage;
    if(!img->load(filename))
        qDebug() << "文件打开失败";
    else{
        stuffimg.load(filename);
        brush = QBrush(stuffimg); // 建立画刷

    }
}

int shape::getShape()
{
    shapeMode = ui->shapeBox->currentIndex();
    return shapeMode;
}

Qt::PenStyle shape::getStyle()
{
    styleMode = ui->styleBox->currentIndex();
    if(styleMode == 0)
        return Qt::SolidLine;
    else if(styleMode == 1)
        return Qt::DashLine;
    else if(styleMode == 2)
        return Qt::DotLine;
    else if(styleMode == 3)
        return Qt::DashDotLine;
    else if(styleMode == 4)
        return Qt::DashDotDotLine;
    else{
        qDebug() << "cannot set style";
        return Qt::NoPen;
    }
}

void shape::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        XYPointer = e->pos();
    }
}

void shape::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        beginPoint = e->pos();
        if(getShape() == 1)
            paintCircle(image);
        else if(getShape() == 2)
            paintSquare(image);
        else if(getShape() == 3)
            paintTriangle(image);
        else
            qDebug() << "cannot find";
    }
}

void shape::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() && Qt::LeftButton)
    {
        if(getShape() == 0)
        {
            endPoint = e->pos();
            paintLine(image);
        }
    }
}

void shape::paintLine(QImage &board)
{
    QPainter p(&board);
    pen.setColor(penColor);
    pen.setStyle(getStyle());
    p.setPen(pen); // 在画布上放笔
    p.drawLine(beginPoint,endPoint);
    beginPoint = endPoint; // 关键一步，没有就会出现断点清
    qDebug() << "划线" << penColor;
    update();
}

void shape::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(pen);
    p.drawImage(0,0,image);
}

void shape::paintCircle(QImage &board)
{
    QPainter p(&board);
    p.drawEllipse(beginPoint,100,100);
    update();
}

void shape::paintSquare(QImage &board)
{
    QPainter p(&board);
    pt.clear();
    p.drawRect(beginPoint.x()-50, beginPoint.y()-50, 100, 100);
    pt.push_back(QPointF(beginPoint.x()-50, beginPoint.y()-50));
    pt.push_back(QPointF(beginPoint.x()+50, beginPoint.y()-50));
    pt.push_back(QPointF(beginPoint.x()+50, beginPoint.y()+50));
    pt.push_back(QPointF(beginPoint.x()-50, beginPoint.y()+50));
    pt.push_back(QPointF(beginPoint.x()-50, beginPoint.y()-50));
    p.setBrush(brush); // 设置画刷
    QPainterPath patpath = QPainterPath();
    QPolygonF f = QPolygonF(pt);
    patpath.addPolygon(f); // 将多边形放到绘画路径里面去
    p.drawPath(patpath);
    update();
}

void shape::paintTriangle(QImage &board)
{
    QPainter p(&board);
    qreal lowx, highx;
    double cos30 = sqrt(3)/2, rtan30 = sqrt(3);
    lowx = 50*rtan30;
    highx = 100 * cos30 -lowx;
    qreal x = beginPoint.x();
    qreal y = beginPoint.y();
    QPointF a = QPointF(x,y-highx);
    QPointF b = QPointF(x-50,y+lowx);
    QPointF c = QPointF(x+50,y+lowx);
    qDebug() << a << b << c;

    p.drawLine(a,b);
    p.drawLine(b,c);
    p.drawLine(c,a);
//    p.drawLine(beginPoint, QPoint(0,0));
    update();
}

