#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QImage>
#include <QMouseEvent>
#include <QColorDialog>
#include <QFileDialog>
#include <iostream>
#include <QDebug>
#include <cmath>
#include <QSize>
#include <QBrush>
#include <QPainterPath>
#include <QVector>
#include <QPolygonF>

namespace Ui {
class shape;
}

class shape : public QWidget
{
    Q_OBJECT

public:
    explicit shape(QWidget *parent = 0);
    ~shape();

private slots:
    void getColor();
    void clearBoard();
    void loadImage();

private:
    int getShape();
    Qt::PenStyle getStyle();
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintLine(QImage &board);
    void paintEvent(QPaintEvent *);
    void paintCircle(QImage &board);
    void paintSquare(QImage &board);
    void paintTriangle(QImage &board);


private:
    Ui::shape *ui;
    QPainter p;
    QPen pen;
    QColor penColor;
    QPoint XYPointer, beginPoint, endPoint;
    QImage image;
    int shapeMode; // 选择不同的形状
    int styleMode; // 线的不同样式
    QVector<QPointF> pt;
    QImage stuffimg;
    QBrush brush;


};

#endif // SHAPE_H
