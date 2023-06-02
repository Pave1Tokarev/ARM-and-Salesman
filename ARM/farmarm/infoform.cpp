#include "infoform.h"
#include "ui_infoform.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include<QString>
#include <QPixmap>
#include <vector>
InfoForm::InfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoForm)
{
    ui->setupUi(this);
    curr_pic=0;
    QPixmap pix;
    pix.load("C:/img/apples.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/cabage.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/carrot.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/cereals.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/corn.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/cucumber.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/grape.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/onion.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/pea.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/potato.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/rice.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/soya.jpg");
    pictures.push_back(pix);
    pix.load("C:/img/sunflower.jpg");
    pictures.push_back(pix);
    ui->pic_label->setPixmap(pictures[0]);
}

InfoForm::~InfoForm()
{
    delete ui;
}

void InfoForm::next_pic(){
    if(curr_pic<12){
        curr_pic++;
    }
    ui->pic_label->setPixmap(pictures[curr_pic]);

}
void InfoForm::prev_pic(){
    if(curr_pic>0){
        curr_pic--;
    }
    ui->pic_label->setPixmap(pictures[curr_pic]);
}


void InfoForm::on_pushButton_2_clicked()
{
    next_pic();
}


void InfoForm::on_pushButton_clicked()
{
    prev_pic();
}


void InfoForm::on_pushButton_3_clicked()
{
    this->close();
}

