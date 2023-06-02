#include "guideform.h"
#include "ui_guideform.h"
#include <QPixmap>
guideform::guideform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guideform)
{
    ui->setupUi(this);
}

guideform::~guideform()
{
    delete ui;
}
