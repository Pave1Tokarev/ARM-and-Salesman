#include "getweather.h"
#include"curl/curl.h"
#include"string"
static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp){
    ((std::string*)userp)->append((char*)contents,size*nmemb);
    return size * nmemb;
}
GetWeather::GetWeather()
{
    CURL *curl;
    CURLcode response;
    std::string str_response;
    curl=curl_easy_init();
    curl_easy_setopt(curl,CURLOPT_URL,"https://bots.gismeteo.ru/weather-perm-4476/month/");
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,getResponsetoString);
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,&str_response);
    response=curl_easy_perform(curl);
    curl_easy_cleanup(curl);

}
