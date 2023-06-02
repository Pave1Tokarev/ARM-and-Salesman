#ifndef GETWEATHER_H
#define GETWEATHER_H

#include<vector>
class GetWeather
{
public:
    GetWeather();
private:
    std::vector<int> temrature;
    std::vector<int> wetness;
    std::vector<bool> isRaint;

};

#endif // GETWEATHER_H
