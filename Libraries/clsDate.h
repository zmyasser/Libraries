#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    int _Year = 1900;

public:
    // Constructors
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(const std::string& sDate)
    {
        std::vector<std::string> vDate = clsString::Split(sDate, "/");
        try
        {
            _Day = std::stoi(vDate[0]);
            _Month = std::stoi(vDate[1]);
            _Year = std::stoi(vDate[2]);
        }
        catch (...)
        {
            _Day = 0;
            _Month = 0;
            _Year = 0;
        }
    }

    clsDate(short Day, short Month, int Year) : _Day(Day), _Month(Month), _Year(Year) {}

    clsDate(short DateOrderInYear, int Year)
    {
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1.GetDay();
        _Month = Date1.GetMonth();
        _Year = Date1.GetYear();
    }

    // Getters / Setters
    void SetDay(short Day)
    { 
        _Day = Day;
    
    }

    short GetDay() const
    { 
        return _Day; 
    }

    __declspec(property(get = GetDay, put = SetDay)) short Day;



    void SetMonth(short Month)
    { 
        _Month = Month;
    
    }
    short GetMonth() const
    { 
        return _Month; 
    }

    __declspec(property(get = GetMonth, put = SetMonth)) short Month;



    void SetYear(int Year) 
    { 
        _Year = Year;
    }

    int GetYear() const
    {
        return _Year; 
    }

    __declspec(property(get = GetYear, put = SetYear)) int Year;



    void Print() const 
    { 
        std::cout << DateToString() << std::endl; 
    }

    // System date
    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    }

    static std::string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        return std::to_string(now->tm_mday) + "/" +
            std::to_string(now->tm_mon + 1) + "/" +
            std::to_string(now->tm_year + 1900) + " - " +
            std::to_string(now->tm_hour) + ":" +
            std::to_string(now->tm_min) + ":" +
            std::to_string(now->tm_sec);
    }

    // Validation
    static bool IsValidDate(const clsDate& Date)
    {
        if (Date._Day < 1 || Date._Month < 1 || Date._Month > 12) return false;
        short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        return Date._Day <= DaysInMonth;
    }

    bool IsValid() const 
    {
        return IsValidDate(*this);
    }

    // Date to string
    static std::string DateToString(const clsDate& Date)
    {
        return std::to_string(Date._Day) + "/" +
            std::to_string(Date._Month) + "/" +
            std::to_string(Date._Year);
    }

    std::string DateToString() const
    { 
        return DateToString(*this); 
    }

    // Leap year
    static bool isLeapYear(int Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear() const 
    { 
        return isLeapYear(_Year); 
    }

    // Days/Hours/Minutes/Seconds
    static int NumberOfDaysInAYear(int Year)
    { 
        return isLeapYear(Year) ? 366 : 365; 
    }

    int NumberOfDaysInAYear() const 
    {
        return NumberOfDaysInAYear(_Year); 
    }

    static int NumberOfHoursInAYear(int Year) 
    { 
        return NumberOfDaysInAYear(Year) * 24; 
    }

    int NumberOfHoursInAYear() const 
    {
        return NumberOfHoursInAYear(_Year); 
    }

    static long NumberOfMinutesInAYear(int Year) 
    { 
        return static_cast<long>(NumberOfHoursInAYear(Year)) * 60; 
    }

    long NumberOfMinutesInAYear() const 
    {
        return NumberOfMinutesInAYear(_Year);
    }

    static long NumberOfSecondsInAYear(int Year) 
    { 
        return NumberOfMinutesInAYear(Year) * 60; 
    }

    long NumberOfSecondsInAYear() const 
    { 
        return NumberOfSecondsInAYear(_Year); 
    }

    static short NumberOfDaysInAMonth(short Month, int Year)
    {
        if (Month < 1 || Month > 12) return 0;
        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return Month == 2 ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    short NumberOfDaysInAMonth() const 
    { 
        return NumberOfDaysInAMonth(_Month, _Year); 
    }

    static int NumberOfHoursInAMonth(short Month, int Year) 
    { 
        return NumberOfDaysInAMonth(Month, Year) * 24;
    }

    int NumberOfHoursInAMonth() const 
    { 
        return NumberOfHoursInAMonth(_Month, _Year); 
    }

    static int NumberOfMinutesInAMonth(short Month, int Year) 
    { 
        return NumberOfHoursInAMonth(Month, Year) * 60; 
    }

    int NumberOfMinutesInAMonth() const 
    { 
        return NumberOfMinutesInAMonth(_Month, _Year); 
    }

    static long NumberOfSecondsInAMonth(short Month, int Year)
    { 
        return NumberOfMinutesInAMonth(Month, Year) * 60; 
    }

    long NumberOfSecondsInAMonth() const 
    {
        return NumberOfSecondsInAMonth(_Month, _Year); 
    }

    // Day of week: 0 = Sunday
    static short DayOfWeekOrder(short Day, short Month, int Year)
    {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + 12 * a - 2;
        return (Day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
    }

    short DayOfWeekOrder() const
    {
        return DayOfWeekOrder(_Day, _Month, _Year); 
    }

    static std::string DayShortName(short DayOfWeek)
    {
        std::string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return arrDayNames[DayOfWeek];
    }

    std::string DayShortName() const 
    { 
        return DayShortName(DayOfWeekOrder()); 
    }

    static std::string MonthShortName(short MonthNumber)
    {
        std::string Months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        return Months[MonthNumber - 1];
    }

    std::string MonthShortName() const 
    { 
        return MonthShortName(_Month); 
    }

    // Calendar printing
    static void PrintMonthCalendar(short Month, int Year)
    {
        short current = DayOfWeekOrder(1, Month, Year);
        short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short i = 0;
        for (; i < current; i++) 
        {
            printf("     ");
        }

        for (short j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0; printf("\n"); 
            }
        }

        printf("\n  _________________________________\n");
    }

    void PrintMonthCalendar() const
    { 
        PrintMonthCalendar(_Month, _Year); 
    }

    static void PrintYearCalendar(int Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");

        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }
    }

    void PrintYearCalendar() const 
    { 
        PrintYearCalendar(_Year); 
    }

    // Days from beginning of year
    static short DaysFromTheBeginningOfTheYear(short Day, short Month, int Year)
    {
        short total = 0;

        for (short i = 1; i < Month; i++)
        {
            total += NumberOfDaysInAMonth(i, Year);
        }

        return total + Day;
    }

    short DaysFromTheBeginningOfTheYear() const
    {
        return DaysFromTheBeginningOfTheYear(_Day, _Month, _Year);
    }

    // Convert day-of-year to date
    static clsDate GetDateFromDayOrderInYear(short DayOrder, int Year)
    {
        clsDate Date(1, 1, Year);
        short remaining = DayOrder;

        while (remaining > NumberOfDaysInAMonth(Date._Month, Year))
        {
            remaining -= NumberOfDaysInAMonth(Date._Month, Year);
            Date._Month++;
        }

        Date._Day = remaining;

        return Date;
    }

    // Add / Subtract days
    static clsDate AddOneDay(const clsDate &Date)
    {
        clsDate temp = Date;

        if (temp._Day == NumberOfDaysInAMonth(temp._Month, temp._Year))
        {
            temp._Day = 1;
            if (temp._Month == 12) { temp._Month = 1; temp._Year++; }
            else temp._Month++;
        }
        else temp._Day++;

        return temp;
    }

    void AddOneDay() 
    { 
        *this = AddOneDay(*this); 
    }

    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate temp = Date1;
        Date1 = Date2;
        Date2 = temp;
    }


    // ==================== Date Comparison ====================
    static bool IsDate1BeforeDate2(const clsDate& Date1, const clsDate& Date2)
    {
        if (Date1._Year != Date2._Year) return Date1._Year < Date2._Year;
        if (Date1._Month != Date2._Month) return Date1._Month < Date2._Month;
        return Date1._Day < Date2._Day;
    }

    bool IsDateBeforeDate2(const clsDate& Date2) const 
    { 
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(const clsDate& Date1, const clsDate& Date2)
    {
        return Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day;
    }

    bool IsDateEqualDate2(const clsDate& Date2) const 
    { 
        return IsDate1EqualDate2(*this, Date2); 
    }

    static bool IsDate1AfterDate2(const clsDate& Date1, const clsDate& Date2)
    {
        return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
    }

    bool IsDateAfterDate2(const clsDate& Date2) const 
    { 
        return IsDate1AfterDate2(*this, Date2); 
    }

    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

    static enDateCompare CompareDates(const clsDate& Date1, const clsDate& Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2)) return Before;
        if (IsDate1EqualDate2(Date1, Date2)) return Equal;
        return After;
    }

    enDateCompare CompareDates(const clsDate& Date2) const 
    { 
        return CompareDates(*this, Date2); 
    }

    static int GetDifferenceInDays(const clsDate &Date1, const clsDate &Date2, bool IncludeEndDay = false)
    {
        clsDate tempDate1 = Date1;
        clsDate tempDate2 = Date2;

        if (!IsDate1BeforeDate2(tempDate1, tempDate2)) SwapDates(tempDate1, tempDate2);

        int Days = 0;

        while (!IsDate1EqualDate2(tempDate1, tempDate2))
        {
            tempDate1 = AddOneDay(tempDate1);
            Days++;
        }

        if (IncludeEndDay) Days++;
        {
            return Days;
        }
    }

    int GetDifferenceInDays(const clsDate& Date2, bool IncludeEndDay = false) const
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }


    // Other methods (Add X days/weeks/months/years) can follow same pattern...
};