#pragma once
#include <chrono>
#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

//class declaration
class Temperature 
{
  public:
  Temperature();
  void menu();
  void enter_c_f_k();
  void write_data();
  void getTimeStr();
  void change_date_format();
  void start_auto_writting();
  private:
    std::string tmp,tmp01,tmp02,result;
    double celsius;
    char unit;

};


#endif //TEMPERATURE_H_