#include "subject.h"
#include "ui_subject.h"
#include "shape.h"

subject::subject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::subject)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("3115000554+叶坤"));
    connect(ui->subjectBtn,SIGNAL(clicked()), this, SLOT(clickedSubject()));
}

subject::~subject()
{
    delete ui;
}

void subject::clickedSubject()
{
    shape* shaper = new shape();
    shaper->show();
}

