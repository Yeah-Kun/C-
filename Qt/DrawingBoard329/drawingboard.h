#ifndef DRAWINGBOARD_H
#define DRAWINGBOARD_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QRgb>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QColorDialog>
#include <QPixmap>
#include <QIcon>
#include <QBrush>
#include <QPainterPath>
#include <QPolygonF>
#include <QVector>
#include <QPainter>

namespace Ui {
class DrawingBoard;
}

class DrawingBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawingBoard(QWidget *parent = 0);
    ~DrawingBoard();

protected:
    void paintEvent(QPaintEvent *); // 绘图事件
    void mouseDoubleClickEvent(QMouseEvent *e); // 双击事件
    void mouseClickEvent(QMouseEvent *e); // 单击事件
    void mousePressEvent(QMouseEvent *e); // 鼠标按下事件
    void mouseMoveEvent(QMouseEvent *e); // 鼠标移动
    void mouseReleaseEvent(QMouseEvent *e); // 鼠标释放
    void paint(QImage &drawboard); // 乱画模式，画图
    void writeModel(QImage &drawboard, int begin, int end); // 画模型

private slots:
    void cleanDrawBoard(); // 清空画布
    void paintCircle();
    void timerTask();
    void setPenColor(); // 设置画笔颜色
    void changeMode(); // 改变画图模式
    void fullModel(); // 使用image填充模型


private:
    Ui::DrawingBoard *ui;
    QPen pen; // 设置画笔
    QBrush brush; // 画刷，填充img用
    QRgb bgColor; // 背景颜色
    QPoint beginPoint; // 初始绘图点
    QPoint endPoint; // 结束绘图点
    bool isDrawing; // 判断是否绘图（鼠标是否持续按下）
    QImage image, stuffimg; // 画布，填充模板图片
    QTimer *timer; // 自动绘画计时器
    QPoint XYpoint; // 绘画原点
    int mode; // 模式序号
    QVector<QPoint> pt;// 存储模型模式的点
    //QPoint pt[300]; // 存储模型模式的点
    int ptcounter; // 点数
    QPainterPath patpath; // 模型路径
    QPainter p;
};

#endif // DRAWINGBOARD_H
