#ifndef FORECAST_H
#define FORECAST_H

#include <QWidget>
#include"forcast_page.h"
namespace Ui {
class Forecast;
}

class Forecast : public QWidget
{
    Q_OBJECT

public:
    explicit Forecast(QWidget *parent = nullptr);
    ~Forecast();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Forecast *ui;
    forcast_page forecaster;
};

#endif // FORECAST_H
