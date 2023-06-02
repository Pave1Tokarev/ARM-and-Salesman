#ifndef FORCAST_PAGE_H
#define FORCAST_PAGE_H

#include <QWidget>
#include<Plants.h>
namespace Ui {
class forcast_page;
}

class forcast_page : public QWidget
{
    Q_OBJECT

public:
    explicit forcast_page(QWidget *parent = nullptr);
    ~forcast_page();
    void potato_up();
    void apple_up();
    void cabage_up();
    void carrot_up();
    void wheat_up();
    void corn_up();
    void cucumber_up();
    void grape_up();
    void onion_up();
    void pea_up();
    void rice_up();
    void soya_up();
    void sunflower_up();


private:
    Ui::forcast_page *ui;
    std::vector<int>date;
    std::vector<int> day_temp;
    std::vector<int> night_temp;
    std::vector<bool> rain;
};

#endif // FORCAST_PAGE_H
