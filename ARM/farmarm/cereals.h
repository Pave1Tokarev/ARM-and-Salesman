#ifndef CEREALS_H
#define CEREALS_H

#include <QWidget>

namespace Ui {
class cereals;
}

class cereals : public QWidget
{
    Q_OBJECT

public:
    explicit cereals(QWidget *parent = nullptr);
    ~cereals();

private slots:
    void on_closecrls_clicked();

private:
    Ui::cereals *ui;
};

#endif // CEREALS_H
