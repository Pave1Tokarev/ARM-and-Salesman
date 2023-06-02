#include "forcast_page.h"
#include "ui_forcast_page.h"
#include<fstream>
#include<vector>
#include<string>
#include"windows.h"
#include"Plants.h"
#include<QString>
using namespace std;
forcast_page::forcast_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forcast_page)
{
    ui->setupUi(this);
    std::string tmp;
    bool tmpbool;
        std::ifstream fin("C:/img/weather2.txt");
        while (!fin.eof()) {
            fin >> tmp;
            date.push_back(stoi(tmp));
            fin >> tmp;
            day_temp.push_back(stoi(tmp));
            fin >> tmp;
            night_temp.push_back(stoi(tmp));
            fin>>tmp;
            tmpbool=!(tmp=="0");
            rain.push_back(tmpbool);

        }
        fin.close();
}
void forcast_page::potato_up(){
    ui->note->setText(QString::fromStdString(""));
    potato potatotmp;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для картофеля");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]>=potatotmp.temperature+4){
            chance-=0.5;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=potatotmp.night_temperature-2){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=1;i<rain.size()-1;i++){
        if(rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(potatotmp.notify!=""){
        ui->note->setText(QString::fromStdString(potatotmp.notify));
    }

}
void forcast_page::rice_up(){
    ui->note->setText(QString::fromStdString(""));
    rice ricemp;
    double chance=100;
    ui->plant_name->setText("Анализ погоды для риса");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-3>=ricemp.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=ricemp.night_temperature){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=1;i<rain.size()-1;i++){
        if(rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1.5;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(ricemp.notify!=""){
        ui->note->setText(QString::fromStdString(ricemp.notify));
    }

}
void forcast_page::apple_up(){
    ui->note->setText(QString::fromStdString(""));
    apple applenp;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для яблони");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-3>=applenp.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=applenp.night_temperature){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1.5;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(applenp.notify!=""){
        ui->note->setText(QString::fromStdString(applenp.notify));
    }

}
void forcast_page::cabage_up(){
    ui->note->setText(QString::fromStdString(""));
    cabage cbg;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для капусты");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-7>=cbg.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=cbg.night_temperature){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(cbg.notify!=""){
        ui->note->setText(QString::fromStdString(cbg.notify));
    }

}
void forcast_page::carrot_up(){
    ui->note->setText(QString::fromStdString(""));
    carrot crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для моркови");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-9>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=crt.night_temperature){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::wheat_up(){
    ui->note->setText(QString::fromStdString(""));
    wheat crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для пшеницы");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-3>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=crt.night_temperature){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::corn_up(){
    ui->note->setText(QString::fromStdString(""));
    corn crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для кукурузы");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-9>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=crt.night_temperature){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::cucumber_up(){
    ui->note->setText(QString::fromStdString(""));
    cucumber crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для огурца");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=crt.night_temperature){
            chance-0.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::grape_up(){
    ui->note->setText(QString::fromStdString(""));
    grape crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для винограда");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]>=crt.temperature){
            chance-=2.5;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=crt.night_temperature){
            chance-2.5;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=3;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::onion_up(){
    ui->note->setText(QString::fromStdString(""));
    onion crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для лука");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-5>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=crt.night_temperature){
            chance-=1;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::pea_up(){
    ui->note->setText(QString::fromStdString(""));
    pea crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для гороха");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-5>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]<=crt.night_temperature){
            chance-=1;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::soya_up(){
    ui->note->setText(QString::fromStdString(""));
    soya crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для сои");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-7>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]+1<=crt.night_temperature){
            chance-=1;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-2;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==rain[i+2]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
void forcast_page::sunflower_up(){
    ui->note->setText(QString::fromStdString(""));
    sunflower crt;
    double chance=110;
    ui->plant_name->setText("Анализ погоды для подсолнечника");
    string high_termo="";
    string low_termo="";
    string dry="";
    for(int i=0;i<day_temp.size();i++){
        if(day_temp[i]-7>=crt.temperature){
            chance-=1;
            high_termo+=(std::to_string(date[i])+",");
        if(night_temp[i]+3<=crt.night_temperature){
            chance-=1;
            low_termo+=(std::to_string(date[i])+",");
        }

        }
    }

    QString qstr = QString::fromStdString("Дни с температурой выше нормальной : ")+QString::fromStdString(high_termo);
    ui->tempover->setText(qstr);
    QString qstr1 = QString::fromStdString("Дни с ночными заморозками : ")+QString::fromStdString(low_termo);
    ui->nightcold->setText(qstr1);
    for(int i=2;i<rain.size()-1;i++){
        if(rain[i-2]==rain[i-1]==rain[i]==rain[i+1]==0){
            chance-=1;
            dry+=(to_string(date[i])+",");
        }
    }
    QString dd = QString::fromStdString("Засушливые дни : ")+QString::fromStdString(dry);
    ui->water->setText(dd);
    QString qchance=QString::fromStdString("Примерный шанс выживания урожая : ") + QString::fromStdString(to_string(chance))+QString::fromStdString("%");
    ui->chance->setText(qchance);
    if(crt.notify!=""){
        ui->note->setText(QString::fromStdString(crt.notify));
    }

}
forcast_page::~forcast_page()
{
    delete ui;
}
