#include <iostream>
#include "Date.h"

int main()
{   char esc;
    std::string date;

    do
    {
        std::cout << "Ingresa fecha dd/mm/yyyy" << std::endl;
        std::cin >> date;
        Date d = Date(date);

        if (d.setDate(date)!=0)
        {
             std::cout <<  d.getDate() << std::endl;
        }
    } while ((esc = std::cin.get())!= 'z');

    return 0;
}
