#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "clsDate.h"

class clsUtility
{
public:

    // ---------------- RANDOM ----------------
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int GetRandomNumber(int from, int to)
    {
        return rand() % (to - from + 1) + from;
    }

    // ---------------- INPUT ----------------
    static int ReadPositiveNumber()
    {
        int Number = 0;

        do
        {
            std::cout << "Please enter a positive number: ";
            std::cin >> Number;

        } while (Number <= 0);

        return Number;
    }

    // ---------------- CHAR GENERATION ----------------
    enum enCharType {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
            CharType = (enCharType)GetRandomNumber(1, 3);

        switch (CharType)
        {
        case SmallLetter:
            return char(GetRandomNumber(97, 122));
        case CapitalLetter:
            return char(GetRandomNumber(65, 90));
        case Digit:
            return char(GetRandomNumber(48, 57));
        case SpecialCharacter:
            return char(GetRandomNumber(33, 47));
        default:
            return char(GetRandomNumber(65, 90));
        }
    }

    static std::string GenerateWord(enCharType CharType, short Length)
    {
        std::string Word = "";

        for (int i = 0; i < Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }

        return Word;
    }

    static std::string GenerateKey()
    {
        return GenerateWord(SmallLetter, 4) + "-" +
            GenerateWord(CapitalLetter, 4) + "-" +
            GenerateWord(Digit, 4) + "-" +
            GenerateWord(SpecialCharacter, 4);
    }

    static void GenerateKeys(short NumberOfKeys)
    {
        for (short i = 1; i <= NumberOfKeys; i++)
        {
            std::cout << "Key[" << i << "] : " << GenerateKey() << std::endl;
        }
    }

    // ---------------- ARRAY ----------------
    static void FillArrayWithRandomNumbers(int arr[], short Length, int from, int to)
    {
        for (short i = 0; i < Length; i++)
        {
            arr[i] = GetRandomNumber(from, to);
        }
    }

    static void PrintArray(int arr[], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            std::cout << arr[i] << " ";
        }

        std::cout << std::endl;
    }

    static int MaxNumberInArray(int arr[], short Length)
    {
        int Max = arr[0];

        for (short i = 1; i < Length; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }

        return Max;
    }

    static int SumOfArray(int arr[], short Length)
    {
        int Sum = 0;

        for (short i = 0; i < Length; i++)
        {
            Sum += arr[i];
        }

        return Sum;
    }

    static float AverageOfArray(int arr[], short Length)
    {
        return (float)SumOfArray(arr, Length) / Length;
    }

    static void CopyArray(int Source[], int Destination[], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            Destination[i] = Source[i];
        }
    }

    static void ReverseCopyArray(int Source[], int Destination[], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            Destination[i] = Source[Length - 1 - i];
        }
    }

    static void ShuffleArray(int arr[], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            int idx1 = GetRandomNumber(0, Length - 1);
            int idx2 = GetRandomNumber(0, Length - 1);
            Swap(arr[idx1], arr[idx2]);
        }
    }

    static bool IsNumberInArray(int arr[], short Length, int Number)
    {
        for (short i = 0; i < Length; i++)
        {
            if (arr[i] == Number)
            {
                return true;
            }
        }
        return false;
    }

    // ---------------- SWAP ----------------
    static void Swap(int& A, int& B)
    {
        int temp = A;
        A = B;
        B = temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(std::string& A, std::string& B)
    {
        std::string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    // ---------------- PRIME ----------------
    enum enPrimeNumber { Prime = 1, NotPrime = 2 };

    static enPrimeNumber IsPrime(int Number)
    {
        if (Number < 2)
        {
            return NotPrime;
        }

        for (int i = 2; i <= sqrt(Number); i++)
        {
            if (Number % i == 0)
            {
                return NotPrime;
            }
        }

        return Prime;
    }

    static void PrintPrimeNumbers(int arr[], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            if (IsPrime(arr[i]) == Prime)
            {
                std::cout << arr[i] << " ";
            }
        }
    }

    // ---------------- CHECKS ----------------
    static bool IsPalindromeArray(int arr[], short Length)
    {
        for (short i = 0; i < Length / 2; i++)
        {
            if (arr[i] != arr[Length - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    static void PrintEvenNumbers(int arr[], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            if (arr[i] % 2 == 0)
            {
                std::cout << arr[i] << " ";
            }
        }
    }

    static void PrintOddNumbers(int arr[], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            if (arr[i] % 2 != 0)
            {
                std::cout << arr[i] << " ";
            }
        }
    }

    // ---------------- ENCRYPTION ----------------
    static std::string EncryptText(std::string Text, short Key = 5)
    {
        for (size_t i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + Key);
        }

        return Text;
    }

    static std::string DecryptText(std::string Text, short Key = 5)
    {
        for (size_t i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - Key);
        }

        return Text;
    }

    // ---------------- NUMBER TO TEXT ----------------
    static std::string NumberToText(long Number)
    {
        if (Number == 0)
            return "Zero";

        if (Number >= 1 && Number <= 19)
        {
            std::string arr[] = {
                "", "One", "Two", "Three", "Four",
                "Five", "Six", "Seven", "Eight", "Nine",
                "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
            };
            return arr[Number] + " ";
        }

        if (Number <= 99)
        {
            std::string arr[] = {
                "", "", "Twenty", "Thirty", "Forty",
                "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
            };
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number <= 999)
            return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);

        if (Number <= 999999)
            return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);

        if (Number <= 999999999)
            return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);

        return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
    }
};