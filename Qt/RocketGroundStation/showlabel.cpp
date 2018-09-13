#include "showlabel.h"

ShowLabel::ShowLabel(QWidget *parent):QLabel(parent)
{

}

ShowLabel::~ShowLabel()
{
    qDebug() << "del ShowLabel";
}

void ShowLabel::paintEvent(QPaintEvent *)
{
    const int x = imageRect.width();
    const int y = imageRect.height();
    this->resize(x,y);
    QPainter p(this);
    QColor lineColor(106,254,60); 
    p.setPen(QPen(lineColor, 1));   
    p.drawPixmap(0,0,QPixmap::fromImage(image));
    p.drawLine(0,y/2, x, y/2); // 水平线
    p.drawLine(x/2,0, x/2, y); // 垂直线
}
