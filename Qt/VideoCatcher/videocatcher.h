#ifndef VIDEOCATCHER_H
#define VIDEOCATCHER_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraInfo>

namespace Ui {
class VideoCatcher;
}

class VideoCatcher : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoCatcher(QWidget *parent = 0);
    ~VideoCatcher();

private:
    Ui::VideoCatcher *ui;
};

#endif // VIDEOCATCHER_H
