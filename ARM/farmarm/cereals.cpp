#include "cereals.h"
#include "ui_cereals.h"
#include <QPixmap>
cereals::cereals(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cereals)
{
    ui->setupUi(this);
    QPixmap crlspix;
    crlspix.load("C:/img/cereals.jpg");
    ui->cereals_label->setPixmap(crlspix);
}

cereals::~cereals()
{
    delete ui;
}

void cereals::on_closecrls_clicked()
{
    this->close();
}

