#include "graff.h"
#include "ui_graff.h"

graff::graff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graff)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("涂鸦模式"));
}

graff::~graff()
{
    delete ui;
}
