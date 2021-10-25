#include <iostream>
#include "temperature.h"
#include <time.h>
#include <fstream>
#include <thread>
#include <ctime>
Temperature::Temperature(){
   srand (time(NULL));
   getTimeStr();
  celsius=rand()%30-30;
  unit = 'C';
  result=tmp;
  menu();
}
void Temperature::menu()
{
 
   int ch;
    do
    {
        system ("clear");
        std::cout << "............................................\n";
        std::cout << "                Temperature\n";
        std::cout << "--------------------------------------------\n\n";
        std::cout << "::::::::::::::: PROGRAMM MENU :::::::::::::::\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Change the unit of temperature measurement \n";
        std::cout << "2. Change type of a date\n";
        std::cout << "3. Write in the file the current temerature and date\n";
        std::cout<<"4. Start writting the information once an hour \n";
        std::cout << "Enter Your Choice : ";
        std::cin >> ch;
        system ("clear");
        switch (ch)
        {
        case 1:
            enter_c_f_k();
        	  break;
         case 2:
       change_date_format();
         	  break;
        
         case 3:
          write_data();
          
         	  break;
             case 4:
             start_auto_writting();
             break;
         }        

    }while (ch);
}
 void Temperature::enter_c_f_k() {
   std::cout << "0. Exit\n";
   std::cout << "1. Celsius \n";
   std::cout << "2. Fahrenheit\n";
   std::cout << "3. Kelvin\n";
   std::cout << "Enter Your Choice : ";
   int ch;
   std::cin>>ch;
   if(ch==0){
     exit(0);
   }
   else if(ch==1){
     if(unit=='F'){
       celsius = (celsius-32.00)/1.8000;
     }
     else if(unit == 'K'){
       celsius = celsius - 273.15;
     }
     unit = 'C';
   }
   else if(ch==2){
     if(unit == 'K'){
       celsius = (celsius-273.15) *1.8000+32.00;
     }
     else if(unit == 'C'){
       celsius = (celsius*1.8000)+32.00;
     }
     unit = 'F';
   }
   else if(ch==3){
     if(unit == 'C'){
        celsius = celsius + 273.15;
     }
     else if(unit == 'F'){
        celsius = ((celsius-32.00)/1.8000)+273.15;
     }
     
     unit = 'K';
   }
   
 }

 void Temperature::write_data(){
   std::ofstream fout;
   
   fout.open("test.txt" ,std::ios_base::out | std::ios_base::binary | std::ios_base::app);
  if(fout.is_open()){
    fout<<"The current temerature is "<< celsius << unit<<" "<< result<<"\n";
  }
  fout.close();
 }
 
 void Temperature::getTimeStr(){
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::string tmp1(30, '\0');
    std::string tmp2(30, '\0');
    std::string tmp3(30, '\0');
    std::strftime(&tmp1[0], tmp1.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    tmp=tmp1;
    std::strftime(&tmp2[0], tmp2.size(), "%d-%m-%Y %H:%M:%S", std::localtime(&now));
    tmp01=tmp2;
     std::strftime(&tmp3[0], tmp3.size(), "%m-%d-%Y %H:%M:%S", std::localtime(&now));
     tmp02=tmp3;
}

void Temperature::change_date_format(){
  std::cout << "0. Exit\n";
   std::cout << "1. YYYY :: MM :: DD \n";
   std::cout << "2. DD :: MM :: YYYY \n";
   std::cout << "3. MM :: DD :: YYYY \n";
   std::cout << "Enter Your Choice : ";
    int ch;
   std::cin>>ch;
   if(ch==0){
     exit(0);
   }
   else if(ch==1){
    
     result=tmp;
   }
   else if(ch==2){
     
     result=tmp01;
   }
   else if(ch==3){
     
     result=tmp02;
   }
}

void Temperature::start_auto_writting(){
  int ch=1;
   using namespace std::chrono_literals;
while(ch){
  system ("clear");
   srand (time(NULL));
   getTimeStr();
  celsius=rand()%30-30;
  result=tmp;
  getTimeStr();
    write_data();
    std::cout << "0. Exit\n";
   std::cout << "1. Continue \n";
    std::cout<<"If you want to exit please input 0 \n";
    std::cout<<"or for continue input 1\n";
   std::this_thread::sleep_for(3600000ms);
   std::cin>>ch;
   if (ch == 0){exit(0);}
       
}
}
