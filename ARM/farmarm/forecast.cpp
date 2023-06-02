#include "forecast.h"
#include "ui_forecast.h"

Forecast::Forecast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Forecast)
{
    ui->setupUi(this);
}

Forecast::~Forecast()
{
    delete ui;
}

void Forecast::on_pushButton_2_clicked()
{
    forecaster.potato_up();
    forecaster.show();
}


void Forecast::on_pushButton_5_clicked()
{
    forecaster.rice_up();
    forecaster.show();
}


void Forecast::on_pushButton_6_clicked()
{
    forecaster.apple_up();
    forecaster.show();
}


void Forecast::on_pushButton_10_clicked()
{
    forecaster.cabage_up();
    forecaster.show();
}


void Forecast::on_pushButton_11_clicked()
{
    forecaster.carrot_up();
    forecaster.show();
}


void Forecast::on_pushButton_12_clicked()
{
    forecaster.wheat_up();
    forecaster.show();
}


void Forecast::on_pushButton_13_clicked()
{
    forecaster.corn_up();
    forecaster.show();
}


void Forecast::on_pushButton_9_clicked()
{
    forecaster.cucumber_up();
    forecaster.show();
}


void Forecast::on_pushButton_8_clicked()
{
    forecaster.grape_up();
    forecaster.show();
}


void Forecast::on_pushButton_7_clicked()
{
    forecaster.onion_up();
    forecaster.show();
}


void Forecast::on_pushButton_4_clicked()
{
    forecaster.pea_up();
    forecaster.show();
}


void Forecast::on_pushButton_3_clicked()
{
    forecaster.soya_up();
    forecaster.show();
}


void Forecast::on_pushButton_clicked()
{
    forecaster.sunflower_up();
    forecaster.show();
}

