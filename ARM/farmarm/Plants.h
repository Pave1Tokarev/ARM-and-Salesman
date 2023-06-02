#ifndef PLANTS_H
#define PLANTS_H


#include<string>
class plant{
public:
    plant(){
        temperature=0;
        night_temperature=0;
        notify="";
    }
    int temperature;
    int night_temperature;
    std::string notify;

};
class apple : public plant{
public:
    apple():plant(){
        temperature=21;
        night_temperature=-4;
        notify="";
    }
};
class cabage : public plant{
public:
    cabage(){
        temperature=16;
        night_temperature=-1;
        notify="";
    }
};
class carrot:public plant{
    public:
    carrot(){
        temperature=15;
        night_temperature=-3;
        notify="";
    }
};
class wheat:public plant{
public:
    wheat(){
        temperature=21;
        night_temperature=12;
        notify="";
    }
};
class corn:public plant{
public:
    corn(){
        temperature=20;
        night_temperature=8;
        notify="";
    }
};
class cucumber:public plant{
    public:
    cucumber(){
        temperature=25;
        night_temperature=18;
        notify="Рекомендуется выращивание в теплице";
    }
};
class grape:public plant{
    public:
    grape(){
       temperature=25;
       night_temperature=19;
       notify="В период дождей велик шанс развития у винограда грибковых заболеваний";
    }
};
class onion:public plant{
    public:
    onion(){
        temperature=19;
        night_temperature=8;
        notify="";
    }
};
class pea:public plant{
    public:
    pea(){
        temperature=20;
        night_temperature=5;
        notify="";
    }
};
class potato:public plant{
public:
    potato(){
        temperature=21;
        night_temperature=14;
        notify="";
    }
};
class rice:public plant{
public:
    rice(){
        temperature=23;
        night_temperature=16;
        notify="требуется специальная почва(наносные почвы речных и приречных долин)";
    }
};
class soya:public plant{
public:
    soya(){
        temperature=17;
        night_temperature=8;
        notify="";
    }
};
class sunflower:public plant{
    public:
    sunflower(){
        temperature=18;
        night_temperature=12;
        notify="";
    }
};
#endif // PLANTS_H
