#ifndef SUBJECT_H
#define SUBJECT_H

#include <QMainWindow>

namespace Ui {
class subject;
}

class subject : public QMainWindow
{
    Q_OBJECT

public:
    explicit subject(QWidget *parent = 0);
    ~subject();

private slots:
    void clickedSubject();


private:
    Ui::subject *ui;
};

#endif // SUBJECT_H
