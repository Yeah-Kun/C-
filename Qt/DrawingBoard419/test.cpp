#include "test.h"
void calCos()
{
    int x = 1, y = 0;
    QPoint tempPoint, tempPoint2; // 临时点
    tempPoint = QPoint(0,0);
    tempPoint2 = QPoint(0,3);
    qDebug() << ((pow(x-tempPoint.x(), 2) + pow(y-tempPoint.y(), 2) +
                  pow(x-tempPoint2.x(), 2) + pow(y-tempPoint2.y(), 2) -
                  pow(tempPoint2.x()-tempPoint.x(), 2) + pow(tempPoint2.y()-tempPoint.y(), 2))
                   / (2 * sqrt(pow(x-tempPoint.x(), 2) + pow(y-tempPoint.y(), 2))* sqrt(pow(x-tempPoint2.x(), 2) + pow(y-tempPoint2.y(), 2)))
                  );
}
