#ifndef SHOWLABEL_H
#define SHOWLABEL_H
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QPen>

class ShowLabel : public QLabel
{
    Q_OBJECT
public:
    ShowLabel(QWidget *parent);
    ~ShowLabel();
protected:
    void paintEvent(QPaintEvent *);

public:
    QRect imageRect;
    QImage image;
    //static QColor lineColor; // 辅助线颜色
};

//QColor ShowLabel::lineColor(106,254,60);
#endif // SHOWLABEL_H
