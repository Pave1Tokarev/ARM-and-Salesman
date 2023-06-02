#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"infoform.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_info_button_clicked()
{
    info_menu.show();
}


void MainWindow::on_plan_button_clicked()
{
    forecast_menu.show();
}

