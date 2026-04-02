
#include <iostream>
#include "clsUtility.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsDate.h"

int main()
{

    //------------------ clsInputValidate Class ------------------
    std::cout << "_____________clsInputValidate Library_____________ \n";
    auto Number = clsInputValidate<float>::ReadNumberBetween(11.3, 20.7);
    std::cout << "Number: " << Number << std::endl;;



    //------------------ clsUtility Class ------------------
    std::cout << "\n\n_____________clsUtility Library_____________ \n";
    int arr[6] = { 10, 3, 20, 100, 299, 568 };
    int MaxNumber = clsUtility::MaxNumberInArray(arr, 6);
    std::cout << "Maximum Number in array: " << MaxNumber << std::endl;


    //------------------ clsString Class ------------------
    std::cout << "\n\n_____________clsString Library_____________ \n";
    clsString Name("Zaabal Mohamed Yasser");
    std::cout << "Name: " << Name.GetValue() << std::endl;
    std::cout << "Number of Words: " << Name.CountWords() << std::endl;



    //------------------ clsDate Class ------------------
    std::cout << "\n\n_____________clsDate Library_____________ \n";
    clsDate Date1(1, 6, 2003);
    clsDate Date2;
    std::cout << "Difference in days: " << Date1.GetDifferenceInDays(Date2) << std::endl;


    system("pause>0");

    return 0;
}

