#ifndef INFOFORM_H
#define INFOFORM_H

#include <QWidget>
#include <vector>
#include <QPixmap>

namespace Ui {
class InfoForm;
}

class InfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit InfoForm(QWidget *parent = nullptr);
    ~InfoForm();
    void next_pic();
    void prev_pic();
    std::vector<QPixmap> pictures;

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::InfoForm *ui;
    int curr_pic;


};

#endif // INFOFORM_H
