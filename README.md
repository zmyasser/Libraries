# 🌟 C++ Utilities Library Collection

Welcome to **C++ Utilities**, a comprehensive collection of reusable C++ libraries designed to simplify everyday programming tasks.  
This repository combines four powerful libraries — **clsDate**, **clsString**, **clsInputValidate**, and **clsUtility** — into a single toolbox that helps you manage **dates, strings, input validation, random generation, arrays, encryption, and more**.

---

## 🔹 Overview

This collection is designed for **C++ developers** who want to write clean, efficient, and safe code without reinventing the wheel. The libraries work together seamlessly:

- **clsDate** – Handle dates and times, including validation, comparison, addition/subtraction, and calendars.
- **clsString** – Efficient string manipulation, including splitting, trimming, casing, and numeric checks.
- **clsInputValidate** – Safe user input handling, including numeric ranges, string input, and date validation.
- **clsUtility** – General-purpose helper functions: random numbers, arrays, encryption, prime checks, number-to-text conversion, and swapping.

---

## ⚡ Key Features

- **Date Handling**
  - Create, validate, and compare dates
  - Leap year support
  - Convert day-of-year to actual date
  - Print month and year calendars
  - Calculate differences in days

- **String Utilities**
  - Split strings by delimiters
  - Trim leading/trailing spaces
  - Convert strings to uppercase or lowercase
  - Check if strings are numeric
  - Safe string manipulations for various use cases

- **Input Validation**
  - Read numbers and strings safely
  - Validate numbers within a range
  - Validate dates within a range
  - Template-based approach works for numeric types, strings, and dates

- **General Utilities**
  - Generate random numbers, letters, words, and keys
  - Array operations: fill, print, shuffle, reverse, copy, palindrome checks
  - Encrypt and decrypt text using simple key-based shifts
  - Check for prime numbers and print primes from arrays
  - Convert numbers to readable English text (e.g., `123 -> "One Hundred Twenty Three"`)
  - Swap values for integers, doubles, chars, strings, and even dates

---

## 📦 Example Usage

```cpp
#include "clsDate.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUtility.h"
#include <iostream>

int main() {
    // Date utilities
    clsDate today;
    clsDate birthday(15, 8, 2000);
    std::cout << "Today: " << today.DateToString() << std::endl;
    std::cout << "Days until birthday: " << today.GetDifferenceInDays(birthday) << std::endl;

    // String utilities
    std::string text = "Hello,World";
    std::vector<std::string> parts = clsString::Split(text, ",");
    std::cout << "First part: " << parts[0] << std::endl;

    // Input validation
    int age = clsInputValidate<int>::ReadNumberBetween(1, 120, "Enter your age: ");
    std::string name = clsInputValidate<std::string>::ReadString();

    // Utility functions
    clsUtility::Srand();
    int arr[5] = {1,2,3,4,5};
    clsUtility::ShuffleArray(arr, 5);
    clsUtility::PrintArray(arr, 5);

    std::string encrypted = clsUtility::EncryptText("Hello");
    std::string decrypted = clsUtility::DecryptText(encrypted);
    std::cout << "Encrypted: " << encrypted << " | Decrypted: " << decrypted << std::endl;

    std::cout << "Random key: " << clsUtility::GenerateKey() << std::endl;
    return 0;
}
