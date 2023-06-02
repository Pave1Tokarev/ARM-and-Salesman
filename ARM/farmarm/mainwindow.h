#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"infoform.h"
#include "forecast.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_info_button_clicked();

    void on_plan_button_clicked();

private:
    Ui::MainWindow *ui;
    InfoForm info_menu;
    Forecast forecast_menu;

};


#endif // MAINWINDOW_H
