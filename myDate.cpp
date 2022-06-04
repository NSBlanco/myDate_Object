#include "myDate.h"
#include <iostream>

int Greg2Julian(int month, int day, int year) {

    int JD = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;

    return JD;
}

void Julian2Greg(int JD, int& month, int& day, int& year) {

    JD += 68569;
    int temp = 4 * JD / 146097;
    JD = JD - (146097 * temp + 3) / 4;
    year = 4000 * (JD + 1) / 1461001;
    JD = JD - 1461 * year / 4 + 31;
    month = 80 * JD / 2447;
    day = JD - 2447 * month / 80;
    JD = month / 11;
    month = month + 2 - 12 * JD;
    year = 100 * (temp - 49) + year + JD;

}

myDate::myDate(){ // Set the date to May 11, 1959
    this->month = 05;
    this->day = 11;
    this->year = 1959;
}

myDate::myDate(int M, int D, int Y){ //overloaded constructor. This will set the date to the values passed in through the parameter list represented by Month, Day and Year
    if (M > 12){
        this->month = 05;
        this->day = 11;
        this->year = 1959;
    }
    else{
        this->month = M;
        this->day = D;
        this->year = Y;

    }
    
}

void myDate::display(){
    std::cout << monthName() << " " << this->day << ", "<< this->year;
} 

void myDate::increaseDate(int N){
    int j = Greg2Julian(this->month,this->day,this->year); 
    j += N;
    Julian2Greg(j, this->month,this->day,this->year);

}

void myDate::decreaseDate(int N){
    int j = Greg2Julian(this->month,this->day,this->year); 
    j -= N;

    Julian2Greg(j, this->month,this->day,this->year);
} 

void myDate::addMonth(){

    if (dayOfYear() == 366){
        
    }
    // getYear();
    // this->month;
    // this->year;
    int month =this->month;
    month+=1;
    int j = Greg2Julian(month,this->day,this->year);
    Julian2Greg(j,this->month,this->day,this->year);
    
    
}

int myDate::daysBetween(myDate D){
    int dDate = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
    int actualDate = Greg2Julian(this->month,this->day,this->year);
    int difference = (dDate - actualDate);
    return difference;

} 

int myDate::getMonth(){
    return this->month;
}

int myDate::getDay(){
    return this->day;
}

int myDate::getYear(){
    return this->year;
} 

int myDate::dayOfYear(){
    int day = Greg2Julian(this->month,this->day,this->year);
    int startYear = Greg2Julian(1,1,this->year)-1;
    return day - startYear;
}
std::string myDate::dayName(){
    char day = Greg2Julian(this->month,this->day,this->year) % 7;

    switch(day){
        case (6):
            return "Sunday";
            break;
        case (0):
            return "Monday";
            break;
        case (1):
            return "Tuesday";
            break;
        case (2):
            return "Wednesday";
            break;
        case (3):
            return "Thursday";
            break;
        case (4):
            return "Friday";
            break;
        case (5):
            return "Saturday";
            break;
        default:
            return "Idk";
            break;


    }


}
std::string myDate::monthName(){
    int month = this->month;

    switch(month){
        case (1):
            return "January";
            break;
        case (2):
            return "Feburary";
            break;
        case (3):
            return "March";
            break;
        case (4):
            return "April";
            break;
        case (5):
            return "May";
            break;
        case (6):
            return "June";
            break;
        case (7):
            return "July";
            break;
        case (8):
            return "August";
            break;
        case (9):
            return "September";
            break;
        case (10):
            return "October";
            break;
        case (11):
            return "November";
            break;
        case (12):
            return "December";
            break;




        default:
            return "Idk";
            break;


    }


}


