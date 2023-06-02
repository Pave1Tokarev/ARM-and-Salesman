#ifndef GUIDEFORM_H
#define GUIDEFORM_H

#include <QWidget>
#include<QString>
namespace Ui {
class guideform;
}

class guideform : public QWidget
{
    Q_OBJECT

public:
    explicit guideform(QWidget *parent = nullptr);
    ~guideform();


private:
    Ui::guideform *ui;
};

#endif // GUIDEFORM_H
