#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>



class myDate{

public:
    myDate();

    myDate(int M, int D, int Y);
    
    void display(); 

    void increaseDate(int N); 
    void decreaseDate(int N); 

    int daysBetween(myDate D); 
    void addMonth();
    int getMonth(); 
    int getDay(); 
    int getYear(); 
    int dayOfYear();
    std::string dayName();
    std::string monthName();
    

private:
    int day;
    int month;
    int year;
    



};

#endif 