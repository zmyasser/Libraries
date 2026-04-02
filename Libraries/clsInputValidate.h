#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include "clsDate.h"

template <typename T>
class clsInputValidate
{
public:

    // ---------------- NUMBER VALIDATION ----------------
    static bool IsNumberBetween(T Number, T from, T to)
    {
        return (Number >= from && Number <= to);
    }

    // ---------------- STRING NUMBER VALIDATION ----------------
    static bool IsNumberStringBetween(const std::string& Number, const std::string& from, const std::string& to)
    {
        try
        {
            int num = std::stoi(Number);
            int f = std::stoi(from);
            int t = std::stoi(to);

            return (num >= f && num <= t);
        }
        catch (...)
        {
            return false; 
        }
    }

    // ---------------- STRING INPUT ----------------
    static std::string ReadString()
    {
        std::string S;
        std::getline(std::cin >> std::ws, S);
        return S;
    }

    // ---------------- NUMBER INPUT ----------------
    static T ReadNumber(const std::string& prompt = "Enter a number: ", const std::string& errorMsg = "Invalid input, try again:\n")
    {
        T Number;

        std::cout << prompt;

        while (!(std::cin >> Number))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMsg;
        }

        return Number;
    }

    static T ReadNumberBetween(T from, T to, const std::string& prompt = "Enter a number: ", const std::string& errorMsg = "Out of range, try again:\n")
    {
        T Number = ReadNumber(prompt);

        while (!IsNumberBetween(Number, from, to))
        {
            std::cout << errorMsg;
            Number = ReadNumber(prompt);
        }

        return Number;
    }

    // ---------------- DATE VALIDATION ----------------
    static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
    {
        
        if (!clsDate::IsDate1BeforeDate2(DateFrom, DateTo))
        {
            clsUtility::Swap(DateFrom, DateTo); 
        }

        bool AfterOrEqualFrom =
            (clsDate::CompareDates(Date, DateFrom) == clsDate::After ||
                clsDate::CompareDates(Date, DateFrom) == clsDate::Equal);

        bool BeforeOrEqualTo =
            (clsDate::CompareDates(Date, DateTo) == clsDate::Before ||
                clsDate::CompareDates(Date, DateTo) == clsDate::Equal);

        return AfterOrEqualFrom && BeforeOrEqualTo;
    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
};
