#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class clsString
{
private:
    std::string _Value;

public:

    clsString() : _Value("") {}

    clsString(const std::string& Value)
    {
        _Value = Value;
    }

    void SetValue(const std::string& Value)
    {
        _Value = Value;
    }

    const std::string& GetValue() const
    {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) std::string Value;

    // ---------------- LENGTH ----------------
    static size_t Length(const std::string& S1)
    {
        return S1.length();
    }

    size_t Length() const
    {
        return _Value.length();
    }

    // ---------------- WORD COUNT ----------------
    static short CountWords(const std::string& S1)
    {
        std::string temp = S1;
        std::string delim = " ";
        short Counter = 0;
        size_t pos = 0;

        while ((pos = temp.find(delim)) != std::string::npos)
        {
            std::string word = temp.substr(0, pos);
            if (!word.empty())
            {
                Counter++;
            }

            temp.erase(0, pos + delim.length());
        }

        if (!temp.empty())
            Counter++;

        return Counter;
    }

    short CountWords() const
    {
        return CountWords(_Value);
    }

    // ---------------- CASE FUNCTIONS ----------------
    static std::string UpperAllString(std::string S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
            S1[i] = std::toupper(S1[i]);

        return S1;
    }

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static std::string LowerAllString(std::string S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
        {
            S1[i] = std::tolower(S1[i]);
        }

        return S1;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    // ---------------- SPLIT ----------------
    static std::vector<std::string> Split(const std::string& S1, const std::string& Delim)
    {
        std::vector<std::string> result;
        std::string temp = S1;
        size_t pos = 0;

        while ((pos = temp.find(Delim)) != std::string::npos)
        {
            std::string word = temp.substr(0, pos);
            if (!word.empty())
            {
                result.push_back(word);
            }

            temp.erase(0, pos + Delim.length());
        }

        if (!temp.empty())
        {
            result.push_back(temp);
        }

        return result;
    }

    std::vector<std::string> Split(const std::string& Delim) const
    {
        return Split(_Value, Delim);
    }

    // ---------------- TRIM ----------------
    static std::string TrimLeft(const std::string& S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i);
            }
        }
        return "";
    }

    static std::string TrimRight(const std::string& S1)
    {
        if (S1.empty()) return "";

        for (int i = (int)S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    static std::string Trim(const std::string& S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    // ---------------- JOIN ----------------
    static std::string JoinString(const std::vector<std::string>& vString, const std::string& Delim)
    {
        if (vString.empty()) return "";

        std::string result;

        for (const std::string& s : vString)
        {
            result += s + Delim;
        }

        return result.substr(0, result.length() - Delim.length());
    }

    // ---------------- REPLACE ----------------
    static std::string ReplaceWord(const std::string& S1, const std::string& StringToReplace, const std::string& ReplaceTo)
    {
        std::vector<std::string> words = Split(S1, " ");

        for (std::string& w : words)
        {
            if (w == StringToReplace)
            {
                w = ReplaceTo;
            }
        }

        return JoinString(words, " ");
    }

    // ---------------- CLEAN ----------------
    static std::string RemovePunctuations(const std::string& S1)
    {
        std::string result;

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (!std::ispunct(S1[i]))
            {
                result += S1[i];
            }
        }

        return result;
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }
};