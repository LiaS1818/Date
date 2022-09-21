#include <iostream>
#include <sstream>
#include <string.h>
#include <conio.h>

class Date
{
private:
    
    int aDay, aMonth, aYear;
public:
    bool bisiesto;
    std::string date;
    Date(std::string);

    int setDate(std::string _date){
        int longitud = _date.length();
        if (longitud>10)
        {
            std::cout << "Fecha mal escrita" << std::endl;
            return 0;
        }

    }

    std::string getDate(){
        
        std::string day, month, year;
        std::stringstream stream(date);

        getline(stream, day, '/');
        getline(stream, month, '/');
        getline(stream, year, '/');

        validYear(year);
        validMonth(month);
        validDay(day);
    }

    void validYear(std::string year){
         aYear = stoi(year);
        
        while (aYear==0)
        {
            std::cout << "Año invalido" << std::endl;
        }
        
        
        if (aYear%4==0 && aYear%100 !=0 || aYear%400 == 0)
        {
            bisiesto = true;
        }else{
            bisiesto = false;
        }
        
        std::cout << "Año" << aYear << std::endl;
    }

    
    void validDay(std::string day){

        aDay = stoi(day);
        
        if (bisiesto == true  && aDay==29 && aMonth==2)
        {
            std::cout << "Dia: " << aDay << std::endl;
        }else{
            std::cout << "Dia invalido" << std::endl;
        }
        if (bisiesto == false && aDay<30)
        {
            std::cout << "Dia: " << aDay << std::endl;
        }
        
    }


    void validMonth(std::string month){
        aMonth = stoi(month);

        while(aMonth>30  && bisiesto == false || aMonth<=0)
        {
            std::cout << "Mes invalido mi vida, ingresa otro" << std::endl;
            std::cin >> aMonth;
        }

        std::cout << "Mes:" << aMonth << std::endl;
    }

};

Date::Date(std::string _date){
    date = _date;
}


