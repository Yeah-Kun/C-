#ifndef MODEL_H
#define MODEL_H

#include <QWidget>
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
#include <QtAlgorithms>
#include <QFileDialog>
#include <QFile>
#include <math.h>
#include <QDataStream>


namespace Ui {
class model;
}

class model : public QWidget
{
    Q_OBJECT

public:
    explicit model(QWidget *parent = 0);
    ~model();

protected:
    void paintEvent(QPaintEvent *); // 绘图事件
    void mouseDoubleClickEvent(QMouseEvent *e); // 双击事件
    void mousePressEvent(QMouseEvent *e); // 鼠标按下事件
    void mouseMoveEvent(QMouseEvent *e); // 鼠标移动
    void mouseReleaseEvent(QMouseEvent *e); // 鼠标释放
    void writeModel(QImage &drawboard); // 右击连接首尾两点
    void writeModel(QImage &drawboard, int begin, int end); // 画模型
    void addPoint(QMouseEvent *e); // 增加点
    void delPoint(QMouseEvent *e); // 删除点
    void rewriteModel(QImage &drawboard); // 重画整个Image，用于更新
    void setCenter(QMouseEvent *e); // 设置中心
    void setFocusPoint(QMouseEvent *e); // 选择关键单



public slots:
    void mouseClickEvent(); // 单击事件
    void EditMode(); // 改变模型编辑模式
    void setCenterMode(); // 设置中心点模式
    void saveModel(); // 保存模型
    void loadModel(); // 加载模型
    void selectImg(); // 选择图片


private slots:
    void cleanDrawBoard(); // 清空画布


private:
    Ui::model *ui;
    QBrush brush; // 画刷，填充img用
    QRgb bgColor; // 背景颜色
    QPoint beginPoint, endPoint; // 初始、结束绘图点
    QPen pen; // 画圈用的画笔
    QImage image, stuffimg; // 画布，填充模板图片
    QPoint XYpoint; // 绘画原点
    QVector<QPoint> pt;// 存储模型模式的点
    int ptcounter; // 点数
    QPainterPath patpath; // 模型路径
    QPainter p; // 相当于画画的人
    QTimer *timer;   //定时器,单双击事件
    bool isWrite; // 模型是否可画
    // 模式
    // 0：描绘模型
    // 1：编辑模型
    // 2：设置模型中心点
    int mode;
    QVector<QPoint> newpt; // 保存新模型数组
    QPoint FocusPoint; // 选中焦点
    int FocusIndex;
    QString imgpath; // 图片绝对路径
};

#endif // MODEL_H
