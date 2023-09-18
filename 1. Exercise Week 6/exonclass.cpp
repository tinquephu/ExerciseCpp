#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

istream &operator>>(istream &input, Date &date);
ostream &operator<<(ostream &output, const Date &date);
Date &operator++(Date &date);
Date operator++(Date &date, int);
Date &operator--(Date &date);
Date operator--(Date &date, int);
bool operator<(const Date date, const Date &other);
bool operator>(const Date &date, const Date &other);
bool operator==(const Date &date, const Date &other);
bool operator!=(const Date date, const Date &other);

int findDaysInMonth(int month, int year);
bool isValidDate(const Date &date);
void calculateTomorrow(Date date);
void calculateYesterday(Date date);

int main()
{
    Date currentDate;
    Date otherDate;

    cout << "Enter the current date (dd mm yyyy): ";
    cin >> currentDate;

    cout << "Enter another date (dd mm yyyy): ";
    cin >> otherDate;

    cout << "Current date: " << currentDate << endl;
    cout << "Other date: " << otherDate << endl;

    calculateTomorrow(currentDate);
    calculateYesterday(currentDate);

    if (currentDate > otherDate)
    {
        cout << currentDate << " is greater than " << otherDate << endl;
    }
    else if (currentDate < otherDate)
    {
        cout << currentDate << " is less than " << otherDate << endl;
    }
    else
    {
        cout << currentDate << " is equal to " << otherDate << endl;
    }

    if (currentDate != otherDate)
    {
        cout << currentDate << " is not equal to " << otherDate << endl;
    }

    return 0;
}

istream &operator>>(istream &input, Date &date)
{
    input >> date.day >> date.month >> date.year;
    return input;
}

ostream &operator<<(ostream &output, const Date &date)
{
    output << date.day << "/" << date.month << "/" << date.year;
    return output;
}

Date &operator++(Date &date)
{
    int daysInMonth = findDaysInMonth(date.month, date.year);

    if (date.day < daysInMonth)
    {
        date.day++;
    }
    else
    {
        date.day = 1;
        if (date.month < 12)
        {
            date.month++;
        }
        else
        {
            date.month = 1;
            date.year++;
        }
    }

    return date;
}

Date operator++(Date &date, int)
{
    Date temp = date;
    ++date;
    return temp;
}

Date &operator--(Date &date)
{
    if (date.day > 1)
    {
        date.day--;
    }
    else if (date.month > 1)
    {
        date.month--;
        date.day = findDaysInMonth(date.month, date.year);
    }
    else
    {
        date.year--;
        date.month = 12;
        date.day = 31;
    }

    return date;
}

Date operator--(Date &date, int)
{
    Date temp = date;
    --date;
    return temp;
}

bool operator<(const Date date, const Date &other)
{
    if (date.year < other.year)
    {
        return true;
    }
    else if (date.year == other.year && date.month < other.month)
    {
        return true;
    }
    else if (date.year == other.year && date.month == other.month && date.day < other.day)
    {
        return true;
    }

    return false;
}

bool operator>(const Date &date, const Date &other)
{
    return other < date;
}

bool operator==(const Date &date, const Date &other)
{
    return (date.day == other.day && date.month == other.month && date.year == other.year);
}

bool operator!=(const Date date, const Date &other)
{
    return !(date == other);
}

int findDaysInMonth(int month, int year)
{
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        daysInMonth[2] = 29;
    }

    return daysInMonth[month];
}

bool isValidDate(const Date &date)
{
    int daysInMonth = findDaysInMonth(date.month, date.year);
    return (date.day >= 1 && date.day <= daysInMonth && date.month >= 1 && date.month <= 12);
}

void calculateTomorrow(Date date)
{
    if (isValidDate(date))
    {
        date++;
        cout << "Tomorrow: " << date << endl;
    }
    else
    {
        cout << "Invalid date" << endl;
    }
}

void calculateYesterday(Date date)
{
    if (isValidDate(date))
    {
        date--;
        cout << "Yesterday: " << date << endl;
    }
    else
    {
        cout << "Invalid date" << endl;
    }
}
