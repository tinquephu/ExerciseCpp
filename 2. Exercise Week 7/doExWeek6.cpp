#include <iostream>
using namespace std;

struct Date {
    int day, month, year;
} ;

istream &operator >>(istream& in, Date& d)
{
    cout
}

int main()
{
    Date today;
    cout << "Today is " << today;
}