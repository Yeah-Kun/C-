#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("高级编程实训"));


    QToolBar *toolBar = new QToolBar(this);
    toolBar->setMovable(false);     // 设置工具栏不可移动,默认是可移动
    //this->addToolBar(toolBar);  // 把工具栏添加到窗口

    QAction *act[3];

    act[0] = new QAction(QIcon(":/board/icon/涂鸦.png"),"涂鸦模式", this);
    act[1] = new QAction(QIcon(":/board/icon/设计.png"),"设计模式", this);
    act[2] = new QAction(QIcon(":/board/icon/游戏.png"),"游戏模式", this);

    for(int i=0; i<3; i++) // 添加控件
        toolBar->addAction(act[i]);

    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); // 在图标隔壁显示文字

    connect(act[0], SIGNAL(triggered()), this, SLOT(GraffMode()));
    connect(act[1], SIGNAL(triggered()), this, SLOT(ModelMode()));

}

Board::~Board()
{
    delete ui;
}

void Board::GraffMode()
{
    graff* graffgame = new graff();
    graffgame->show();
}

void Board::ModelMode()
{
    model* modelgame = new model();
    modelgame->show();
}

void Board::GameMode()
{

}
