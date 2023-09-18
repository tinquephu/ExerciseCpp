#include <iostream>
using namespace std;

struct Date {
    int day, month, year;
    void yesterday(){
        if (day == 1) {
            if (month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                day = 31;
            } else if (month == 1) {
                year--;
                month = 12;
                day = 31;
            } else 
            {
                day--;
                month--;
            }
        } else {day--;}
        cout << "Yesterday is " << day << "/" << month << "/" << year;
    }
} ;


int main() 
{
    Date date;
    cout << "Today is " ;
    cin >> date.day >> date.month >> date.year;
    date.yesterday(); 
    

}