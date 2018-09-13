#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QToolBar>
#include "model.h"
#include "graff.h"
#include "test.h"

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);
    ~Board();

private slots:
    void GraffMode(); // 涂鸦模式
    void ModelMode(); // 设计模式
    void GameMode(); // 游戏模式

private:
    Ui::Board *ui;
};

#endif // BOARD_H

