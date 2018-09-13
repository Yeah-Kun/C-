#ifndef GRAFF_H
#define GRAFF_H

#include <QWidget>

namespace Ui {
class graff;
}

class graff : public QWidget
{
    Q_OBJECT

public:
    explicit graff(QWidget *parent = 0);
    ~graff();

private:
    Ui::graff *ui;
};

#endif // GRAFF_H
