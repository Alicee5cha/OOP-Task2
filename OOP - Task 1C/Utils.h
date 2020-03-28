#pragma once

#include <string>
#include <iostream>
#include "date.h"
class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    
    static Date* getCurrentDate();

    static std::string ToUpperR(std::string s);
    static std::string ToUpperI(std::string s);
    static bool StartsWith(std::string fullText, std::string searchText);
};